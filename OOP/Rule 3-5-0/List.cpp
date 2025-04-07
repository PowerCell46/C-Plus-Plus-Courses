#include "List.h"
#include <sstream>
// #include "iostream"

/*!******************************!*/

List::Node::Node(int value, Node *prev, Node *next) :
    value(value), prev(prev), next(next) {}


int List::Node::getValue() const {
    return this->value;
}


void List::Node::setValue(int value) {
    this->value = value;
}


List::Node *List::Node::getNext() const {
    return this->next;
}


void List::Node::setNext(Node *next) {
    this->next = next;
}


List::Node *List::Node::getPrev() const {
    return this->prev;
}


void List::Node::setPrev(Node *prev) {
    this->prev = prev;
}

/*!******************************!*/

List::List() :
    head(nullptr), tail(nullptr), size(0) {}


bool List::isEmpty() const {
    return this->getSize() == 0;
}


size_t List::getSize() const {
    return this->size;
}


void List::add(int value) {
    ++this->size;

    if (!this->tail || !this->head) { // No elements 'til now
        Node *initElement = new Node{value, nullptr, nullptr};
        this->head = initElement;
        this->tail = initElement;
        return;
    }

    if (this->head->getValue() >= value) { // New value is smaller than the head (smallest)
        Node *newHead = new Node{value, nullptr, this->head};

        this->head->setPrev(newHead);
        this->head = newHead;
        return;
    }

    Node *currentNode = this->head;

    while (currentNode && currentNode->getValue() < value) // Iterate until finding the next element
        currentNode = currentNode->getNext();

    Node *newNode = new Node{value, nullptr, currentNode};

    if (currentNode) { // If there's a next element
        if (currentNode->getPrev()) {
            currentNode->getPrev()->setNext(newNode);
            newNode->setPrev(currentNode->getPrev());
        }
        currentNode->setPrev(newNode);

    } else { // New value is the biggest (new head)
        this->tail->setNext(newNode);
        newNode->setPrev(this->tail);
        this->tail = newNode;
    }
}


void List::removeFirst() {
    if (this->head) {
        --this->size;
        Node *newHead = nullptr;

        if (this->head->getNext()) { // If there's a next element - it becomes the new head
            this->head->getNext()->setPrev(nullptr);
            newHead = this->head->getNext();
        }

        delete this->head;
        this->head = newHead;

        if (this->size == 0)
            this->tail = nullptr;
    }
}


void List::removeAll() {
    Node* current = this->head;

    while (current) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}


List &List::operator<<(const int &value) {
    add(value);

    return *this;
}


std::string List::toString() const {
    if (!this->head || !this->tail)
        return "";

    std::stringstream resultStream{};
    Node *currentNode = this->head;

    while (currentNode != this->tail) {
        resultStream << currentNode->getValue() << ' ';
        currentNode = currentNode->getNext();
    }
    resultStream << this->tail->getValue();

    return resultStream.str();
}


int List::first() const {
    return this->head->getValue();
}


List &List::operator=(const List &other) {
    if (this == &other)
        return *this;

    removeAll();
    this->size = other.getSize();

    if (!other.head || !other.tail)
        return *this;

    this->head = new Node{other.head->getValue(), nullptr, nullptr};
    Node* currentOther = other.head->getNext();
    Node* previous = this->head;

    while (currentOther) {
        Node* currentThis = new Node{currentOther->getValue(), previous, nullptr};
        previous->setNext(currentThis);

        currentOther = currentOther->getNext();
        previous = currentThis;
    }

    if (other.tail)
        this->tail = previous;

    return *this;
}


List::List(const List &other) {
    this->size = other.getSize();

    if (!other.head || !other.tail) {
        this->head = nullptr;
        this->tail = nullptr;

    } else {
        this->head = new Node{other.head->getValue(), nullptr, nullptr};
        Node* currentOther = other.head->getNext();
        Node* previous = this->head;

        while (currentOther) {
            Node* currentThis = new Node{currentOther->getValue(), previous, nullptr};
            previous->setNext(currentThis);

            currentOther = currentOther->getNext();
            previous = currentThis;
        }

        this->tail = previous;
    }
}


List::~List() {
    Node* current = this->head;

    while (current) {
        Node* next = current->getNext();
        // std::cout << "Deleting element " << current->getValue() << '\n';
        delete current;
        current = next;
    }
}


List List::getReversed(List l) {
    if (!l.head || !l.tail)
        return List{};

    List reversedList{};

    Node* currentOrderedNode = l.tail;
    reversedList.head = new Node{currentOrderedNode->getValue(), nullptr, nullptr};
    Node* previousReversedNode = reversedList.head;
    currentOrderedNode = currentOrderedNode->getPrev();

    while (currentOrderedNode != l.head) {
        Node* currentReversedNode = new Node{currentOrderedNode->getValue(), previousReversedNode, nullptr};
        previousReversedNode->setNext(currentReversedNode);
        previousReversedNode = currentReversedNode;
        currentOrderedNode = currentOrderedNode->getPrev();
    }

    reversedList.tail = new Node{currentOrderedNode->getValue(), previousReversedNode, nullptr};
    previousReversedNode->setNext(reversedList.tail);

    return reversedList;
}


void List::addAll(const List &other) {
    if (!other.head || !other.tail)
        return;

    Node* currentOtherNode = other.head;

    if (other.head->getValue() > this->tail->getValue()) {
        Node* previousNode = this->tail;

        while (currentOtherNode != other.tail) {
            Node* currentNode = new Node{currentOtherNode->getValue(), previousNode, nullptr};
            previousNode->setNext(currentNode);
            previousNode = currentNode;
            currentOtherNode = currentOtherNode->getNext();
        }

        this->tail = new Node{currentOtherNode->getValue(), previousNode, nullptr};
        previousNode->setNext(this->tail);

    } else if (other.tail->getValue() < this->head->getValue()) {
        Node* newHead = new Node{other.head->getValue(), nullptr, nullptr};
        Node* previousNode = newHead;
        Node* currentOtherNode = other.head->getNext();

        while (currentOtherNode != other.tail) {
            Node* currentNode = new Node{currentOtherNode->getValue(), previousNode, nullptr};
            previousNode->setNext(currentNode);
            previousNode = currentNode;
            currentOtherNode = currentOtherNode->getNext();
        }

        Node* linkNode = new Node{currentOtherNode->getValue(), previousNode, this->head};
        previousNode->setNext(linkNode);
        this->head->setPrev(linkNode);
        this->head = newHead;

    } else {
        while (currentOtherNode != other.tail) {
            add(currentOtherNode->getValue());
            currentOtherNode = currentOtherNode->getNext();
        }

        add(currentOtherNode->getValue());
    }
}


List &List::operator<<(const List &other) {
    addAll(other);

    return *this;
}
