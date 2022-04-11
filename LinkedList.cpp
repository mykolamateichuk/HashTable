#include "LinkedList.h"
#include <iostream>

using namespace std;

long long generateRandLong() {
    long long number = 0;
    unsigned int numberOfDigits = rand() % 5 + 11;

    unsigned int digit;
    for (int i = 0; i < numberOfDigits; i++) {
        if (i == numberOfDigits - 1) {
            digit = rand() % 9 + 1;
        }
        else {
            digit = rand() % 10;
        }

        number += digit * (int) (pow(10, i));
    }

    return number;
}

const string colorArray[] = {"red", "blue", "grey", "black", "white", "yellow"};

Data::Data() {
    this->number = rand() % 11 + 3;
    this->color = colorArray[rand() % 6];
    this->withCharger = rand() % 2;
}

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr) {
        temp = current;
        delete current;


        current = temp->next;
    }
}

void LinkedList::print() {
    Node *current = head;
    int count = 1;

    while (current != nullptr) {
        cout << "Node" << count << " [";
        cout << current->value->data.number << " ";
        cout << current->value->data.color << " ";
        cout << current->value->data.withCharger << "]"<< endl;

        current = current->next;
        count++;
    }
}

void LinkedList::push_back(HashNode *data) {
    Node *new_node = new Node();
    new_node->value = data;

    if (!head) {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
    new_node->next = nullptr;
}

HashNode* LinkedList::get(long long key) {
    Node *current = head;

    while (current != nullptr) {

        if (current->value->key == key) {
            return current->value;
        }

        current = current->next;
    }
}

int LinkedList::size() {
    Node *current = head;
    int count = 0;

    while (current != nullptr) {
        current = current->next;
        count++;
    }

    return count;
}

void LinkedList::remove(long long key) {
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {

        if (current->value->key == key) {
            if (!prev) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }

            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}


