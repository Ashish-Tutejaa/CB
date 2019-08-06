        #include<iostream>
        #include<climits>
        #include<math.h>
        using namespace std;
        int minimizer(int * arr,int low,int high,int dp[][1000])
            {
            cout<<"LOW: "<<low<<" HIGH: "<<high<<endl;
            for(int o = low;o<=high;o++)
                cout<<arr[o]<<" ";cout<<endl;
            //base case
            if(dp[low][high]!=-1)
                return dp[low][high];
            if(low==high)
                {
                dp[low][high]=0;
                return 0;
                }
            //rec case
            int self=0;
                for(int h=low;h<=high;h++)  
                    self+=arr[h];
            
            int ans = INT_MAX;
            for(int k=low;k<high;k++)
                {
                int temp = minimizer(arr,low,k,dp) + minimizer(arr,k+1,high,dp) + self;
                ans = min(ans,temp);
                }
            if((high-low)>=2)
                {
                    int otans = INT_MAX;
                    int lowTemp = arr[low];
                    int highTemp = arr[high]; 
                    int actHigh = high-1;
                    int actlow = low+1;
                    arr[low]+=arr[high];
                    self=0;
                    for(int h=actlow;h<=high;h++)  
                            self+=arr[h];
                    for(int k=actlow;k<high;k++)
                        {
                        int temp = minimizer(arr,actlow,k,dp) + minimizer(arr,k+1,high,dp) + self;
                        otans = min(otans,temp);
                        }
                    arr[low] = lowTemp;
                    arr[high]=highTemp;
                    arr[high]+=arr[low];
                    self=0;
                    for(int h=low;h<=actHigh;h++)  
                            self+=arr[h];
                    for(int k=low;k<actHigh;k++)
                        {
                        int temp = minimizer(arr,low,k,dp) + minimizer(arr,k+1,actHigh,dp) + self;
                        otans = min(otans,temp);
                        }
                otans+=lowTemp+highTemp;
                ans = min(ans,otans);
                }
            dp[low][high]=ans;
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
            int dp[1000][1000];
            for(int i=0;i<n;i++)    
                {
                for(int j=0;j<n;j++)
                    {
                    dp[i][j]=-1;
                    }
                }
            for(int i=0;i<n;i++)
                cin>>arr[i];
            cout<<minimizer(arr,0,n-1,dp)<<endl;
            }
        }