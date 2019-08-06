#include<iostream>
#include<unordered_set>
#include<queue>
#include<bits/stdc++.h>
using namespace std; 
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    unordered_set<int> s;
    s.clear();
    int odds=0,evens=0;
    while(n--)
        {
        int temp;
        cin>>temp;
        if(s.empty())
            {
            s.insert(temp);
            int dummy0 = __builtin_popcount(temp);
            if(dummy0&1)odds++;
            else evens++;
            }
        else
            {
            queue<int> q;
            for(auto itr = s.begin();itr!=s.end();itr++)
                {
                if(*itr!=temp)
                    {
                    int xr = temp^(*itr);
                    q.push(xr);
                    int dummy1 = __builtin_popcount(xr);
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
            int dummy2 = __builtin_popcount(temp);
            if(dummy2&1)odds++;
            else evens++;
            }
        cout<<evens<<" "<<odds<<endl;
        //end of while
        }
    }
}
