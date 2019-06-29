#include<iostream>
using namespace std;
bool maze(int arr[][5],int m,int n,int i,int j)
    {
    
    if(i==(m-1) and j==(n-1))
        {cout<<"done"<<endl;return true;
        arr[i][j]=4;
        }
        
    if(i>(m-1) or j>(n-1))
    { cout<<"two"<<endl;return false;
   
    }
     if(arr[i][j]==4)
        {cout<<"four"<<endl;
        return false;
        }   
    if(arr[i][j]==1)
        {cout<<"three"<<endl;
        return false;
        }
    for(int k=0;k<m;k++)
        {
        for(int l=0;l<n;l++)
            {
            if(k==i&&l==j)
                cout<<3<<" ";
            else
            cout<<arr[k][l]<<" ";
            }cout<<endl;
        }cout<<endl<<endl;
    bool right = maze(arr,m,n,i,++j);
    if(right)
        {
        arr[i][j]=4;
        cout<<"right"<<endl;return true;
        }
    bool down = maze(arr,m,n,++i,j);
    if(down)
        {
        arr[i][j]=4;
        cout<<"down"<<endl;return true;
        }
    if(!(right and down))
        {
        return false;
        }
    //code for all possible paths is on github.  
    }
int main()
{
int arr[5][5]={
   {0,0,0,0,0},
    {0,0,1,0,1},
    {0,0,0,1,1},
    {1,1,0,0,0},
    {1,1,0,1,0,},
};
maze(arr,5,5,0,0);
}