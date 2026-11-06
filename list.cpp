#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node(T v) {
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

    Node* getNode(int index) {
        Node* current;
        if (index < size / 2) {
            current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = tail;
            for (int i = size - 1; i > index; i--) {
                current = current->prev;
            }
        }
        return current;
    }

    void removeNode(Node* node) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        delete node;
        size--;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    DoublyLinkedList(const DoublyLinkedList& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }

    ~DoublyLinkedList() {
        clear();
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
        return *this;
    }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void push_front(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pop_back() {
        if (size == 0) {
            std::cout << "Error: list is empty" << std::endl;
            return;
        }
        removeNode(tail);
    }

    void pop_front() {
        if (size == 0) {
            std::cout << "Error: list is empty" << std::endl;
            return;
        }
        removeNode(head);
    }

    void insert(int index, T value) {
        if (index < 0 || index > size) {
            std::cout << "Error: index out of range" << std::endl;
            return;
        }
        if (index == 0) {
            push_front(value);
        } else if (index == size) {
            push_back(value);
        } else {
            Node* nextNode = getNode(index);
            Node* prevNode = nextNode->prev;
            Node* newNode = new Node(value);
            newNode->prev = prevNode;
            newNode->next = nextNode;
            prevNode->next = newNode;
            nextNode->prev = newNode;
            size++;
        }
    }

    void erase(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Error: index out of range" << std::endl;
            return;
        }
        removeNode(getNode(index));
    }

    bool remove(T value) {
        int index = find(value);
        if (index == -1) {
            return false;
        }
        erase(index);
        return true;
    }

    int find(T value) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    T& operator[](int index) {
        return getNode(index)->value;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Error: index out of range" << std::endl;
            return T();
        }
        return getNode(index)->value;
    }

    T front() {
        if (size == 0) {
            std::cout << "Error: list is empty" << std::endl;
            return T();
        }
        return head->value;
    }

    T back() {
        if (size == 0) {
            std::cout << "Error: list is empty" << std::endl;
            return T();
        }
        return tail->value;
    }

    void reverse() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        Node* temp = head;
        head = tail;
        tail = temp;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }

    void print() {
        std::cout << "[ ";
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "]  size = " << size << std::endl;
    }

    void printReverse() {
        std::cout << "[ ";
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->prev;
        }
        std::cout << "]  size = " << size << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    list.print();
    list.printReverse();

    list.insert(2, 15);
    list.print();

    list.erase(1);
    list.print();

    list.pop_back();
    list.pop_front();
    list.print();

    list.push_back(40);
    list.push_back(50);
    list.print();

    std::cout << "find(40) = " << list.find(40) << std::endl;
    std::cout << "find(999) = " << list.find(999) << std::endl;

    if (list.remove(40)) {
        std::cout << "40 removed" << std::endl;
    }
    list.print();

    list[0] = 100;
    std::cout << "list[0] = " << list[0] << std::endl;
    std::cout << "get(1) = " << list.get(1) << std::endl;
    std::cout << "front = " << list.front() << ", back = " << list.back() << std::endl;

    list.reverse();
    list.print();
    list.printReverse();

    DoublyLinkedList<int> copy(list);
    copy.push_back(777);
    list.print();
    copy.print();

    DoublyLinkedList<int> other;
    other = copy;
    other.clear();
    other.print();
    copy.print();

    DoublyLinkedList<double> d;
    d.push_back(1.5);
    d.push_back(2.5);
    d.print();

    return 0;
}