#include<iostream>
using namespace std;
int main()
{

int points;
cin>>points;
int x[points]={0};
int y[points]={0};
int maximum = 0;
for(int i=0;i<points;i++)
    {
    cin>>x[i]>>y[i];
    int temp = maximum;
    maximum = max(x[i],y[i]);
    if(temp>maximum)maximum = temp;
    }

int arr[maximum][maximum]={0};

for(int i=0;i<points;i++)
    {
    int first = x[i];
    int second = y[i];
    for(int j=0;j<maximum;j++)
        {
        arr[j][second]=1;
        }
    for(int j=0;j<maximum;j++)
        {
        arr[first][j]=1;
        }
    }

int temper=0;
int answer = 0;

for(int i=0;i<maximum;i++)
    {
    for(int j=0;j<maximum;j++)
        {
                        temper =0;
                    if(arr[i][j]==0)
                        {
                        temper =1;
                        for(int k=j+1;k<maximum;k++)
                            {
                            if(arr[i][k]==1)
                            break;

                            else
                                temper++;
                            }
                        for(int k=i+1;k<maximum;k++)
                            {
                        
                                if(arr[k][j]==1)
                                break;
                            
                            else
                                
                                temper++;
                        
                            }
                        for(int k=j-1;k>0;k--)
                            {
                                if(arr[i][k]==1)
                            
                                break;
                                
                            else
                                temper++;
                            }
                        for(int k=i-1;k>0;k--)
                            {
                            
                                if(arr[k][j]==1)
                                
                                break;
                        else
                                temper++;
                            }
                        }
        if(answer<temper)answer = temper;
        }
    
    }
cout<<answer<<endl;
}