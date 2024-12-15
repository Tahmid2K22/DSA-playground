#include <iostream>
using namespace std;

class linked_list;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=nullptr;
    }
    Node(){
        next=nullptr;
    }
    friend  linked_list;
};


class linked_list{
    Node *head=nullptr;
public:
    linked_list(){

    }
    linked_list(int d){
        head=new Node(d);
    }


    void traverse(){
        Node *cur=head;
        while(cur!=nullptr){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<'\n';
    }
   

    Node* getHead(){return head;}
    void setHead(Node *n){head=n;}
};

Node* swap(linked_list &l){
    Node* head=l.getHead();
    Node  *cur=head;
    Node* prev;

    prev=cur->next;

    if(prev==nullptr) return head;
    cur->next=cur->next->next;
    prev->next=cur;
    head=prev;
    l.setHead(prev);
    cur=prev->next;

    while(cur->next!=nullptr && cur->next->next!=nullptr){
        prev=cur->next;
        cur->next=cur->next->next;
        prev->next=cur->next->next;
        cur->next->next=prev;
        cur=cur->next->next;
        if(cur==nullptr) break;
    }

    return head;
}




int main(){
    linked_list l;
    int size,data;
    Node *n;
    Node *cur;
    cout<<"Size: ";
    cin>>size;
    if(size>0){
        cin>>data;
        n=new Node(data);
        l.setHead(n);
        cur=l.getHead();
    } 

    for(int i=1;i<size;i++){
        cin>>data;
        n=new Node(data);
        cur->next=n;
        cur=cur->next;
        
    }
    swap(l);
    l.traverse();
    return 0;
}