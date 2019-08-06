//the twenty forty eight problem
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
string solver(string doubt,int size,int i)
    {
    string temp;
    //base case
    if(i==(size))
        return "";
    //rec case
    return mappy[doubt[i]]+" "+solver(doubt,size,i+1);
    }
int main()
{
string damn;
cin>>damn;
string answer = solver(damn,damn.size(),0);
cout<<answer<<endl;
}