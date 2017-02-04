//All statements in comments are working properly. You can uncomment and test them too.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* newNode(int data){
    node *temp = new node();
    temp->data=data;
    temp->left=temp->right=nullptr;
    return temp;
}

node* insert(int data,node* root){
    if(root==nullptr)
        root = newNode(data);
    else if(data<=root->data)
        root->left = insert(data,root->left);
    else
        root->right = insert(data,root->right);
    return root;
}

bool binSearchIterative(int x, node *root){
    node *currentNode = root;
    while(currentNode!=nullptr){
        if(x==currentNode->data)
            return true;
        else if(x<= currentNode->data)
            currentNode=currentNode->left;
        else
            currentNode=currentNode->right;
    }
    return false;
}

bool binSearch(int x, node *root){
    if(root==nullptr)
        return false;
    if(x==root->data)
        return true;
    else if(x<=root->data)
        return binSearch(x,root->left);
    else
        return binSearch(x,root->right);
}

//Space Complexity of pre,in,post Order traversal is O(h) where h is the height of tree as function stack grows up to h elements then shrinks again
//Space Complexity in worst case is O(n) and O(log n) in best case
//Time Complexity is O(n) as all nodes are visited once
void preOrder(node *root){
    if(root!=nullptr){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

/*void preOrder(node *root){
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}*/

void inOrder(node *root){
    if(root!=nullptr){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void postOrder(node *root){
    if(root!=nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void levelOrder(node *root){
    // Time complexity is O(n) due to each node being visited at least once.
    // Space complexity is O(1) when data is stored like linked list, at all time only one element of the queue will be used
    // and for worst and average case it is O(n)
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        cout<<Q.front()->data<<" ";
        if(Q.front()->left!=nullptr)
            Q.push(Q.front()->left);
        if(Q.front()->right!=nullptr)
            Q.push(Q.front()->right);
        Q.pop();
    }
}

int min(node *root){
    if(root==nullptr){
        cout<<"Err";
        return -1;
    }
    while(root->left!=nullptr)
        root=root->left;
    return root->data;
}

int max(node *root){
    if(root==nullptr){
        cout<<"Err";
        return -1;
    }
    while(root->right!=nullptr)
        root=root->right;
    return root->data;
}

int maxrecur(node* root){
    if(root==nullptr){
        cout<<"Err";
        return -1;
    }
    else if(root->right==nullptr)
        return root->data;
    else
        maxrecur(root->right);
}

int minrecur(node* root){
    if(root==nullptr){
        cout<<"Err";
        return -1;
    }
    else if(root->left==nullptr)
        return root->data;
    else
        minrecur(root->left);
}

int binHeight(node *root){
    if(root==nullptr)
        return -1;
    return max(binHeight(root->left),binHeight(root->right))+1;
}

//Inefficient ways to check if a given tree is BST. Complexity is O(n^2).
bool isSubtreeLesser(node *root, int value){
    if(root==nullptr)
        return true;
    if(root->data <= value
       && isSubtreeLesser(root->left, value)
       && isSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool isSubtreeGreater(node *root, int value){
    if(root==nullptr)
        return true;
    if(root->data > value
       && isSubtreeGreater(root->left, value)
       && isSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool isBinSearchTree(node *root){
    if(root==nullptr)
        return true;
    if(isSubtreeLesser(root->left,root->data)
       && isSubtreeGreater(root->right,root->data)
       && isBinSearchTree(root->left)
       && isBinSearchTree(root->right))
        return true;
    else
        return false;
}

//Another inefficient way to check whether a tree is a BST or not
bool isBinSearchTree2(node *root){
    if(root==nullptr)
        return true;
    if(root->left!=nullptr && max(root->left) > root->data)
        return false;
    if(root->right!=nullptr && min(root->right) < root->data)
        return false;

    if(!isBinSearchTree2(root->left) || !isBinSearchTree2(root->right))
        return false;

    return true;
}

//Most effective way which a has time complexity of O(n)
bool isBinSearchTree3(node *root, int minValue, int maxValue){
    if(root==nullptr)
        return true;
    if(root->data >= minValue
       && root->data < maxValue
       && isBinSearchTree3(root->left, minValue, root->data)
       && isBinSearchTree3(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

//Another way to write the above function
/*bool isBinSearchTree3(node *root, int minValue, int maxValue){
    if(root==nullptr)
        return true;
    if(root->data <= minValue
       || root->data > maxValue)
        return false;

    return isBinSearchTree3(root->left, minValue, root->data)
       && isBinSearchTree3(root->right, root->data, maxValue);
}*/

bool isBinSearchTree3INITIATOR(node *root){
    return isBinSearchTree3(root, INT_MIN, INT_MAX);
}

//Another really efficient way too with complexity of O(n)
vector<int> a;
void isBinSearchTreeINORDER_METHOD(node *root){
    if(root!=nullptr){
        isBinSearchTreeINORDER_METHOD(root->left);
        a.push_back(root->data);
        isBinSearchTreeINORDER_METHOD(root->right);
    }
}

node *maxADDRESS(node *root){
    if(root==nullptr)
        return root;
    while(root->right!=nullptr)
        root=root->right;
    return root;
}

node *del(int data, node *root){
    if(root==nullptr)
        return root;
    if(data < root->data)
        root->left = del(data, root->left);
    else if(data > root->data)
        root->right = del(data, root->right);
    else {
        //No child
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            root=nullptr;
        }
        //One child
        else if(root->right==nullptr){
            node *temp=root;
            root = root->left;
            delete temp;
        }
        else if(root->left==nullptr){
            node *temp=root;
            root = root->right;
            delete temp;
        }
        //Two children
        else {
            node *temp = maxADDRESS(root->left);
            root->data = temp->data;
            root->left = del(temp->data, root->left);
        }
    }
    return root;
}

node* binSearchIterativeADDRESS(int x, node *root){
    node *currentNode = root;
    while(currentNode!=nullptr){
        if(x==currentNode->data)
            return currentNode;
        else if(x<= currentNode->data)
            currentNode=currentNode->left;
        else
            currentNode=currentNode->right;
    }
    return nullptr;
}

//In Order successor in O(h)
int inOrderSUCCESSOR(int data, node *root){
    if(root==nullptr)
        return -1;
    node *current = binSearchIterativeADDRESS(data, root);

    //Corner Case Error
    if(max(root)==current->data)
        return -1;

    //Node has right sub tree
    if(current->right!=nullptr)
        return min(current->right);

    //No right sub tree
    else{
        node *successor = nullptr;
        node *ancestor = root;
        while(ancestor!=current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor= ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor->data;
    }
}

int main()
{
    node *root=nullptr;
    /*root = insert(8,root);
    root = insert(6,root);
    root = insert(4,root);
    root = insert(1,root);
    root = insert(3,root);
    root = insert(9,root);
    root = insert(2,root);
    root = insert(5,root);
    root = insert(10,root);
    root = insert(7,root);
    root = insert(11,root);*/

    //BST's in-order traversal is always sorted while for different order of insertion, pre-order and post-order are different.

    root = insert(6,root);
    root = insert(4,root);
    root = insert(10,root);
    root = insert(2,root);
    root = insert(5,root);
    root = insert(7,root);
    root = insert(11,root);
    root = insert(1,root);
    root = insert(3,root);
    root = insert(9,root);
    root = insert(8,root);

    cout<<"Pre Order Traversal: ";
    preOrder(root);
    cout<<"\nIn Order Traversal: ";
    inOrder(root);
    cout<<"\nPost Order Traversal: ";
    postOrder(root);
    cout<<"\nLevel Order Traversal: ";
    levelOrder(root);

    cout<<"\nIn Order Traversal: ";
    inOrder(root);

    /*cout<<"\nElement to be searched: ";
    int x;
    cin>>x;
    //if(binSearch(x,root))
    if(binSearchIterative(x,root))
        cout<<"Found.\n";
    else
        cout<<"Not in the BST.\n";

    //cout<<"Maximum: "<<max(root)<<"\n";
    cout<<"Maximum: "<<maxrecur(root)<<"\n";
    //cout<<"Minimum: "<<min(root)<<"\n";
    cout<<"Minimum: "<<minrecur(root)<<"\n";

    cout<<"Height of BST: "<<binHeight(root)<<"\n";

    //BST confirmation has 4 solutions.

    // if(isBinSearchTree(root))
    // if(isBinSearchTree2(root))
    // if(isBinSearchTree3INITIATOR(root))
    isBinSearchTreeINORDER_METHOD(root);
    if(is_sorted(a.begin(),a.end()))
        cout<<"It is a BST\n";
    else
        cout<<"Not a BST\n";

    cout<<"\nElement you want to delete: ";
    int y;
    cin>>y;
    del(y,root);*/

    cout<<"\nIn Order successor of which element: ";
    int e;
    cin>>e;
    int e2=inOrderSUCCESSOR(e,root);
    cout<<e2;
    cout<<"\nIn Order Traversal: ";
    inOrder(root);
    return 0;
}
