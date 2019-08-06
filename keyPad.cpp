#include<iostream>
#include<unordered_map>
using namespace std;
void keyPad(char * inp,char * op,int i,int j,unordered_map<char,string> mappy)
    {
    // cout<<"ANS: "<<op<<endl;
    // cout<<"HAAAAN"<<endl;
    //base case
    if(inp[i]=='\0')
        {
        int temp =0;
        while(op[temp]!='\0')
            cout<<op[temp++];cout<<" ,";
        return;
        }
    //rec case
    string temp = mappy[inp[i]];
    // cout<<"STRING: "<<temp<<" J: "<<j<<endl;
    for(int k=0;k<temp.size();k++)
        {
        op[j] = temp[k];
        keyPad(inp,op,i+1,j+1,mappy);
        }
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    unordered_map<char,string> mappy;
    mappy['2']="ABC";
    mappy['3']="DEF";
    mappy['4']="GHI";
    mappy['5']="JKL";
    mappy['6']="MNO";
    mappy['7']="PQRS";
    mappy['8']="TUV";
    mappy['9']="WXYZ";
    char inp[100];
    cin>>inp;
    int i=0;
    while(inp[i]!='\0')
        cout<<inp[i++];cout<<endl;
    char op[100]={""};
    keyPad(inp,op,0,0,mappy);
    }
}