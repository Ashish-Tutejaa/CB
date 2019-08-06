#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;cin>>n;
    int mapping[100000] = {0};
    int powers[n+1];
    for(int i =1;i<=n;i++)
        {
        cin>>powers[i];
        int lb = i-powers[i];
        int ub = i + powers[i];
        if(lb<1)
            lb = 1;
        if(ub>n)
            ub = n;
        for(int k = lb;k<=ub;k++)
            {
            mapping[k]++;
            }
        }
    int zomb[n+1];
    for(int i =1;i<=n;i++)
        cin>>zomb[i];
 
    int counter = 0;
    for(int i = 1;i<=n;i++)
        {
        if(mapping[zomb[i]]>0)
            {
            mapping[zomb[i]]--;
            counter++;
            }
        }
    if(counter==n)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
    }
}