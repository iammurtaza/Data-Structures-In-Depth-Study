#include <iostream>

using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
}*start=NULL,*start2=NULL;

int count=0;

void iab(int val){
    node *temp = new node;
    temp->data=val;
    temp->prev=NULL;
    if(start==NULL){
        temp->next=NULL;
        start=temp;
    }
    else{
        start->prev=temp;
        temp->next=start;
        start=temp;
    }
    count++;
}

void iae(int val){
    node *temp = new node;
    temp->data=val;
    temp->next=NULL;
    if(start==NULL){
        temp->prev=NULL;
        start=temp;
    }
    else{
        start2=start;
        while(start2->next!=NULL){
            start2=start2->next;
        }
        start2->next=temp;
        temp->prev=start2;
    }
    count++;
}

void iaap(int val,int pos){
    node *temp = new node;
    temp->data=val;
    if(pos==1)
        iab(val);
    else if(pos==count)
        iae(val);
    else if(pos<count){
        start2=start;
        for(int i=2;i<pos;i++){
            start2=start2->next;
        }
        temp->prev=start2;
        temp->next=start2->next;
        start2->next=temp;
        temp->next->prev=temp;
        count++;
    }
    else
        cout<<"Invalid position\n";
}

void dab(){
    if(start==NULL){
        cout<<"No element to delete\n";
    }
    else{
        start=start->next;
        count--;
    }
}

void dae(){
    if(start==NULL){
        cout<<"No element to delete\n";
    }
    else{
        start2=start;
        while(start2->next->next!=NULL){
            start2=start2->next;
        }
        start2->next=NULL;
        count--;
    }
}

void daap(int pos){
    if(pos==1)
        dab();
    else if(pos==count)
        dae();
    else if(pos<count){
        start2=start;
        for(int i=2;i<pos;i++){
            start2=start2->next;
        }
        start2->next=start2->next->next;
        start2->next->next->prev=start2;
        count--;
    }
    else{
        cout<<"Invalid position\n";
    }
}

void view(){
    start2=start;
    while(start2!=NULL){
        cout<<start2->data<<" ";
        start2=start2->next;
    }
    cout<<"\n";
}

void revsee(){
    start2=start;
    while(start2->next!=NULL){
        start2=start2->next;
    }
    while(start2!=NULL){
        cout<<start2->data<<" ";
        start2=start2->prev;
    }
    cout<<"\n";
}

void rev(){
    node *temp=new node;
    start2=start;
    while(start2->next!=NULL){
        start2=start2->next;
    }
    start=start2;
    while(start2!=NULL){
        temp=start2->next;
        start2->next=start2->prev;
        start2->prev=temp;
        start2=start2->next;
    }
}

int main()
{   int ex=1,cho,pos,val;
    while(ex){
    cout<<"Doubly Linked List\n";
    cout<<"1. iab\n2. iae\n3. iaap\n4. dab\n5. dae\n6. daap\n7. view\n8. revsee\n9. rev\n10. exit\n";
    cin>>cho;
    switch(cho){
        case 1: cin>>val;
                iab(val);
                view();
            break;
        case 2: cin>>val;
                iae(val);
                view();
            break;
        case 3: cin>>val>>pos;
                iaap(val,pos);
                view();
            break;
        case 4: dab();
                view();
            break;
        case 5: dae();
                view();
            break;
        case 6: cin>>pos;
                daap(pos);
                view();
            break;
        case 7: view();
            break;
        case 8: revsee();
            break;
        case 9: rev();
                view();
            break;
        case 10: ex=0;
            break;
    }
    }
    return 0;
}
