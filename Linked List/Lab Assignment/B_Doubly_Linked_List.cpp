//Author: Tahmid Hossain Chowdhury Mahin 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
public:
    int data;
    Node *next,*prev;
    Node(int data){
        this->data=data;
        next=prev=nullptr;
    }
};





int main()
{
    Node *head=nullptr;
    Node *tail = nullptr;
    Node *n_node,*cur,*tmp;
    ll n;
    cin>>n;
    while(n--){
        string s;
        ll x;
        cin>>s;
        if(s=="insert"){
            cin>>x;
            n_node = new Node(x);
            if(head==nullptr){
                head=n_node;
                tail=head;
                continue;
            }
            n_node->next=head;
            head->prev=n_node;
            head=n_node;

        }
        else if(s=="delete"){
            cin>>x;
            if(head==nullptr) continue;
            cur=head;
            while(cur!=nullptr && cur->data!=x) cur=cur->next;
            if(cur==nullptr) continue;
            tmp=cur;
            if(cur->prev != nullptr) cur->prev->next = cur->next;
            else head = cur->next;
            if(cur->next != nullptr) cur->next->prev = cur->prev;
            else tail = cur->prev;
            delete cur;

        }else if(s=="deleteFirst"){
            if(head==nullptr) continue;
            tmp=head;
            head=head->next;
            if(head!=nullptr) head->prev=nullptr;
            else tail=nullptr;
            delete tmp;

        }else{
            if(tail==nullptr) continue;
            tmp=tail;
            tail=tail->prev;
            if (tail != nullptr) tail->next = nullptr;
            else head = nullptr;
            delete tmp;
        }

    }

    cur=head;
    while(cur!=nullptr){
        cout<<cur->data;
        if(cur->next!=nullptr) cout<<" ";
        cur=cur->next;
    }
    cout<<endl;
    
    
    
    return 0;
}