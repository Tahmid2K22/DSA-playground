//Author: Tahmid Hossain Chowdhury Mahin 
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next,*prev;
    Node(int data){
        this->data=data;
        next=prev=NULL;
    }
    ~Node(){
        delete next,prev;
    }
};

void forwardTraversal(Node *head){
    Node *cur=head;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur=cur->next;
    }
    cout << endl;
    return;
}

void backwardTraversal(Node *tail){
    Node *cur=tail;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur=cur->prev;
    }
    cout << endl;
    return;
}

void insertion(Node* &head,Node* &tail,int pos,int data){
    
    Node *cur=head;
    Node *newNode=new Node(data);
    if(pos==0){
        if(head==NULL){
            head=newNode;
            return;
        }
        newNode->next=cur;
        cur->prev=newNode;
        head=newNode;
        return;
    }
    int count=0;
    while(count<pos-1){
        if(cur==NULL){
            cout << "Out of Bound" << endl;
            delete cur;
            return ;
        }
        count++;
        cur=cur->next;
    }
    if(cur==NULL){
            cout << "Out of Bound" << endl;
            delete cur;
            return;
    }
    
    
    newNode->next=cur->next;
    newNode->prev=cur;
    if(cur->next!=NULL) (cur->next)->prev=newNode;
    cur->next=newNode;
    if(newNode->next==NULL) tail=newNode;
    
    return;
}


void deletion(Node* &head,Node* &tail,int pos){
    int count=0;
    Node* cur=head;
    while(count<pos){
        if(cur==NULL){
            cout << "Out of Bound" << endl;
            delete cur;
            return ;
        }
        cur=cur->next;
        count++;
    }
    if(cur==NULL){
        cout << "Out of Bound" << endl;
        delete cur;
        return ;
    }
    if(pos==0){
        head=cur->next;
        head->prev=NULL;
    }
    else if(cur->next==NULL){
        tail=cur->prev;
        tail->next=NULL;
    }
    else{
        (cur->prev)->next=cur->next;
        (cur->next)->prev=cur->prev;
    }
    
    return;
}

void  updatation(Node* &head,Node* &tail,int pos,int data){
    int count=0;
    Node* cur=head;
    while(count<pos){
        if(cur==NULL){
            cout << "Out of Bound" << endl;
            delete cur;
            return ;
        }
        cur=cur->next;
        count++;
    }
    if(cur==NULL){
        cout << "Out of Bound" << endl;
        delete cur;
        return ;
    }
    cur->data=data;
    
    return;
}

int main()
{
    Node *head=NULL;
    Node *tail;
    
    for(int i=0;i<6;i++){
        insertion(head,tail,i,i+1);
    }
    
    forwardTraversal(head);
    backwardTraversal(tail);
    
    deletion(head,tail,2);
    insertion(head,tail,2,23);
    
    forwardTraversal(head);
    backwardTraversal(tail);
    
    updatation(head,tail,2,512);
    
    forwardTraversal(head);
    backwardTraversal(tail);
    
    return 0;
}
