#include<bits/stdc++.h>
using namespace std;

// Class to create a doubly linked list node
class Node{
    public:
    string name; 
    int age;
    Node* next;
    Node* prev;
// Constructor 
    Node(string name, int age){
        this->name = name;
        this->age = age;
        next = NULL;
        prev = NULL;
    }
};
// Function for creating a node
Node* create(string *name, int *age, int members)
{
    Node* curr=NULL;
    Node* prev_ = NULL;
    Node* next_ = NULL;
    Node* head = NULL;
    for(int i=0;i<members;i++)
    {        
        curr = new Node(name[i],age[i]);        
// Checking if linked list is currently empty
	if(head==NULL)
        {
            head = curr;
        }
        curr->prev = prev_;
        if(prev_!=NULL)
        {
            prev_->next = curr;
        }
        prev_ = curr;
    }
    return head;
}
// Function to add the values of age and name to the current linked list head node
void add(Node* head, int age, string name)
{
    Node* nh = new Node(name, age);
    nh->next = head;
    head->prev = nh;
    head = nh;
}
// Printing the contents of linked list node
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->name<<" "<<head->age<<endl;
        head = head->next;
    }
}
// Main function
int main()
{
// Variable for number of family members
    int n;  
    cout<<"Enter number of members in family :- ";
    cin>>n;	
// Array for storing ages of family members
    int *age = new int[n];   
// Array for storing names of family members
    string *name = new string[n];
    cout<<"Enter name of family member along with their age"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of member:- ";
        cin>>name[i]>>age[i];
    }
    Node* head = create(name, age, n);
    print(head);
return 0;
}
