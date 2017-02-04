#include <iostream>
#include <array>

using namespace std;

array<int, 5> a={};
int f=-1,r=-1,c;

/*void print(){
    int count = (r+a.size()-f)%a.size() + 1;
    for(int i = 0; i <count; i++){
        int index = (f+i) % a.size();
        cout<<a[index]<<" ";
    }
    cout<<"\n";
}*/

void print(){
    int f2=f;
    for(int i = 0; i <c; i++){
        cout<<a[f2]<<" ";
        f2 = (f2+1) % a.size();
    }
    cout<<"\n";
}

void enq(int d){
    if(f==-1 && r==-1){
        f=r=c=0;
    }
    else if(f==(r+1)%a.size()){
        cout<<"Queue full\n";
        return;
    }
    else {
        r=(r+1)%a.size();
    }
    a[r]=d;
    c++;
    print();
}

void deq(){
    if(f==-1 && r==-1){
        cout<<"Queue Empty\n";
    }
    else if(f==r){
        f=r=-1;
    }
    else {
        f=(f+1)%a.size();
        c--;
        print();
    }
}

int main()
{
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
    enq(7);
    enq(9);
    enq(12);
    return 0;
}
