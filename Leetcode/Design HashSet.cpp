#include <iostream>
#include <sstream>

struct LinkNode {
    int number;
    LinkNode* next;
};

class MyHashSet {
    static constexpr size_t DEFAULT_SIZE = 40;
    LinkNode** keys;
    size_t size;
public:
    MyHashSet() :
        keys(new LinkNode *[DEFAULT_SIZE]{}), size(DEFAULT_SIZE) {}

    explicit MyHashSet(const size_t& size) :
        keys(new LinkNode *[size]{}), size(size) {}

    ~MyHashSet() { // Destructor
        for (int i = 0; i < this->size; ++i) {
            LinkNode* currentNode = *(this->keys + i);

            while (currentNode) {
                LinkNode* temp = currentNode->next;
                delete currentNode;
                currentNode = temp;
            }
        }

        delete[] this->keys;
    }

    void add(const int& key) {
        const size_t currentHash = key % this->size;
        LinkNode* newNode = new LinkNode{key, nullptr};

        LinkNode* pointer = *(this->keys + currentHash);
        if (!pointer) // If no element at the current Hash -> directly put it there
            *(this->keys + currentHash) = newNode;

        else {
            LinkNode* previous = nullptr;

            while (pointer) {
                if (pointer->number == key) { // If the value is already inserted -> don't add it again
                    delete newNode;
                    return;
                }
                previous = pointer;
                pointer = pointer->next;
            }

            previous->next = newNode; // Add the new value at the end of the linked list
        }
    }

    void remove(const int& key) {
        const size_t currentHash = key % this->size;

        LinkNode* pointer = *(this->keys + currentHash);
        LinkNode* previous = nullptr;

        while (pointer) {
            if (pointer->number == key) {
                if (previous)
                    previous->next = pointer->next;
                else
                    *(this->keys + currentHash) = pointer->next;
                delete pointer;
                return;
            }
            previous = pointer;
            pointer = pointer->next;
        }
    }

    [[nodiscard]] bool contains(const int& key) const {
        const size_t currentHash = key % this->size;

        LinkNode* pointer = *(this->keys + currentHash);

        while (pointer) {
            if (pointer->number == key)
                return true;
            pointer = pointer->next;
        }

        return false;
    }
};

int main() {
    MyHashSet myHash;

    myHash.add(10);
    myHash.add(50);
    myHash.remove(50);

    std::cout << myHash.contains(10);

    return 0;
}
