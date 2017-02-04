#include <iostream>
#include <stack>
using namespace std;

struct list {
	int data;
	list *next;
}*start=NULL;

int count() {
	if(start==NULL) {
		return 0;
	}
	else {
	int i=0;
	list *temp=start;
	while(temp!=NULL) {
		temp=temp->next;
		i++;
	}
	return i;
	}
}

void show() {
  if(start!=NULL) {
  list *temp=start;
  while(temp!=NULL) {
   cout<<temp->data<<" ";
   temp=temp->next;
  }
  }
  else cout<<"List is empty. Fill the list first";
}

void ibeg(int value) {
  list *temp = new list();
  temp->data=value;
  temp->next=start;
  start=temp;
}

void iend(int value) {
	list *temp2 = new list();
	temp2->data=value;
	temp2->next=NULL;
	if(start!=NULL) {
	list *temp=start;
    while(temp->next!=NULL)
     temp=temp->next;
    temp->next=temp2;
    }
    else start=temp2;
}

void isp(int value, int pos) {
	if(pos==0)
	ibeg(value);
	else {
	list *temp3 = new list();
	temp3->data=value;
	temp3->next=NULL;
	list *temp=start;
	for(int i=1;i<pos;i++)
       temp=temp->next;
    temp3->next=temp->next;
	temp->next=temp3;
    }
}

void dbeg() {
   if(start!=NULL) {
   list *temp=start;
   temp=temp->next;
   start=temp;
   }
   else start=NULL;
}

void dend() {
    if(count()!=1) {
	list *temp=start;
	while(temp->next->next!=NULL)
	temp=temp->next;
	temp->next=NULL;
    }
    else start=NULL;
}

void dsp(int pos) {
	if(pos==0)
	dbeg();
	else {
	list *temp=start;
	for(int i=1;i<pos;i++)
	temp=temp->next;
	list *temp2 = temp->next;     //can also be done by temp->next=temp->next->next; but then we can't free memory
	temp->next = temp2->next;
	delete temp2;
    }
}

