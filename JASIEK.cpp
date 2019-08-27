#include<bits/stdc++.h>
#define SZ 40010
#define MD 20005
using namespace std;
int main()
{
int rowsDone[SZ] = {0};
int colsDone[SZ] = {0};
int board[SZ][SZ] = {0};
for(int i =0;i<SZ;i++)
    {
    for(int j = 0;j<SZ;j++)
        {
        board[i][j] = i;
        }
    }
board[MD][MD] = 1;
rowsDone[MD] = 1;
colsDone[MD] = 1;
char temp;
cin>>temp;
int rows,cols;
rows = cols = MD;
int counter =0;
if(temp == 'P')
while(1)
    {
    cin>>temp;
    switch (temp)
        {
        case 'K':
            break;
        case 'N':
            rows--;  
            board[rows][cols]++;
            continue;
        case 'W':
            cols--;
            board[rows][cols]++;
            continue;
        case 'E':
            cols++;
            board[rows][cols]++;
            continue;
        case 'S':
            rows++;
            board[rows][cols]++;
            continue;
        }
        counter++;
    }
for(int i =0;i<SZ;i++)
    {
    for(int j = 0;j<SZ;j++)
        {
        if(board[i][j]==0)
            {
            if(board[i-1][j]==1 and board[i+1][j]==1 and board[i][j-1]==1 and board[i][j+1]==1)
                {
                counter++;
                board[i][j]++;
                }memset(board,0,sizeof(int)*SZ*SZ);
            }
        }
    }
cout<<counter<<endl;
}