#include <iostream>

using namespace std;


// task 1
// what is the difference between typename and class in template
template<class Type>
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
        if (!isStackFull()) {
            stackTop++;
            list[stackTop] = data;
            count++;
        } else {
            cout << "Cannot add to full stack" << endl;
        }
    }

    void pop() {
        if (!isStackEmpty()) {
            stackTop--;
            count--;
        } else {
            cout << "Cannot remove element from empty list" << endl;
        }
    }

    Type top() {
        return list[stackTop];
    }

    int CountStackElements() {
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

    ~StackType() {
        delete[]list;
    }

private:
    int stackTop;
    int maxStackSize;
    int count;
    Type *list;
};

template<class Type>
struct Node {
    Type data;
    Node<Type> *next;

    Node() {
        next = NULL;
    }
};

template<class Type>
class LinkedListStack {
private:
    Node<Type> *top;
    int count;

public:
    LinkedListStack() {
        top = NULL;
        count = 0;
    }

    void CreateStack() {
        if (!isStackEmpty()) {
            Node<Type> *temp = top;
            while (!temp) {
                top = top->next;
                delete temp;
                temp = top;
            }
        } else cout << "Cannot delete element from empty list\n";

    }

    bool isStackEmpty() {
        return count == 0;
    }

    void push(Type data) {
        Node<Type> *newNode = new Node<Type>;
        newNode->data = data;

        if (isStackEmpty()) {
            newNode->next = NULL;
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        count++;
    }

    void pop() {
        if (!isStackEmpty()) {
            Node<Type> *temp = top;
            //while (temp) {
            top = top->next;
            delete temp;
            temp = top;
            count--;
            //}
        } else cout << "Cannot delete element from empty list\n";

    }

    Type Top() {
        return top->data;
    }

    int CountStackElements() {
        return count;
    }

    void DestroyStack() {
        Node<Type> *temp = top;
        while (count != 0) {
            pop();
            count--;
        }
    }

    void printAll() {
        Node<Type> *temp = top;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome(string data) {
        bool answer = false;
        // copying all data characters to the stack
        for (char &i: data) push(i);

        // checking if the num of characters is odd or even
        if(data.size() % 2 == 0) {
            for (char &i: data) {
                if (top->data == i) {
                    answer = true;
                    top = top->next;
                } else return false;
            }
            return answer;
        } else {
            for (int i = 0; i < (data.size() - 1); i++) {
                if (top->data == data[i]) {
                    answer = true;
                    top = top->next;
                } else return false;
            }
            return answer;
        }
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

    // testing task 1
    LinkedListStack<int> stack;
    cout << "Is stack empty: " << stack.isStackEmpty() << endl;

    cout << "Adding elements to the stack\n";
    stack.push(5);
    cout << "Is stack empty: " << stack.isStackEmpty() << endl;

    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }
    cout << "Stack elements are\n";
    stack.printAll();

    cout << "Top element is: " << stack.Top() << endl;

    cout << "Deleting one element from the stack\n";
    stack.pop();
    cout << "Stack elements are\n";
    stack.printAll();

    cout << "Number of elements in stack: " << stack.CountStackElements() << endl;

    cout << "Destroying the stack\n";
    stack.DestroyStack();
    cout << "Number of elements in stack: " << stack.CountStackElements() << endl;

    string palindrome = "Something";
    cout << "Checking whether a string " << palindrome <<  " is palindrome or not: " << stack.isPalindrome(palindrome) << endl;

    palindrome = "ACCA";
    cout << "Checking whether a string " << palindrome <<  " is palindrome or not: " << stack.isPalindrome(palindrome) << endl;

    return 0;
}
