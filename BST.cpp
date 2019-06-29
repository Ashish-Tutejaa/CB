#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node 
    {
    public:
    int data;
    node * left;
    node * right;
    node(int data)
        {
        this->data = data;
        left = NULL;right = NULL;
        }
    };
node *  insertInBST(node * &root,int d)
    {
    if(root == NULL)
        {
        node * rot = new node(d);
        return rot;
        }
    //insert in left 
    if(d<root->data)
        {
        root->left = insertInBST(root->left,d);
        //the address of left of root will be updated as many times as there is an addition
        //to the left subtree of the root.
        //the address will stay the same, except it will just be re-written multiple times.

        }
    else
        {
        root->right = insertInBST(root->right,d);
        }
    return root;
    }
node * takeInput()
    {
    int d;
    cin>>d;
    node * root = NULL;
    while(d!=1)
        {
        root = insertInBST(root,d);
        cin>>d;
        }return root;
    }

bool search(node * root,int key)
    {
    if(root==NULL)
        return false;
    if(root->data == key)
        {
        return true;
        }
    if(key<root->data)
        return search(root->left,key);
    //we need the return statement above to ensure that regular nodes something,as well.
    else return search(root->right,key);
    //complexity O(h);
    }
node * del(node * &root,int key)
    {
    //base case
    if(root == NULL)
        return NULL;
    if(root -> data == key)
        {
        if(root->left == NULL and root->right == NULL)
            {
            delete root;
            return NULL;
            }
        else if(root->left!=NULL and root->right == NULL)
            {
            node * temp = root->left;
            delete root;
            return temp;
            }
        else if(root->right!=NULL and root->left == NULL)
            {
            node * temp = root->right;
            delete root;
            return temp;
            }
        else
            {
            node * temp = root->right;
            while(temp->left!=NULL)
                {
                temp = temp->left;
                }//basically find the smallest element in the right subTree
                //or the largest element in the left subTree;
            root->data = temp->data;
            root->right = del(root->right,temp->data);
            return root;//the largest or smallest elements in their respective
            //subTrees will always only have one child.
            }
        }
    else if(root->data > key)
        {
        root->left = del(root->left,key);
        return root;
        }
    else
        {
        root->right = del(root->right, key);
        return root;
        }
    }
// node *  hbf(int * arr,int first,int last)
//     {
//     node * answer;
//     int pivot = (last-first)/2;
//     // pivot--;
//     pivot/=2;
//     cout<<pivot<<endl;
//     if(answer==NULL)
//         node * temp = new node(arr[pivot]);
//     cout<<"LMAO"<<endl;

//     else insertInBST(answer,arr[pivot]);
        
//     answer->left = hbf(arr,first,pivot-1);
//     answer ->right = hbf(arr,pivot+1,last);
//     return answer;
//     }
void Print(node * root)
    {
    if(root == NULL){return;}
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
    }
node * arrayToBST(int arr[],int s,int e)
    {
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    node * root = new node(arr[mid]);
    root->left = arrayToBST(arr,s,mid-1);
    root->right = arrayToBST(arr,e,mid+1);
    }
class LLPair
    {
    public:
    node * head;
    node * tail;
    };
LLPair tree2LL(node * root)
    {
    LLPair l;
    //base case
    if(root == NULL)
        {
        l.head = NULL;
        l.tail = NULL;
        return l;
        }
    if(root->left == NULL and root->right == NULL)
        {
        l.head = root;
        l.tail = root;
        return l;
        }
    //rec case
    if(root->left!=NULL and root->right == NULL)
        {
        LLPair leftLL = tree2LL(root->left);
        leftLL.tail ->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
        }
    if(root->left == NULL and root->right!=NULL)
        {
        LLPair rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
        }
    else 
        {
        LLPair leftLL = tree2LL(root->left);
        LLPair rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;
        l.head = leftLL.head;
        l.tail = rightLL.tail;
        return ;
        }
    }
node * fromPreOrder(int * arr,int * sorted,int i,int size)
    {
    int temp;
    node * root;
    if(!i)
        {
        root = new node(arr[i]);
        int temp = arr[i];
        }
    bool jhanda=0;
    map<int,bool> mapLeft;
    map<int,bool> mapRight;
    for(int i=0;i<size;i++)
        {
        if(sorted[i]==temp)
            jhanda=1;
        if(!jhanda)
            mapLeft.insert(pair<int,bool>(sorted[i],1));
        else
            mapRight.insert(pair<int,bool>(sorted[i],1));
        }
    bool flagLeft=0,flagRight=0;
    for(int i=0;i<size;i++)
        {
        if(!flagLeft)
            {
            if(mapLeft.find(arr[i])!=mapLeft.end())
                {
                node * tem = new node(arr[i]);
                root->left = tem;
                }
            }
        if(!flagRight)
            {
            if(mapRight.find(arr[i])!=mapRight.end())
                {
                node * tem = new node(arr[i]);
                root->right = tem;
                }
            }
        }
    }
//to make sure a variable isn't impacted by recursion, either make it global
//or make it static, or pass it by reference.
node * preToBST(int * pre,int *in,int s,int e)
    {
    static int x = 0;
    //base case
    if(s>e)
        return NULL;
    node *  root = new node(pre[x]);
    //search the infex of x in preOrder;
    int j;
    for(j=s;j<e;j++)
        {
        if(in[j]==pre[x])
            {
            break;
            }
        }
    //j knows index of pre[x] in j
    x++;
    root->left = preToBST(pre,in,s,j-1);
    root->right = preToBST(pre,in,j+1,e);
    return root;
    }
int countBST(int n)
    {
     if(n==1)return 1;
     int ans =0;
     for(int i=1;i<=n;i++)
        ans+=countBST(n-i)*countBST(i-i);
        return ans;
    }
int main()
{
// node * root = takeInput();
int arr[] = {1,3,5,7,9,10,11};
int size = (sizeof(arr)/sizeof(int));
//                                                                                                      
// Print(answer);cout<<endl;
int arr2[]={7,3,1,5,10,9,11};
int size = sizeof(arr2)/sizeof(int);
int sorted[size];
for(int i=0;i<size;i++)
    {
    sorted[i]=arr2[i];
    }
sort(sorted,sorted+size);
node * temp = fromPreOrder(arr,sorted,0,size);
return 0;
}