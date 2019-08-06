//Karumanchi BT questions.
//Level Order Printing
#include<iostream>
#include<stack>
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
        left = NULL;
        right = NULL;
        }
    ~node()
        {
        if(left!=NULL)
            delete left;
        if(right!=NULL)
            delete right;
        }
    };
node* buildTree()
    {
    int data;
    cin>>data;
    if(data==-1)
        return NULL;
    node * root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    }
void preOrder(node * root)
    {
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
    }
void inOrder(node * root)
    {
    if(root == NULL)
        return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
    return;
    }
void postOrder(node * root)
    {
    if(root == NULL)
        return;
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
    return;
    }
void levelOrder(node * root)
    {
    if(root==NULL)
        return;
    queue<node *> q;
    q.push(root);
    if(root->left == NULL and root->right == NULL)
        {
        cout<<q.front()->data<<endl;
        q.pop();
        return;
        }
    q.push(NULL);
    while(!q.empty())
        {
        if(q.front()==NULL)
            {
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
            continue;
            }
        node * temp = q.front();
        cout<<q.front()->data<<" ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        }
    return ;
    }
int height(node * root)
    {
    if(root==NULL)
        return 0;
    return 1 + max(height(root->left),height(root->right));
    }
void printXLevel(node * root,int k)
    {
    if(root==NULL)
        return;
    if(k==1)
        cout<<root->data<<" ";
    else
        {
        k--;
        printXLevel(root->right,k);
        printXLevel(root->left,k);
        }
    }
void recurLevelOrder(node * root)
    {
    int levels = height(root);
    for(int i=1;i<=levels;i++)
        {
        printXLevel(root,i);
        }
    }
int maxInTree(node * root)
    {
    //base case
    if(root==NULL)
        return 0;
    //rec case
    int maxi = root->data;
    return max(maxi,max(maxInTree(root->left),maxInTree(root->right)));
    }
int maxNoRec(node * root)
    {
    if(root==NULL)
        return -1;
    //doing preOrder Traversal using stack.
    stack<node *> s;
    stack<int> maximum;
    node * temp = root;
    while(1)
        {
        // cout<<"LOOPING"<<endl;
        while(temp!=NULL)
            {
            // cout<<temp->data<<" ";
            s.push(temp);
            if(maximum.size()==0)
                maximum.push(root->data);
            if(s.top()->data>maximum.top())
                maximum.push(s.top()->data);
            temp = temp->left;
            }
        if(s.empty())
            {
            break;
            // cout<<"BREAK"<<endl;
            }
   
        temp = s.top();
        s.pop();
        temp = temp->right;
        }
    return maximum.top();
    }
bool search(node * root,int key)
    {
    //base case
    if(root==NULL)
        return false;
    //rec case
    int found = root->data;
    if(found==key)
        return true;
    else
        {
        return search(root->left,key) or search(root->right,key);
        }
    }
int searchNoRec(node * root,int key)
    {
    if(root==NULL)
        return -1;
    stack<node *> s;
    node * temp = root;
    bool flag=0;
    while(1)
        {
        while(temp!=NULL)
            {
            s.push(temp);
            temp = temp->left;
            }
        if(s.empty())
        break;
        temp = s.top();
        s.pop();
        if(temp->data == key)
        flag=1;
        temp = temp->right;
        }
    return flag;
    }
int sizeBT(node * root)
    {
    //base case
    if(root==NULL)
    return 0;
    //rec case
    return 1+sizeBT(root->left)+sizeBT(root->right);
    }
int sizeBTNoRec(node * root)
    {
    if(root==NULL)
        return -1;
    queue<node *> q;
    q.push(root);
    int counter=0;
    while(!q.empty())
        {
        node * temp = q.front();
        q.pop();
        counter++;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        }   
    return counter;
    }
int deepestNode(node * root)
    {
    
    }
int main()
{
//3 4 6 -1 -1 8 -1 -1 5 -1 7 -1 -1
node * temp = buildTree();
cout<<"MAXIMUM:"<<maxNoRec(temp)<<endl;
cout<<"SEARCH for 8:"<<searchNoRec(temp,17)<<endl;
cout<<"SIZE of BT:"<<sizeBTNoRec(temp)<<endl;
}