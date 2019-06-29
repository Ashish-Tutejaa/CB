//NOT SO EASY MATH
#include<iostream>
#include<vector>
using namespace std;
int main()
{
int arr[]={2,3,5};
int num;cin>>num;
int size = sizeof(arr)/sizeof(int);
int summer=0;
int intersectSum=0;
vector<int> vase;
int n = (1<<size);
for(int k=0;k<n;k++)
    {
    for(int l=0;l<n;l++)
        {
        if((k&(1<<l))!=0)
            {
            vase.push_back(arr[l]);
            }
        }


    for(int i=0;i<vase.size();i++)
        cout<<vase[i]<<" ";
        cout<<endl;

    if(vase.size()!=0)
    {
        if(((vase.size())&1)==0)
            {
            int dummy=1;
            for(int h =0 ;h<vase.size();h++)
                {
                dummy*=vase[h];
                }
            summer-=num/dummy;
            cout<<"subbing"<<endl;
            }
        else
            {
            int dummy=1;
            for(int h =0 ;h<vase.size();h++)
                {
                dummy*=vase[h];
                }
            summer+=num/dummy;
            cout<<"adding"<<endl;
            }
    }
    vase.clear();
    }
cout<<summer<<endl;
}