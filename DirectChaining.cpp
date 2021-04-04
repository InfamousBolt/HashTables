#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    int key;
    struct node* next;
};

struct hashIndexList{
    struct node* head;
    struct node* tail;
};

struct hashIndexList* arr;
int size=0;
int max_cap=10;

void insert(int key, int value){
    int index=key%max_cap;
    struct node* list=(struct node*) arr[index].head;
    struct node* item;
    item=(struct node*)malloc(sizeof(struct node));
    item->data=value;
    item->key=key;
    item->next=NULL;

    if(list==NULL){
        arr[index].head=item;
        arr[index].tail=item;
    }else{
        item->next=arr[index].head;
        arr[index].head=item;
    }
    size++;
}

int searchElement(int key){
    int index=key%max_cap;
    struct node* list=arr[index].head;
    int flag=0;
    while(list!=NULL){
        if(list->key==key){
            flag=1;
            break;
        }
    }
    if(flag==1)
        return 1;
    return 0;
}

void display(){
    for(int i=0;i<max_cap;i++){
        struct node* temp=arr[i].head;
        if(temp==NULL){
            cout<<"No element at arr["<<i<<"]"<<endl;
        }else{
            cout<<"Elements at arr["<<i<<"] :"<<endl;
            while(temp!=NULL){
                cout<<" Key: "<<temp->key<<" Value: "<<temp->data;
                temp=temp->next;
            }
        }
    }
}

void initializeTable(){
    for(int i=0;i<max_cap;i++){
        arr[i].head=NULL;
        arr[i].tail=NULL;
    }
}

int main(){
    arr=(struct hashIndexList*)malloc(sizeof(struct hashIndexList)*max_cap);
    initializeTable();
    int key,value;
    for(int i=0;i<10;i++){
        cin>>key>>value;
        insert(key,value);
    }
    display();
    cout<<"\n";
    cout<<searchElement(5000);
}