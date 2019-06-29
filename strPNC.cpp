#include<iostream>
using namespace std;
int perm (char *str,int i)
    {
    //base case
    if(str[i]=='\0')
        {
        cout<<str<<endl;
        return 0;
        }
    //rec case
    for(int j=i;str[j]!='\0';j++)
        {
        swap(str[i],str[j]);
        perm(str,i+1);
        swap(str[i],str[j]);     //backtracking used here
        }
    }
int main()
{
char str[] = "abc";
perm(str,0);
}