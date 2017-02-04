#include <iostream>

using namespace std;

struct BSTnode{
    int data;
    BSTnode *left;
    BSTnode *right;
};

BSTnode *getNewNode(int data){
    BSTnode *newNode= new BSTnode;
    newNode->data=data;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}

BSTnode* insert(BSTnode* root,int data){
    if(root==NULL)
        root = getNewNode(data);

    else if(data<=root->data)
        root->left = insert(root->left,data);

    else
        root->right = insert(root->right,data);

    return root;
}

bool binSearch(BSTnode* root, int data){
	if(root == NULL)
		return false;

	else if(root->data==data)
		return true;

	else if(data<=root->data)
		return binSearch(root->left,data);

	else
		return binSearch(root->right,data);
}

int main()
{   BSTnode* root = NULL;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
	int n;
	cout<<"Enter number to be searched\n";
	cin>>n;
	if(binSearch(root,n) == true)
		cout<<"Found\n";
	else
		cout<<"Not Found\n";
}
