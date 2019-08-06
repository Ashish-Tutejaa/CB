#include<iostream>
using namespace std;
int bsearch(int preComp[],int key,int start,int end)
    {
    //doing it iteratively.
    int ans = -1;
    while(start<=end)
        {
        int mid = start + (end-start)/2;
        if(preComp[mid]>key)
            {
            end = mid-1;
            continue;
            }
        if(preComp[mid]<key)
            {
            ans =preComp[mid];
            start = mid+1;
            }
        if(preComp[mid]==key)
            {
            end = mid-1;
            }
        }
    return ans;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int dividend,divisor;
    cin>>dividend>>divisor;
    int preComp[dividend] = {0};
    int count = divisor;
    for(int i = 0;i<dividend;i++)
        {
        preComp[i] = count;
        count+=divisor;
        }
    cout<<bsearch(preComp,dividend,0,dividend-1)<<endl;
    }
}