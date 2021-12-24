#include<fstream>
#include"math_tool.h"
#include "QuineMcClusky.h"

using namespace std;

int main(){

    string buf;
    vector<string> tmp_fsm;
    string nistr,nostr,npstr,nsstr,str_tmp;

    ifstream kiss("ass_fsm.kiss",ios::in);//判断是否完成文件读取
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
  
  string gatetype[] ={"or","and","not","input","notreg","reg"};
  string connecttype [] ={"N","R","in","out"} ;
  
   vector <string> minterms,buff;
   vector <mintermspair> group[ni+ns+1];
   vector <string> simed;
   mintermspair minters_p[2*np];
   int hhhhh;
   int numofeqn ;
   int numof_in;
   int ortreeleaves[ns];int andtreeleaves[no];

   gate_tree = new gate*[ns];
   for(int j = 0;j<ns;j++)
    {   
        numofeqn = 0 ;
        for(int n = 0;n<np;n++)//读取真值表并扩展dont care
        {   
            if(strcmp(stg_n[n][j],'1')){
              numof_in = numofchar('-',stg_i[n]+stg_p[n]);//cout<<stg_i[n]+stg_p[n]<<endl;
              if(numof_in == 0)
              {buff.push_back(stg_i[n]+stg_p[n]);
              }
              else
              {string tmp = stg_i[n]+stg_p[n];
              expandontcare(tmp,buff,numof_in);
              }      
            }
        }
            for(int ini = 0 ,inj =0;ini<buff.size();ini++){//cout<<buff[ini]<<endl;
               if(!in_vector(minterms,buff[ini])){
                   minterms.push_back(buff[ini]);//cout<<buff[ini]<<endl;
                   numofeqn++;
                }
            }for(int ini = 0;ini<minterms.size();ini++){cout<<minterms[ini]<<endl;}cout<<endl;
            buff.resize(0);
    //GROUP
    bool oversim = 1;
    
    while(oversim){
       hhhhh =0;int dontaskmore = minterms.size();
       for(int m = 0 ;m<ni+ns+1;m++){group[m].resize(0);}
       for(int m = 0 ;m<minterms.size();m++){//cout<<minterms[m]<<endl;
           minters_p[m].minterms = minterms[m];
           minters_p[m].in_token = m;
           group[numofchar('1',minterms[m])].push_back(minters_p[m]);
       }
       minterms.resize(0);
       int token [numofeqn];for(int ini =0 ;ini<numofeqn;ini++){token[ini] = 0;}
       for(int m =1;m<ni+ns+1;m++){
         if(group[m].size() != 0)
           {   //cout<<m<<"&"<<group[m].size()<<endl;
               for(int ini = 0;ini<group[m].size();ini++){//cout<<group[m][ini].minterms<<endl;

                    for(int inini = 0;inini<group[m+1].size()&&group[m+1].size()!=0&&token[group[m][ini].in_token] == 0&&m<ni+ns;inini++){//当n_group不为空时，为group中每一个元素查找n_group中的格林码
                        if(token[group[m+1][inini].in_token] == 1){}
                        else if(isGreyCode(group[m][ini].minterms,group[m+1][inini].minterms)&&!in_vector(minterms,replace_complements(group[m][ini].minterms,group[m+1][inini].minterms))){
                            minterms.push_back( replace_complements(group[m][ini].minterms,group[m+1][inini].minterms) );
                            token[group[m][ini].in_token] = 1;
                            token[group[m+1][inini].in_token] = 1;
                            hhhhh++;
                      }
                    }
                   
                    if (token[group[m][ini].in_token]==0)//如果该项没有找到合并，再已经ngroup中已经token的部分查找
                    { 
                    for(int inini = 0,find = 0;inini<group[m+1].size()&&group[m+1].size()!=0&&find == 0&&m<ni+ns;inini++){//当n_group不为空时，为group中每一个元素查找n_group中的格林码
                        if(isGreyCode(group[m][ini].minterms,group[m+1][inini].minterms)&&!in_vector(minterms,replace_complements(group[m][ini].minterms,group[m+1][inini].minterms))){
                        minterms.push_back( replace_complements(group[m][ini].minterms,group[m+1][inini].minterms) );
                        token[group[m][ini].in_token] = 1;
                        find = 1;
                        hhhhh++;
                        }
                    }
                    }

                    if (token[group[m][ini].in_token]==0)
                    {//向上查找
                      for(int inini = 0,find = 0;inini<group[m-1].size()&&group[m-1].size()!=0&&find ==0&&m>0;inini++){//当n_group不为空时，为group中每一个元素查找n_group中的格林码
                        if(isGreyCode(group[m][ini].minterms,group[m-1][inini].minterms)&&!in_vector(minterms,replace_complements(group[m][ini].minterms,group[m-1][inini].minterms))){
                        minterms.push_back( replace_complements(group[m][ini].minterms,group[m-1][inini].minterms) );
                        token[group[m][ini].in_token] = 1;
                        find = 1;
                        hhhhh++;
                        }
                    }
                    }
                    if (token[group[m][ini].in_token]==0){
                        simed.push_back(group[m][ini].minterms);
                    }
                   
              }
           }
         }if(hhhhh == 0){oversim = 0;}
       }
for(int ini = 0 ;ini <simed.size();ini++){cout<<simed[ini]<<"<<"<<endl;}cout<<"==============================="<<endl;
       //for(int ini =0 ;ini<simed.size();ini++){cout<<simed[ini]<<endl;}

        int num_or_this = simed.size() - 1 ; 
        int depth_or = log2(num_or_this)+1;
        int depth_and =log2(ni+ns-1)+1;
        int depth = depth_and+depth_or+1;
        int  num_leaves = pow(2,depth);
        ortreeleaves[j] = num_leaves;
        gate_tree[j] = new gate[num_leaves]; 
        
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
           int num_dontcare = numofchar('-',simed[q]);
           int a = 2*(ns+ni-num_dontcare);
           int* hhh =abb(a,n); 
           for(int o = 0;o<ns+ni-num_dontcare-1;o++)//分配非末端与门
           {   
                gate_tree[j][hhh[o]].type_gate = 1;
                gate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                gate_tree[j][hhh[o]].use_it = 1;
                gate_tree[j][hhh[o]].gate = num_and;  num_and++;
           } 
           //对与门树进行输入分配          
            for(int p = 0 ,o = ns+ni-1-num_dontcare;p<ni+ns;p++)
                   {  
                       if(p < ni){   
                         if(simed[q][p]!='-')  {       
                            if(simed[q][p] == '0'){
                            gate_tree[j][hhh[o]].use_it = 1;
                            gate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                            gate_tree[j][hhh[o]].type_gate = 2;
                            gate_tree[j][hhh[o]].gate= p;
                            }else {gate_tree[j][hhh[o]].type_gate = 3;
                            gate_tree[j][hhh[o]].type_output = 2;
                            gate_tree[j][hhh[o]].output = p;
                            gate_tree[j][hhh[o]].gate= p;}
                           o++;}
                    }else if(p >= ni&&simed[q][p] !='-'){ 
                        if(simed[q][p]!='-')  { 
                            if(simed[q][p] == '0'){
                            gate_tree[j][hhh[o]].use_it = 1;
                            gate_tree[j][hhh[o]].type_gate = 4;
                            gate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                            gate_tree[j][hhh[o]].gate = p - ni;
                            }else {gate_tree[j][hhh[o]].type_gate = 5;
                            gate_tree[j][hhh[o]].type_output = 1;
                            gate_tree[j][hhh[o]].output = p-ni;
                            gate_tree[j][hhh[o]].gate = p - ni;}
                            o++;}
                            }
                }
                q++;     
        }simed.resize(0);
    }

   minterms.resize(0);buff.resize(0);simed.resize(0);

   ogate_tree = new gate*[no];
   for(int j = 0;j<no;j++)
    {   numofeqn = 0;
        for(int n = 0;n<np;n++)//读取真值表并扩展动态care
        {   
            if(strcmp(stg_o[n][j],'1')){
              int numof_in = numofchar('-',stg_p[n])+numofchar('-',stg_i[n]);
              if(numof_in == 0)
              {buff.push_back(stg_i[n]+stg_p[n]);
              }
              else 
              {
              expandontcare(stg_i[n]+stg_p[n],buff,numof_in);
              }      
            }
       }  
       for(int ini = 0 ;ini<buff.size();ini++){
           if(!in_vector(minterms,buff[ini])){
                minterms.push_back(buff[ini]);
                numofeqn++;
           }
       }for(int ini = 0;ini<minterms.size();ini++){cout<<minterms[ini]<<endl;}cout<<endl;
       buff.resize(0);      

    //GROUP
    bool oversim = 1;
    vector <string> simed;simed.resize(0);
    while(oversim){
       hhhhh =0;
       for(int m = 0 ;m<ns+ni+1;m++){group[m].resize(0);}
       for(int m = 0 ;m<minterms.size();m++){
           minters_p[m].minterms = minterms[m];//cout<<minterms[m]<<endl;
           minters_p[m].in_token = m;
           group[numofchar('1',minterms[m])].push_back(minters_p[m]);
       }
       minterms.resize(0);
       int token [numofeqn];for(int ini =0 ;ini<numofeqn;ini++){token[ini] = 0;}
       for(int m =0;m<ns+ni+1;m++){
         if(group[m].size() != 0)
           {   //cout<<m<<" & "<<group[m].size()<<endl;
               for(int ini = 0;ini<group[m].size();ini++){//cout<<group[m][ini].minterms<<endl;

                    for(int inini = 0;inini<group[m+1].size()&&group[m+1].size()!=0&&token[group[m][ini].in_token] == 0&&m<ni+ns;inini++){//当n_group不为空时，为group中每一个元素查找n_group中的格林码
                        if(token[group[m+1][inini].in_token] == 1){}
                        else if(isGreyCode(group[m][ini].minterms,group[m+1][inini].minterms)&&!in_vector(minterms,replace_complements(group[m][ini].minterms,group[m+1][inini].minterms))){
                            minterms.push_back( replace_complements(group[m][ini].minterms,group[m+1][inini].minterms) );
                            token[group[m][ini].in_token] = 1;
                            token[group[m+1][inini].in_token] = 1;//cout<<minterms[hhhhh]<<endl;
                            hhhhh++;
                      }
                    }
                   
                    if (token[group[m][ini].in_token]==0)//如果该项没有找到合并，再已经ngroup中已经token的部分查找
                    { 
                    for(int inini = 0,find = 0;inini<group[m+1].size()&&group[m+1].size()!=0&&find == 0&&m<ni+ns;inini++){//当n_group不为空时，为group中每一个元素查找n_group中的格林码
                        if(isGreyCode(group[m][ini].minterms,group[m+1][inini].minterms)&&!in_vector(minterms,replace_complements(group[m][ini].minterms,group[m+1][inini].minterms))){
                        minterms.push_back( replace_complements(group[m][ini].minterms,group[m+1][inini].minterms) );
                        token[group[m][ini].in_token] = 1;
                        find = 1;//cout<<minterms[hhhhh]<<endl;
                        hhhhh++;
                        }
                    }
                    }

                    if (token[group[m][ini].in_token]==0)
                    {//向上查找
                      for(int inini = 0,find = 0;inini<group[m-1].size()&&group[m-1].size()!=0&&find ==0&&m>0;inini++){//当n_group不为空时，为group中每一个元素查找n_group中的格林码
                        if(isGreyCode(group[m][ini].minterms,group[m-1][inini].minterms)&&!in_vector(minterms,replace_complements(group[m][ini].minterms,group[m-1][inini].minterms))){
                        minterms.push_back( replace_complements(group[m][ini].minterms,group[m-1][inini].minterms) );
                        token[group[m][ini].in_token] = 1;
                        find = 1;//cout<<minterms[hhhhh]<<endl;
                        hhhhh++;
                        }
                    }
                    }
                   
                    if (token[group[m][ini].in_token]==0){
                        simed.push_back(group[m][ini].minterms);
                    }
                   
              }
           }
         }if(hhhhh == 0){oversim = 0;}//cout<<hhhhh<<endl;
       }
    for(int ini = 0 ;ini <simed.size();ini++){cout<<simed[ini]<<"<<"<<endl;}cout<<"==============================="<<endl;
        int num_or_this = simed.size() - 1;
        int depth_or = log2(num_or_this)+1;
        int depth_and = log2(ns+ni-1)+1;
        int depth = depth_and+depth_or+1;
        int num_leaves = pow(2,depth);
        andtreeleaves[j] = num_leaves;
        ogate_tree[j] = new gate[num_leaves]; 
        
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
           int num_dontcare = numofchar('-',simed[q]);
           int a = 2*(ns + ni - num_dontcare);
           int* hhh =abb(a,n);   
           for(int o = 0;o<ns + ni - num_dontcare -1;o++)//分配与门
           {
                ogate_tree[j][hhh[o]].type_gate = 1;
                ogate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                ogate_tree[j][hhh[o]].use_it = 1;
                ogate_tree[j][hhh[o]].gate = num_and;  num_and++;
           }  
           //对与门树进行输入分配             
            for(int p = 0 ,o = ns+ni-1-num_dontcare;p<ni+ns;p++)
                   {  
                       if(p < ni){   
                         if(simed[q][p]!='-')  {       
                            if(simed[q][p] == '0'){
                            ogate_tree[j][hhh[o]].use_it = 1;
                            ogate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                            ogate_tree[j][hhh[o]].type_gate = 2;
                            }else {ogate_tree[j][hhh[o]].type_gate = 3;
                            ogate_tree[j][hhh[o]].type_output = 2;
                            ogate_tree[j][hhh[o]].output = p;}
                            ogate_tree[j][hhh[o]].gate= p;
                            o++; }
                    }else if(p >= ni&&simed[q][p] !='-'){ 
                        if(simed[q][p]!='-')  { 
                            if(simed[q][p] == '0'){
                            ogate_tree[j][hhh[o]].use_it = 1;
                            ogate_tree[j][hhh[o]].type_gate = 4;
                            ogate_tree[j][hhh[o]].output =num_wire;  num_wire++;
                            ogate_tree[j][hhh[o]].gate = p - ni; 
                            }else {ogate_tree[j][hhh[o]].type_gate = 3;
                            ogate_tree[j][hhh[o]].type_output = 1;
                            ogate_tree[j][hhh[o]].gate = p-ni;
                            ogate_tree[j][hhh[o]].output = p-ni;
                            ogate_tree[j][hhh[o]].use_it = 1;}
                            o++; }
                            }       
                }
                q++;   
        }
    } cout<<"pass !"<<endl;

cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    for(int j = 0 ;j<ns;j++) 
    {   
        for(int x = 0 ;x<ortreeleaves[j];x++){
           if(gate_tree[j][x].use_it == 1) 
            {
                switch (gate_tree[j][x].type_gate)
                {
                case 0://orlist += "sta"+to_string(j)+" "+to_string(x)+" ";
                    orlist += "or or"+to_string(gate_tree[j][x].gate)+"("+connecttype[gate_tree[j][x].type_output]+to_string(gate_tree[j][x].output)+",";
                    orlist += connecttype [gate_tree[j][gate_tree[j][x].place*2].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2].output)+",";
                    orlist += connecttype [gate_tree[j][gate_tree[j][x].place*2+1].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2+1].output)+");\n";
                    break;
                case 1://andlist += "sta"+to_string(j)+" "+to_string(x)+" ";
                    andlist += "and and"+to_string(gate_tree[j][x].gate)+"("+connecttype[gate_tree[j][x].type_output]+to_string(gate_tree[j][x].output)+",";
                    andlist += connecttype[gate_tree[j][gate_tree[j][x].place*2].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2].output)+",";
                    andlist += connecttype[gate_tree[j][gate_tree[j][x].place*2+1].type_output]+to_string(gate_tree[j][gate_tree[j][x].place*2+1].output)+");\n"; 
                    break;
                case 2://notlist += "sta"+to_string(j)+" "+to_string(x)+" "; 
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(gate_tree[j][x].output)+",";
                    notlist += "in"+to_string(gate_tree[j][x].gate)+");\n";
                    num_not++;
                    break;
                case 4://notlist += "sta"+to_string(j)+" "+to_string(x)+" "; 
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(gate_tree[j][x].output)+",";
                    notlist += "R"+to_string(gate_tree[j][x].gate)+");\n";
                    num_not++;
                    break;    
                case 5:
                    reglist += "always@(posedge clk or negedge rst)\n  if(!rst)\n R" ;
                    reglist += to_string(gate_tree[j][0].gate) +=" <= N" ;
                    reglist += to_string(gate_tree[j][1].output)+=";\n";
                    reglist += "else\n R" + to_string(gate_tree[j][0].gate) +=" <= 1'b0;\n" ;
                    break;
                default:
                    break;
                }
            }
          }
        }  //this*/

    for(int j = 0 ;j<no;j++){
        for(int x = 0 ;x<andtreeleaves[j] ;x++){
           if(ogate_tree[j][x].use_it == 1) 
            {
                switch (ogate_tree[j][x].type_gate)
                {
                case 0://orlist += "out"+to_string(j)+" "+to_string(x)+" ";
                    orlist += "or or"+to_string(ogate_tree[j][x].gate)+"("+connecttype[ogate_tree[j][x].type_output]+to_string(ogate_tree[j][x].output)+",";
                    orlist += connecttype [ogate_tree[j][ogate_tree[j][x].place*2].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2].output)+",";
                    orlist += connecttype [ogate_tree[j][ogate_tree[j][x].place*2+1].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2+1].output)+");\n";
                    break;
                case 1://andlist += "out"+to_string(j)+" "+to_string(x)+" ";
                    andlist += "and and"+to_string(ogate_tree[j][x].gate)+"("+connecttype[ogate_tree[j][x].type_output]+to_string(ogate_tree[j][x].output)+",";
                    andlist += connecttype[ogate_tree[j][ogate_tree[j][x].place*2].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2].output)+",";
                    andlist += connecttype[ogate_tree[j][ogate_tree[j][x].place*2+1].type_output]+to_string(ogate_tree[j][ogate_tree[j][x].place*2+1].output)+");\n"; 
                    break;
                case 2://notlist += "out"+to_string(j)+" "+to_string(x)+" "; 
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(ogate_tree[j][x].output)+",";
                    notlist += "in"+to_string(ogate_tree[j][x].gate)+");\n";
                    num_not++;
                    break;
                case 4://notlist += "out"+to_string(j)+" "+to_string(x)+" "; 
                    notlist += "not not"+to_string(num_not) +"(N"+to_string(ogate_tree[j][x].output)+",";
                    notlist += "R"+to_string(ogate_tree[j][x].gate)+");\n";
                    num_not++;
                    break;    
                case 5:
                    reglist += "always@(posedge clk or negedge rst)\n  if(!rst)\n O" ;
                    reglist += to_string(ogate_tree[j][0].gate) +=" <= N" ;
                    reglist += to_string(ogate_tree[j][1].output)+=";\n";
                    reglist += "else\n O" + to_string(ogate_tree[j][0].gate) +=" <= 1'b0;\n" ;
                    break;
                default:
                    break;
                }
            }
          }

    }  
      
   // cout<<orlist;
   // cout<<andlist;
  //  cout<<notlist;

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

    ofstream file("c1126.v",ios::out); 
    file<<"//num of or = "<<num_or+1<<endl;
    file<<"//num of and = "<<num_and+1<<endl;
    file<<"//num of not = "<<num_not+1<<endl;
    file<<"//num of wire = "<<num_wire+1<<endl;   
    file<<"module c1126 (";
    file<<inputlist<<","<<outputlist<<",clk,rst);\n\n";
    file<<"input "<<inputlist<<",clk,rst;\n\n";
    file<<"output "<<outputlist<<";\n\n";
    file<<"wire "<<inputlist<<","<<wirelist<<",clk,rst;\n\n";
    file<<"reg "<<reg<<";\n\n";
    file<<reglist<<"\n";
    file<<andlist<<"\n";
    file<<orlist<<"\n";
    file<<notlist<<"\n";
    file<<"endmodule";
    
    
    cout<<"logic equation extract successfully"<<endl;

    return 0;
}