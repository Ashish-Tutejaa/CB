#include<iostream>
#include<climits>
using namespace std;
int sumOfDigits(int a)
    {
    //base case
    if(a==0)
        return 0;
    //rec casse
    int temp = a%10;
    return temp + sumOfDigits(a/10);
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int arr[n];
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    for(int i = 0;i<n;i++)
        {
        for(int j = i+1;j<n;j++)
            {
            int temp = sumOfDigits(arr[i]*arr[j]);
            maxi = max(temp,maxi);
            }
        }
    cout<<maxi<<endl;
    }
}