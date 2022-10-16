#include <iostream>
using namespace std;
//using linked list for the code
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void display(Node *head){
    Node *temp = head;
    while(temp -> next != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << temp -> data << endl;
}

int linear_search(Node *head, int x){
    int i = 0;
    Node * temp = head;
    while(temp != NULL){
        if(temp -> data == x){
            return i;
        }
        else{
            temp = temp -> next;
            i = i + 1;
        }
    }
    return -1;
}

Node *midPoint(Node *head, Node *tail){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head-> next;
    while(fast != tail){
        fast = fast -> next;
        if(fast != tail){
            slow = slow -> next;
            fast = fast -> next;
        }
    }    
    return slow; 
}

Node* binary_search(Node *head, int value){
    Node *start = head;
    Node *tail = NULL;
    do{
        Node* mid = midPoint(start, tail);

        if(mid == NULL){
            return NULL;
        }

        if(mid -> data == value){
            return mid;
        }

        else if(mid -> data < value){
            start = mid -> next;

        }

        else{
            tail = mid;
        }
        
    }
    while(tail == NULL || tail != start);

    return NULL;
}

int main(){
    int mid, value;
    Node *head = takeinput();
    display(head);
    cout << "Enter the element that you want to find:- "<< endl;
    cin >> value;

    cout <<"Linear Search:- "<< linear_search(head, value) << endl;
    if(binary_search(head, value)== NULL){
        cout<< "value is not present" << endl;
    }
    else{
        cout << "value is present"<< endl;
    }
}
