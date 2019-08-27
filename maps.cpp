#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
int main()
{
string ans;cin>>ans;
unordered_map<char,int> mappy;
for(int i = 0 ; i < ans.size() ; i++)
    {
    mappy[ans[i]] = mappy[ans[i]]+1;
    }
int rev;char num;
rev =  INT_MIN;
// for(auto x: {1,2,3,4,5})
//     {
//     cout<<x<<" ";
//     }cout<<endl;
for(auto x:mappy)
    {
    cout<<x.first<<" "<<x.second<<"->";
    if(x.second > rev)
        {
        rev = x.second;
        num = x.first;
        }
    }cout<<endl;
cout<<num<<" "<<rev<<endl;
}
