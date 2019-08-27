//everything to do about trees.
#include<iostream>
#include<queue>
#include<map>
using namespace std;
class node
    {
    public:
    int data;
    node * left;
    node * right;
    node():data(-1),left(NULL),right(NULL){}
    node(int val):data(val),left(NULL),right(NULL){}
    ~node()
        {
        if(left!=NULL)delete left;
        if(right!=NULL)delete right;
        }
    };
node * buildTree()
    {
    int data;
    cin>>data;
    if(data==-1)
        return NULL;
    node * root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
    }
node * buildLevelOrder()
    {
    queue<node *> q;
    int data;
    cin>>data;
    if(data == -1)
        return NULL;
    node * temp = new node(data);
    q.push(temp);
    while(!q.empty())
        {
        int l,r;
        cin>>l>>r;
        if(l == -1)
            q.front()->left = NULL;
        else
        q.front()->left = new node(l);
        if(r==-1)
            q.front()->right = NULL;
        else
        q.front()->right = new node(r);
        if(q.front()->left != NULL)
            q.push(q.front()->left);
        if(q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
        }
    return temp;
    }
void preOrder(node * root)
    {
    //base case
    if(root==NULL)
        return;
    //rec case
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    }
void bfs(node * root)
    {
    //base case
    if(root==NULL)
        return;
    //rec case
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
        {
        node * temp = q.front();
        q.pop();
        if(temp==NULL)
            {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
            continue;
            }
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        
        }
    }
node* insertInBST(node * root,int data)
    {
    //base case
    if(root==NULL)
        {
        return new node(data);
        }
    //rec case
    if(root->data > data)
        root->left = insertInBST(root->left, data);
    if(root->data < data)
        root->right = insertInBST(root->right,data);
    return root;
    }
node* buildBST()
    {
    int data;
    cin>>data;
    node * temp = NULL;
    //remember to take temp as NULL to ensure that no garbage value is passed to insert fxn.
    while(data!=-1)
        {
        temp = insertInBST(temp,data);
        cin>>data;
        }
    return temp;
    }
node * p = NULL;
void inOrderSucc(node * root)
    {
    //base case
    if(root == NULL)
        return ;
    //rec case
    inOrderSucc(root->left);
    if(p!=NULL)
        {
        cout<<"ELEMENT: "<<p->data<<" SUCC: "<<root->data<<endl;
        p = root;
        }
    if(p == NULL)
        {
        p  = root;
        }
    inOrderSucc(root->right);
    }
//in the pair first is root data second is depth
void topView(node * root,int xxx,map<int,pair<int,int>> &mappy,int ht)
    {
    //base case
    if(root == NULL)
        return;
    //rec case
    pair<int,int> temp;
        temp.first = root->data;
        temp.second = ht;
    if(mappy.find(xxx)==mappy.end())
        {
        mappy[xxx] = temp;
        }
    else if(mappy[xxx].second < temp.second)
        {
        mappy[xxx] = temp;
        }
    topView(root->left,xxx-1,mappy,ht+1);
    topView(root->right,xxx+1,mappy,ht+1);
    }
int main()
{
// node * root = buildTree();
// cout<<"NEXT"<<endl;
// node * root2 = buildLevelOrder();
// cout<<"NEXT"<<endl;
// bfs(root);cout<<endl;
// cout<<"NEXT"<<endl;
// preOrder(root);cout<<endl;
// cout<<"NEXT"<<endl;
// bfs(root2);cout<<endl;
// cout<<"NEXT"<<endl;
// preOrder(root2);cout<<endl;
node * BST;
BST = buildBST();
cout<<"NEXT"<<endl;
// preOrder(BST);
// cout<<"NEXT"<<endl;
bfs(BST);
cout<<"NEXT"<<endl;
// insertInBST(BST,5);
// bfs(BST);
// cout<<"NEXT"<<endl;
// preOrder(BST);
inOrderSucc(BST);
map<int,pair<int,int>> mappy;
topView(BST,0,mappy,0);
for(auto x:mappy)
    {
    cout<<x.second.first<<" ";
    }cout<<endl;
}