#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    int i;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
        {
        pq.push(arr[i]);
        }
    int totSum=0;
    while(pq.size()>1)
        {
     
             int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        totSum += one +two;
        // cout<<"ONE: "<<one<<" TWO: "<<two<<" SUM: "<<totSum<<endl;
        pq.push(one + two);
   
        }
    cout<<totSum<<endl;
    }
}