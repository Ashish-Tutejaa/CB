#include<iostream>
using namespace std;
class node
    {
    public:
    string data;
    node * left;
    node * right;
    node(){}
    node(string data)
        {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        }
    };
node * creator(string str)
    {
    //base case
    //checking if there are no ? or : in the string
    int countChecker=0;
    for(int jk=0;jk<str.size();jk++)
        {
        if(str[jk]=='?' or str[jk]==':')
            countChecker++;
        }
    if(!countChecker)
        return (new node(str));
    //EOS
    string thisOne;
    node * root;
    int i=0;
    while(str[i++]!='?')
    for(int j=0;j<=i;j++)
        thisOne+=str[j];
    root->data = thisOne;
    //finding string to get the left;
    string leftOne;
    int countQ=1;
    int end=0;
    for(int h=i+1;h<str.size();h++)
        {
        if(str[h]=='?')countQ++;
        if(str[h]==':')countQ--;
        if(str[h]==':' and !countQ)
            {
            end=h;
            }
        }
    for(int j=i+1;j<=end;j++)
        {
        leftOne+=str[j];
        }
    root->left =creator(leftOne);
    string rightOne;
    for(int h=end+1;h<str.size();h++)
        {
        rightOne+=str[h];
        }
    root->right = new node(rightOne);
    return root;
    }
void printer(node * root)
    {
    if(root==NULL)
        return;
    printer(root->left);
    printer(root->right);
    cout<<root->data<<" ";
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string ques;
    cin>>ques;
    node * root = creator(ques);
    cout<<endl;
    printer(root);
    cout<<endl;
    }
}