#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    ~Node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};

void inserthead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node* temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void inserttail(Node* &head,Node* &tail,int data)
{
    Node* temp=new Node(data);
    if(tail==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertpos(Node* &head,Node* &tail,int data,int pos)
{
    if(pos==1)
    {
        inserthead(head,tail,data);
        return;
    }
    int cnt=1;
    Node* ins=new Node(data);
    Node* temp=head;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    ins->next=temp->next;
    temp->next->prev=ins;
    temp->next=ins;
    ins->prev=temp;
}

void deletion(Node* &head,Node* &tail,int pos)
{
    Node* temp=head;
    if(pos==1)
    {
        head=head->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node*curr=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            curr=temp;
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL)
        {
            tail=temp->prev;
        }
        temp->prev=NULL;
        curr->next=temp->next;
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
    Node* head=NULL;
    Node* tail=NULL;
    inserthead(head,tail,3);
    inserthead(head,tail,5);
    inserthead(head,tail,8);
    inserttail(head,tail,9);
    inserttail(head,tail,12);
    insertpos(head,tail,15,3);
    deletion(head,tail,6);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
}