#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};

// task 1
class List {
private:
    Node *head;
public:
    List() {
        head = NULL;
    }

    void insertAtFront(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void printAll() {
        Node *temp = head;

        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

// task 2
struct DoubleNode {
    int data;
    DoubleNode *next, *prev;

    DoubleNode() {
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList : public List {
private:
    DoubleNode *head, *tail;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void DoubleFrontInsertion(int data) {
        DoubleNode *newDoubleNode = new DoubleNode;
        newDoubleNode->data = data;
        if (head) {
            newDoubleNode->prev = head->prev;
            newDoubleNode->next = head;
            head = newDoubleNode;
        } else {
            newDoubleNode->prev = head;
            newDoubleNode->next = head;

            head = newDoubleNode;
        }
    }
};

//task 3
class CircularLinkedList : public List {
private:
    Node *head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void CircularFrontInsertion(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        if (!head) {
            insertAtFront(data);
            return;
        }
        newNode->next = head;
        head = newNode;

        Node *temp = head->next;

        do {
            temp = temp->next;
            if (temp == newNode->next) temp = newNode;
        } while (temp);
    }
};

int main() {
    // testing task 1
    List obj;
    obj.insertAtFront(5);
    obj.insertAtFront(4);
    obj.printAll();

    // testing task 2
    DoubleLinkedList obj_double;
    obj_double.DoubleFrontInsertion(5);
    obj_double.DoubleFrontInsertion(4);
    obj_double.printAll();

    // testing task 3
    CircularLinkedList obj_circular;
    obj_circular.CircularFrontInsertion(5);
    obj_circular.CircularFrontInsertion(6);
    obj_circular.CircularFrontInsertion(6);
    obj_circular.CircularFrontInsertion(6);
    obj_circular.CircularFrontInsertion(6);
    obj_circular.printAll();

    return 0;
}
