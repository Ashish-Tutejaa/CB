#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<functional>
using namespace std;
class point
    {
    public:
    int x;
    int y;
    int distance;
    point(){}
    point(int x,int y)
        {
        this->x = x;
        this->y = y;
        distance = pow(this->x,2)+pow(this->y,2);
        distance = sqrt(distance);
        }
    bool operator()(point a,point b)
        {
        return a.distance>b.distance;
        }
    };

int main()
{
int n;
cin>>n;
priority_queue<point,vector<point>,point> pq;
while(n--)
    {
    cout<<"input coordinates"<<endl;
    int temp1,temp2;
    cin>>temp1>>temp2;
    point A(temp1,temp2);
    pq.push(A);
    }
while(!pq.empty())
    {
    cout<<pq.top().x<<" "<<pq.top().y<<" "<<pq.top().distance<<"   ";
    pq.pop();
    }cout<<endl;
}