#include<iostream>
#include<queue>
using namespace std;
int main()
{
long long int n,m,k;
cin>>n>>m>>k;
string str;
for(long long int i=1;i<=n;i++)
    str+='a';
// cout<<str<<endl;
for(long long int i=0;i<m;i++)
    {
    long long int temp;
    cin>>temp;
    str[temp-1]=-1+'0';
    }
cout<<str<<endl;
// for(auto x:v)
//     cout<<x<<" ";cout<<endl;
long long int i = 0;
long long int j = k;
bool flag=0;
int moves =0;
while(1)
    {
queue<long long int> q;
    // cout<<"I: "<<i<<" J: "<<j<<endl;
    // for(auto x:v)
    // cout<<x<<" ";cout<<endl;
    flag=0;
    for(long long int x = i;x<j;x++)
        {
        if(x>=str.size())
            break;
        if(str[x]=='/')
            {
            // cout<<"FOUND AT: "<<x<<endl;
            q.push(x);
            flag=1;
            }
        }
    if(flag)
        {
        // cout<<"KILL"<<endl;
        long long int count=0;
        while(!q.empty())
            {
            long long int dummy = q.front()-count;
            str.erase(str.begin()+dummy);
            q.pop();
            count++;
            }
        moves++;
        }
    if(!flag)
        {
        // cout<<"NO KILL"<<endl;
        if((j+k)>=str.size())
            {
            i+=str.size()-j;
            j = str.size();
            }
        else
            {
            i+=k;
            j+=k;
            }
        }
    if(str.size()==(n-m))
        break;
    }
cout<<moves<<endl;
}