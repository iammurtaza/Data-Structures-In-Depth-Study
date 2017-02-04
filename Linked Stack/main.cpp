#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
}*top=nullptr;

void print(){
    node *t2= top;
    while(t2!=nullptr){
        cout<<t2->data<<" ";
        t2=t2->next;
    }
    cout<<"\n";
}

void push(int data){
    node *temp = new node();
    temp->data = data;
    //temp->next = nullptr;
    //if(top!=nullptr)
    temp->next = top;
    top = temp;
    print();
}

void pop(){
    if(top!=nullptr){
        node *t2= top;
        top=top->next;
        delete t2;
    }
    else
        cout<<"Err\n";
    print();
}

int main()
{
    push(3);
    push(10);
    push(19);
    pop();
    pop();
    pop();
    pop();
}
