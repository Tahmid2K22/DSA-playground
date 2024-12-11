#ifndef CUSTOM_LINKED_LIST_H_INCLUDED
#define CUSTOM_LINKED_LIST_H_INCLUDED

#include <iostream>
using namespace std;

template <class T = int>
class linked_list;

template<class T=int>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data=data;
        next=nullptr;
    }
    Node(){
        next=nullptr;
    }
    friend  linked_list<T>;
};

template<class T>
class linked_list{
    Node<T> *head=nullptr;
    int total_size;
public:
    linked_list(){
        total_size=0;
    }

    linked_list(Node<T>* head){
        this->head=head;
        total_size=1;
    }
    linked_list(T d){
        head=new Node<T>(d);
        total_size=1;
    }

    void insertion(int pos,T val){
				if (pos < 0 || pos > total_size) {
        	cout << "Invalid position for insertion\n";
        	return;
    		}
        Node<T> *n = new Node<T>(val);
        if (pos < 0 || (pos > 0 && head == nullptr)) {
            cout << "Out of bounds\n";
            delete n;
            return;
        }
        if(head==nullptr){
            head=n;
            total_size++;
            return;
        }
        if(pos==0){
            n->next=head;
            head=n;
            total_size++;
            return;
        }
        Node<T> *cur=head;
        int count=0;
        while(count<pos-1){
            cur=cur->next;
            count++;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                delete n;
                return;
            }
        }
        if(cur==nullptr){
                cout<<"Out of bound\n";
                delete n;
                return;
        }
        n->next=cur->next;
        cur->next=n;
        total_size++;
        return;
    }

    void deletion(int pos){
        if(head==nullptr){
            cout<<"The list is empty\n";
            return;
        }
        if(pos < 0 || pos >= total_size){
            cout<<"Out of bound\n";
        }
        if (pos == 0) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
	    total_size--;
            return;
        }
        Node<T> *cur=head;
        int count=0;
        while(count<pos-1){
            cur=cur->next;
            count++;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        if(cur==nullptr){
            cout<<"Out of bound\n";
            return;
        }
        Node<T> *tmp=cur->next;
        cur->next=cur->next->next;
        total_size--;
        delete tmp;
        return;

    }

    void update(int pos,T val){
        if(head==nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node<T> *cur=head;
        int count=0;
        while(count<pos){
            cur=cur->next;
            count++;
            if(cur==nullptr){
                cout<<"Out of bound\n";
                return;
            }
        }
        if(cur==nullptr){
            cout<<"Out of bound\n";
            return;
        }
        cur->data=val;
        return;
    }

    void Bubble_sort(){
        for(int i=0;i<total_size-1;i++){
            Node<T> *cur=head;
            for(int j=0;j<total_size-i-1;j++){
                if(cur && cur->next && cur->data > cur->next->data) swap(cur->data , cur->next->data);
                cur=cur->next;
            }
        }
    }

    int size(){
        return total_size;
    }

    void traverse(){
        Node<T> *cur=head;
        while(cur!=nullptr){
            cout<<(cur->data)<<" ";
            cur=cur->next;
        }
        cout<<'\n';
    }

    ~linked_list() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

};

#endif // CUSTOM_LINKED_LIST_H_INCLUDED
