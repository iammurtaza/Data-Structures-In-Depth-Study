#include <iostream>
#include <algorithm>

using namespace std;

int a[100],n,x,start,last,mid,result;

int binsearch(){
    start=0;
    last=n-1;
    while(start<=last){
        mid=last + (start-last)/2; //Cool Shit. (start+last) might overflow.
        if(a[mid]==x)
            return mid;
        else if(x>a[mid])
            start=mid+1;
        else
            last=mid-1;
    }
    return -1;
}

int binsearchRecur2(int start, int last){
    if(start>last)
        return -1;
    mid=last + (start-last)/2;
    if(a[mid]==x)
        return mid;
    else if(x>a[mid])
        return binsearchRecur2(mid+1,last);
    else
        return binsearchRecur2(start, mid-1);
}

int binsearchFIRST_OCCURANCE_OF_ELEMENT(){
    start=0;
    last=n-1;
    while(start<=last){
        mid=last + (start-last)/2; //Cool Shit. (start+last) might overflow.
        if(a[mid]==x){
            while(a[mid]==x)
                mid--;
            mid++;
            return mid;
        }
        else if(x>a[mid])
            start=mid+1;
        else
            last=mid-1;
    }
    return -1;
}

int binsearchFIRST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH(){
    start=0;
    last=n-1;
    result=-1;
    while(start<=last){
        mid=last + (start-last)/2; //Cool Shit. (start+last) might overflow.
        if(a[mid]==x){
            result=mid;
            last=mid-1;
        }
        else if(x>a[mid])
            start=mid+1;
        else
            last=mid-1;
    }
    return result;
}

int binsearchLAST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH(){
    start=0;
    last=n-1;
    result=-1;
    while(start<=last){
        mid=last + (start-last)/2; //Cool Shit. (start+last) might overflow.
        if(a[mid]==x){
            result=mid;
            start=mid+1;
        }
        else if(x>a[mid])
            start=mid+1;
        else
            last=mid-1;
    }
    return result;
}

int binsearchCOUNT_SPECIFIC_ELEMENT(){
    int f=binsearchFIRST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH();
    int l=binsearchLAST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH();
    if(f==-1 && l==-1)
        return 0;
    else return l-f+1;
}

int binsearchFIRST_AND_LAST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH(bool choice){
    start=0;
    last=n-1;
    result=-1;
    while(start<=last){
        mid=last + (start-last)/2; //Cool Shit. (start+last) might overflow.
        if(a[mid]==x){
            result=mid;
            if(choice==true)
                last=mid-1;
            else
                start=mid+1;
        }
        else if(x>a[mid])
            start=mid+1;
        else
            last=mid-1;
    }
    return result;
}

int binsearchCOUNT_SPECIFIC_ELEMENT_BETTER_APPROACH(){
    int f=binsearchFIRST_AND_LAST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH(true);
    if(f!=-1){
        int l=binsearchFIRST_AND_LAST_OCCURANCE_OF_ELEMENT_OLOGN_APPROACH(false);
        return l-f+1;
    }
    else return 0;
}

int binsearchNUMBER_OF_ROTATION(){
    int start=0;
    int last=n-1;
    while(start<=last){
        mid=last + (start-last)/2;
        if(a[start]<a[last]) //Array is sorted.
            return start;
        int prev = (mid-1+n)%n;
        int next = (mid+1+n)%n;
        if(a[mid]<a[prev] && a[mid]<a[next])
            return mid;
        else if(a[mid]<a[last])
            last = mid - 1;
        else if(a[mid]>a[start])
            start = mid + 1;
    }
    return -1;
}

int binsearchSearch_element_in_a_circular_sorted_arr(){
    int start = 0;
    int last = n-1;
    while(start<=last){
        int mid=last + (start-last)/2;
        if(a[mid]==x)
            return 1;
        if(a[mid]<=a[last]){
            if(x>a[mid] && x<=a[last])
                start = mid + 1;
            else
                last = mid -1;
        }
        if(a[start]<=a[mid]){
            if(x>=a[start] && x<a[mid])
                last  = mid-1;
            else
                start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int i,j,temp;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cin>>x;

    /*int ret=binsearch();
    if(ret==-1)
        cout<<"Not in the list";
    else cout<<"Found at "<<ret;

    int ret2=binsearchRecur(0,n-1);
    if(ret2==-1)
        cout<<"Not in the list";
    else cout<<"Found at "<<ret2;

    int ret3=binsearchFIRST_OCCURANCE_OF_ELEMENT_2();
    if(ret3==-1)
        cout<<"Not in the list";
    else cout<<"Found at "<<ret3;

    int ret4=binsearchCOUNT_SPECIFIC_ELEMENT_BETTER_APPROACH();
    cout<<"No. of occurrences of "<<x<<" are "<<ret4;*/

    int k;
    cout<<"How many times do you want to rotate? ";
    cin>>k;

    for(j=0;j<k;j++){
        temp=a[n-1];
        for(i=n-1;i>0;i--)
            a[i]=a[i-1];
        a[0]=temp;
    }

    cout<<"New array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";

    //cout<<"Number of rotations is "<<binsearchNUMBER_OF_ROTATION();

    cout<<binsearchSearch_element_in_a_circular_sorted_arr();

    return 0;
}


