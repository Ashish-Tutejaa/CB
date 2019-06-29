//Largest/Smallest
#include <iostream> 
using namespace std; 
int getNext(int n) 
{ 
	/* Compute c0 and c1 */
	

	return n; 
} 

// Driver Code 
int main() 
{ 
	int n = 5; 
    int temp = n; 
    int temp2 =n;
	int zeroes = 0; 
	int ones = 0; 

	while (((temp & 1) == 0) && (temp != 0)) 
	{ 
		zeroes ++; 
		temp >>= 1; 
	} 
	while ((temp & 1)==1) 
	{ 
		ones++; 
		temp >>= 1; 
	} 
	if (zeroes +ones == 31 || zeroes + ones== 0) 
		cout<<-1<<endl; 
	int p = ones + zeroes;
	temp2 |= (1 << p); 
	temp2 &= ~((1 << p) - 1); 
	temp2 |= (1 << (ones - 1)) - 1; 
	cout <<temp2<<endl;
} 
