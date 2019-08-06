#include<bits/stdc++.h>
#define O(str) cout<<str<<endl
using namespace std;
int checker(int arr[][1000],int rows,int cols)
    {
    // for(int k = 0;k<rows;k++)
    //     {

    //     for(int h=0;h<cols;h++)
    //         {
    //         cout<<arr[k][h]<<" ";
    //         }cout<<endl;
    //     }cout<<endl<<endl;
    int counter=0;
    bool flag=1;
    for(int k = 0;k<rows;k++)
        {
        for(int h=0;h<cols;h++)
            {
            flag=1;
            if(arr[k][h]!=1)
                {
                //checking if the black can cut the white.
                if((k-2)>=0 and (h+1)<cols)
                    if(arr[k-2][h+1]==1)
                        flag=0;
                if((k-2)>=0 and (h-1)>=0)
                    if(arr[k-2][h-1]==1)
                        flag=0;
                if((k+2)<rows and (h-1)>=0)
                    if(arr[k+2][h-1]==1)
                        flag=0;
                if((k+2)<rows and (h+1)<cols)
                    if(arr[k+2][h+1]==1)
                        flag=0;
                if((k+1)<rows and (h-2)>=0)
                    if(arr[k+1][h-2] ==1)
                        flag=0;
                if((k+1)<rows and (h+2)<cols)
                    if(arr[k+1][h+2]==1)
                        flag=0;
                if((k-1)>=0 and (h+2)<cols)
                    if(arr[k-1][h+2]==1)
                        flag=0;
                if((k-1)>=0 and (h-2)>=0)
                    if(arr[k-1][h-2]==1)
                        flag=0;
                if(flag)    
                    {
                    // O("INCREMENT");
                    counter++;
                    }
                }
            }
        }
    return counter;
    }
int ways(int arr[][1000],int rows,int cols)
    {
    int counter=0;
    for(int i=0;i<rows;i++)
        {
        for(int j=0;j<cols;j++)
            {
            arr[i][j]=1;
        counter+=checker(arr,rows,cols);
            arr[i][j]=-1;
            }
        }
    return counter;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n,m;
    cin>>n>>m;
    int arr[1000][1000];
    // cout<<"LOL"<<endl;
    memset(arr,-1,(1000*1000)*sizeof(int));
    // O("NOPE");
    cout<<ways(arr,n,m)<<endl;
    }
}