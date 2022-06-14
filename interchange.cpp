#include <iostream>
#include <fstream>
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
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_back(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }
    Node *getHead()
    {
        return head;
    }
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void swapNode(Node *a, Node *b)
    {
        int data = a->data;
        a->data = b->data;
        b->data = data;
    }
    void interchangeSort()
    {
        int i = 1;
        Node *pos = head;
        while (pos)
        {
            Node *jump = pos->next;
            while (jump)
            {
                if (pos->data > jump->data)
                {
                    swapNode(pos, jump);
                }
                jump = jump->next;
            }
            cout << "B" << i << ": ";
            pos = pos->next;
            printList();
            i++;
        }
    }
};
void readFile(List &l)
{
    // cout << "Da doc file txt: " << endl;
    int data;
    ifstream myfile("./input.txt");
    while (!myfile.eof())
    {
        myfile >> data;
        l.push_back(data);
    }
    myfile.close();
}
void writeFile(List &l)
{
    ofstream myfile("output.txt");
    Node *temp = l.getHead();
    while (temp)
    {
        myfile << temp->data << " ";
        temp = temp->next;
    }
    myfile.close();
}
int main()
{
    List l;
    readFile(l);
    l.printList();
    l.interchangeSort();
    cout << "interchangerSort: " << endl;
    l.printList();
    writeFile(l);
    return 0;
}