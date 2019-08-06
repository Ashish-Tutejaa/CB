//Hostel Visit
#include<iostream>
#include<queue>
using namespace std;
void print(priority_queue<point> take)
	{
	while(!take.empty())
		{
		cout<<take.top().distance<<" ";take.pop();
		}cout<<endl;
	}

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
		this->distance = (2*x)+(2*y);
		}
	};
int main()
{
int q,k;
cin>>q>>k;
priority_queue<point> pq;
while(q--)
	{
	int temp;cin>>temp;
	if(temp&1)
		{
		int x,y;cin>>x>>y;
		point A(x,y);
		if(pq.size()<k)
			{
			pq.push(A);
			}
		else
			{
			if(A.distance < pq.top().distance)
				{
				pq.pop();
				pq.push(A);
				}
			}
		}
	if(!temp&1)
		{
		print(pq);
		}
	}
}