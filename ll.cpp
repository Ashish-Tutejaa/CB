//linked lists
#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
node * next;
node(int data)
    {
    this->data = data;
    next = NULL;
    }
~node()
    {//now, as the destructor is called whatever happens, the object will be deleted.
    //now, the next means that the rest of the linked list is deleted.
    //imp to understand as otherwise, the last node can't be deleted as next == NULL.
    //the destructor will simply pass, and it will delete.
    //recursive calling for the destructor of the next node.
    //It is recursive focus on that.  test it w/ cout statements.
    if(next!=NULL)//the whole ll will be deleted in this way.
    //delete will call the destructor.
        {
        delete next;
        }
    cout<<"Deleting"<<data<<endl;
    }
/*This is the same as 
node(int d):data(d),next(NULL){}This is called an initialization list.
the main point is that the data members are initialized.  For the above method inside the constructor;
we are making and then assigning.  For const data members we must use an initialization list.
*/
};
/*In the below function we are passing the value of head, as head itself is a pointer.  So, we must pass head 
by reference.  Either pass address of head and take a double pointer.  Or take reference as below.
If we are ever changing the head of a linked list pass by reference always, or use double pointer and pass
address of the head to the function.*/
void insertAtHead(node * &head,int data)
{
if (head == NULL)
    {
    head = new node(data);
    return;
    }
node * n = new node(data);
n->next = head;
head = n;
return;
}
/*in the below function, as head is passed by value, the linked list will be printed everytime
head is called. Basically, if we are changing the head itself i.e head = new node
or head = head->next etc. pass by ref.*/
void printLL(node * head)
    {
    while(head!=NULL)
        {
        cout<<" ->"<<head->data;
        head = head->next;
        }cout<<endl;
    }
//for below, don't need to pass head by ref, but if p = 0 then we do need head by ref.  so just take head
//by ref.
int length (node * head)
    {
    int counter=0;
    while(head!=NULL)
        {
        head= head->next;
        counter++;
        }
    return counter;
    }
void insertInMiddle(node* &head,int d,int p)
    {
    //if p>length of ll;
    if(p>length(head))
        {
        return;
        }
    if(p==0)
        {
        insertAtHead(head,d);
        return;
        }
    node * itr = head;
    while(1)
        {
        itr = itr->next;
        p--;
        if(p==0)break;
        }

    node * temp = new node(d);
    temp->next = itr->next;
    itr->next = temp;
    return;
    }
//below is deletion and search in a linked list.
void deletenode(node * &head)
    {
    delete head;//this will delete the info that the head is pointing to.  This will cause
    //memory leak as the first node is deleted, and the rest of the linked list is still in mem and we can;t
    //now access.
    /*To solve this we can define a destructor as shown above.*/
    //delete doesn't free static mem.  Head will only end with main.
    //but now, head has the address of the memory which has been deleted.  So, now just set head
    //equal to NULL;
    head = NULL;
    }
void deleteInTheMiddle(node * head,int p)
    {
    if(head == NULL)
        {
        cout<<"Empty list"<<endl;return;
        }
    if(p==0)
        {
        node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return ;
        }
    node * temp = head;
    node * prev;
    while(p--)
        {
        prev = temp;
        temp = temp->next;
        }
    prev->next = temp->next;
    temp->next = NULL;//here we have to set temp->next = NULL otherwise due to the destructor, the whole
    //list will get deleted.
    delete temp;
    return;
    }
//search recursive
int search(node * head,int p,int counter)
    {
    if(counter>length(head))
        {
        cout<<"not in list"<<endl;
        return -1;
        }
    if(head->data==p)
        return counter;
    counter++;
    head = head->next;
    search(head,p,counter);
    }
//reverse: iterative
node * rev(node * & head)
    {
    
    node * nextStored;
    node * itr = head;
    node * prev = itr;
    bool jhanda =0 ;
    while(itr!=NULL)
        {
        if(!jhanda)
            {
            itr=itr->next;
            jhanda=1;
            }
        
        nextStored = itr->next;
        itr->next = prev;
        prev = itr;
        itr = nextStored;
        }
     head->next = NULL;
    return prev;
    }
//reverse: recursive DO AT HOME
//Merge Two  LL
void merge(node * & headO,node * & headT)
    {
    node * headOne = headO;
    node * headTwo = headT;
    if(headOne==NULL or headTwo==NULL)
        return;
    if(headOne->data>headTwo->data)
        {
        if(headTwo->next->data<headOne->data)
            {
                cout<<"hm"<<endl;
            }
        node * temp=headTwo->next;
        headTwo->next = headOne;
        headTwo = temp;
        
        }
    if(headOne->data<headTwo->data)
        {
         if(headOne->next->data<headTwo->data)
            {
            cout<<"hm"<<endl;
            }
        node * temp=headOne->next;
        headOne->next = headTwo;
        headOne = temp;
       
        }
    merge(headOne,headTwo);
    }

int main()
{
node * head = new node(10);
node * tail;
insertAtHead(head,20);
insertAtHead(head,30);
insertAtHead(head,40);
insertInMiddle(head,900,1);
printLL(head);
deleteInTheMiddle(head,1);
printLL(head);
cout<<search(head,900,1)<<endl;
search(head,5000,1);
tail = rev(head);
cout<<"SECOND"<<endl;printLL(tail);
node * headS = new node(8);
insertAtHead(headS,7);
insertAtHead(headS,4);
insertAtHead(headS,1);
node * headT = new node(12);
insertAtHead(headT,10);
insertAtHead(headT,2);
insertAtHead(headT,0);
cout<<"ONE"<<endl;
printLL(headS);
cout<<"TWO"<<endl;
printLL(headT);
merge(headS,headT);
cout<<"MERGED"<<endl;
printLL(headT);
}
/*for the tail pointer, we have two corner cases: insertion at beginning with p = 0 and insertion at the end
with p = lenght.*/
//MergeSort with LL
//Alternate Merge: HWK-> a1 an a2 an-1 a3 an-2 a4 an-3 etc.
/*
K reverse a ll means reverse a linked list in increments of K.
1,2,3,4,5,6,7,8: 3,2,1,6,5,4,7,8  Do via recursion this one.
We have two linked lists that have one point in common, find that point which is in common.  DO with STACK.
What two pointer?
- Cycle Detection Question in Linked Lists: find cycle (y/n), if there is break the cycle.  Can do this
using slow and fast pointers.  If the pointers meet, then there is a cycle.  Fast moves two, and slow moves
one.  unordered_map<node*,bool>  Popular Algorithm: Floyd's Cycle Algorithm.  
Proof of Floyd's Algorithm:Ds = x+y;Df =x+2y+z;Df = 2Ds; x+2y+z = 2x+2y;x = z;  So meeting point of 
fast and slow when they move one each with fast at initial meeting point, we get the place where the cycle starts.
XOR Linked list: one pointer and can traverse in either front or back directions.
store XOR of address of front and back node.XOR ll = LLcoolJ
*/