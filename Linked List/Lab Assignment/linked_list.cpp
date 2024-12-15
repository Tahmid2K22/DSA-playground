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

    void insert_at_first(int d){
        Node *n=new Node(d);
        if(head==nullptr){
            head=n;
            return;
        }
        n->next=head;
        head=n;
        return;
    }

    void insert_at_end(int d){
        Node *cur=head;
        Node *n=new Node(d);
        if(head==nullptr){
            head=n;
            return;
        }
        while(cur->next!=nullptr){
            cur=cur->next;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                delete n;
                return;
            }
        }
        cur->next=n;
    }

    // void insert_at_pos(int pos,int d){
    //     Node *cur=head;
    //     int count=0;
    //     while(count<pos-1){
    //         cur=cur->next;
    //         count++;
    //         if(cur==nullptr){
    //             cout<<"Out of bound\n";
    //             return;
    //         }
    //     }
    //     if(cur==nullptr){
    //             cout<<"Out of bound\n";
    //             return;
    //     }
    //     Node *n=new Node(d);
    //     n->next=cur->next;
    //     cur->next=n;
    //     return;
    // }

    void insert_before_value(int val,int d){
        Node *cur=head;
        while(cur->next->data!=val){
            cur=cur->next;
            if(cur->next==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        Node *n=new Node(d);
        n->next=cur->next;
        cur->next=n;
        return;
    }

    void insert_after_value(int val,int d){
        Node *cur=head;
        while(cur->data!=val){
            cur=cur->next;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        Node *n=new Node(d);
        n->next=cur->next;
        cur->next=n;
        return;
    }

    void delete_at_first(){
        if(head==nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node *tmp=head;
        head=head->next;
        delete tmp;
    }

    void delete_at_last(){
        if(head==nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node *cur=head;
        while(cur->next->next!=nullptr){
            cur=cur->next;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        Node *tmp=cur->next;
        cur->next=nullptr;
        delete tmp;
    }

    void delete_before_value(int val){
        if(head==nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node *cur=head;
        while(cur->next->next->data!=val){
            cur=cur->next;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
        }
        Node *tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
    }

    void delete_after_value(int val){
        if(head==nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node *cur=head;
        while(cur->data!=val){
            cur=cur->next;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        Node *tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
    }

    Node* getHead(){return head;}
    void setHead(Node *n){head=n;}
};





int main(){
    linked_list l;
    int size,data;
    cout<<"Size: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>data;
        l.insert_at_end(data);
    }
    int x,y;
    cout<<"Delete After value: ";
    cin>>x;
    l.delete_after_value(x);
    l.traverse();

    cout<<"Delete before value: ";
    cin>>x;
    l.delete_before_value(x);
    l.traverse();

    cout<<"insert after value: ";
    cin>>x;
    cout<<"Data value: ";
    cin>>y;
    l.insert_after_value(x,y);
    l.traverse();

    cout<<"insert before value: ";
    cin>>x;
    cout<<"Data value: ";
    cin>>y;
    l.insert_before_value(x,y);
    l.traverse();
    return 0;
}