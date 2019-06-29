#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct node
    {
     public:
    int data;
    node * left;
    node * right;
    node(int data)
        {
        this->data = data;
        left = NULL;
        right = NULL;
        }
    };
//recursive building function
node * buildTree()
    {
    int data;cin>>data;
    if(data==-1)
        return NULL;
    node * root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
    }
//recursive printing function
void Print(node * root)
    {
    if(root == NULL){return;}
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
    }
//1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
//function to print level
void printLevel(node * root,int k)
    {
    if(root == NULL)return;
    if(k==0){cout<<root->data<<" ";return;}cout<<endl;
    printLevel(root->left,k-1);
    printLevel(root->right,k-1);
    }
//function to get height of tree
int height(node * root)
    {
    return root == NULL?0:1+max(height(root->left),height(root->right));
    }
void printAllLevels(node * root)
    {
    //complexity of this is N^2;
    int levels = height(root);
    for(int i=0;i<levels;i++)
        {
        printLevel(root,i);
        }
    }
//printing in pre post and in order.
//WAP to count all nodes
int count(node * root,int counter)
    {
    if(root == NULL)return 0;
    else counter++;
    counter+=count(root->left,0);
    counter+=count(root->right,0);
    return counter;
    }
//sum of all nodes in a tree
int sumOfAll(node * root,int sum)
    {
    if(root == NULL)return 0;
    else sum=root->data;
    sum+=sumOfAll(root->left,0);
    sum+=sumOfAll(root->right,0);
    return sum;
    }
//Self Code Below:
//replace all nodes by the sum of their descendants
void replaceByDescSum(node * &root)
    {
    if(root == NULL)return;
    root->data+=sumOfAll(root->left,0)+sumOfAll(root->right,0);
    replaceByDescSum(root->left);
    replaceByDescSum(root->right);
    }
//Class Code Below:
int replaceNodesBySum(node * root)
    {
    if(root == NULL)return 0;
    if(root->left == NULL and root->right == NULL)
    {
    return root->data;
    }
    int temp = root->data;
    root->data = replaceNodesBySum(root->left) + replaceNodesBySum(root->right);
    return root->data+temp;
    }
//In Srivastava
void levelOrder(node * root)
    {
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
        {
        node * f = q.front();
            if(f==NULL)
                {
                q.pop();
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                    continue;
                }
            }
        q.pop();//removing the selected.
        cout<<f->data<<" ";
        if(f->left!=NULL)
            {
            q.push(f->left);
            }
        if(f->right!=NULL)
            {
            q.push(f->right);
            }
        }
    }
//recursive level order building or a tree
node * buildTreeLvl()
    {
    queue<node *>q;
    int temp;cin>>temp;
    node * root = new node(temp);
    q.push(root);
    while(!q.empty())
        {
        int data1,data2;
        cin>>data1>>data2;
        node * f  = q.front();
        q.pop();
        if(data1!=-1)
            {
            f->left = new node(data1);
            q.push(f->left);
            }
        if(data2!=-1)
            {
            f->right = new node(data2);
            q.push(f->right);
            }
        }
    return root;
    }
//1 2 3 4 -1 5 6 -1 -1 8 -1 -1 -1 -1 -1
//complexity of below fxn is n^2.
int diameter(node * root)
    {
    if(root==NULL)return 0;
    int sum=0;
    sum=height(root->left)+height(root->right)+1;
    int sum2=max(diameter(root->left),diameter(root->right));
    return max(sum,sum2);
    }
//below is improving the complexity of the above function...
class MyPair{
public:
    int height;
    int diameter;
};
MyPair diameterOptimised(node * root)
    {
    MyPair p;
    if (root == NULL)
        {
        p.height =0;p.diameter=0;
        return p;
        }
    //rec case
    //post order:left right root
    //complexity is O(1).  We're going from the bottom up.
    MyPair left = diameterOptimised(root->left);
    MyPair right = diameterOptimised(root->right);
    p.height = max(left.height,right.height)+1;
    p.diameter = max(max(left.diameter,right.diameter),(left.height+right.height));
    return p;
    }
class HBPair{
public:
int height;
int balance;
};
HBPair heightCheck(node * root)
    {
    HBPair p;
    if(root == NULL)
        {
        p.height =0 ;
        p.balance=0;
        return p;
        }
    HBPair left = heightCheck(root->left);
    HBPair right = heightCheck(root -> right);
    if(abs(left.height-right.height)and left.balance and left.balance)
        {
        p.balance = true;
        }
    else{
    p.balance=false;
    }
    p.height = max(left.height,right.height);
    return p;
    }
//No Do below using the MyPair technique.  include and exclude.  Can be done in O(n);
int checker(node * root,int sum)
    {
    map<node *,bool>mappy;
    if(root == NULL){return 0;};
    if(mappy.find(root)==mappy.end())
        {
        mappy.insert(pair<node*,bool>(root,1));
        sum+=root->data;
        }
    sum+=checker(root->left,0);
    sum+=checker(root->right,0);
    cout<<sum<<endl;
    }
bool maxSubSet(node * root)
    {
    checker(root,0);
    maxSubSet(root->left);
    maxSubSet(root->right);
    }

int main()
{
node * root = buildTree();

Print(root);cout<<endl;
cout<<"level one"<<endl;
printLevel(root,1);cout<<endl;
cout<<"All Levels"<<endl;
printAllLevels(root);cout<<endl;
cout<<"Number of nodes"<<endl;
cout<<count(root,0)<<endl;
cout<<"Sum of nodes"<<endl;
cout<<sumOfAll(root,0)<<endl;
cout<<"Replaced by Sum Desc"<<endl;
replaceByDescSum(root);
Print(root);cout<<endl;
// cout<<"Level Order Building"<<endl;
// node * Newroot = buildTreeLvl();
// Print(Newroot);cout<<endl;
cout<<"Diameter of Trees"<<endl;
cout<<diameter(root)<<endl;
cout<<"Check BF"<<endl;
heightCheck(root);
cout<<"CheckSubSet"<<endl;
maxSubSet(root);
return 0;
}