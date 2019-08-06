#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
long long int testCases;
cin>>testCases; 
while(testCases--)
    {
    long long int n;cin>>n; 
    vector<long long int> v;
    for(long long int i=0;i<n;i++)
        {
        long long int temp;cin>>temp;
        v.push_back(temp);
        }
    long long int dummy = n-1;
        // cout<<"ERROR1"<<endl;

    long long int penalty =0;
    while(dummy--)
        {
        for(long long int i=0;i<v.size();i++)
            cout<<v[i]<<" ";cout<<endl; 
        long long int lowest_pair;
        long long int maximum = INT_MAX;
        for(long long int i=1;i<v.size();i++)
            {
            long long int temp = v[i-1]+v[i];
            if(temp<maximum)
                {
                maximum = temp;
                lowest_pair = i;
                }
            }
                // cout<<"ERROR2"<<endl;

        long long int anotherOne = v[0]+v[v.size()-1];
        if(anotherOne<maximum)
            {
            maximum = anotherOne;
            lowest_pair = 0;
            }
        // cout<<"ERROR3"<<endl;
        if(lowest_pair)
            {
            // cout<<"ACHA1"<<endl;
            long long int first = v[lowest_pair];
            long long int second = v[lowest_pair -1 ];
            v[lowest_pair-1]=first+second;
            penalty+=first+second;
            v.erase(v.begin()+lowest_pair);
            }
                // cout<<"ERROR4"<<endl;

        if(!lowest_pair)
            {
            // cout<<"ACHA2"<<endl;
            long long int first = v[0];
            long long int second = v[v.size()-1];
            v[0] = first+second;
            penalty+=first+second;
            // cout<<"AFTER THS"<<endl;
            v.erase(v.begin()+(v.size()-1));
            // cout<<"BEFORE THIS"<<endl;
            }
        }
    cout<<penalty<<endl;
    }
}