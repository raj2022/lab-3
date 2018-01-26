#include <iostream>
using namespace std;

//Construction of node
struct node{
int data;
node *prev;
node *next;
};

class linkedList{
private:
node *head,*tail;
public:
linkedList(){
head = NULL;
tail = NULL;
}

//Adds a new element to the end of the linked list
void insert(int n){
node *temp = new node;
temp->data = n;
if(head==NULL){
head = temp;
tail = temp;
temp->next = NULL;
temp->prev = NULL;
}
else {
tail->next = temp;
temp->prev = tail;
temp->next = NULL;
tail = temp;
}
}


// Adds a new element to the end of the linked list
void insertAt(int pos1, int n2){
int count=1;
node *curr=new node;
node *pr=new node;
node *temp=new node;
temp->data=n2;
temp->prev=NULL;
temp->next=NULL;
curr=head;
if(count>pos1){
while(count!=pos1){
pr=curr;
curr=curr->next;
curr->prev=pr;
count++;
}
temp->next=curr;
temp->prev=pr;
pr->next=temp;
curr->prev=temp;
}
else if(count<pos1) {
cout<<"The node does not exist "<<endl;
}
}

// Deletes the element at the end of the list
void deletenode() {
//If the linked list is empty
if (head==NULL){
cout<<"The list is empty"<<"\n";
}
else if(head==tail){
delete head;
head=NULL;
tail=NULL;
}

else {
node *temp,*cur;
temp=head;
cur=head->next;
cur->prev=head;
head=head->next;
delete temp;
head->prev=NULL;
}
}

// Deletes the element at the position
void deleteAt (int pos2){
int count=1;
node *temp=new node;
node *curr=new node;
node *pr=new node;
curr=head;
while(count!=pos2){
pr=curr;
curr=curr->next;
curr->prev=pr;
count++;
}
temp=curr->next;
pr->next=temp;
temp->prev=pr;
delete curr;
}
// Returns the number of items in the linked list
int countitem(){
node *temp;
temp=head;
int length=0;
if (head==NULL){
cout<<"The list is empty"<<"\n";
}
else if(head!=NULL){
while(temp!=NULL) {
length++;
temp=temp->next;
}
cout<<"The number of elements in the linkedlist are : "<<length<<"\n";
}
return length;
}
// Displays all the elements in the linked list
void display(){
node *temp;
temp=head;
cout<<"The elements of the linked list are : "<<"\n";
while(temp!=NULL){
cout<<temp->data<<"->";
temp=temp->next;
}
cout<<"NULL"<<"\n";
}


}; 

//Main function for the programme
int main() {
int n2,pos1,pos2;
linkedList l;
l.insert(1);
l.insert(2);
l.insert(3);
l.insert(4);
l.insert(5);
l.display();
l.countitem();
cin>>pos1>>n2;
l.insertAt(pos1,n2);
cout<<"After the insertion of the node at "<<pos1<<" with the value of "<<n2<<" : "<<endl;
l.display();
l.deletenode();
cout<<"After the deletion of the node at the end : "<<endl;
l.display();
cin>>pos2;
l.deleteAt(pos2);
cout<<"After the deletion of the node at "<<pos2<<" : "<<endl;
l.display();
return 0;
}