void irev() {
	list *prev,*current,*next;
	prev=NULL;
	current=start;
	while(current!=NULL) {
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	start=prev;
}

void prrev(list *head) {
   if(head==NULL) {
   	return;
   }
   prrev(head->next);
   cout<<head->data<<" ";
}

void rrev(list *temp1) {
	if(temp1->next==NULL) {
		start=temp1;
		return;
	}
	rrev(temp1->next);
	list *temp2 = temp1->next;     //if no temp2 is declared then temp1->next->next = temp1;
	temp2->next = temp1;
	temp1->next = NULL;
}

void srevDATA(){
    stack<int> S;
    list *start2 = start;
    while(start2!=NULL){
        S.push(start2->data);
        start2=start2->next;
    }
    start2= start;
    while(start2!=NULL){
        start2->data=S.top();
        S.pop();
        start2=start2->next;
    }
}

void srevADDRESS(){
    stack<list *> S;
    list *start2 = start;
    while(start2!=NULL){
        S.push(start2);
        start2=start2->next;
    }
    start2 = S.top();
    start = start2;
    S.pop();
    while(!S.empty()){
        start2->next=S.top();
        S.pop();
        start2 = start2->next;
    }
    start2->next=NULL;
}

int main(int argc, char** argv) {
	int c=10;
	while(c!=0) {
	cout<<"\n\n MENU  \n\n";
	cout<<"1. Insert\n";
	cout<<"2. Delete\n";
	cout<<"3. Reverse\n";
	cout<<"4. Print\n";
	cout<<"5. Count\n\n";
    cout<<"Enter your option(0 to exit): ";
    cin>>c;
    cout<<"\n\n";
    switch(c) {
    	case 1 : int c1,value,pos1,pos2;
		         cout<<"  Enter sub category \n\n";
    	         cout<<"  1. Beginning\n";
    	         cout<<"  2. End\n";
    	         cout<<"  3. Before specific position\n";
    	         cout<<"  4. After specific position\n\n";
    	         cout<<"  Enter your option: ";
    	         cin>>c1;
    	         switch(c1) {
    	         	case 1 : cout<<"  Enter data: ";
					         cin>>value;
					         ibeg(value);
					         cout<<"\n"<<"Now list is : ";
							 show();
					         break;
    	         	case 2 : cout<<"  Enter data: ";
    	         	         cin>>value;
    	         	         iend(value);
    	         	         cout<<"\n"<<"Now list is : ";
							 show();
    	         	         break;
    	         	case 3 : cout<<"  Enter data: ";
    	         	         cin>>value;
							 cout<<"  Enter position: ";
							 cin>>pos1;
							 if(pos1>0&&pos1<=count()) {
							 isp(value, pos1-1);
							 cout<<"\n"<<"Now list is : ";
							 show();
						     }
							 else cout<<"\nInvalid position. Current size of list is "<<count();
							 break;
					case 4 : cout<<"  Enter data: ";
    	         	         cin>>value;
							 cout<<"  Enter position: ";
							 cin>>pos2;
							 if(pos2>0&&pos2<=count()) {
							 isp(value, pos2);
							 cout<<"\n"<<"Now list is : ";
							 show();
						     }
							 else cout<<"\nInvalid position. Current size of list is "<<count();
							 break;
					default : cout<<"Invalid Choice \n";
				 }
				 break;
    	case 2 : int c2,pos3;
	           	 cout<<"  Enter sub category \n\n";
    	         cout<<"  1. Beginning\n";
    	         cout<<"  2. End\n";
    	         cout<<"  3. Specific position\n\n";
    	         cout<<"  Enter your option: ";
    	         cin>>c2;
    	         switch(c2) {
    	         	case 1 : dbeg();
    	                     cout<<"\n"<<"Now list is : ";
							 show();
					         break;
    	         	case 2 : dend();
    	         	         cout<<"\n"<<"Now list is : ";
							 show();
    	         	         break;
    	         	case 3 : cout<<"  Enter position: ";
							 cin>>pos3;
							 if(pos3>0&&pos3<=count()) {
							 dsp(pos3-1);
						     cout<<"\n"<<"Now list is : ";
							 show();
							 }
							 else cout<<"\nInvalid position. Current size of list is "<<count();
							 break;
					default : cout<<"Invalid Choice \n";
				 }
				 break;
		case 3 : int c3;
	           	 cout<<"  Enter sub category \n\n";
    	         cout<<"  1. Only print using recursion\n";
    	         cout<<"  2. Reverse using recursion\n";
    	         cout<<"  3. Reverse using iterative method\n";
    	         cout<<"  4. Reverse using stacks\n\n";
    	         cout<<"  Enter your option: ";
    	         cin>>c3;
    	         switch(c3) {
    	         	case 1 : if(count()>1) {
					         cout<<"\nReverse order of list is : ";
					         prrev(start);
					         }
					         else cout<<"\nNothing to reverse. Atleast have 2 or more items";
    	         	         break;
    	         	case 2 : if(count()>1) {
    	         		     rrev(start);
    	         	         cout<<"\n"<<"Now list is : ";
							 show();
					         }
					         else cout<<"\nNothing to reverse. Atleast have 2 or more items";
					         break;
					case 3 : if(count()>1) {
					         irev();
					         cout<<"\n"<<"Now list is : ";
							 show();
						     }
						     else cout<<"\nNothing to reverse. Atleast have 2 or more items";
							 break;
					case 4 : if(count()>1) {
                                //srevDATA();
                                srevADDRESS();
                                cout<<"\n"<<"Now list is : ";
                                show();
							 }
						     else
                                cout<<"\nNothing to reverse. Atleast have 2 or more items";
							 break;
					default : cout<<"Invalid Choice \n";
				 }
		         break;
	    case 4 : show();
		         break;
		case 5 : cout<<"\n"<<count();
		         break;
		default : cout<<"Invalid Choice \n";
	}
    }
	return 0;
}
