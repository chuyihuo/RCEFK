#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>

using namespace std;



/*function to convert decimal to binary
* Eg: 14 = 1110
*/

//function to pad zeros to the binary equivalent of digits.
//Eg: If there are 4 variables, 2, that is 10 in binary is represented as 0010

//function to check if two terms differ by just one bit

//function to check if 2 vectors are equal
bool VectorsEqual(vector<string> a,vector<string> b)
{
   if(a.size()!=b.size())
      return false;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}



string pad(string bin,int VARIABLES)
{
   int max=VARIABLES-bin.length();
   for(int i=0; i<max; i++)
       bin="0"+bin;
   return bin;
}

string decToBin(int n)
{
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decToBin(n / 2) + "0";
   else
       return decToBin(n / 2) + "1";
}

int expandontcare(string x,vector<string> &b,int a){
   for(int i = 0;i<pow(2,a);i++){
      string hhh = decToBin(i);
      hhh = pad(hhh,a) ;
      string tmp ;
         for(int j = 0,n = 0;j<x.length();j++){
         if(x[j] !='-')
         {tmp += x[j];}
         else{tmp += hhh[n];
              n++;}
        } 
        b.push_back(tmp);
   }

}

bool isGreyCode(string a,string b)
{
   int flag=0;
   for(int i=0;i<a.length();i++)
   {
       if(a[i]!=b[i])
        flag++;
   }
   return (flag==1);
}

//function to replace complement terms with don't cares
// Eg: 0110 and 0111 becomes 011-
string replace_complements(string a,string b)
{
   string temp="";
   for(int i=0;i<a.length();i++)
   if(a[i]!=b[i])
       temp=temp+"-";
   else
       temp=temp+a[i];

   return temp;
}

//function to check if string b exists in vector a
bool in_vector(vector<string> a,string b)
{
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}


//function to reduce minterms
vector<string> reduce(vector<string> minterms)
{
/*for (int i=0; i<minterms.size(); i++)
       cout << minterms[i]<<endl;
       cout <<endl;*/

      vector<string> newminterms;

      int max=minterms.size();
      int* checked = new int[max];
      for(int i=0;i<max;i++)
      {
          for(int j=i;j<max;j++)
          {
               //If a grey code pair is found, replace the differing bits with don't cares.
               if(isGreyCode(minterms[i],minterms[j]))
               {
                  checked[i]=1;
                  checked[j]=1;
                  if(!in_vector(newminterms,replace_complements(minterms[i],minterms[j])))
                     newminterms.push_back(replace_complements(minterms[i],minterms[j]));
               }
          }
      }

      //appending all reduced terms to a new vector
      for(int i=0;i<max;i++)
      {
          //cout<<checked[i]<<endl;
          if(checked[i]!=1 && ! in_vector(newminterms,minterms[i]))
           newminterms.push_back(minterms[i]);
      }

       delete[] checked;
   
       return newminterms;
}

struct mintermspair{
    string minterms;
    int in_token;
};

