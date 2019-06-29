#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Triplet{
public:
    string name;
    int x,y;
    Triplet(string n,int x,int y){
    name = n;
    this->x = x;
    this->y=y;
    }
};
//use stl for muuuch faster work.
bool compare{Triplet a,Triplet b}
    {
    return a.x*a.x + a.y*a.y < b.x*b.x+b.y*b.y;
    //we do this for distance
    }

int main()
{
int n;cin>>n;
vector<Triplet> v;
for(int i=0;i<n;i++)
    {
    string name;
    int x,y;
    cin>>name>>x>>y;
    Triplet t(name,x,y);
    v.push_back(t);
    }
    sort(v.begin(),v.end(),compare);
    //a version of for Each loop in C++:
        for(Triplet t:v){
        cout<<t.name<<" "<<t.x*t.x+t.y*t.y<<endl;
        }
}