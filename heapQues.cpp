#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void printHeap(priority_queue<int,vector<int>,greater<int>>)
    {

    }
int main()
{
priority_queue<int,vector<int>,greater<int>> h;
int no,cnt=0,k=3;
//instead of EOF you can also write -1.
//scanf has a return type.  It returns the number of things it has read.
//if it reads nothing, you get a -1 value.
while(scanf("%d",&no)!=EOF)
    {
    cnt++;
    if(no==-1)
        {
        printHeap(h);
        }
    else
    {
        if(cnt<k){
            h.push(no);cnt++;
        }
        else
        {
                if(no>h.top()){
                h.pop();
                h.push(no);
                }
        }
    
    }
    
    }
}