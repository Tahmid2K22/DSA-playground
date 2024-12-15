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





int main(){
    linked_list l1;
    int size,data,total_size=0;
    Node *n;
    Node *cur;
    cout<<"First list size: ";
    cin>>size;
    total_size+=size;
    if(size>0){
        cin>>data;
        n=new Node(data);
        l1.setHead(n);
        cur=l1.getHead();
    } 

    for(int i=1;i<size;i++){
        cin>>data;
        n=new Node(data);
        cur->next=n;
        cur=cur->next;
    }
    

    cout<<"Second list size: ";
    cin>>size;
    total_size+=size;

    for(int i=0;i<size;i++){
        cin>>data;
        n=new Node(data);
        cur->next=n;
        cur=cur->next;
    }
    cout<<total_size<<endl;
    for(int i=0;i<total_size-1;i++){
        cur=l1.getHead();
        for(int j=0;j<total_size-i-1;j++){
            if(cur!=nullptr && cur->next!=nullptr && cur->data > cur->next->data) swap(cur->data , cur->next->data);
            cur=cur->next;
        }
    }

    l1.traverse();
    return 0;
}