#include<iostream>
using namespace std;
class node
{
public:
int data;
node * next;
node (){}
node ( int d): data(d),next(NULL){}
};
node * insAtHead(node * temp, int data)
    {
    if(temp == NULL)
        return new node(data);
    else
        {
        node * dummy = new node(data);
        dummy->next = temp;
        return dummy;        
        }
    }
node * buildLL()
    {
    int data;
    cin>>data;
    node * temp = NULL;
    while(data!=-1)
        {
        temp = insAtHead(temp,data);
        cin>>data;
        }
    return temp;
    }
void printLL(node * head)
    {
    node * temp = head;
    while(temp!=NULL)
        {
        cout<<temp->data<<"->";
        temp = temp->next;
        }cout<<endl;
    }
node * insertExt(node *&head,int data)
    {
    if(head == NULL)
        return new node(data);
    node * n = new node(data);
    n->next = head;
    head = n;
    return head;
    }
void insertInMiddle(node * &head,int data,int pos)
    {
    int count = 1;
    node * temp = head;
    while(count<(pos-1))
        {
        if(temp == NULL)
            break;
        temp = temp->next;
        count++;
        }
    if(count>pos)
        return;
    node * putIn = new node(data);
    putIn->next = temp->next;
    temp->next = putIn;
    return;
    }
bool recSearch(node * head,int data)
    {
    //base case
    if(head == NULL)
        return false;
    //rec case
    if(head->data==data)
        return true;
    else return recSearch(head->next, data);
    }
void reverse(node * & head)
    {
    node * temp = head;
    node * n = NULL;
    node * p = NULL;
    while(temp!=NULL)
        {
        n = temp->next;
        temp->next = p;
        p = temp;
        temp = n;   
        }
    head = p;
    }
node * &recursiveReverse(node * &head,node *&tail)
    {
    //base case
    if(head->next == NULL)
        {
        tail = head;
        return head;
        }
    //rec case
    node * &nexter = recursiveReverse(head->next,tail);
    nexter->next = head;
    return head;
    }
int main()
{
node * head;
head = buildLL();
printLL(head);
cout<<"INSERTING"<<endl;
insertExt(head,22);
printLL(head);
cout<<"INSERTING AT POS 5"<<endl;
insertInMiddle(head,99,5);
printLL(head);
cout<<"Implementing recursive search in LL"<<endl;
int data;cin>>data;
cout<<recSearch(head,data)<<endl;
cout<<"REVERSING A LL"<<endl;
reverse(head);
printLL(head);
cout<<"REVERSE AGAIN"<<endl;
node * tail = NULL;
recursiveReverse(head,tail);
head->next = NULL;
printLL(tail);
}