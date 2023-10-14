#include <iostream >
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int n)
    {
        data = n;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            delete prev;
            this->next = NULL;
        }
    }
};
void Print(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->prev << " " << temp->data << " " << temp->next << "\t\t\t";
        temp = temp->next;
    }
    cout << "Head: " << head->data << "     " << tail->data << "\n\n\n";
}
void Head(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void Tail(Node *&tail, int d)
{
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void mid(Node *&head, Node *&tail, int p, int d)
{
    Node *temp = new Node(d);
    if (p == 1)
    {
        Head(head, d);
        return;
    }
    Node *curr = head;
    int c = 1;
    while (c < p - 1)
    {
        curr = curr->next;
        c++;
    }
    if (curr->next == NULL)
    {
        Tail(tail, d);
        return;
    }
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}
void Delete(int pos, Node *&head, Node *&tail)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node *curr = head;
    Node *pre = NULL;
    int c = 1;
    while (c < pos)
    {
        pre=curr;
        curr = curr->next;
        c++;
    }
    if(curr->next==NULL){
        tail=tail->prev;
    }
    curr->prev=NULL;
    pre->next=curr->next;
    curr->next=NULL;
    delete curr;
}
int main()
{
    Node *n = new Node(98);
    cout << n->prev << " " << n->data << " " << n->next << endl;
    Node *head = n;
    Node *tail = n;
    Print(head, tail);
    Head(head, 55);
    Print(head, tail);
    Tail(tail, 70);
    Print(head, tail);
    mid(head, tail, 2, 45);
    Print(head, tail);
    mid(head, tail, 5, 112);
    Print(head, tail);
    Delete(5, head, tail);
    Delete(3, head, tail);
    Delete(1, head, tail);
    Print(head, tail);
}
