#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b)
    {
    if(a.length()!=b.length())
    return a.length()<b.length();
    else
    {
    return a<b;
    }
    
    }
//use set in any questions with perm.
int main()
{
vector<string> v1;
int n;cin>>n;
for(int i=0;i<n;i++)
    {
    string str;cin>>str;
    v1.push_back(str);
    }
sort(v1.begin(),v1.end(),compare);
for(int i=0;i<n;i++)
    cout<<v1[i]<<" ";cout<<endl;
}