//converting a string to an integer using recursion.  String or Char Array.
#include<iostream>
#include<math.h>
using namespace std;
int converter(char * arr,int size)
    {
    int temp;
    //base case
    if(arr[1]=='\0')
        return (arr[0]-'0');
    //rec case
    temp = pow(10,(size-1))*((char)(arr[0]-'0'));
    temp+=converter(arr+1,size-1);
    return temp;
    }
int main()
{
char arr[5]={'1','2','3','4','\0'};
int temp = converter(arr,4);
cout<<temp<<endl;
}