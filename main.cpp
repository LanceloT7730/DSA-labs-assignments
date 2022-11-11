#include <iostream>

using namespace std;
// task 1 implementation
/*template<class Type>
class queueType {
public:
    bool isEmptyQueue() {
        return count == 0;
    }

    bool isFullQueue() {
        return count == maxQueueSize;
    }

    void initializeQueue() {
        queueRear = -1;
        queueFront = -1;
        count = 0;
        list = new Type[maxQueueSize];
    }

    Type front() {
        cout << "Front: " << list[queueFront] << endl;
        return list[queueFront];
    }

    Type back() {
        cout << "Back: " << list[queueRear] << endl;
        return list[queueRear];
    }


    void addQueue(const Type &queueElement) {
        if (!isFullQueue()) {
            queueRear = (queueRear + 1) % maxQueueSize;
            if (queueFront == -1) queueFront = (queueFront + 1) % maxQueueSize;
            count++;
            list[queueRear] = queueElement;
        }
    }

    void deleteQueue() {
        if (!isEmptyQueue()) {
            queueFront = (queueFront + 1) % maxQueueSize;
            if (queueRear == 0) queueRear = (queueRear - 1) % maxQueueSize;
            count--;
        }
    }

    void printQueue() {
        for (int i = 0; i < maxQueueSize; i++) {
            cout << list[queueFront + i] << endl;
        }

    }

    queueType(int queueSize = 10) { // Function with default parameters
        maxQueueSize = queueSize;
    }

    queueType(const queueType<Type> &otherQueue) {
        maxQueueSize = otherQueue.maxQueueSize;
        initializeQueue();
        for (int i = 0; i < maxQueueSize; i++) {
            addQueue(otherQueue.list[queueFront + i]);
        }
    }

// To create a Queue object that copies another queue
    ~queueType() {

    }

private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    Type *list;
};*/

struct Node {
    int data;
    Node *next;

    Node() {
        next == NULL;
    }
};

class LinkedList {
private:
    Node *head, *last;
public:
    LinkedList() {
        head = NULL;
        last = NULL;
    }

    void printAll() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    bool isEmptyQueue() {
        if (head) return true;
        else return false;
    }

    void initializeQueue() {
        Node *temp = head;
        while (temp) {

        }

    }

    int front() {
        return head->data;
    }

    int back() {
        return last->data;
    }

    void addQueue(int data) {
        //Node *temp = head;
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            last = newNode;

        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void deleteQueue(){
        head = head->next;
    }
};

int main() {
    // task 1 testing
    /*queueType<int> Q1;
    Q1.initializeQueue();
    cout << "Is the queue empty? " << Q1.isEmptyQueue() << endl; // output is 1 as it is empty for now

    Q1.addQueue(15);
    Q1.addQueue(25);
    Q1.addQueue(4);
    Q1.addQueue(12);
    Q1.addQueue(123);
    Q1.addQueue(75);
    Q1.addQueue(85);
    Q1.addQueue(55);
    Q1.front(); // should display 15
    Q1.deleteQueue();

    Q1.printQueue();// should display all the queue element in the order they are added
    // except 15

    cout << endl << "Second part started" << endl;
    queueType<int> Q2(Q1);
    Q1.addQueue(1000);
    Q1.addQueue(2000);
    Q1.printQueue(); // Should display all the members of Q1 in the order they are
    // inserted except 15 as it was deleted earlier
    Q2.printQueue();
// Should display all the members of Q2 i-e all the members of Q1 except for 1000
// and 2000
    Q1.initializeQueue();
    Q1.printQueue();
//Should display a message &quot;An empty Queue can&#39;t be displayed&quot;
    Q1.addQueue(35);
    cout << Q1.front() << endl;
//Should display 35
    cout << Q1.front() << endl;
//Should display 35
    Q1.addQueue(3);
    Q1.printQueue();
//Should display both 35 and 3*/

    // task 2 testing
    LinkedList list;
    list.addQueue(5);
    list.addQueue(6);
    list.deleteQueue();
    /*for (int i = 0; i < 5; i++) {
        list.addQueue(i);
    }*/
    list.printAll();

    return 0;
}