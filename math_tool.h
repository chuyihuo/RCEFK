#include<iostream>
#include<string>
#include <vector>
#include<cmath>
#include<time.h>
#include<math.h>
#include<cstring>
#include<random>

using namespace std;

vector<int> Transform(int n,int nb)
{
    vector<int>m;
    for(int i =nb-1; i>=0; i--)
    {
        m.push_back( ( (n>>i) & 1) );//与1做位操作，前面位数均为0
    }
    return m;
}

int ran_arr(int a[], int n) //随机排列一个数组
{ int index, tmp, i; 

   for (i = 0; i <n; i++) 
    { 
       index = rand() % (n - i) + i; 
       if (index != i) 
         { 
            tmp = a[i]; 
            a[i] = a[index]; 
            a[index] = tmp; 
         } 
    } 
    return 0;}

int ran_arr(string a[], int n) //随机排列一个字符串数组
{int index,  i;
   string tmp; 

   for (i = 0; i <n; i++) 
    { 
       index = rand() % (n - i) + i; 
       if (index != i) 
         { 
            tmp = a[i]; 
            a[i] = a[index]; 
            a[index] = tmp; 
         } 
    } 
    return 0;}

int* gen_incremental_arr( int ni){//生成顺序数列数组
    int* arr = new int[ni];
    for(int i = 0 ;i < ni ;i++)
    {
        arr[i]=i;
    }
    return arr;
}

int strcmp(string a,string b){//比较字符串是否相等
    int n,m,i = 1;
    if(sizeof(a)!=sizeof(b)){i = 0;}
        for(int j = 0 ;(a[j] != NULL) || (b[j] != NULL);j++)
        {if(a[j]!=b[j])
        {i = 0;}}
   return i ;
}

int strcmp(char a, char b){//比较字符是否相等
    int i = 0;
    if(a == b){i = 1;};
    return i;
}

bool check_dont_care( char b){
    int a = 0;
    if (b == '-'){a = 1;}
    return a;
}

string* find_it_inarr(int size_arr,int number_element,string*a )//找出队列中的状态
{
    string *b = new string[number_element];
    b[0]=a[0];
    for(int i =0, j = 1; i<size_arr&&j<number_element;i++){ 
       int c =0;
       for(int n = 0 ;n <j;n++)
        { 
          if(strcmp(a[i],b[n]))c++;
        }
        if(c == 0)  {b[j] = a[i];j++; }
    }
    
    return b;
}

int numofchar(char a,string b){
    int ll = 0;
    for(int i =0; b[i]!=NULL; i++){
        if(b[i] == a){
            ll++;
        }
    }
    return ll;
}

struct gate
{
   int place;
   int type_output;
   int output;
   int type_gate;
   int gate;
   bool use_it;
};

gate** gate_tree;
gate** ogate_tree;

//生成局部二叉树key值
int* abb(int a,int b){
    int*hhh = new int[a-1];
    int aaa [a-1];
    int bbb [a -1];
    int c =log2(a)+1;
    int n = 0;
    for(int i = 0 ;i<c;i++){
        for(int j =0 ;j<pow(2,i)&&n<a-1;j++){
        aaa[n] =b*pow(2,i);
        bbb[n] = j;
        hhh[n] = aaa[n]+bbb[n];
        n++;
        }
    }
    return hhh;
}