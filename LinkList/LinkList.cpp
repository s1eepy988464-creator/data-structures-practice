#include <iostream>
#include "LinkList.h"
using namespace std;
template <class T>
LinkList<T>::LinkList()
{
    head=new Node<T>;
    head->next=nullptr;
}
template <class T>
LinkList<T>::LinkList(T a[], int n)
{
    head=new Node<T>;
    Node<T>* rear=head;
    for(int i=0; i<n; i++)
    {
        Node<T> * s=new Node<T>;
        s->data=a[i];
        rear->next=s;
        rear=s;
    }
    rear->next=nullptr;
}
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> * p=head;
    while(p)
    {
        Node<T> * q=p;
        p=p->next;
        delete q;
    }
}
template <class T>
int LinkList<T>::ListLength()
{
    int len=0;
    Node<T>* p=head->next;
    while(p)
    {
        p=p->next;
        len++;
    }
    return len;
}
template <class T>
T LinkList<T>::Get(int pos)
{
    Node<T>*p=head->next;
    int i=1;
    while(p && i<pos)
    {
        p=p->next;
        i++;
    }
    if(!p || i>pos)
    {
        cerr<<"位置不合法"<<endl;
        exit(1);
    }
    return p->data;
}
template <class T>
int LinkList<T>::Locate(T item)
{
    Node<T>* p=head->next;
    int i=1;
    while(p && p->data!=item)
    {
        p=p->next;
        i++;
    }
    if(!p)
        return 0;
    return i;
}
template <class T>
void LinkList<T>::PrintLinkList()
{
    Node<T>* p=head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
template <class T>
void LinkList<T>::Insert(int i, T item)
{
    Node<T>* p=head;
    int j=0;
    while(p && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i-1)
    {
        cerr<<"插入位置不合法"<<endl;
        exit(1);
    }
    Node<T>* s=new Node<T>;
    s->data=item;
    s->next=p->next;
    p->next=s;
}
template <class T>
T LinkList<T>::Delete(int i)
{
    Node<T>* p=head;
    int j=0;
    while(p->next && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p->next || j>i-1)
    {
        cerr<<"删除位置不合法"<<endl;
        exit(1);
    }
    Node<T>* q=p->next;
    T item=q->data;
    p->next=q->next;
    delete q;
    return item;
}
template <class T>
void LinkList<T>::Invert()
{
    Node<T>* p=head->next;
    head->next=nullptr;
    while(p)
    {
        Node<T>* q=p;
        p=p->next;
        q->next=head->next;
        head->next=q;
    }
}
template <class T>
void LinkList<T>::Merge(LinkList<T> &L1, LinkList<T> &L2)
{
    Node<T>* p1=L1.head->next;
    Node<T>* p2=L2.head->next;
    Node<T>* rear=head;
    while(p1 && p2)
    {
        if(p1->data<=p2->data)
        {
            rear->next=p1;
            rear=p1;
            p1=p1->next;
        }
        else
        {
            rear->next=p2;
            rear=p2;
            p2=p2->next;
        }
    }
    if(p1)
        rear->next=p1;
    else
        rear->next=p2;
    L1.head->next = nullptr;
    L2.head->next = nullptr;
}
