#include <iostream>

struct LinkNode {
    int number;
    LinkNode* previous;
    LinkNode* next;
};

class MyLinkedList {
    LinkNode* head;
    LinkNode* tail;
    size_t currentSize;
public:
    MyLinkedList() :
        head(), tail(), currentSize(0) {}

    ~MyLinkedList() {
        if (this->tail)
            this->tail->next = nullptr;

        while (this->head) {
            LinkNode* nextLinkNode = this->head->next;
            delete this->head;
            this->head = nextLinkNode;
        }
    }

    static LinkNode* findNodeByIndex(LinkNode* node, const int& searchIndex, const int& currentIndex = 0) {
        if (searchIndex == currentIndex)
            return node;
        return findNodeByIndex(node->next, searchIndex, currentIndex + 1);
    }

    [[nodiscard]] int get(const int& index) const {
        if (index < this->currentSize)
            return findNodeByIndex(this->head, index)->number;

        return -1;
    }

    void addAtHead(const int& val) {
        LinkNode* newHead = new LinkNode{val, nullptr, nullptr};

        if (this->tail && this->head) {
            newHead->next = this->head;
            newHead->previous = this->tail;

            this->tail->next = newHead;
            this->head->previous = newHead;

        } else {
            this->tail = newHead;
            newHead->previous = newHead;
            newHead->next = newHead;
        }

        this->head = newHead;
        ++this->currentSize;
    }

    void addAtTail(const int& val) {
        LinkNode* newTail = new LinkNode{val, nullptr, nullptr};

        if (this->tail && this->head) {
            newTail->previous = this->tail;
            newTail->next = this->head;

            this->tail->next = newTail;
            this->head->previous = newTail;

        } else {
            this->head = newTail;
            newTail->previous = newTail;
            newTail->next = newTail;
        }

        this->tail = newTail;
        ++this->currentSize;
    }

    void addAtIndex(const int& index,const  int& val) {
        if (index > this->currentSize)
            return;
        
        if (index == 0)
            addAtHead(val);

        else if (index == this->currentSize)
            addAtTail(val);

        else {
            LinkNode* newLinkNode = new LinkNode{val, nullptr, nullptr};

            LinkNode* previousNodeAtIndex = findNodeByIndex(this->head, index);

            newLinkNode->next = previousNodeAtIndex;
            newLinkNode->previous = previousNodeAtIndex->previous;

            previousNodeAtIndex->previous->next = newLinkNode;
            previousNodeAtIndex->previous = newLinkNode;
            ++this->currentSize;
        }
    }

    void deleteAtIndex(const int& index) {
        if (index < this->currentSize) {
            const LinkNode* deleteNode = findNodeByIndex(this->head, index);

            if (deleteNode->next == deleteNode && deleteNode->previous == deleteNode) {
                delete deleteNode;
                --this->currentSize;
                this->head = nullptr;
                this->tail = nullptr;
                return;
            }
            deleteNode->previous->next = deleteNode->next;
            deleteNode->next->previous = deleteNode->previous;
            if (index == 0)
                this->head = deleteNode->next;
            else if (index + 1 == this->currentSize)
                this->tail = deleteNode->previous;

            delete deleteNode;
            --this->currentSize;
        }
    }
};

int main() {
    MyLinkedList myLinked;

    myLinked.addAtIndex(1, 0);

    std::cout << myLinked.get(0);

    // myLinked.addAtHead(1);
    // myLinked.addAtTail(3);
    // myLinked.addAtIndex(1, 2);
    //
    // std::cout << myLinked.get(1) << '\n';
    //
    // myLinked.deleteAtIndex(1);
    //
    // std::cout << myLinked.get(1) << '\n';
    // std::cout << myLinked.get(3) << '\n';
    //
    // myLinked.deleteAtIndex(3);
    // myLinked.deleteAtIndex(0);
    //
    // std::cout << myLinked.get(0) << '\n';
    //
    // myLinked.deleteAtIndex(0);
    // std::cout << myLinked.get(0) << '\n';

    return 0;
}
