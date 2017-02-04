#include <iostream>
#include <array>

using namespace std;

array<int, 5> a={};
int f=-1,r=-1;

void print(){
    int f2=f,r2=r;
    while(f2<=r2){
        cout<<a[f2]<<" ";
        f2++;
    }
    cout<<"\n";
}

void enq(int d){
    if(f==-1 && r==-1){
        f=r=0;
    }
    else if(r==a.size()-1){
        cout<<"Queue full\n";
        return;
    }
    else {
        r++;
    }
    a[r]=d;
    print();
}

void deq(){
    if(f==-1 && r==-1){
        cout<<"Queue Empty\n";
    }
    else if(f==r){
        f=r=-1;
    }
    else{
        f++;
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
