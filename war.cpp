#include<iostream>
#include<vector>
#include<climits>
#include<stdlib.h>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    vector<int> v;
    v.clear();
    for(int i=0;i<(n-1);i++)
        {
        int temp;
        cin>>temp;
        v.push_back(temp);
        }
    int f;cin>>f;
    bool flag=0;
    for(int i=0;i<(n-1);i++)
        {
        if(v[i]<=f)
            flag=1;
        }
    if(!flag)
        {
        cout<<"impossible"<<endl;
        continue;
        }
    cout<<"possible"<<endl;
 
    //finding values for p and d;
    int d = INT_MAX;
    int pos=INT_MAX;
    for(int i=0;i<n;i++)
        {
        if(v[i]>f)
            continue;
        v.insert(v.begin()+i,0);
        // for(auto x:v)
        //     cout<<x<<" ";cout<<endl;
        vector<int> temp;
        for(auto x:v)
            temp.push_back(x);
        int j=0;
        int destroy=0;
  
        while(1)
            {
            if(temp.size()<=2)
                break;
            if(j>=temp.size())
                j=0;
            // cout<<"CURRENT: "<<temp[j]<<endl;
            // for(auto x:temp)
            //     cout<<x<<" ";cout<<endl;
            if(temp[j]==-1)
                {
                if((j+1)==temp.size())
                    j=0;
                else j++;
                }
            if(temp[j]==0)
                {
                if((j+1)==temp.size())
                    j=0;
                else j++;
                //continue;
                }
            
            if(temp[j]!=0)
                {
                int dummy=1+j;
                if(j==(temp.size()-1))
                 dummy=0;
                if(temp[dummy]==0)
                    {
                    destroy+=temp[j];
                    if((j+2)==temp.size())
                        j=0;
                    if((j+2)>temp.size())
                        j=1;
                    else j+=2;
                    // continue;
                    }
                if(temp[dummy]==-1)
                    {
                    while(temp[dummy]==-1)
                        {
                        if((dummy+1)==temp.size())
                            dummy=0;
                        else dummy++;
                        }
                    }
                j = dummy;
                    temp[j]=-1;
                   if((j+1)==temp.size())
                    j=0;
                else j++;
                    // continue;
                }
            }
        int last;
        for(auto x:temp)
            {
            if(x!=0)
                last = x;
            }
        if(destroy==d and last<=f)
            {
            pos = min(pos,i+1);
            }
        if(destroy<d and last<=f)
            {
            pos =i+1;
            d = destroy;
            // cout<<"D IS: "<<d<<" POS IS: "<<pos<<endl;
            }
        temp.clear();
        //eos
        v.erase(v.begin()+i);
        }
    d+=f;
    cout<<pos<<" "<<d<<endl;
    }
}