#include<iostream>
#include<math.h>
using namespace std;
typedef long long int ll;
int main()
{
string num;
cin>>num;
for(int i = 0;i<num.size();i++)
    {
    if((num[i]-'0')>4)
        {
        if(i==0)
            continue;
        int temp = num[i]-'0';
        temp = abs(temp-9);
        num[i] = temp+'0';
        }
    }
cout<<num<<endl;
}