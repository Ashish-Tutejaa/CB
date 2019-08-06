#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
unordered_map<int,int> mappy;
int ans[n];
for(int i=0;i<n;i++)
    ans[i]=arr[i];
sort(arr,arr+n);
for(int i=0;i<n;i++)
    {
    mappy[arr[i]] = n-i-1;
    }
// for(auto x:mappy)
//     cout<<x.first<<","<<x.second<<" ";cout<<endl;
bool flag = 0;
    // for(int i=0;i<n;i++)
    //     cout<<ans[i]<<" ";cout<<endl;
    for(int y=0;y<n;y++)
        {
                    flag =false;
                int select;
                for(int i=y+1;i<n;i++)
                    {
                    // cout<<"  L:"<<ans[i]<<" "; 
                    if(mappy[ans[y]]>mappy[ans[i]])
                        {
                        flag = true;
                        break;
                        }
                    }
                if(!flag)
                    continue;
                int current = ans[y];
                int choosen = mappy[current];
                int index = INT_MAX;
                for(int i=y+1;i<n;i++)
                    {
                    int temp = mappy[ans[i]];
                    if(choosen>temp)
                        {
                        choosen = min(choosen,temp);
                        index = i;
                        }
                    }
                swap(ans[y],ans[index]);
                k=k-1;
                if(k==0)
                    break;
                //check if the array is sorted.  If it is just break;
                // bool checker = true;
                // for(int i=1;i<n;i++)
                //     {
                //     if(mappy[ans[i]]<mappy[ans[i-1]])
                //         checker = false;
                //     }
                // if(checker)
                //     break;
                }
for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";cout<<endl;
}