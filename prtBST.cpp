#include<iostream>
#include<vector>
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
    left = NULL;
    right = NULL;
    }
};
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
void Print(node * root)
    {
    if(root == NULL){return;}
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
    }
//mine
void printBranches(node * root)
    {
    vector<node *> vecty;
    //base case
    if(root->left == NULL and root->right == NULL)
        {
        for(int i=0;i<vecty.size();i++)
            {
            cout<<vecty[i]<<" ";
            }cout<<endl;
        vecty.pop_back();
        }
    //rec case
    if(root->left!=NULL)
        {
        vecty.push_back(root->left);
        printBranches(root->left);
        }
    if(root->right!=NULL)
        {
        vecty.push_back(root->right);
        printBranches(root->right);
        }
    cout<<root->data<<endl;
    }
//sir
void root2Leaf(node * root,vector<int> & v)
    {
    if(root == NULL)return ;
    if(root->left == NULL and root->right == NULL)
        {
        v.push_back(root->data);
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";cout<<endl;
            v.pop_back();
            return;
        }
    //rec case
    v.push_back(root->data);
    root2Leaf(root->left,v);
    root2Leaf(root->right,v);
    v.pop_back();
    return;
    }
//1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
void mirror(node * root)
    {
    if(root == NULL)
        return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
    return ;
    }
int main()
{
node * root = buildTree();
Print(root);cout<<endl;
vector<int>v;
root2Leaf(root,v);cout<<endl;
mirror(root);
Print(root);cout<<endl;
}