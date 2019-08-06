#include<iostream>
#include<utility>
using namespace std;
int main()
{
int n;cin>>n;
int arr[n][n];
for(int i =0 ;i<n;i++)
    {
    for(int j = 0;j<n;j++)
        {
        cin>>arr[i][j];
        }
    }
for(int i =0 ;i<n;i++)
    {
    for(int j = 0;j<n;j++)
        {
        cout<<arr[i][j]<<",";
        }cout<<endl;
    }
pair<int,int> pairs[4];
pair<int,int> temp;
temp.first = temp.second = 0;
pairs[0] = temp;
temp.first = 0;temp.second = n-1;
pairs[1] = temp;
temp.first = n-1;temp.second = 0;
pairs[3] = temp;
temp.first = n-1;temp.second = n-1;
pairs[2] = temp;
int index = 0;
int dummy = 0;
int sub = 0;
while(1)
    {
    if(index==3)
        {
        // if(index==0)
        arr[pairs[index].first][pairs[index].second]  = dummy;
        break;
        // if(sub==(n/2))
        // break;
        // sub++;
        // continue;
        }
    if(index==0)
        {
        dummy = arr[pairs[index].first][pairs[index].second];
        index++;
        continue;
        }
    arr[pairs[index-1].first][pairs[index].second] = arr[pairs[index].first][pairs[index].second];
    index++;
    }
for(int i =0 ;i<n;i++)
    {
    for(int j = 0;j<n;j++)
        {
        cout<<arr[i][j]<<",";
        }cout<<endl;
    }
}