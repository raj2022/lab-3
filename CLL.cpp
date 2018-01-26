#include <iostream>
using namespace std;

//Construction of node
struct node{
int data;
node *next;
};

class linkedList{
private:
node *head, *tail;
public:
linkedList(){
head=NULL;
tail=NULL;
}

//Adds a new element to the end of the linked list
void insert (int n){
node *temp=new node;
temp->data=n;
temp->next=NULL;
if(head==NULL){
head=temp;
}
else {
tail->next=temp;
}
tail=temp;
tail->next=head;
}

//inserts 3 at the first position
void insertAt(int pos1, int n1){
node *curr,*prev;
node *temp=new node;
temp->data=n1;
temp->next=NULL;
curr=head;
prev=curr;
for(int i=1; i<pos1; i++){
prev=curr;
curr=curr->next;
}
prev->next=temp;
temp->next=curr;
}

//Deletes the element at the end of the list
void deletenode(){
node*curr=new node;
node*prev=new node;
curr=head;
while(curr->next!=head){
prev=curr;
curr=curr->next;
}
tail=prev;
prev->next=head;
delete curr;
}

// Deletes the element(or node) at the position
void deleteAt(int pos2){
node *curr=new node;
node *prev=new node;
node *temp=new node;
curr=head;
for(int i=1; i<pos2; i++){
prev=curr;
curr=curr->next;
temp=curr->next;
}
prev->next=temp;
delete curr;
}

//Returns the number of items in the linked list
int countitem(){
int length=0;
node *temp;
temp=head;
if(head==NULL){
cout<<"The linked list is empty "<<endl;
}
else{
do
{
length++;
temp=temp->next;
}
while(temp!=head);
cout<<"The number of elements in the linked list is : "<<length<<endl;
return length;
}
}
// Displays all the elements in the linked list
void display(){
node *temp= new node;
temp=head;
cout<<"The elements of the linked list is: "<<endl;
do 
{
cout<<temp->data<<"->";
temp=temp->next;
}
while(temp!=head);
cout<<" head"<<endl;
}

};	

int main(){
int n1,pos1,pos2;
linkedList l;
l.insert(1);
l.insert(2);
l.insert(3);
l.insert(4);
l.insert(5);
l.display();
l.countitem();
cin>>pos1>>n1;
l.insertAt(pos1,n1);
cout<<"The linked list after insertion of the value "<<n1<<" in the "<<pos1<<" position :"<<endl;
l.display();
l.deletenode();
cout<<"The linked list after deletion of the node from one end "<<endl;
l.display();
cin>>pos2;
l.deleteAt(pos2);<<"The linked list after deletion of the node at "<<pos2<<" is :"<<endl;
l.display();
return 0;
}

