#include<iostream>
#include<math.h>
using namespace std;
typedef long long int lol;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    lol n;
    cin>>n;
    string k;
    cin>>k;
    lol arr[n]={0};
    lol loop=0;
    lol residue = 0; 
    for (lol j = 0; j < k.length(); j++) 
        {
        residue = (residue*10 + (lol)k[j] - '0') %n;
        }   
    loop = residue; 
       for(lol j = 0;j<loop;j++)
            {
            arr[j]+=1;
            }
  
    for(lol j=0;j<n;j++)
        cout<<arr[j]<<" ";cout<<endl;


    lol ans[n]={0};
    lol count1s=0,count0s=0;
    for(lol jacob = 0;jacob<n;jacob++)
        {
        if(!arr[jacob])count0s++;
        else count1s++;
        }
    if(count1s>count0s)
        {
        for(lol h =0;h<n;h++)
            {
            ans[h]=1;
            }
        lol temporary =1;
        while(count0s!=0)
            {
            ans[temporary]=0;
            temporary+=2;
            count0s--;
            }
        }
    if(count0s>count1s and count1s!=0)
        {
        for(lol h =0;h<n;h++)
            {
            ans[h]=0;
            }
        lol temporary =1;
        while(count1s!=0)
            {
            ans[temporary]=1;
            temporary+=2;
            count1s--;
            }
        }
    else if(count1s==count0s)
        {
        for(lol u = 0;u<n;u++)
            {
            if(u&1)ans[u]=0;
            else ans[u]=1;
            }
        }
    for(lol j=0;j<n;j++)
        cout<<ans[j]<<" ";cout<<endl;

        lol sum=0;
    for(lol j=1;j<n;j++)
        {
        lol temp = abs(ans[j-1]-ans[j]);
        sum+=temp;
        }
    cout<<sum<<endl;
    }
}