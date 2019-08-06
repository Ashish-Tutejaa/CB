#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;cin>>n;
int arr[n];
for(int i =0;i<n;i++)
    cin>>arr[i];
int targ;cin>>targ;
unordered_map<int,int> m;
for(int i =0;i<n;i++)
    m[arr[i]]++;
for(int i = 0 ;i<n;i++)
    {
    for(int j =i+1;j<n;j++)
        {
        int first = arr[i];
        int second = arr[j];
        int temp = first + second;
            if(m.find(targ-temp)!=m.end() and m[targ-temp]>0)
                {
                m[abs(targ-temp)]--;
                m[first]--;
                m[second]--;
                int * op = new int[3];
                op[0] = first;
                op[1] = second;
                op[3] = (targ-temp);
                sort(op,op+3);
                cout<<op[0]<<", "<<op[1]<<" and "<<op[3]<<endl;
                }
        }
    }
}