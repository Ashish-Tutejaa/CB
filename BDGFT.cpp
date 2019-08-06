#include<iostream>
using namespace std;
// bool checker(int i,int j,int * preComp)
//     {
//      int start = i;
//     int end = j;
//     int numOnes=0;
//     if(i>0)
//     numOnes = preComp[j]-preComp[i-1];
//     else
//     numOnes = preComp[j]-preComp[i];
//     if(preComp[j]==preComp[i])
//         {
//         if(i>0)
//             {
//             if(preComp[i-1]<preComp[i])
//                 numOnes = 1;
//             else 
//                 numOnes = 0;
//             }
//         else
//             {
//             numOnes = 1;     
//             }
        
//         }
//     int numZeroes = (j-i+1)-numOnes;
//     if(numZeroes>(numOnes*numOnes))
//         return true;
//     else
//         return false;
//     }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int counter =0 ;
    string str;
    cin>>str;
    int n = str.length();
    int preComp[n]={0};
    for(int i=0;i<n;i++)
        {
        if(str[i]=='1')
            {
            preComp[i]++;
            }
        if(i>0)
            preComp[i]+=preComp[i-1];
        }
    for(int i=0;i<n;i++)
        {
       
        for(int j=n-1;j>=i;j--)
            {
                // cout<<"I: "<<i<<" J: "<<j<<endl;
    
            int start = i;
            int end = j;
            int numOnes=0;
            if(i>0)
            numOnes = preComp[j]-preComp[i-1];
            else
            numOnes = preComp[j]-preComp[i];
            if(preComp[j]==preComp[i])
                {
                if(i>0)
                    {
                    if(preComp[i-1]<preComp[i])
                        numOnes = 1;
                    else 
                        numOnes = 0;
                    }
                else
                    {
                    numOnes = 1;     
                    }
                }
            int numZeroes = (j-i+1)-numOnes;
            if(numZeroes ==(numOnes*numOnes))
                counter++;
            // cout<<"1s:"<<numOnes<<" 0s: "<<numZeroes<<endl;            
            }
        }
    cout<<counter<<endl;
    }
}