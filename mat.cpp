#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int testCases;
    cin>>testCases;
    while(testCases--)
        {
        int n;
        cin>>n;
        char arr[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        int pairsAv=0;
        int indAv=0;
        for(int i=0;i<(n-1);i++)
            {
            for(int j=i+1;j<n;j++)
                {
                if(arr[i][j]=='C')
                    pairsAv++;
                }
            }

        for(int i=0;i<n;i++)
            {
            for(int j=i;j==i;j++)
                {
                if(arr[i][j]=='C')
                    indAv++;
                }
            }
        int pairsNeed = n/2;
        int indNeed=n%2;
        if(indNeed==0)
            {
            if(pairsAv>=pairsNeed)
                cout<<pairsNeed<<endl;
            else
                cout<<pairsAv<<endl;
            }
        else
            {
            int ans =0;
            if(pairsAv>=pairsNeed)
                ans+=pairsNeed;
            else
                ans+=pairsAv;
            if(indAv>=indNeed)
                ans+=indNeed;
            else
                ans+=indAv;
            cout<<ans<<endl;
            }
        }
    return 0;
}

