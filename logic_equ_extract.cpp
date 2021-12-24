#include<fstream>
#include"math_tool.h"

using namespace std;

int main(){

    string buf;
    vector<string> tmp_fsm;
    string nistr,nostr,npstr,nsstr,str_tmp;

    ifstream kiss("1111.kiss",ios::in);//判断是否完成文件读取
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
   
    /*string register_vector[ns];//在真值表中提取逻辑表达式
    string input_vector[ni];
    string output_vector[no];
    
    for(int i = 0;i<ni;i++){
        input_vector[i] = "input"+to_string(i);//cout<<input_vector[i]<<endl;
    }   

    for(int i = 0 ;i<ns;i++){
        register_vector[i] = "reg" + to_string(i) +"=";
       for(int n = 0;n<np;n++)
        {   if(strcmp(stg_n[n][i],'1')){
            
            for(int j = 0;j<ni;j++){
            if (strcmp(stg_i[n][j] ,'0')){register_vector[i].append("!"+input_vector[j]);}
            else if(strcmp(stg_i[n][j],'1')){register_vector[i].append(input_vector[j]);}
            }

            for(int m = 0;m<ns;m++){
                if(strcmp(stg_p[n][m],'0')){register_vector[i].append("!reg"+to_string(m));}
                else if(strcmp(stg_p[n][m],'1')){register_vector[i].append("reg"+to_string(m));}
            }
            register_vector[i].append("+");
          }
       }
        register_vector[i].erase(register_vector[i].end() - 1);
        cout<<register_vector[i]<<endl;
    }

    for(int i =0 ;i < no;i++){
     output_vector[i] = "output" + to_string(i)+"=";
     for(int j = 0 ; j <np; j++){
      if(strcmp(stg_o[j][i],'1'))
       {  for(int n = 0 ;n<ns;n++) {
           if(strcmp(stg_n[j][n],'0')){
            output_vector[i].append("!reg"+to_string(n));
           }else{ output_vector[i].append("reg"+to_string(n));}
          } output_vector[i].append("+");
       }
     } output_vector[i].erase(output_vector[i].end() - 1);  cout<<output_vector[i]<<endl;
  }
    cout<<"logic equation extract successfully"<<endl;*/

 string not_list,andlist,orlist,reglist,wirelist;
 int num_wire,num_and,num_or,num_not; 
 
    return 0;
}