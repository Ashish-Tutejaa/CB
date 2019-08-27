#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int main()
{
int rows,cols;
cin>>rows>>cols;
int ans[rows][cols];
int checker[rows] = {0};
memset(ans,0,sizeof(int) * rows * cols);
for(int i =0;i<rows;i++)
    {
    for(int j =0;j<cols;j++)
        {
        cin>>ans[i][j];
        }
    }
for(int i =0;i<rows;i++)
    {
    int counter =0;
    for(int j =0;j<cols;j++)
        {
        if(ans[i][j]==0)
            counter++;
        }
    checker[i] = counter;
    }
int answer = INT_MIN;
for(int i =0;i<rows;i++)
    { int ways =0;
    for(int j = 0;j<rows;j++)
        {
            if(checker[i]==checker[j])
                {
                bool flag = true;
                for(int k =0;k<cols;k++)
                    {
                    if(ans[i][k]!=ans[j][k])
                        flag = false;
                    }
                if(flag)
                    ways++;
                }
        }
        answer = max(answer,ways);
    }
cout<<answer<<endl;
}