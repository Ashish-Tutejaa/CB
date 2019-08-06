#include<iostream>
#include<vector>
using namespace std;
void permute(string str,vector<string> &v,int k)
    {
    if (k==str.length()-1)
        v.push_back(str);
    for(int i = k ;i<str.length();i++)
        {
        swap(str[i],str[k]);
        permute(str,v,k+1);
        swap(str[i],str[k]);
        }
    }
bool checkerFxn(string s1,string s2)
    {
    if(s2.length()<s1.length())
        return false;
    vector<string> v;
    permute(s1,v,0);
     string focus;
    string check;
    int count = 0;
    int j = 0;
    bool flag = false;
    int i = 0;
    for(int k = 0;k<v.size();k++)
        {
        focus = v[k];
        check = s2;
        count = 0;
        while(count <= check.length()-focus.length())
            {
            if(check[count]==focus[j])
                {
1               ;i = count;
                while(check[i]==focus[j])
                    {
                    i++;
                    j++;
                   
                    if(j==focus.length())
                        {flag = true;}
                    }
                }
            j = 0;
            count++;
            }
        }
    return flag;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    // string str;
    // cin>>str;
    // vector<string> v;
    // permute(str,v,0);
    string s1,s2;
    cin>>s1>>s2;
    bool ans = checkerFxn(s1,s2);
    cout<<ans<<endl;
    }
}