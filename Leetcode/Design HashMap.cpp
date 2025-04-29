struct LinkNode {
    int number;
    LinkNode* next;
};

class MyHashMap {
    static constexpr size_t DEFAULT_SIZE = 40;
    LinkNode** keys;
    LinkNode** values;
    size_t size;
public:
    MyHashMap() :
        keys(new LinkNode*[DEFAULT_SIZE]{}), values(new LinkNode*[DEFAULT_SIZE]{}), size(DEFAULT_SIZE) {}

    MyHashMap(const size_t& size) :
        keys(new LinkNode*[size]{}), values(new LinkNode*[size]{}), size(size) {}

    ~MyHashMap() {
        for (int i = 0; i < this->size; ++i) {
            LinkNode* keyLinkNode = *(this->keys + i);
            LinkNode* valueLinkNode = *(this->values + i);

            while (keyLinkNode && valueLinkNode) {
                LinkNode* nextKeyNode = keyLinkNode->next;
                LinkNode* nextValueNode = valueLinkNode->next;
                delete keyLinkNode;
                delete valueLinkNode;
                keyLinkNode = nextKeyNode;
                valueLinkNode = nextValueNode;
            }
        }
        delete[] this->keys;
        delete[] this->values;
    }

    void put(const int& key, const int& value) {
        const int hashValue = key % this->size;

        LinkNode* keyPointer = *(this->keys + hashValue);
        LinkNode* valuePointer = *(this->values + hashValue);

        while (keyPointer) {
            if (keyPointer->number == key) {
                valuePointer->number = value;
                return;
            }
            if (keyPointer->next == nullptr) {
                keyPointer->next = new LinkNode{key, nullptr};
                valuePointer->next = new LinkNode{value, nullptr};
                return;
            }
            keyPointer = keyPointer->next;
            valuePointer = valuePointer->next;
        }

        *(this->keys + hashValue) = new LinkNode{key, nullptr};
        *(this->values + hashValue) = new LinkNode{value, nullptr};
    }

    [[nodiscard]] int get(const int& key) const {
        const size_t hashValue = key % this->size;

        LinkNode* keyPointer = *(this->keys + hashValue);
        LinkNode* valuePointer = *(this->values + hashValue);

        while (keyPointer) {
            if (keyPointer->number == key)
                return valuePointer->number;
            keyPointer = keyPointer->next;
            valuePointer = valuePointer->next;
        }
        return -1;
    }

    void remove(const int& key) {
        const size_t hashValue = key % this->size;

        LinkNode* keyPointer = *(this->keys + hashValue);
        LinkNode* valuePointer = *(this->values + hashValue);

        LinkNode* previousKeyPointer = nullptr;
        LinkNode* previousValuePointer = nullptr;

        while (keyPointer) {
            if (keyPointer->number == key) {
                if (previousKeyPointer && previousValuePointer) {
                    previousKeyPointer->next = keyPointer->next;
                    previousValuePointer->next = valuePointer->next;

                } else {
                    *(this->keys + hashValue) = keyPointer->next;
                    *(this->values + hashValue) = valuePointer->next;
                }

                delete keyPointer;
                delete valuePointer;
                return;
            }
            previousKeyPointer = keyPointer;
            previousValuePointer = valuePointer;
            keyPointer = keyPointer->next;
            valuePointer = valuePointer->next;
        }
    }
};
