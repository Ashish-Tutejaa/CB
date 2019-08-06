#include<iostream>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std; 
int main()
{
long long int testCases;
cin>>testCases;
while(testCases--)
    {
    long long int n;
    cin>>n;
    set<long long int> s;
    s.clear(); 
    long long int odds=0,evens=0;
    while(n--)
        {
        long long int temp;
        cin>>temp;
        if(s.find(temp)!=s.end())
            {
            cout<<evens<<" "<<odds<<endl;
            continue;
            }
        if(s.empty())
            {
            s.insert(temp);
            long long int dummy0 = __builtin_popcount(temp);
            if(dummy0&1)odds++;
            else evens++;
            }
        else
            {
            queue<long long int> q;
            for(auto itr = s.begin();itr!=s.end();itr++)
                {
                if(*itr!=temp)
                    {
                    long long int xr = temp^(*itr);
                    q.push(xr);
                    long long int dummy1 = __builtin_popcount(xr);
                    if(dummy1&1)odds++;
                    else evens++;
                    }
                }
            while(!q.empty())
                {
                s.insert(q.front());
                q.pop();
                }
            s.insert(temp);
            long long int dummy2 = __builtin_popcount(temp);
            if(dummy2&1)odds++;
            else evens++;
            }
        cout<<evens<<" "<<odds<<endl;
        //end of while
        }
    }
}
