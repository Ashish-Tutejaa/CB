#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class important
    {
    public:
    int x;
    int y;
    important(){}
    important(int a,int b):x(a),y(b){}
    };
bool myComp(const important a,const important b)
    {
    cout<<"A: "<<a.x<<","<<a.y<<" b "<<b.x<<","<<b.y<<endl;
    return a.y < b.y;
    }
int main()
{
int n;
cin>>n;
int x[n];int y[n];
for(int i =0;i<n;i++)
    {
    cin>>x[i];
    }
for(int i =0;i<n;i++)
    {
    cin>>y[i];
    }
vector<important> vecty;
for(int i =0;i<n;i++)
    {
    important temp;
    temp.x = x[i];
    temp.y = y[i];
    vecty.push_back(temp);
    }
sort(vecty.begin(),vecty.end(),myComp);cout<<endl;
for(auto x:vecty)
    {
    cout<<x.x<<" "<<x.y<<endl;
    }
}