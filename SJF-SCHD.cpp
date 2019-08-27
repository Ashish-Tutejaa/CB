#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
class vars
    {
    public:
    int arrival;
    int burst;
    vars(){}
    vars(int a,int b):arrival(a),burst(b){}
    int operator()(const vars & p1,const vars & p2)
        {
        return p1.arrival > p2.arrival;
        }
    void operator = (const vars & p2)
        {
        arrival = p2.arrival;
        burst = p2.burst;
        }
    };
bool myComp(const vars a,const vars b)
    {    
    return a.burst < b.burst;
    }
int main()
{
int n;cin>>n;
priority_queue<vars,vector<vars>,vars> pq;
int arr[n];
int burst[n];
for(int i = 0;i<n;i++)
    {
    cin>>arr[i];
    }
for(int i =0;i<n;i++)
    {
    cin>>burst[i];
    }
for(int i =0;i<n;i++)
    {
    vars temp(arr[i],burst[i]);
    pq.push(temp);
    }
int wait = 0;
int totalTime = 0;
int turnAround = 0;
while(1)
    {
    // cout<<"SIZE: "<<pq.size()<<endl;
    cout<<pq.top().arrival<<" "<<pq.top().burst<<endl;
    vars dummy = pq.top();
    pq.pop();
    if(pq.size()>0)
    if((pq.top().arrival == dummy.arrival) or (totalTime>=pq.top().arrival))
        {
        vector<vars> vect;
        vect.push_back(dummy);
        while((pq.top().arrival == dummy.arrival) or (totalTime>=pq.top().arrival))
            {
            vars hmm = pq.top();
            vect.push_back(hmm);
            pq.pop();
            if(pq.size()==0)
                break;
            }
        sort(vect.begin(),vect.end(),myComp);
        dummy = vect[0];
        // cout<<"VECTOR: ";
        // for(auto y:vect)
        //     {
        //     cout<<y.arrival<<" "<<y.burst<<" ,";
        //     }cout<<endl;
        for(int i =1;i<vect.size();i++)
            {
            pq.push(vect[i]);
            }
        vect.clear();
        }
    int temp =0;
    if(totalTime == 0)
        {
        totalTime+=dummy.arrival;
        temp = totalTime;
        }
    // cout<<"SELECTED: "<<dummy.arrival<<" "<<dummy.burst<<endl;
    temp = totalTime;
    totalTime+=dummy.burst;
    wait+= abs(temp - dummy.arrival);
    turnAround+= abs(temp - dummy.arrival) + dummy.burst;
    // cout<<"time "<<totalTime<<" wait: "<<abs(temp-dummy.arrival)<<" turnAround "<<abs(temp - dummy.arrival) + dummy.burst<<endl;
    if(pq.size()==0)
        {
        break;
        }
    }
wait= wait/n;
turnAround=turnAround/n;
cout<<"TOTAL TIME: "<<totalTime<<" average waiting time "<<wait<<" average turn around "<<turnAround<<endl;
}