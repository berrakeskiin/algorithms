#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(T value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addAtFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void RemoveFromFront() {
        if (!head) return;
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void RemoveFromEnd() {
        if (!tail) return;
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    int length() const {
        return size;
    }

    bool find(T value) const {
        Node<T>* curr = head;
        while (curr) {
            if (curr->data == value) return true;
            curr = curr->next;
        }
        return false;
    }

    void print() const {
        Node<T>* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void printReverse() {
        Node<T>* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void reverseValues() {
        Node<T>* left = head;
        Node<T>* right = tail;
        while (left != right && left->prev != right) {
            T temp = left->data;
            left->data = right->data;
            right->data = temp;
            left = left->next;
            right = right->prev;
        }
    }

    Node<T>* pointerAtkthFromFront(int k) {
        if (k < 1 || k > size) {
            cout << "List too short." << endl;
            return nullptr;
        }
        Node<T>* curr = head;
        int count = 1;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        return curr;
    }

    T valueAtkthFromFront(int k) {
        Node<T>* p = pointerAtkthFromFront(k);
        if (p != nullptr) return p->data;
        return T{};
    }

    int replaceAll(T a, T b) {
        int count = 0;
        Node<T>* curr = head;
        while (curr) {
            if (curr->data == a) {
                curr->data = b;
                count++;
            }
            curr = curr->next;
        }
        return count;
    }

    int countOccurrences(T value) {
        int count = 0;
        Node<T>* curr = head;
        while (curr) {
            if (curr->data == value) count++;
            curr = curr->next;
        }
        return count;
    }

    void addAtPosition(T value, int k) {
        if (k < 1 || k > size + 1) {
            cout << "Position out of range" << endl;
            return;
        }
        if (k == 1) {
            addAtFront(value);
        } else if (k == size + 1) {
            addAtEnd(value);
        } else {
            Node<T>* temp = head;
            for (int i = 1; i < k - 1; i++) {
                temp = temp->next;
            }
            Node<T>* newNode = new Node<T>(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
        }
    }

    void deleteAtPosition(int k) {
        if (k < 1 || k > size || head == nullptr) {
            cout << "Unable to delete: position out of range." << endl;
            return;
        }

        if (k == 1) {
            RemoveFromFront();
            return;
        }

        if (k == size) {
            RemoveFromEnd();
            return;
        }

        Node<T>* curr = head;
        int index = 1;
        while (curr != nullptr && index < k) {
            curr = curr->next;
            index++;
        }

        if (curr == nullptr) {
            cout << "Unable to delete: position out of range." << endl;
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }

    void insertSorted(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = tail = newNode;
            size++;
            return;
        }

        if (value <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            size++;
            return;
        }

        if (value >= tail->data) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            size++;
            return;
        }

        Node<T>* curr = head;
        while (curr->next != nullptr && curr->next->data < value) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        size++;
    }
};

