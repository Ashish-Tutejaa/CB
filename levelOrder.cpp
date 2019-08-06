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
void revLvlOrder(node * root)
    {
    if(root==NULL)
        {
        cout<<"Empty tree"<<endl;
        return;
        }
    queue<node *> q;
    stack<node *>s;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
        {
        if(q.front()==NULL)
            {
            q.pop();
            if(!q.empty())
                {
                s.push(NULL);
                q.push(NULL);
                }
            continue;
            }
        node * temp = q.front();
        q.pop();
        s.push(temp);
        if(temp->right!=NULL)
            q.push(temp->right);
        if(temp->left!=NULL)
            q.push(temp->left);
        }
    while(!s.empty())
        {
        if(s.top()==NULL)
            {
            s.pop();
            cout<<endl;continue;
            }
        cout<<(*s.top()).data<<" ";
        s.pop();
        }
    }
int maxInTree(node * root)
    {
    if(root==NULL)
        return INT16_MIN;
    int temp = root->data;
    return max(max(temp,maxInTree(root->left)),max(temp,maxInTree(root->right)));
    }
int count(node * root)
    {
    if(root==NULL)
        return 0;
    return 1+count(root->left)+count(root->right);
    }
int diameter(node * root,int k=0)
    {
    if(root->left==NULL and root->right ==  NULL)
        return k;
    int left =diameter(root->left,k+1);
    int right = diameter(root->right,k+1);
    int mx = max(left,right);
    if(k)
        return mx;
    else if(!k)
        {
        return left+right+1;
        }
    
    }
int repBySum(node * root)
    {
    if(root==NULL)
        return 0;
    int left = repBySum(root->left);
    int right = repBySum(root->right);
    int temp = root->data;
    if(root->left==NULL and root->right == NULL)
        {
        return temp;
        }
    else
        {
        root->data = left+right;
        return temp + left + right;     
        }
    }
class HBPair
    {
    public:
    int height;
    int bf;
    HBPair(){}
    HBPair(int height,int bf)
        {
        this->height = height;
        this->bf = bf;
        }
    };
HBPair heightBal(node * root)
    {
    HBPair now;
    if(root == NULL)
        {
        now.height = 0;
        now.bf = 0;
        return now;
        }
    HBPair left = heightBal(root->left);
    HBPair right = heightBal(root->right);
    now.height = max(left.height,right.height)+1;
    now.bf = max(max(left.bf,right.bf),(abs(left.height-right.height)));
    return now;
    }
node * builder(int arr[],int start,int end)
    {
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    node * root = new node(arr[mid]);
    root->left = builder(arr,start,mid-1);
    root->right = builder(arr,mid+1,end);
    return root;
    }
int main()
{
// //3 4 6 -1 -1 8 -1 -1 5 -1 7 -1 -1
// node* root = buildTree();
// preOrder(root);
// cout<<endl<<"_________________________________"<<endl;
// inOrder(root);
// cout<<endl<<"_________________________________"<<endl;
// postOrder(root);
// cout<<endl<<"_________________________________"<<endl;
// levelOrder(root);
// cout<<"_________________________________"<<endl;
// printXLevel(root,3);
// cout<<endl<<"_________________________________"<<endl;
// cout<<height(root);
// cout<<endl<<"_________________________________"<<endl;
// recurLevelOrder(root);
// cout<<endl<<"_________________________________"<<endl;
// revLvlOrder(root);
// cout<<endl<<"_________________________________"<<endl;
// cout<<maxInTree(root);
// cout<<endl<<"_________________________________"<<endl;
// cout<<count(root);
// cout<<endl<<"_________________________________"<<endl;
// // cout<<diameter(root);
// // cout<<endl<<"_________________________________"<<endl;
// repBySum(root);
// levelOrder(root);cout<<"YES"<<endl;
// HBPair temp = heightBal(root);
// cout<<"height = "<<temp.height<<" BF: "<<temp.bf;
cout<<endl<<"_________________________________"<<endl;
int arr[] = {1,2,3,4,5,6,7};
int size = sizeof(arr)/sizeof(int);
node * rootTwo = builder(arr,0,size-1);
levelOrder(rootTwo);cout<<"YES TWO"<<endl;
cout<<endl<<"_________________________________"<<endl;




}