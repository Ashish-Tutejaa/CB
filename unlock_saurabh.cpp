#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool sortbysec(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.second<b.second;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    ll n1 =n;
    unordered_map<ll,ll> m;
    ll i=0;
    while(n1--)
    {
        ll d;
        cin>>d;
        m.insert(make_pair(d,i));
    }
    auto itr = m.begin();
    i =0;
    while(itr!=m.end() and k>0)
    {
        if(itr->second!=n-itr->first)
        {
            itr->second = n-(itr->first);
            m[n-i]= i;
            k--;
        }
        itr++;
        i++;
    }
    vector<pair<ll,ll> > v;
    itr=m.begin();
    i=0;
    while(itr!=m.end())
    {
        ll a=itr->second;
        ll b=itr->first;
        v.push_back(make_pair(a,b));
        itr++;i++;
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        cout<<v[i].second<<" ";
    }
}