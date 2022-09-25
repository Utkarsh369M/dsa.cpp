#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    ~Node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
};

int insertpos(Node* &tail,int data,int element)
{
    if(tail==NULL)
    {
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }
    else
    {
        Node* curr = tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        Node* temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void deletion(Node* &tail,int element)
{
    if(tail==NULL)
    {
        return;
    }
    Node* prev=tail;
    Node* curr=prev->next;
    while(curr->data!=element)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    if(prev==curr)
    {
        tail=NULL;
    }
    if(tail==curr)
    {
        tail=prev;
    }
    curr->next=NULL;
    delete curr;
}
void print(Node* &tail)
{
    Node* temp= tail;
    if(tail==NULL)
    {
        cout<<"empty"<<" ";
    }
    do
    {
       cout<<tail->data<<" ";
       tail=tail->next; 
    } while (tail!=temp);
    cout<<endl;
}

int main()
{
    Node* tail=NULL;
    insertpos(tail,5,13);
    print(tail);
    insertpos(tail,23,5);
    print(tail);
    insertpos(tail,22,23);
    print(tail);
    deletion(tail,23);
    print(tail);
    cout<<tail->data<<" ";
}