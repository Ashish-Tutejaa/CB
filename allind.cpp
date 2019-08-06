#include<iostream>
using namespace std;
string retStr(int * arr,int key,int front,int back)
    {
    string temp;
    //base case
    if(front==back)
        return "";
    if(arr[front]==key)
        {
        temp = front-'0';
        temp+=retStr(arr,key,front+1,back);
        }
    temp+=retStr(arr,key,front+1,back);
    return temp;
    }
int * solver(int * arr,int key,int front,int back)
    {
    string temp = retStr(arr,key,front,back);
    for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";cout<<endl;
    int arr2[temp.size()];
    for(int i=0;i<temp.size();i++)
        {
        arr2[i]='0'+temp[i];
        cout<<arr2[i]<<" ";
        }cout<<endl;
    return arr2;
    }

int main()
{
int size;
cin>>size;
int arr[size];
for(int i=0;i<size;i++)
    cin>>arr[i];
int key;cin>>key;
int * ans = solver(arr,key,0,size);
}