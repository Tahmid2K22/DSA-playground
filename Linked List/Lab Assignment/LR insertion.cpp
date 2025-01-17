//Author:Tahmid Hossain Chowdhury Mahin
#include <iostream>

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int n){
        data=n;
        next=nullptr;
        prev=nullptr;
    }
};


using namespace std;

int main()
{
    Node *n=new Node(0);
    Node *nn;
    Node *head=n;
    Node *cur=n;
    int si;
    cin>>si;
    string s;
    cin>>s;
    for(int i=0;i<si;i++){
        if(s[i]=='L'){
            nn=new Node(i+1);
            nn->next=cur;
            nn->prev=cur->prev;
            if(cur->prev!=nullptr) cur->prev->next=nn;
            cur->prev=nn;
            if(cur==head) head=cur->prev;
            cur=cur->prev;

        }else{
            nn=new Node(i+1);
            nn->next=cur->next;
            nn->prev=cur;
            if(cur->next!=nullptr) cur->next->prev=nn;
            cur->next=nn;
            cur=cur->next;
        }

    }
    cur=head;
    while(cur!=nullptr){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    return 0;
}
