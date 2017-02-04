#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
}*rear=nullptr, *head=nullptr;

void print(){
    node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void enq(int d){
    node *temp= new node();
    temp->data=d;
    temp->next=nullptr;
    if(rear==nullptr){
        head = rear = temp;
    }
    else{
        rear->next = temp;
        rear=temp;
    }
    print();
}

void deq(){
    if(head==rear){
        cout<<"Queue is empty\n";
        head=rear=nullptr;
    }
    else {
        node *temp=head;
        head=head->next;
        delete temp;
        print();
    }
}

int main()
{
    deq();
    deq();
    deq();
    enq(3);
    enq(4);
    enq(7);
    enq(9);
    enq(12);
    enq(7);
    enq(9);
    enq(12);
    deq();
    deq();
    deq();
    enq(101);
    enq(102);
    deq();
    deq();
    deq();
    deq();
    deq();
    deq();
    deq();
    deq();
    enq(7);
    enq(9);
    enq(12);
    return 0;
}
