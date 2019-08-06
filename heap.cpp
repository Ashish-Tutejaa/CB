#include<iostream>
using namespace std;
struct heap
    {
    int * arr;
    int capacity;
    int curSize;
    bool heapType;
    };
void heapify(heap &,int);
void createHeap(heap &h,int capacity,bool heapType)
    {
    h.arr = new int[capacity];
    h.capacity = capacity;
    h.heapType = heapType;
    h.curSize = 0;
    }
void deleteion(heap &h)
    {
    cout<<h.arr[0]<<endl;
    int temp = h.arr[0];
    h.arr[0] = h.arr[h.curSize-1];
    h.arr[h.curSize-1] = temp;
    h.curSize--;
    heapify(h,0);
    }
void percolateUp(heap &h)
    {
    if(!h.curSize)
        return;
    int parent;
    int current = h.curSize-1;
    if(h.heapType)
        {
          while(1)
            {
            parent = (current-1)/2;
            if(h.arr[current]>h.arr[parent])
                {
                swap(h.arr[current],h.arr[parent]);
                current = parent;
                }
            else
                break;
            }
        }
    else
        {
        while(1)
            {
            parent = (current-1)/2;
            if(h.arr[current]<h.arr[parent])
                {
                swap(h.arr[current],h.arr[parent]);
                current = parent;
                }
            else
                break;
            } 
        }
    }
void reSizeHeap(heap &h)
    {
    int * arr = new int[h.capacity*2];
    int * temp = h.arr;
    for(int i = 0;i<h.curSize;i++)
        arr[i] = h.arr[i];
    h.arr = arr;
    free(temp);
    }
void insertion(heap &h, int data)
    {
    h.curSize++;
    if(h.curSize>=h.capacity)
        reSizeHeap(h);

    h.arr[h.curSize-1] = data;
    percolateUp(h);
    }
void bfs(heap &h)
    {
    int i = 0;
    int end = 1;
    for(i = 0;i<h.capacity;i++)
        {
        if(i==end)
            {

        end = 2*end + 1;
            cout<<endl;
            }
        cout<<h.arr[i];
        }
    }
void heapify(heap &h,int i)
    {
    if(i>=h.curSize)
        return;
    int parent = h.arr[i];
    int child1,child2;
    child1 = child2 = -1;
    int selected = i;
    if(((2*i)+1)<h.curSize)
    child1 = h.arr[(2*i)+1];
    if(((2*i)+2)<h.curSize)
    child2 = h.arr[(2*i)+2];
    if(h.heapType)
        {
        if(child1!=-1)
            {
            if(h.arr[selected]<h.arr[(2*i)+1])
                selected = (2*i)+1;
            }
        if(child2!=-1)
            {
            if(h.arr[selected]<h.arr[(2*i)+2])
                selected = (2*i)+2;
            }
        if(selected!=i)
            {
            swap(h.arr[selected],h.arr[i]);
        heapify(h,selected);
            }
        else
        {
            return;
        }
        
        }
    else
        {
        if(child1!=-1)
            {
            if(h.arr[selected]>h.arr[child1])
                selected = child1;
            }
        if(child2!=-1)
            {
            if(h.arr[selected]>h.arr[child2])
                selected =child2;
            }
        if(selected!=i)
            swap(h.arr[selected],h.arr[i]);
        heapify(h,selected);      
        }
    }
int main()
{
heap A;
cout<<"input capacity and heap type"<<endl;
int capacity,heapType;
cin>>capacity>>heapType;
createHeap(A,capacity,heapType);
cout<<"How many elements do you want to add to heap?"<<endl;
int n;cin>>n;
int arr[n];
cout<<"INPUT Elements"<<endl;
for(int i = 0;i<n;i++)
    cin>>arr[i];
cout<<"INSERTING INTO HEAP"<<endl;
for(int i = 0;i<n;i++)
    insertion(A,arr[i]);
cout<<"BFS on HEAP"<<endl;
bfs(A);
cout<<"DOING heapsort"<<endl;
cout<<"input number of elements"<<endl;
int k;cin>>k;
int array[k];
for(int i = 0;i<k;i++)
    cin>>array[i];
heap B;
createHeap(B,k+1,1);
for(int i = 0;i<k;i++)
    {
    insertion(B,array[i]);
    }
bfs(B);cout<<endl;
for(int i = 0;i<k;i++)
    {
    deleteion(B);
    }
}