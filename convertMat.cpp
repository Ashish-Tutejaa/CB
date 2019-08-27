#include<bits/stdc++.h>
using namespace std;
int main()
{
int rows,cols;
cin>>rows>>cols;
int arr1[rows][cols];
int arr2[rows][cols];

for(int i =0;i<rows;i++)
    for(int j =0;j<cols;j++)
        cin>>arr1[i][j];

memset(arr2,0,sizeof(int)*rows*cols);
vector<pair<int,int>> pos;
for(int i =0;i<rows-1;i++)
    {
    for(int j = 0;j<cols-1;j++)
        {
        if(arr1[i][j]!=0 and arr1[i+1][j]!=0 and arr1[i][j+1]!=0 and arr1[i+1][j+1]!=0)
            {
            arr2[i][j] = arr2[i+1][j] = arr2[i][j+1] = arr2[i+1][j+1] = 1;
            pos.push_back(pair<int,int> (i,j));
            }
        }
    }
bool same = true;
for(int i =0;i<rows;i++)
    {
    for(int j =0;j<cols;j++)
        {
        if(arr1[i][j]!=arr2[i][j])
            {
            same =false;
            break;
            }
        }
    }
if(!same)
    {
    cout<<-1<<endl;
    }
else
    {
    cout<<pos.size()<<endl;
for(auto x:pos)
    {
    cout<<x.first+1<<" "<<x.second+1<<endl;
    }

    }

}