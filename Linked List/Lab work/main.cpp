#include "custom_linked_list.h"
using namespace std;


int main()
{
    linked_list<int>l1,l2;
    for(int i=0;i<5;i++){
        int data;
        cin>>data;
        l1.insertion(i,data);
    }
    for(int i=1;i<=10;i+=2){
        int data;
        cin>>data;
        l1.insertion(i,data);
    }
    l1.traverse();
    return 0;
}
