#include<iostream>
using namespace std;
int pi[100] = {0};
void piHash(string pat)
    {
    int j = 0;
    int i = 1;
    while(i<pat.length())
        {
        if(pat[i]==pat[j])
            {
            pi[i] = j+1;
            j++;
            i++;
            }
        else 
            {
            if(j!=0)
                {
                j = pi[j-1];
                }
            else
                {
                i++;
                }
            }
        }
    }
void KMP(string txt,string pat)
    {
    int i,j;
    i = j = 0;
    while(i<txt.size())
        {
        if(txt[i]==pat[j])
            {
            i++;
            j++;
            // cout<<i<<" "<<j<<endl;
            }
        if(j==pat.size())
            {
            cout<<"found at: "<<i-j<<endl;
            j= pi[j-1];
            }
        else if (txt[i]!=pat[j])
            {
            if(j>0)
            j = pi[j-1];
            else
                i++;
            // cout<<"RESET: "<<i<<" "<<j<<endl;
            }
        }
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string txt;
    string pat;
    cin>>txt>>pat;
    piHash(pat);
    KMP(txt,pat);
    }
}




// #include<iostream>
// using namespace std;
// int pi[100];
// void piTable(string str)
//     {
//     int i = 1;
//     int j = 0;
//     pi[0]=0;
//     while(i<str.length())
//         {
//         if(str[i]==str[j])
//             {
//             pi[i]=j+1;
//             i++;
//             j++;
//             }
//         else
//             {
//             if(j!=0)
//                 j = pi[j-1];
//             else
//                 {
//                 j = 0;
//                 i++;
//                 }
//             }
//         }
//     }
// void kmp(string str1,string str2)
//     {
//     int i = 0;
//     int j = 0;
//     while(i<str2.length())
//         {
//         if(str2[i]==str1[j])
//             {
//             i++;
//             j++;
//             }
//         if(j==str1.length())
//             {
//             cout<<"FOUND AT:"<<i-j<<endl;
//             j= pi[j-1];
//             }
//         if(str2[i]!=str1[j])
//             {
//             if(j>0)
//                 j = pi[j-1];
//             else
//                 i++;    
//             }
//         }
//     }
// int main()
// {
// int testCases;
// cin>>testCases;
// while(testCases--)
//     {
//     string str1,str2;
//     cin>>str1>>str2;
//     for(int i = 0;i<100;i++)
//         pi[i]=0;
//     piTable(str1);
//     // for(int i = 0;i<100;i++)
//     //     cout<<pi[i]<<" ";cout<<endl;
//     kmp(str1,str2);
//     }
// }