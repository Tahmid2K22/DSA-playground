#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int d):data(d),next(nullptr){}
};

void solve(){
    int n,m,d,c=0;
    cin>>n>>m;
    string s;
    Node *head=nullptr;
    Node *tail=nullptr,*n_node,*cur;
    while(m--){
        cin>>s;
        if(s=="pushLeft"){
            cin>>d;
            if(c>=n){
                cout<<"The queue is full\n";
                continue;
            }
            n_node = new Node(d);
            if(head==nullptr){
                head=n_node;
                tail=head;
                cout<<"Pushed in left: "<<d<<endl;
                c++;
                continue;
            }

            n_node->next=head;
            head=n_node;
            cout<<"Pushed in left: "<<d<<endl;
            c++;

        }else if(s=="pushRight"){
            cin>>d;
            if(c>=n){
                cout<<"The queue is full\n";
                continue;
            }
            n_node = new Node(d);

            if(tail==nullptr){
                tail=n_node;
                head=tail;
                cout<<"Pushed in right: "<<d<<endl;
                c++;
                continue;;
            }
      
            tail->next=n_node;
            tail=n_node;
            cout<<"Pushed in right: "<<d<<endl;
            c++;
            
        }else if(s=="popLeft"){
            if(head==nullptr){
                cout<<"The queue is empty\n";
                continue;
            }
            Node *tmp=head;
            if(head->next==nullptr){
                cout<<"Popped from left: "<<tmp->data<<endl;
                c--;
                delete tmp;
                head=nullptr;
                tail=nullptr;
                continue;
            }
            head=head->next;
            cout<<"Popped from left: "<<tmp->data<<endl;

            c--;
            delete tmp;

        }else{
            if(tail==nullptr){
                cout<<"The queue is empty\n";
                continue;
            }
            cur=head;
            if(head==tail){
                Node *tmp=tail;
                cout<<"Popped from right: "<<cur->data<<endl;
                c--;
                head=nullptr;
                tail=nullptr;
                continue;
            }
            while(cur->next!=tail) cur=cur->next;
            Node *tmp=tail;
            cur->next=nullptr;
            tail=cur;
            cout<<"Popped from right: "<<tmp->data<<endl;
            c--;
            delete tmp;

        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        cout << "Case " << it << ":\n";
        solve();
    }
}