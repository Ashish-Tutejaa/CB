#include<iostream>
using namespace std;
string set = "AB";
int counter = 0;
void maker(int n,char arr[],int i)
    {
    //base case
    if(i==n)
        {
        arr[i]='\0';
        cout<<arr<<endl;
        // int checker = 0;
        // char arr[3] = "BBB";
        // int j = 0 ;
        // for(int l = 0;l<=n-3;l+=3)
        //     {
            
        //     }
        return;
        }
    //rec case
    else
        {
        arr[i] = set[0];
        maker(n,arr,i+1);
        arr[i] = set[1];
        maker(n,arr,i+1);
        }
    
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    char arr[n+1];
    maker(n,arr,0);
    cout<<counter<<endl;
    }
}