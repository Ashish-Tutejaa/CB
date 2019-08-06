#include<iostream>
#include<vector>
using namespace std;
void subSetSum(vector<int> v,int low,int high)
    {
    int sum;
    //base case
    if(low>high)
        return;
    for(int i=low;i<=high;i++)
        sum+=v[i];
    if(!sum)
        {
        for(int i=low;i<=high;i++)
            cout<<v[i]<<" ";cout<<endl;
        return;
        }
    //rec case
    for(int i=low;i<high;i++)
        {
        subSetSum(v,i,high);
        }
    for(int i=high;i>=low;i--)
        {
        subSetSum(v,i,high);
        }
    return;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
        {
        int temp;cin>>temp;
        v.push_back(temp);
        }
    subSetSum(v,0,v.size()-1);
    }
}