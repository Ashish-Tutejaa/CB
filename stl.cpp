//vector
#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector<int> v;
for(int i=0;i<=10;i++)
    {
    v.push_back(i*i);
    cout<<v[i]<<endl;
    cout<<v.capacity()<<endl;
    }cout<<endl;
    cout<<v.max_size()<<endl;
for(int i=0;i<=5;i++)
    {
    cout<<v[i]<<endl;
    }
return 0;
//v.capacity() = size actually taken in memory
//using sizeof doesn't show the property of the vector of doubling up when full
//v.capacity() does actually show that.
// max space a vector is taking up.
//doubling capacity of vector is order N.
//doubling N times order is N log(n).  to avoid this, just choose a bigger capacity 
//in the beginning.  Do this by using v.reserve(10^8).  This way it won't grow for
//random things.
//pop_back can be used to pop things from the back and return them.
//shrinking policy: if only 25% of the capacity is being used, decrease the size to half.
//v.at(i) == v[i];
//v.begin() returns an iterator pointing to the first element of the array.
//v.clear() this removes all elements.
//sort also takes a third argument which is actually a function.  To reverse sort
//use this:
/*
bool compare(int a,int b)
    {
    return a>b;
    }
pair<string,int> p1;
p1.first = "apple";p1.second =50;
v.push_back(make_pair(fruit,price));// if you make a vector of pairs then use this to 
insert pairs in there.
*/
}
