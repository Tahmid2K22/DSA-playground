#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    char data;
    Node *next;
    Node(char d):data(d),next(nullptr){}
    Node():next(nullptr){}
};

void solve(){
    string s;
    // getline(cin, s);
    cin >> s;
    Node *head=nullptr,*n_node;
    for(auto it:s){
        if(it=='(' || it=='['){
            n_node = new Node(it);
            n_node->next=head;
            head=n_node;
        }else{
            if(it==')'){
                if(head==nullptr || head->data=='['){
                    cout<<"No\n";
                    return;
                }
                Node *tmp=head;
                head=head->next;
                delete tmp;
            }else if(it==']'){
                if(head==nullptr || head->data=='('){
                    cout<<"No\n";
                    return;
                }
                Node *tmp=head;
                head=head->next;
                delete tmp;
            }
        }
    }
    if(head==nullptr){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return;
}

int main(){
    int t;
    cin >> t;
    // cin.ignore();
    for(int it=1;it<=t;it++) {
        //cout << "Case " << it << ":\n";
        solve();
    }
}