#include "custom_linked_list.h"
using namespace std;

int main(){
    linked_list<int> l1,l2,l3;
    int data;
    for(int i=0;i<4;i++){
        cin>>data;
        l1.insertion(i,data);
    }
    for(int i=0;i<4;i++){
        cin>>data;
        l2.insertion(i,data);
    }
    l3=l1+l2;
    l3.traverse();

}