#include <iostream>

using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val);
};

// Sorted Linked List Class
class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList(); // Constructed

    void insert(int value);
    void remove(int index);

    // Overloaded operators
    friend ostream& operator<<(ostream& os, const SortedLinkedList& list);
    int operator[](int index);

    ~SortedLinkedList();
};

Node::Node(int val) {
    data = val;
    next = nullptr;
}

SortedLinkedList::SortedLinkedList() {
    head = nullptr;
}


void SortedLinkedList::insert(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *prevNode = head;
        Node *nextNode = head->next;

        if (value <= head->data) {
            Node *headTmp = head;
            head = newNode;
            newNode->next = headTmp;
        }

        while (nextNode != nullptr) {
            if (value >= prevNode->data && value <= nextNode->data) {
                prevNode->next = newNode;
                newNode->next = nextNode;
                break;
            }
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        if (value > prevNode->data) {
            prevNode->next = newNode;
        }
    }
}

void SortedLinkedList::remove(int index) {
    Node *prev = nullptr;
    Node *current = head;
    int i = 0;
    while (current != nullptr) {
        if (index == i) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            break;
        }
        i++;
        prev = current;
        current = current->next;
    }
}

ostream &operator<<(ostream &os, const SortedLinkedList &list) {
    if (list.head == nullptr) {
        return os << "(empty list)" << endl;
    }
    Node *current = list.head;
    while (current != nullptr) {
        if (current != list.head) {
            os << " -> ";
        }
        os << current->data;
        current = current->next;
    }
    return os;
}

int SortedLinkedList::operator[](int index) {
    Node *current = head;
    int i = 0;
    while (current != nullptr) {
        if (i == index) {
            return current->data;
        }
        i++;
        current = current->next;
    }

    throw std::out_of_range ("index out of range");
}

SortedLinkedList::~SortedLinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *nextTmp = current->next;
        delete current;
        current = nextTmp;
    }
}

int main() {
    cout << "running test cases" << endl;
    cout << "test case 1:" << endl;
    SortedLinkedList L;
    L.insert(5); // L = [5]
    cout << L << endl;
    L.insert(8); // L = [5, 8]
    cout << L << endl;
    L.insert(7); // L = [5, 7, 8]
    cout << L << endl;
    L.insert(6); // L = [5, 6, 7, 8]
    cout << L << endl;
    L.insert(6); // L = [5, 6, 6, 7, 8]
    cout << L; // Output: [5, 6, 6, 7, 8]

    cout << "test case 2:" << endl;
    cout << L[2] << endl; // Output: 6
    try {
        cout << L[10] << endl; // Throws out_of_range exception
    } catch (out_of_range &e) {
        cout << "error happened: " << endl;
        cout << e.what() << endl;
    }

    {
        cout << "test case 3:" << endl;
        SortedLinkedList L;
        int arr[] = {5, 6, 6, 7, 8};
        for (int element : arr) {
            L.insert(element);
        }
        L.remove(0); // L = [6, 6, 7, 8]
        cout << L << endl; // Output: [6, 6, 7, 8]
        L.remove(100); // No change (out of bounds)
        cout << L << endl; // Output: [6, 6, 7, 8]
        L.remove(2); // L = [6, 6, 8]
        cout << L << endl; // Output: [6, 6, 8]
        L.remove(2); // L = [6, 6]
        cout << L << endl; // Output: [6, 6]
    }

    SortedLinkedList list;
    while (true) {
        cout << "enter element to insert in list (press Enter to end list): ";
        string input;
        getline(cin, input);
        if (input.empty()) break;
        try {
            int element = stoi(input);
            list.insert(element);
        } catch (...) {
            cout << "invalid input!" << endl;
        }
    }

    cout << list << endl;
}