//bracket problem
#include<iostream>
using namespace std;
//1 is right, 2 is down
bool brac(int n,int counter,int direc,string str)
    {
    //base case
    if(counter>n)return true;
    if(counter==n)
        return true;
    if(counter==0)
        str = "()";
    if(n == 1)
        {
        cout<<str<<endl;
        return true;
        }
    //rec case 
    if(direc == 1) 
        {
        if(str[0]=='(' and str[1]=='(' and counter==(n-1))
            {
            cout<<"()"+str<<endl;
            }
        str+="()";
        if(counter==(n-1))
        cout<<str<<endl;
        counter++;
        
        brac(n,counter,1,str);
        brac(n,counter,2,str);
        }
    if(direc == 2)
        {
        
        string temp = "(";
        temp += str;
        temp +=")";
        str = temp;
        if(counter==(n-1))cout<<str<<endl;
        counter++;
        brac(n,counter,1,str);
        brac(n,counter,2,str);
        }
    counter++;
    brac(n,counter,1,str);
    brac(n,counter,2,str);
    }
int main()
{
int n;cin>>n;
brac(n,0,0,"");
return 0;
}