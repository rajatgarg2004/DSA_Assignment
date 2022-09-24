#include<bits/stdc++.h>
using namespace std;
class Node{
    public:

    string name;
    int age;
    Node* next;
    Node* prev;

    Node(string name, int age){
        this->name = name;
        this->age = age;
        next = NULL;
        prev = NULL;
    }
};

Node* create(string *name, int *age, int members)
{
    Node* curr=NULL;
    Node* prev_ = NULL;
    Node* next_ = NULL;
    Node* head = NULL;
    for(int i=0;i<members;i++)
    {
        
        curr = new Node(name[i],age[i]);
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

void add(Node* head, int age, string name)
{
    Node* nh = new Node(name, age);
    nh->next = head;
    head->prev = nh;
    head = nh;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->name<<" "<<head->age<<endl;
        head = head->next;
    }
}




int main()
{
    int n;
    cout<<"Enter number of members in family: ";
    cin>>n;

    int *age = new int[n];
    string *name = new string[n];

    cout<<"Enter name of family members with their ages"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of member :";
        cin>>name[i]>>age[i];
    }
    Node* head = create(name, age, n);
    print(head);
return 0;
}
