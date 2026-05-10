// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;  

public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (!empty()) {
            pop();
        }
    }

    // Вставка элемента в очередь за O(n)
    void push(const T& val) {
        Node* newNode = new Node(val);

        if (!head || val.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* cur = head;
        while (cur->next && cur->next->data.prior >= val.prior) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }

    T pop() {
        if (!head) {
            throw std::runtime_error("TPQueue: попытка извлечения из пустой очереди");
        }
        Node* temp = head;
        T result = head->data;
        head = head->next;
        delete temp;
        return result;
    }

    // Проверка очереди на пустоту
    bool empty() const {
        return head == nullptr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
