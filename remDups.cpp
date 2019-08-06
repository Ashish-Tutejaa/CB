#include<iostream>
using namespace std;
string remove(string str,int i,int size)
	{
	string temp;
	//base case
	if(i==size)
		return "";
	if(str[i]!=str[i+1])
		temp = str[i];
	temp+=remove(str,i+1,size);
	return temp;
	}
int main()
{
string str;
cin>>str;
cout<<remove(str,0,str.size())<<endl;
}