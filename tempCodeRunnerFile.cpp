#include<fstream>
#include"math_tool.h"
#include "Quine-McClusky.h"

using namespace std;

int main(){

    string buf;
    vector<string> tmp_fsm;
    string nistr,nostr,npstr,nsstr,str_tmp;

    ifstream kiss("1.kiss",ios::in);//判断是否完成文件读取
    if(!kiss.is_open()){
        cout<<"wrong open file"<<endl;return 0;
    }else{cout<<"file is ok"<<endl;}
    
    while (getline(kiss,buf))
    {
       tmp_fsm.push_back(buf);
    }
    kiss.close();

   int size_fsm_file = tmp_fsm.size();
   string* stg_i = new string[size_fsm_file];
   string* stg_p = new string[size_fsm_file];
   string* stg_n = new string[size_fsm_file];
   string* stg_o = new string[size_fsm_file];
   int row_stg = 0;

    for(int j = 0 ; j <size_fsm_file;j++){
        switch(tmp_fsm[j][1])
        {   case 'i' : {
            for(int i = 2;tmp_fsm[j][i] != NULL;i++)
            { if(tmp_fsm[j][i]!=' ') 
            {nistr+=tmp_fsm[j][i];}} 
            break;}

            case 'o' : { for(int i = 2;tmp_fsm[j][i] != NULL;i++)
            { if(tmp_fsm[j][i]!=' ') 
            {nostr+=tmp_fsm[j][i];}} 
            break;}

            case 'p' : { 
            for(int i = 2;tmp_fsm[j][i] != NULL;i++)
            { if(tmp_fsm[j][i]!=' ') 
            {npstr+=tmp_fsm[j][i];}} 
            break;}

            case 's' : {
            for(int i = 2;tmp_fsm[j][i] != NULL;i++)
            { if(tmp_fsm[j][i]!=' ') 
            {nsstr+=tmp_fsm[j][i];}}
            break;}
     
            case '-' :
            case '0' :
            case '1' :{;
            for( int i = 0,n = 0;tmp_fsm[j][i] != NULL;i++)
              {    
                  if(tmp_fsm[j][i] != ' ')
                  {   
                    str_tmp += tmp_fsm[j][i]; 
                  }
                  else if(n==0){stg_i[row_stg] =str_tmp;str_tmp={};n++;}
                  else if(n==1){stg_p[row_stg] =str_tmp;str_tmp={};n++;}
                  else if(n==2){stg_n[row_stg] =str_tmp;str_tmp={};n++;}
              }
              stg_o[row_stg] =str_tmp;str_tmp={};//cout<<stg_i[row_stg]<<" "<<stg_p[row_stg]<<" "<<stg_n[row_stg]<<" "<<stg_o[row_stg]<<endl;
              row_stg++;
            break;
            }
            
            default : {break;}
        }
    }

    int ni = stoi(nistr);   
    int no = stoi(nostr);
    int np = stoi(npstr);
    int ns ;
    for(ns = 0;stg_p[0][ns] != NULL;ns++){;}
   
    string register_vector[ns];//在真值表中提取逻辑表达式
    string input_vector[ni];
    string output_vector[no];

    string notlist,andlist,orlist,reglist,wirelist,inputlist,outputlist;
    int num_wire = 0,num_and = 0,num_or = 0,num_not = 0,num_reg = 0; 

    for(int i = 0;i<ni;i++){
        input_vector[i] = "I"+to_string(i);//cout<<input_vector[i]<<endl;
    }   
    
    for(int i = 0 ;i<ns;i++){
        register_vector[i] = "S" + to_string(i) +"=";
       for(int n = 0;n<np;n++)
        {   if(strcmp(stg_n[n][i],'1')){
            
            for(int j = 0;j<ni;j++){
            if (strcmp(stg_i[n][j] ,'0')){register_vector[i].append("!"+input_vector[j]);}
            else if(strcmp(stg_i[n][j],'1')){register_vector[i].append(input_vector[j]);}
            }

            for(int m = 0;m<ns;m++){
                if(strcmp(stg_p[n][m],'0')){register_vector[i].append("!S"+to_string(m));}
                else if(strcmp(stg_p[n][m],'1')){register_vector[i].append("S"+to_string(m));}
            }
            register_vector[i].append("+");
          }
       }
        register_vector[i].erase(register_vector[i].end() - 1);
        cout<<register_vector[i]<<endl;
    }

    for(int i =0 ;i < no;i++){
     output_vector[i] = "O" + to_string(i)+"=";
     for(int j = 0 ; j <np; j++){
      if(strcmp(stg_o[j][i],'1'))
       {  for(int n = 0 ;n<ns;n++) {
           if(strcmp(stg_n[j][n],'0')){
            output_vector[i].append("!S"+to_string(n));
           }else{ output_vector[i].append("S"+to_string(n));}
          } output_vector[i].append("+");
       }
     } output_vector[i].erase(output_vector[i].end() - 1);  cout<<output_vector[i]<<endl;
  }
  
  string gatetype[] ={"or","and","not","input","notreg","reg"};
  string connecttype [] ={"N","R","in","out"} ;
  gate_tree = new gate*[ns];
  
  for(int j = 0;j<ns;j++)
    {   
        int num_or_this = numofchar('+',register_vector[j]);
        int depth_or = log2(num_or_this)+1;
        int depth_and =log2(ni+ns-1)+1;
        int depth = depth_and+depth_or;
        int num_leaves = pow(2,depth+1);
        gate_tree[j] = new gate[num_leaves]; 
        
        int xxx[num_or_this+1];
           for(int q = 0,k=0 ,o=ns+ni-1;q<np;q++){
             if(stg_n[q][j] == '1')
               {xxx[k]=q;k++;}
           }  
        
        for(int i =0;i<num_leaves;i++){//初始化
            gate_tree[j][i].place = i;
            gate_tree[j][i].type_gate = 0;
            gate_tree[j][i].type_output = 0;
            gate_tree[j][i].use_it = 0;
        } 
        //或门的赋值
        gate_tree[j][0].type_gate = 5;
        gate_tree[j][0].use_it = 1;
        gate_tree[j][0].gate = num_reg;num_reg++;
       
        for(int n = 1 ;n<num_or_this+1;n++){
            gate_tree[j][n].gate = num_or ;num_or++;
            gate_tree[j][n].use_it = 1;
            gate_tree[j][n].output = num_wire;num_wire++;
        }
        //为或门每个输入的与门树的赋值
        for(int n = num_or_this+1,q=0;n < 2*num_or_this+2;n++){
           int num_dontcare = numofchar('-',stg_i[xxx[q]])+numofchar('-',stg_p[xxx[q]]);
           int a = 2*(ns+ni-num_dontcare);
           int* hhh =abb(a,n); 
           for(int o = 0;o<ns+ni-num_dontcare-1;o++)//分配与门
           {    
                gate_tree[j][hhh[o]].type_gate = 1;
                gate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                gate_tree[j][hhh[o]].use_it = 1;
                gate_tree[j][hhh[o]].gate = num_and;  num_and++;
           } 
           //对与门树进行输入分配          
            for(int p = 0 ,o = ns+ni-1-num_dontcare;p<ni+ns;p++)
                   {  
                       if(p < ni&& stg_i[xxx[q]][p] !='-'){               
                            if(stg_i[xxx[q]][p] == '0'){
                            gate_tree[j][hhh[o]].use_it = 1;
                            gate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                            gate_tree[j][hhh[o]].type_gate = 2;
                            }else {gate_tree[j][hhh[o]].type_gate = 3;
                            gate_tree[j][hhh[o]].type_output = 2;
                            gate_tree[j][hhh[o]].output = p;}
                            gate_tree[j][hhh[o]].gate= p;
                            o++;
                    }else if(p >= ni&&stg_p[xxx[q]][p-ni] !='-'){ 
                            if(stg_p[xxx[q]][p-ni] == '0'){
                            gate_tree[j][hhh[o]].use_it = 1;
                            gate_tree[j][hhh[o]].type_gate = 4;
                            gate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                            gate_tree[j][hhh[o]].gate = p -ni;
                            }else {gate_tree[j][hhh[o]].type_gate = 5;
                            gate_tree[j][hhh[o]].type_output = 1;}
                            gate_tree[j][hhh[o]].gate = p-ni;
                            o++;
                            }
                   
                }
                q++;     
        }       
    }
   
   ogate_tree = new gate*[no];
   for(int j = 0;j<no;j++)
    {  
        int num_or_this ;
        num_or_this = numofchar('+',output_vector[j]);
        int depth_or = log2(num_or_this)+1;
        int depth_and = log2(ns-1)+1;
        int depth = depth_and+depth_or+1;
        int num_leaves = pow(2,depth);
        ogate_tree[j] = new gate[num_leaves]; 
        
        int xxx[num_or_this+1];
           for(int q = 0,k=0 ,o=ns-1;q<np;q++){
             if(stg_o[q][j] == '1')
               {xxx[k]=q;k++;}
           }  
 
        for(int i =0;i<num_leaves;i++){//初始化
            ogate_tree[j][i].place = i;
            ogate_tree[j][i].type_gate = 0;
            ogate_tree[j][i].type_output = 0;
            ogate_tree[j][i].use_it = 0;
        }
        //或门的赋值
        ogate_tree[j][0].type_gate = 5;
        ogate_tree[j][0].use_it = 1;
        ogate_tree[j][0].gate = j;
       
        for(int n = 1 ;n<num_or_this+1;n++){
            ogate_tree[j][n].gate = num_or ;num_or++;
            ogate_tree[j][n].use_it = 1;
            ogate_tree[j][n].output = num_wire;num_wire++;
        }
        //为或门每个输入的与门树的赋值
        for(int n = num_or_this+1,q=0;n < 2*num_or_this+2;n++){
           int num_dontcare = numofchar('-',stg_n[xxx[q]]);
           int a = 2*(ns - num_dontcare);
           int* hhh =abb(a,n);
           for(int o = 0;o<ns-1-num_dontcare;o++)//分配与门
           {
                ogate_tree[j][hhh[o]].type_gate = 1;
                ogate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                ogate_tree[j][hhh[o]].use_it = 1;
                ogate_tree[j][hhh[o]].gate = num_and;  num_and++;
           }  
           //对与门树进行输入分配             
            for(int p = 0 ,o = ns-1-num_dontcare;p<ns;p++)
                   if(stg_n[q][p] !='-'){
                   {if(stg_n[xxx[q]][p] == '0'){
                        ogate_tree[j][hhh[o]].use_it =1 ;
                        ogate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                        ogate_tree[j][hhh[o]].type_gate = 2;
                        }else {ogate_tree[j][hhh[o]].type_gate = 3;
                        ogate_tree[j][hhh[o]].type_output = 1;
                        ogate_tree[j][hhh[o]].output = p;
                        ogate_tree[j][hhh[o]].output = p;
                        ogate_tree[j][hhh[o]].use_it =1 ;}
                    ogate_tree[j][hhh[o]].gate = p;
                    o++;
                }
                }
                q++;     
        }
    } cout<<"pass"<<endl;

    for(int j = 0 ;j<ns;j++) 
    {   int num_or_this = numofchar('+',register_vector[j]);
        int depth_or = log2(num_or_this)+1;
        int depth_and =log2(ni+ns-1)+1;
        int depth = depth_and+depth_or;
        int num_leaves = pow(2,depth+1);
        for(int x = 0 ;x<num_leaves;x++){
           if(gate_tree[j][x].use_it == 1) 
            {
                switch (gate_tree[j][x].type_gate)
                {
                case 0:
                    orlist += "or or"+to_string(gate_tree[j][x].gate)+"("+connecttype[gate_tree[j][x].type_output]+to_string(gate_tree[j][x].output)+",";
                    orlist += connecttype [gate_tree[j][gate_tree[j][x].place*2].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2].output)+",";
                    orlist += connecttype [gate_tree[j][gate_tree[j][x].place*2+1].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2+1].output)+");\n";
                    break;
                case 1:
                    andlist += "and and"+to_string(gate_tree[j][x].gate)+"("+connecttype[gate_tree[j][x].type_output]+to_string(gate_tree[j][x].output)+",";
                    andlist += connecttype[gate_tree[j][gate_tree[j][x].place*2].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2].output)+",";
                    andlist += connecttype[gate_tree[j][gate_tree[j][x].place*2+1].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2+1].output)+");\n"; 
                    break;
                case 2:
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(gate_tree[j][x].output)+",";
                    notlist += "in"+to_string(gate_tree[j][x].gate)+");\n";
                    num_not++;cout<<gate_tree[j][x].output<<"  ";
                    break;
                case 4:
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(gate_tree[j][x].output)+",";
                    notlist += "R"+to_string(gate_tree[j][x].gate)+");\n";
                    num_not++;cout<<gate_tree[j][x].output<<"  ";
                    break;    
                case 5:
                    reglist += "always@(posedge clk)\n   R" ;
                    reglist+=to_string(gate_tree[j][x].gate) +=" <= N" ;
                    reglist += to_string(gate_tree[j][1].output)+=";\n";
                    break;
                default:
                    break;
                }
            }
          }
        }  //this*/

    for(int j = 0 ;j<no;j++){
        int num_or_this = numofchar('+',output_vector[j]);
        int depth_or = log2(num_or_this)+1;
        int depth_and =log2(ns-1)+1;
        int depth = depth_and+depth_or;
        int num_leaves = pow(2,depth+1);cout<<num_leaves<<endl;
        for(int x = 0 ;x<num_leaves;x++){
           if(ogate_tree[j][x].use_it == 1) 
            {
                switch (ogate_tree[j][x].type_gate)
                {
                case 0:
                    orlist += "or or"+to_string(ogate_tree[j][x].gate)+"("+connecttype[ogate_tree[j][x].type_output]+to_string(ogate_tree[j][x].output)+",";
                    orlist += connecttype [ogate_tree[j][ogate_tree[j][x].place*2].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2].output)+",";
                    orlist += connecttype [ogate_tree[j][ogate_tree[j][x].place*2+1].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2+1].output)+");\n";
                    break;
                case 1:
                    andlist += "and and"+to_string(ogate_tree[j][x].gate)+"("+connecttype[ogate_tree[j][x].type_output]+to_string(ogate_tree[j][x].output)+",";
                    andlist += connecttype[ogate_tree[j][ogate_tree[j][x].place*2].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2].output)+",";
                    andlist += connecttype[ogate_tree[j][ogate_tree[j][x].place*2+1].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2+1].output)+");\n"; 
                    break;
                case 2:
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(ogate_tree[j][x].output)+",";
                    notlist += "R"+to_string(ogate_tree[j][x].gate)+");\n";
                    num_not++;
                    break;    
                case 5:
                    reglist += "always@(posedge clk)\n   O" ;
                    reglist+=to_string(ogate_tree[j][x].gate) +=" <= N" ;
                    reglist += to_string(ogate_tree[j][1].output)+=";\n";
                    break;
                default:
                    break;
                }
            }
          }

    }    
       cout<<orlist;
       cout<<andlist;
       cout<<notlist;

    for(int i = 1 ;i<ni+1;i++){
        if(i%10 == 0){inputlist +="\n";}
        inputlist+="in"+to_string(i-1)+",";   
    }   
	inputlist.erase(inputlist.end() - 1);

    for(int i = 1 ;i<no+1;i++){
        if(i%10 == 0){outputlist +="\n";}
        outputlist+="O"+to_string(i-1)+",";   
    }   
	outputlist.erase(outputlist.end() - 1);
    
    string reg;
    for(int i = 1 ;i<ns+1;i++){
        if(i%10 == 0){reg +="\n";}
        reg+="R"+to_string(i-1)+",";   
    }   
    for(int i = 1 ;i<no+1;i++){
        if(i%10 == 0){reg +="\n";}
        reg+="O"+to_string(i-1)+",";   
    }   
	reg.erase(reg.end() - 1);

    for(int i = 1 ;i<num_wire+1;i++){
        if(i%10 == 0){wirelist +="\n";}
        wirelist+="N"+to_string(i-1)+",";   
    }   
	wirelist.erase(wirelist.end() - 1);

    ofstream file("fsm.v",ios::out); 
    file<<"//num of or = "<<num_or+1<<endl;
    file<<"//num of and = "<<num_and+1<<endl;
    file<<"//num of not = "<<num_not+1<<endl;
    file<<"//num of wire = "<<num_wire+1<<endl;   
    file<<"module c1126 (";
    file<<inputlist<<","<<outputlist<<",clk);\n\n";
    file<<"input "<<inputlist<<",clk;\n\n";
    file<<"output "<<outputlist<<";\n\n";
    file<<"wire "<<inputlist<<","<<wirelist<<",clk;\n\n";
    file<<"reg "<<reg<<";\n\n";
    file<<reglist<<"\n";
    file<<andlist<<"\n";
    file<<orlist<<"\n";
    file<<notlist<<"\n";
    file<<"endmodule";
    
    
    cout<<"logic equation extract successfully"<<endl;

    return 0;
}