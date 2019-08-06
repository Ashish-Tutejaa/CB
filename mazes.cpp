#include<iostream>
using namespace std;
int counter =0 ;
int finder(int arr[][4],int rowSize,int colSize,int i,int j)
    {
    //base case(s)
    if(arr[i][j]==9)
        return 1;
    if(i<0)
        return 0;
    if(j<0)
        return 0;
    if(i>=rowSize)
        return 0;
    if(j>=colSize)
        return 0;
    if(arr[i][j]==0)
        return 0;
    counter++;
    if(arr[i][j]==1)
        {
        arr[i][j] = 0 ;
        return finder(arr,rowSize,colSize,i+1,j) or finder(arr,rowSize,colSize,i,j+1) or finder(arr,rowSize,colSize,i-1,j) or finder(arr,rowSize,colSize,i,j-1);
        arr[i][j] = 1;
        }
    }

int main()
{
int arr[4][4]= {
{1,0,1,1},
{1,1,1,0},
{1,0,0,9},
{1,1,1,1},
};
cout<<finder(arr,4,4,0,0)<<endl;
cout<<counter<<endl;
}