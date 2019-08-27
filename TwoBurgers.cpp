#include<iostream>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int buns,bp,cp;
    cin>>buns>>bp>>cp;
    int bc,cc;
    cin>>bc>>cc;
    int totalBuns = buns/2;
    int ans =0 ;
    int gret =0;
    int otras =0;
    int cost = 0;
    int otrasCost = 0;
    if(bc>cc)
        {
        gret = bp;
        cost = bc;
        otras = cp;
        otrasCost = cc;
        }
    else
        {
        gret = cp;
        cost = cc;
        otras = bp;
        otrasCost = bc;
        }
    while(totalBuns)
        {
        if(gret>0)
            {
            ans+=cost;
            gret--;
            totalBuns--;
            continue;
            }
        else
            {
            if(otras>0)
            otras--;
            ans+=otrasCost;
            totalBuns--;
            continue;
            }
        }
    cout<<ans<<endl;
    }
}