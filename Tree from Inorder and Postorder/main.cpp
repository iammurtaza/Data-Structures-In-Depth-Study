#include <iostream>
int pos[10],in[10],n;
using namespace std;

struct node{
    int d;
    node* l;
    node* r;
};

node* getNode(int d){
    node* t = new node();
    t->d=d;
    t->l=t->r=nullptr;
    return t;
}

int srch(int instr,int inlst,int value){
    int i;
    for(i=instr; i<=inlst; i++)
        if(in[i]==value)
            return i;
}

node* maketree(int instr,int inlst){
    static int pi=n-1;
    if(inlst<instr)
        return nullptr;
    node* tree = getNode(pos[pi--]);
    if(inlst==instr)
        return tree;
    int ii=srch(instr,inlst,tree->d);
    tree->r=maketree(ii+1, inlst);
    tree->l=maketree(instr, ii-1);
    return tree;
}

void inorder(node* rx){
    if(rx==nullptr)
        return;
    inorder(rx->l);
    cout<<rx->d<<" ";
    inorder(rx->r);
}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>in[i];
    for(i=0;i<n;i++)
        cin>>pos[i];
    node* root = maketree(0,n-1);
    inorder(root);
    return 0;
}
