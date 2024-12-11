#include <iostream>
using namespace std;

struct CT_marks{
    int roll,mark;
    CT_marks* next=nullptr;
    CT_marks(int r,int m):roll(r),mark(m){}
    CT_marks() : roll(0), mark(0) {}
};

void Bubble_sort(CT_marks* head){
        CT_marks *cur=head;
        int total_size=0;
        while(cur!=nullptr){
            total_size++;
            cur=cur->next;
        }
        for(int i=0;i<total_size-1;i++){
             cur=head;
            for(int j=0;j<total_size-i-1;j++){
                if(cur && cur->next && cur->mark > cur->next->mark) swap(cur->mark , cur->next->mark);
                cur=cur->next;
            }
        }
    }


void insertion(CT_marks *head,int pos,int r,int m){

    CT_marks *n = new CT_marks(r,m);
    if (pos < 0 || (pos > 0 && head == nullptr)) {
        cout << "Out of bounds\n";
        delete n;
        return;
    }

    if(pos==0){
        n->next=head;
        head=n;
        return;
    }
    CT_marks *cur=head;
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
    Bubble_sort(head);
    return;
}

void traverse(CT_marks *head){
        CT_marks *cur=head;
        while(cur!=nullptr){
            cout<<"Roll: "<<cur->roll<<" Marks: "<<cur->mark<<"\n";
            cur=cur->next;
        }
        cout<<'\n';
    }



int main()
{
    CT_marks *head=new CT_marks(1,20);
    for(int i=1;i<10;i++) insertion(head,i,i,20-i);
    insertion(head,10,100,0);
    insertion(head,11,22,100);
    traverse(head);

    return 0;
}
