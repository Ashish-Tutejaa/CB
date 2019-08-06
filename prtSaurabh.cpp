#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        unordered_set<ll > s;
        queue<ll > q;
        s.clear();
        ll Q;
        cin>>Q;
        ll o=0;ll e=0;
        ll turn=0;
        while(Q--)
        {
            ll x;
            cin>>x;
            if(s.count(x)!=0)
            {
                cout<<e<<" "<<o<<endl;
                continue;
            }
            if(turn==0)
            {
                turn++;
                s.insert(x);
                if(__builtin_popcount(x)%2==0)
                {
                    e=1;
                }
                else
                {
                    o=1;
                }
            }
            else
            {
                for(auto itr=s.begin();itr!=s.end();itr++)
                {
                    if(s.count((*itr)^x)==0 and *itr != x)
                    {
                        q.push((*itr)^x);
                    }
                }
                if(s.count(x)==0)
                {
                    q.push(x);
    
                }
                while(!q.empty())
                {
                    if((__builtin_popcount((q.front()))%2)==0)
                    {
                        
                        e++;
                    }
                    else if((__builtin_popcount((q.front()))%2)!=0)
                    {
                     
                        o++;
                    }
                    s.insert(q.front());
                    q.pop();
                }

            }
            cout<<e<<" "<<o<<endl;
        }
    }
}