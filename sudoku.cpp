//sudko solver
#include<iostream>
using namespace std;
bool canPlace(int a[][9],int i,int j,int no,int n)
bool solveSudoku(int a[][9],int i,int j,int n)
    {
    //base case
    if(i==n)
        {
        //print the matrix 
        return true;
        }
    //corner cases
    if(j==n) return solveSudoku(a,i+1,0,n);
    if(a[i][j]!=0){
        return solveSudoku(a,i,j+1,n);
    }
    //rec case
    for(int k=1;k<=n;k++)
        {
        if(canPlace(a,i,j,k)){
            a[i][j]=k;
            bool aageKaSolveHua = solveSudoku(a,i,j+1,n);
            if(aageKaSolveHua){
                return true;
            }
        a[i][j]=0;//this is backtracking.  
            }
        }
    }
int main()
{
int n = 9;
int a[9][9];
for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        {
        cin>>a[i][j];
        }
    }
solveSudoku(a,0,0,n);
}