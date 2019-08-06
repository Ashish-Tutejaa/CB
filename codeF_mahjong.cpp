#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b)
    {
    return (a[0]-'0')<(b[0]-'0');
    }
int main()
{
string arr[3];
for(int i=0;i<3;i++)
    {
    string temp;
    cin>>temp;
    arr[i]=temp;
    }
int k = 2,s = 2;
string temp = arr[0];
for(int i=1;i<3;i++)
    {
    if(temp==arr[i])
        k--;
    }
//checker for k
//checking for s
bool flagS=1;
for(int i=1;i<3;i++)
    {
    int tempO = arr[i][0]-'0';
    int tempT = arr[i-1][0]-'0';
    if(!((tempO+1)==tempT))
        flagS=0;
    }
vector<string> v;
for(int i=0;i<3;i++)
    {
    v.push_back(arr[i]);
    }
sort(v.begin(),v.end(),compare);
for(auto x:v)
    cout<<x<<" ";cout<<endl;
if(!flagS)
    {
    int ans = INT_MAX;
    for(int i=1;i<3;i++)
        {
        int tempO = v[i][0]-'0';
        int tempT = v[i-1][0]-'0';
        ans = min(ans,(tempO-tempT));
        }
    ans--;
    if(ans==0 or ans==1)
        s=1;
    else 
        s=ans;
    }
if(flagS)   
    s=0;
cout<<"S: "<<s<<" K: "<<k<<endl;
cout<<min(k,s)<<endl;
}