#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
    {
    //base case
    if(n==0)
        return 1;
    //rec case
    return n*factorial(n-1);
    }
vector<string> vecty;
void permed(string main,int left,int right)
    {
    if(left==right)
        {
        vecty.push_back(main);
        }
    else
        {
        for(int i=left;i<=right;i++)
            {
            swap(main[left],main[i]);
            permed(main,left+1,right);
            swap(main[left],main[i]);
            }
        }
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int boys[n],girls[n];
    for(int i=0;i<n;i++)
        cin>>boys[i];
    for(int i=0;i<n;i++)
        cin>>girls[i];
    string indexes;
    for(int i=0;i<n;i++)
        {
        char temp = '0'+i;
        indexes+=temp;
        }
    permed(indexes,0,indexes.size()-1);
    // for(auto v = vecty.begin();v!=vecty.end();v++)
    //     {
    //     cout<<*v<<endl;
    //     }
    int maximum=INT16_MIN;
    for(int j=0;j<factorial(n);j++)
        {
        string use = vecty[j];
        int temp =0;
        for(int i=0;i<n;i++)
            {
            // cout<<"to calc temp: "<<boys[i]<<" "<<(girls[use[i]-'0'])<<endl;
            temp+=(boys[i]+(girls[use[i]-'0']))/2;
            }
        if(temp>maximum)maximum = temp;

        // cout<<"Answers: "<<temp<<endl;
        }
    cout<<maximum<<endl;
    }
}