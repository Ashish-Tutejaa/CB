#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void checker(string digits,int i, int size,vector<string> &v,char arr[],unordered_map<int,string>mappy)
    {
//   cout<<arr<<endl;
    //base case
    if(i>=size)
        {
        string temp;
        for(int l = 0;l<i;l++)
            temp+=arr[l];
        v.push_back(temp);
        return;
        }
    //rec case
    int len;
    // cout<<digits[i]-'0'<<endl;

        for(int l = 0;l<mappy[digits[i]-'0'].length();l++)
            {
            arr[i] = mappy[digits[i]-'0'][l];
            checker(digits,i+1,size,v,arr,mappy);
            }
    }
vector<string> letterCombinations(string digits) 
    {
    int size = digits.length();
    unordered_map<int,string> mappy;
    mappy[2] = "abc"; 
    mappy[3] = "def";
    mappy[4] = "ghi";
    mappy[5] = "jkl";
    mappy[6] = "mno";
    mappy[7] = "pqrs";
    mappy[8] = "tuv";
    mappy[9] = "wxyz";
    vector<string> v;
    char pass[size];
    checker(digits,0,size,v,pass,mappy);
    return v;
    }
int main()
{
string str;
cin>>str;
vector<string> v;
v = letterCombinations(str);
for(auto x:v)
    cout<<x<<endl;
}