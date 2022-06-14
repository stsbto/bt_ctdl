#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class List
{
private:
    Node *pHead;

public:
    List()
    {
        pHead = NULL;
    }
    void push_back(int data)
    {
        Node *n = new Node(data);
        if (!pHead)
        {
            pHead = n;
            pHead->next = pHead;
        }
        else
        {
            Node *temp = pHead;
            while (temp->next != pHead)
            {
                temp = temp->next;
            }
            n->next = pHead;
            temp->next = n;
        }
    }
    void printList()
    {
        Node *temp = pHead;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != pHead);
        cout << endl;
    }
    void changeHead()
    {
        Node *temp = pHead;
        do
        {
            if (temp->data == 5)
            {
                pHead = temp;
            }
            temp = temp->next;
        } while (temp != pHead);
    }
};
int main()
{
    List l;
    l.push_back(3);
    l.push_back(5);
    l.push_back(1);
    l.push_back(4);
    l.printList();
    l.changeHead();
    l.printList();
    return 0;
}