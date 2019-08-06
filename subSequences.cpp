#include<iostream>
using namespace std;
void subseq(string str,int cur,int size,string final = "")
    {
    //base case
    if(cur == size)
        {
        cout<<final<<endl;
        return;
        }
    //rec case
    subseq(str,cur+1,size,final);
    subseq(str,cur+1,size,final+str[cur]);
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string str;
    cin>>str;
    subseq(str,0,str.size());
    }
}