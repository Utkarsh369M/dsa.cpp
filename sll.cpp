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

void inserthead(Node* &head,int data)
{
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void inserttail(Node* &tail,int data)
{
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void insertposition(Node* &head,Node* &tail,int data,int pos)
{
    if(pos==1)
    {
        inserthead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        inserttail(tail,data);
        return;
    }
    Node* curr=new Node(data);
    curr->next=temp->next;
    temp->next=curr;
    return;
}

void deletion(Node* &head,Node* &tail,int pos)
{
    Node* temp=head;
    Node* prev=NULL;
    if(pos==1)
    {
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        int cnt=1;
        while(cnt<pos)
        {
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL)
        {
            tail=prev;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}

void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* n1=new Node(10);
    Node* head=n1;
    Node* tail=n1;
    inserthead(head,8);
    inserthead(head,22);
    inserthead(head,23);
    print(head);
    inserttail(tail,42);
    inserttail(tail,43);
    inserttail(tail,56);
    print(head);
    insertposition(head,tail,25,1);
    print(head);
    insertposition(head,tail,53,5);
    print(head);
    insertposition(head,tail,50,10);
    print(head);
    deletion(head,tail,1);
    print(head);
    deletion(head,tail,5);
    print(head);
    deletion(head,tail,8);
    print(head);
    cout<<head->data<<" "<<"value of head"<<endl;
    cout<<tail->data<<" "<<"value of tail"<<endl;
}

