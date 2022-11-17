#include <iostream>

using namespace std;



// task 1
// what is the difference between typename and class in template
template <class Type>
class StackType {
public:
    StackType(int stackSize = 10) {
        maxStackSize = stackSize;
        list = new Type[maxStackSize];
        CreateStack();
    }

    void CreateStack() {
        stackTop = -1;
        count = 0;
    }

    bool isStackEmpty() {
        return count == 0;
    }

    bool isStackFull() {
        return count == maxStackSize;
    }
    void push(Type data) {
        if(!isStackFull()) {
            stackTop++;
            list[stackTop] = data;
            count++;
        } else {
            cout << "Cannot add to full stack" << endl;
        }
    }
    void pop(){
        if(!isStackEmpty()) {
            stackTop--;
            count--;
        } else {
            cout << "Cannot remove element from empty list" << endl;
        }
    }

    Type top() {
        return list[stackTop];
    }

    int CountStackElements(){
        return count;
    }

    void DestroyStack() {
        CreateStack();
    }

    void printAll() {
        int size = count;
        for (int i = 0; i < size; i++) {
            cout << top();
            pop();
        }
    }

private:
    int stackTop;
    int maxStackSize;
    int count;
    Type *list;
};

template <class Type>
struct Node {
    Type data;
    Node <Type> *next;
    string data_string;

    Node() {
        next = NULL;
    }
};
template <class Type>
class LinkedListStack {
private:
    Node <Type> *head;
    int count = 0;
public:
    LinkedListStack() {
        head = NULL;
    }

};
int main() {
    // testing task 1
    /*StackType<char> stack;
    string name;
    cout << "Enter your name to be printed reversely" << endl;
    cin >> name;
    for (int i = 0; i < name.size(); i++) {
        stack.push(name[i]);
    }
    cout << "Result: ";
    stack.printAll();*/
    return 0;
}
