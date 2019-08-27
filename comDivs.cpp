#include<iostream>
#include<algorithm>
#include<math.h>
#include<unordered_map>
typedef long long int ll;
using namespace std;
int main()
{
ll n;cin>>n;
ll arr[n];
for(ll i =0;i<n;i++)
    cin>>arr[i];
unordered_map<ll,ll> maps;
for(ll i=0;i<n;i++)
    {
    maps[arr[i]]++;
    }
unordered_map<ll,ll> mappy;
for(ll i = sqrt(arr[n-1]);i>0;i--)
    {
    for(ll j =(n-1);j>-1;j--)
        {
        if(i>sqrt(arr[j]))
            break;
        if(arr[j]%i==0)
            {
            if(arr[j]/i == i)
                mappy[i]++;
            else
                {
                    mappy[i]++;
                    mappy[arr[j]/i]++;
                }
                
            }
        }
    }
int counter =0;
for(auto x:mappy)
    {
    if(x.second == n)
        counter++;
    }
cout<<counter<<endl;
}