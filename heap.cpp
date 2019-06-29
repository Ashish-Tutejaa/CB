#include<iostream>
#include<vector>
using namespace std;
class heap
    {
    //we work on a vector or an array, but we visualize a tree with heap.
    public:
    vector<int> v;
    bool heapTypeMin;
    heap(int defaultSize=10,bool minHeap=true)
        {
        //default it is minHeap.  if this parameter is false, we get maxHeap.
        v.reserve(defaultSize);//to reserve atleast space for these many elems.
        v.push_back(-1);//to block the zeroth index.
        heapTypeMin = minHeap;
        }
    bool compare(int a,int b)
    {
    // first we pass the parent then we pass the child
    if(!heapTypeMin)
    return a<b;
    else
    {
        return a>b;
    }
    
    }
void insert(int data)
    {
    v.push_back(data);//make last element of heap.
    int index = v.size()-1;//this is index of the last element.
    int parent = index/2;//don't worry about the -1 case as it floors itself.5/2 = 2;
    //note index to be greater than 1 not equal to.
    //if it is equal to ever then we just get -1 and parent will be greater so
    //loop breaks anyways.
    while(index>1 and compare(v[parent],v[index]))
        {
        swap(v[parent],v[index]);
        index = parent;//making index to parent.
        parent/=2;//making parent to it's parent
        //if index =1, parent = 0;
        }
    }
    //get min/max
    int getTop()
        {
        return v[1];
        }
    //remove Min/Max
    void pop()
        {
        swap(v[1],v[v.size()-1]);
        //swapping first and last
        v.pop_back();
        //removing the last.
        heapify(1);//this will moderate the tree.  
        //it is a recursive function which will put the node (in this case root)
        //into it's correct position.
        }
    void heapify(int index)
        {
        //heapify traverses top to bottom in log(n);
        int left = 2*index;
        int right = left++;
        int last_index = v.size()-1;
        int mx_idx = index;//assuming current index is the largest/smallest
        //mx_idx reps index of smallest or largest
        if(left<=last_index and compare(v[index],v[left]))
            {
            mx_idx = left;
            }
        if(right<=last_index and compare(v[mx_idx],v[right]))
            {
            mx_idx = right;
            }
        //base case
        if(mx_idx!=index)
            {
            //as max index is not index we must call heapify again, as heap is not right
            //i.e there are greater or smaller children than the parent.
            swap(v[index],v[mx_idx]);
            heapify(mx_idx);
            }
        }
    bool empty()
        {
        return v.size()==1;
        }
    };

void heapify(int * arr,int i,int n)
    {
    int left = i<<i;
    int right = left++;
    int mx_idx = i;
    if(left<n and arr[i]<arr[left])
        {
        mx_idx = left;
        }
    if(right<n and arr[mx_idx]<arr[right])
        {
        mx_idx = right;
        }
    if(i!=mx_idx)
        {
        swap(arr[i],arr[mx_idx]);
        heapify(arr,mx_idx,n);
        }
    }
int main()
{
// heap A(10,true);
// int n;cin>>n;
// int n1=n;
// while(n--)
//     {
//     int temp;cin>>temp;
//     A.insert(temp);
//     }
// while(n1--)
//     {
//     cout<<A.getTop()<<" ";
//     A.pop();
//     }cout<<endl;
//the above loop returns a sorted output.  The output takes klog(n),but insertion
//here is taking nlog(n);
//another heap trick:
/*
last non-leaf node = n/2 (where n = elements).  taking floor of the division.
get a for loop from last non leaf to n>1
for(int i=n/2;i>=1;i--)
    {
    heapify(i);
    this will convert the array into a heap in O(n) time.
    building is n
    removing k is klog(n).
    as we go up the tree the number of nodes we have to run heapify for decreases,
    but time of heapify increases as depth increases, these cancel each other out,
    so it takes O(n) to heapify the whole array.
    heapify for root is log(n) but each level increases nodes by 2 so that's bad
    but for each level time to heapify decreases.  these cancel each other out
    we get O(n);
    }
heap sort takes nlog(n) for k elems = klog(n);
in heap sort we make an array into a heap, and then keep removing elements
and storing them or outputting.
*/
// int arr[] = {-1,5,4,1,2,3,0};
// int size = sizeof(arr)/sizeof(arr[0]);
// //convert Array to heap
// for(int i=size/2;i>0;i--)
//     {
//     heapify(arr,i,size);
//     }//heap ready in O(n);
// for(int i=0;i<size;i++)
//     cout<<arr[i]<<" ";cout<<endl;
//sort.  remove n elements with log(n) per elem = n log(n); 
//in this heap configuration the printing of the array will be in level order.
//heap is in stl.
//priority queue internally uses a heap to achieve funcionality.
int n;
cin>>n;
heap A(3,true);
while(n--)
    {
    int temp;
    cin>>temp;
    if(temp == -1)
        {
        for(int i=1;i<A.v.size();i++)
            {
            cout<<A.v[i]<<" ";
            }cout<<endl;
        }
    else 
        {
        if(A.v.size()<4)
            {
            A.insert(temp);
            }
        else  if(temp>(A.getTop()))
        {

        A.v[1]=temp;
        A.heapify(1);
        }
        }
      
  
    }
return 0;
}