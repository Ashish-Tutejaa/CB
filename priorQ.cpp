#include<iostream>
#include<queue>
using namespace std;
class fruit
    {
    public:
    string name;
    int price;
    public:
    bool operator()(fruit a,fruit b)
        {
        return a.price<b.price;
        }
    fruit(){}
    fruit(string name,int price){
    this->name = name;
    this->price = price;
    }

    };
class compare
    {
    public:
    bool operator()(fruit a,fruit b)
        {
        return a.price<b.price;
        }
        /*
        can tweak the logic
bool operator()(student a,student b)
        {
        return a..top>b.top;
        }*/
        
    };


int main()
{
//when we use set, it removes duplicates, and sorts.
//we will pass vector<int> and greater<int> to the queue along with our
//data type to make it a MIN heap
//instead of greater<int> if we have to compare things from struc or class
//we make a compare class.  we send a class. The class must be a functor
//with the round brackets overloaded.
//priority_queue<int,vector<int>,greater<int>> h;
//must send vector it is necesary. data types of vector and the default of queue
//must be same.
priority_queue<fruit,vector<fruit>,fruit> h;
// int arr[] = {1,3,2,5,0,8,7};
// int n = sizeof(arr)/sizeof(arr[0]);
fruit a("apple",10),b("banana",20),c("orange",30);
fruit arr[]={a,b,c};
for(int i=0;i<3;i++)
h.push(arr[i]);
//pop while not empty
while(!h.empty())
    {
    cout<<h.top().name<<" "<<h.top().price<<" ";
    h.pop();
    }cout<<endl;
//the priority queue is using MAX HEAP by default
}