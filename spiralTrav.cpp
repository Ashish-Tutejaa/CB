#include<iostream>
using namespace std;
void recurSive(int ** arr,int rowSize,int colSize,int currRow,int currCol,int origRow,int origCol)
    {
    //base case
    if(currCol>(origCol/2) or currRow>(origRow/2))
        return;
    //rec case
    for(int i =currRow;i<rowSize;i++)
        {
        cout<<arr[i][currCol]<<", ";
        }
    for(int i =currCol+1;i<colSize;i++)
        {
        cout<<arr[rowSize-1][i]<<", ";
        }
    for(int j =rowSize-2;j>=currRow;j--)
        {
        cout<<arr[j][colSize-1]<<", ";
        }
    for(int j =colSize-2;j>currCol;j--)
        {
        cout<<arr[currRow][j]<<", ";
        }
    recurSive(arr,rowSize-1,colSize-1,currRow+1,currCol+1,origRow,origCol);
    }
int main()
{
int m,n;
cin>>m>>n;
int ** arr = new int* [m];
for(int i =0;i<m;i++)
    {
    arr[i] = new int[n];
    }
for(int i =0;i<m;i++)
    {
    for(int j = 0;j<n;j++)
        {
        cin>>arr[i][j];
        }
    }
recurSive(arr,m,n,0,0,m-1,n-1);
}