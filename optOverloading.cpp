#include<iostream>
using namespace std;
class dog
    {
    public:
    bool operator()(int a,int b)
        {
        cout<<"In Dog Operator()"<<endl;
        cout<<"Comparing"<<a<<" and "<<b<<" "<<endl;
        return a<b;
        }
    };
int main()
{
dog funnyDog;//Functional Object
//an object which hears like a function, we can call it.
funnyDog(1,2);//Functional Object is also called a functor.
//overloading ();
return 0;
}