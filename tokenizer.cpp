#include<iostream>
#include<cstring>
using namespace std;
int power(int a,int b)
    {
    if(b==0)
        return 1;
    if(b&1)
        {
        int temp = power(a,b/2);
        return temp*temp*a;
        }
    else
        {
        int temp = power(a,b/2);
        return temp*temp;
        }
    }
int str2Num(string str,int index,int size)
    {
    //base case
    if(size == 0)
        return str[index]-'0';
    //rec case
    int temp = str[index]-'0';
    temp*=power(10,size);
    temp+=str2Num(str,index+1,size-1);
    return temp;
    }
int main()
{
string testCases;
getline(cin,testCases);
int runner = str2Num(testCases,0,testCases.size()-1);
// int testCases;
// cin>>testCases;
while(runner--)
    {
    char arr[100];
    cin.getline(arr,100);
    char * ptr = NULL;
    ptr = strtok(arr," ");
        cout<<ptr<<endl;
    while(ptr!=NULL)
        {
        ptr = strtok(NULL," ");
        cout<<ptr<<endl;
        }
    }
}