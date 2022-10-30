#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};
class List {
private:
    Node *head;
public:
    List() {
        head = NULL;
    }
    // task 1
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
int main() {
    List obj;
    obj.insertAtFront(5);
    obj.insertAtFront(4);

    obj.printAll();
    return 0;
}
