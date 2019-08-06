#include<iostream>
#include<queue>
using namespace std;
class node
    {
    public:
    int data;
    node * left;
    node * right;
    node(){}
    node(int data)
        {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        }
    ~node()
        {
        if(left!=NULL)
            delete left;
        if(right!=NULL)
            delete right;
        }
    };
void insert(node * &root,int data)
    {
    if(root==NULL)
        {
        root = new node(data);
        return;
        }
    if(data>root->data and root->right==NULL)
        {
        root->right = new node(data);
        return;
        }
    else if(data<root->data and root->left==NULL)
        {
        root->left = new node(data);
        return;
        }
    if(data<root->data)
        insert(root->left,data);
    else
        insert(root->right,data);
    
    }
node * buildTree()
    {
    int data;
    cin>>data;
    node * root=NULL;
    while(data!=-1)
        {
        insert(root,data);
        cin>>data;
        }
    return root;
    }
bool searcher(node *root,int key)
    {
    //base case
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    //rec case
    bool flag;
    if(key<=root->data)
        flag=searcher(root->left,key);
    else
        flag=searcher(root->right,key);
    return flag;
    }
void inOrder(node * root)
    {
    //base case
    if(root==NULL)
        return;
    //rec case
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    }
void levelOrder(node * root)
    {
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
        {
        if(q.front()==NULL)
            {
            cout<<endl;
            q.pop();
            if(!q.empty())
                {
                q.push(NULL);
                }
            else
                continue;
            }
        node * temp = q.front();
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        cout<<temp->data<<" ";
        }
    }
node * searchPro(node * root,int data)
    {
    //base cases
    if(root==NULL)
        return NULL;
    if(root->data==data)
        return root;
    node * temp;
    if(data<root->data)
        {
        temp = searchPro(root->left,data);
        }
    if(data>=root->data)
        {
        temp = searchPro(root->right,data);
        }
    return temp;
    }
//top down
class head
    {
    public:
    node * head = NULL;
    node * tail = NULL;
    };
head flatten(node * root)
    {
    head A;
    if(root==NULL)
        {
        A.head = NULL;
        A.tail = NULL;
        return;
        }
    if(root->left == NULL and root->right == NULL)
        {
        A.head = root;
        A.tail = root;
        return A;
        }
    head left,right;
    left = flatten(root->left);
    right = flatten(root->right);
    if(root->left!=NULL and root->right == NULL)
        {
        root->left = left.tail;
        root->right = NULL;
        left.tail->right = root;
        A.head = left.head;
        A.tail = root;
        return A;
        }
    if(root->right !=NULL and root->left == NULL)
        {
        root->right = right.head;
        A.head = root;
        A.tail = right.tail;
        return A;  
        }   
    if(root->right!=NULL and root->left !=NULL)
        {
        root->left = left.tail;
        root->right = right.head;
        left.tail->right = root;
        A.head = left.head;
        A.tail = right.tail;
        return A;
        }
    }
void del(node * root,int data)
    {
    // cout<<"DELLL"<<endl;
    node * toDel;
    toDel = searchPro(root,data);
    if(toDel==NULL)
        return ;
    //first subcase with no children.
    if(toDel->left==NULL and toDel->right==NULL)
        {
        delete toDel;
        return;
        }
    //second subcase with one child.
    if(toDel->left==NULL and toDel->right!=NULL)
        {
        toDel= toDel->left;
        }
    else if(toDel->left!=NULL and toDel->right == NULL)
        {
        toDel= toDel->right;
        }
    //third subase with both children.
    else if(toDel->left!=NULL and toDel->right !=NULL)
        {
        node * smallest = toDel->right;
        while(smallest->left!=NULL)
            smallest = smallest->left;
        toDel->data = smallest->data;
        del(toDel->right,smallest->data);
        }
    }
int main()
{
node * root=NULL;
root = buildTree();
inOrder(root);
cout<<endl;
levelOrder(root);


}