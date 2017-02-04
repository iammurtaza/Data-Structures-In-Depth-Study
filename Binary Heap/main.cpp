#include <iostream>

using namespace std;
int a[10],p=-1,n;

void insrt(int x){
    p++;
    a[p]=x;
    int temp=p;

    while(temp>0 && a[temp]<a[(temp-1)/2]){
        swap(a[temp],a[(temp-1)/2]);
        temp=(temp-1)/2;
    }
}

void dcrsky(int i, int nwvl){
    a[i]=nwvl;
    int temp=i;

    while(temp>0 && a[temp]<a[(temp-1)/2]){
        swap(a[temp],a[(temp-1)/2]);
        temp=(temp-1)/2;
    }
}

void min_heapify(int i){
    int l=2*i+1;
    int r=2*i+2;
    int smllst=i;
    if(l<n && a[l]<a[i])
        smllst=l;
    if(r<n && a[r]<a[smllst])
        smllst=r;
    if(smllst!=i){
        swap(a[i],a[smllst]);
        min_heapify(smllst);
    }
}

void extract_min(){
    a[0]=a[n-1];
    n--;
    min_heapify(0);
}

void dltps(int i){
    dcrsky(i, INT_MIN);
    extract_min();
}

void print(){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{   int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insrt(x);
    }
    print();
    dcrsky(8,0);
    print();
    dltps(7);
    print();
    return 0;
}
