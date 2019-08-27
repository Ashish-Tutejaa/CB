#include<iostream>
#include<map>
using namespace std;
int main()
{
int n;
cin>>n;
map<int,pair<int,int>> m;
for(int i =1;i<=n;i++)
    {
    pair<int,int> temp;
    cin>>temp.first>>temp.second;
    m[i] = temp;
    }

}