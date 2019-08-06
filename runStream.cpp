//running stream of numbers
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstdio>
using namespace std;
void print(priority_queue<int,vector<int>,greater<int>> a)
    {
    while(!a.empty())
        {
        cout<<a.top()<<" ";
        a.pop();
        }cout<<endl;
    return ;
    }
int main()
{
priority_queue<int,vector<int>,greater<int>> pq;
int n;
while(scanf("%d",&n)!=EOF)
    {
    if(n==-1)
        {
        print(pq);
        cout<<"YEET"<<endl;
        continue;
        }
    if(pq.size()<3)
        {
        cout<<"IN"<<endl;
        pq.push(n);
        }
    else if(n>pq.top())
        {
        cout<<"replace"<<endl;
        pq.pop();
        pq.push(n);
        }
    }
}