#include<iostream>
#include<climits>
using namespace std;
int summer(int * arr,int low, int high)
    {
    int sum =0;
    for(int h = low;h<=high;h++)
        {
        // cout<<arr[h]<<" ";
        sum+=arr[h];
        }
        // cout<<endl;
    // cout<<"SUMMER: "<<sum<<endl;
    return sum;
    }
int minimize(int * arr,int low,int high)
    {
    // for(int i=low;i<=high;i++)
    //     cout<<arr[i]<<" ";cout<<endl;
    if(low==high)
        return 0;
    int ans = INT_MAX;
    for(int k = low;k<high;k++)
        {
        int temp = minimize(arr,low,k) + minimize(arr,k+1,high) + summer(arr,low,k)+summer(arr,k+1,high);
        ans = min(ans,temp);
        }
    if((high-low)>=2)
        {
            int highTemp = arr[high];
            for(int i = high-1;i>=low;i--)
                {
                arr[i+1] = arr[i];
                }
            arr[low] = highTemp;
            int tempo = low+1;
            int dummy = minimize(arr,low,tempo)+minimize(arr,tempo+1,high)+summer(arr,low,tempo)+summer(arr,tempo+1,high);
            ans = min(dummy,ans);
            //back tracking array.
            for(int i = low+1;i<=high;i++)
                {
                arr[i-1]=arr[i];
                }
            arr[high] = highTemp;
        }
    // cout<<"ANSWER: "<<ans<<endl;
    return ans;
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
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //we shift the array around n times to minimize final, as well.
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
        {
        int temp = minimize(arr,0,n-1);
        ans = min(ans,temp);
        int highTemp = arr[n-1];
            for(int i = n-2;i>=0;i--)
                {
                arr[i+1] = arr[i];
                }
            arr[0] = highTemp;
        }
    cout<<ans<<endl;
    }
}