#include<iostream>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a,int b)
    {
    return a>b;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> mappy;
    while(n--)
        {
        pair<int,int> temp;
        cin>>temp.first>>temp.second;
        if(!mappy.count(temp.first))
            {
            mappy.insert(pair<int,int>(temp.first,temp.second));
            }
        else
            {
            if(temp.second>mappy[temp.first])
                mappy[temp.first]=temp.second;
            }
        }
    vector<int> answer;
    for(auto itr = mappy.begin();itr!=mappy.end();itr++)
        {
        answer.push_back(itr->second);
        }
    sort(answer.begin(),answer.end(),compare);
    for(auto x:answer)
        cout<<x<<" ";cout<<endl;
    }
}