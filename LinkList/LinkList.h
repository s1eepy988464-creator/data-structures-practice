#ifndef LINKLIST_H
#define LINKLIST_H
template <class T>
struct Node {
    T data;
    Node<T> * next;
};

template <class T>
class LinkList
{
    private:
        Node<T> * head;
    public:
        LinkList();
        LinkList(T a[], int n);
        ~LinkList();
        int ListLength();
        T Get(int pos);
        int Locate(T item);
        void PrintLinkList();
        void Insert(int i, T item);
        T Delete(int i);
        void Invert();
        void Merge(LinkList<T> &L1, LinkList<T> &L2);
};
#include "LinkList.cpp"

#endif