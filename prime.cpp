#include<iostream>
#include<unordered_set>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;
void factor(int num,unordered_set<int> &v)
    {
    int choice =2;
    while(num!=1)
        {
        if(num%choice==0)
            {
            num/=choice;
            v.insert(choice);
            }
        else choice++;
        }
    return;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int m = 10;
    int x =10;
    bool flag=0;
    queue<int> q;
    while(m--)
        {
        cout<<1<<" "<<x<<endl;
        fflush(stdin);
        int ans;
        cin>>ans;
        if(ans==-1)
            {
            exit(1);
            }
        if(ans==0 and flag)
            {
            unordered_set<int> s;
            factor(x,s);
             for(auto i:s)
                // cout<<"Values: "<<i<<" ";cout<<endl;
            if(s.size()==1)
                {
                int val;
                for(auto i:s)val=i;
                cout<<2<<" "<<val<<endl;
                fflush(stdin);
                break;
                }
           
            }
        else if(!flag)
            {   
            int num = 100-ans;
            //prime factoring ans;
            unordered_set<int> v;
            factor(num,v);
            
            for(auto x:v)
                {
                // cout<<"Values: "<<x<<" ";cout<<endl;
                q.push(x);
                }
            flag=1;
            }
        x = q.front();
        q.pop();
        }
    }
}