#include<iostream>
#include<vector>
#define prime 2
using namespace std;
typedef long long int ll;
ll power(int a,int b)
    {
    int ans = 1;
    while(b--)
        ans*=a;
    return ans;
    }
ll preHash(string s1)
    {
    ll ans;
    for(int i = 0;i<s1.length();i++)
        {
        int dummy = (ll)(s1[i])* (ll)power(prime,i);
        ans+=dummy;
        }
    return ans;
    }
ll findHash(string s2,ll prevHash,int i,string pat)
    {
    ll newHash = prevHash;
    newHash -= s2[i-1];
    newHash/=prime;
    newHash+=((ll)s2[i+pat.length()-1])*(ll)power(prime,pat.length()-1);
    return newHash;
    }
bool checker(string str,int start,int end,string pat)
    {
         for(int i = start;i<end;i++)
        {
        cout<<str[i]<<" ";
        }cout<<endl;
         for(int i = start;i<end;i++)
        {
        cout<<pat[i]<<" ";
        }cout<<endl;
    bool checker = true;
    for(int i = start;i<end;i++)
        {
        if(str[i]!=pat[i])
            checker = false;
        }
    return checker;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    vector<int> v;
    string s1,s2;
    cin>>s1>>s2;
    ll hash1 = preHash(s1);
    string temp;
    for(int i = 0;i<s1.length();i++)
        temp+=s2[i];
    // cout<<"TEMP: "<<temp<<endl;
    ll firstHash = preHash(temp);
    if(firstHash==hash1)
        {
                    // cout<<"HMM"<<firstHash<<" "<<hash1<<endl;

        bool flag = checker(s2,0,s1.length(),s1);
        if(flag)
            v.push_back(0);
        }
    ll tempHash = firstHash;
    cout<<"hash1: "<<hash1<<endl;
    cout<<"firstHash: "<<firstHash<<endl;
    for(int i = 1;i<=s2.length()-s1.length();i++)
        {
        cout<<"TEMPHASH:"<<tempHash<<endl;
        tempHash = findHash(s2,tempHash,i,s1);
        if(tempHash==hash1)
            {
            cout<<tempHash<<" "<<hash1<<endl;
            bool flag = checker(s2,i,i+s1.length(),s1);
            if(flag)
                v.push_back(i);
            }
        }
    // cout<<hash1<<" "<<firstHash<<endl;
    // cout<<"HERE"<<s1<<" "<<temp<<endl;
    for(auto x:v)
        cout<<x<<" ";cout<<endl;
    }
}