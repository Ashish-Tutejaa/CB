#include<iostream>
#include<unordered_map>
using namespace std;
void keyPad(string inp,char * op,int i,int j,unordered_map<char,string> mappy,int size)
    {
    // cout<<"RAN"<<endl;
    //base case
    if(i==(size))
        {
        op[j] = '\0';
        cout<<op<<endl;
        return;
        }
    //rec case
    string temp;
    temp = mappy[inp[i]];
    for(int k=0;k<temp.size();k++)
        {
        op[j] = temp[k];
        keyPad(inp,op,i+1,j+1,mappy,size);
        }
    }
int main()
{
    unordered_map<char,string> mappy;
    mappy['1']=" ";
    mappy['2']="ABC";
    mappy['3']="DEF";
    mappy['4']="GHI";
    mappy['5']="JKL";
    mappy['6']="MNO";
    mappy['7']="PQRS";
    mappy['8']="TUV";
    // mappy['9']="WXYZ";
    string inp;
    getline(cin,inp);
    char op[100];
    keyPad(inp,op,0,0,mappy,inp.size());
    
}