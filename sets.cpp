#include<iostream>
#include<set>
using namespace std;
int main()
{
//add greater<int> to reverse order of sort.
//you can pass functors to a set as a second argument instead of greater<int>
//to impact the way of sorting.  Duplicates will still be removed, tho.
//the main difference between sets and heap: set removes dups, and in set we can 
//remove particular elements.
//internally, set is basically a bst. However, it is a self balancing BST.
//for a set to remove a duplicate, all attributes of the objects must be the same.
//there is also the multi set and multi maps. Check them out.
//multiset will store everything.  unordered multi set.
set<int,greater<int>> s;
s.insert(1);
s.insert(2);
s.insert(4);
s.insert(1);
s.insert(2);
s.insert(4);
for(int x:s)
    {
    cout<<x<<" ";
    }cout<<endl;
}