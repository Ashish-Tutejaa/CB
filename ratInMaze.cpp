#include<iostream>
using namespace std;
void printer(int arr[][100],int i,int j,int rows,int cols)
    {
    //base case
    if(i==rows-1 and j==cols-1)
    {cout<<endl;
    arr[i][j]=1;
    for(int k=0;k<rows;k++)
        {
        for(int h=0;h<cols;h++)
            {
            cout<<arr[k][h]<<" ";
            }cout<<endl;
        }cout<<endl;
    return;
    }
    if(arr[i][j]!=0)
        return;
 
    if(i>=rows or j>=cols)
        return;
    //rec case
    arr[i][j]=1;
    printer(arr,i+1,j,rows,cols);
    printer(arr,i,j+1,rows,cols);
    arr[i][j]=0;
    return;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int m,n;
    cin>>m>>n;
    int arr[100][100];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    printer(arr,0,0,m,n);
    }
}