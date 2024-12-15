#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data):data(data),next(nullptr){}
};


void traverse(Node* head) {
    if (!head) {
        cout << "Empty" << endl;
        return;
    }
    Node* current = head;
    while (current ) {
        cout << current->data << " ";
        current = current->next;   
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int data;
    cin >> data;
    Node *newNode=new Node(data);
    Node *head=newNode;
    Node *cur=head;
    for(int i=1;i<n;i++){
        cin >> data;
        Node *newNode=new Node(data);
        cur->next=newNode;
        cur=cur->next;
    }
    cur=head;
    
    while(cur && cur->next && cur->data==cur->next->data ){
        cur=cur->next;
        head=cur;
    }
    
    while(cur->next && cur->next->next){
        if(cur->next->data == cur->next->next->data){
            cur->next = cur->next->next;
            continue;
        }
        cur=cur->next;
    }
    
    traverse(head);
    return 0;
}
