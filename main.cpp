// ...existing code...
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& v, Node* n = nullptr) : value(v), next(n) {}
    };
    Node* head;
    Node* tail;
    size_t count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~LinkedList() { clear(); }

    void push_front(const T& value) {
        Node* n = new Node(value, head);
        head = n;
        if (!tail) tail = head;
        ++count;
    }

    void push_back(const T& value) {
        Node* n = new Node(value);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
        ++count;
    }

    bool insert_after(const T& after, const T& value) {
        Node* cur = head;
        while (cur) {
            if (cur->value == after) {
                Node* n = new Node(value, cur->next);
                cur->next = n;
                if (cur == tail) tail = n;
                ++count;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool remove(const T& value) {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur) {
            if (cur->value == value) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                --count;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    T& operator[](size_t index) {
        if (index >= count) throw out_of_range("index out of range");
        Node* cur = head;
        for (size_t i = 0; i < index; ++i) cur = cur->next;
        return cur->value;
    }

    size_t size() const { return count; }

    bool empty() const { return count == 0; }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        head = tail = nullptr;
        count = 0;
    }

    // void for_each(function<void(const T&)> fn) const {
    //     Node* cur = head;
    //     while (cur) { fn(cur->value); cur = cur->next; }
    // }

    template<typename Func>
    void for_each(Func&& fn) const {
        const Node* cur = head;
        while (cur) { fn(cur->value); cur = cur->next; }
    }
};

int main() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert_after(10, 15); // list: 5,10,15,20

    cout << "List contents:";
    list.for_each([](const int& v){ cout << ' ' << v; });
    cout << "\nSize: " << list.size() << '\n';

    list.remove(10); // remove element 10
    cout << "After removing 10:";
    list.for_each([](const int& v){ cout << ' ' << v; });
    cout << "\nElement at index 1: " << list[1] << '\n';

    return 0;
}
// ...existing code...