//same 2048 problem, but now using an integer
#include<iostream>
#include<map>
using namespace std;
map<char,string> mappy = {
{'0',"zero"},
{'1',"one"},
{'2',"two"},
{'3',"three"},
{'4',"four"},
{'5',"five"},
{'6',"six"},
{'7',"seven"},
{'8',"eight"},
{'9',"nine"}
};
/*
string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
use this instead of the map, it's better.
*/
string solver(int n)
    {
    
    }
int main()
{
int n;
cin>>n;
string answer = solver(n);
cout<<answer<<endl;
}