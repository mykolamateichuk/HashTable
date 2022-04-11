#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::~HashTable() {
    delete[] bucketsArray;
}

int HashTable::hash(long long key) {
    return ((117 * key + 227) % 7250517191) % capacity;
}


void HashTable::resize(HashNode *node) {
    capacity *= 2;
    LinkedList *newBucketsArray = new LinkedList[capacity];
    LinkedList *temp = bucketsArray;
    Node *current;

    bucketsArray = newBucketsArray;
    for (int i = 0; i < capacity / 2; i++) {
        current = temp[i].head;

        if (current) {

            while (current != nullptr) {

                insert(current->value->key, current->value->data);

                current = current->next;
            }

        }
    }


    delete [] temp;
    insert(node->key, node->data);
}

void HashTable::insert(long long key, Data data) {
    int index = hash(key);
    HashNode *new_node = new HashNode();
    new_node->data = data;
    new_node->key = key;

    if (find(key) != nullptr) {
        bucketsArray[index].get(key)->data = data;
        return;
    }

    loadFactor = (float) currentSize / (float) capacity;

    if (loadFactor >= maxLoadFactor) {
        resize(new_node);
        currentSize++;
    }
    else {
        bucketsArray[index].push_back(new_node);
        currentSize++;
    }
}

Data *HashTable::find(long long key) {
    int index = hash(key);
    Node *current = bucketsArray[index].head;

    while (current != nullptr) {

        if (current->value->key == key) {
            return &current->value->data;
        }

        current = current->next;
    }
    return nullptr;
}

void HashTable::erase(long long key) {
    int index = hash(key);
    Node *current = bucketsArray[index].head;

    while (current != nullptr) {

        if (current->value->key == key) {
            bucketsArray[index].remove(key);
            currentSize--;
            return;
        }

        current = current->next;
    }
}

int HashTable::size() {
    int size = 0;

    for (int i = 0; i < capacity; i++) {
        size += bucketsArray[i].size();
    }

    return size;
}

void HashTable::print() {
    Node *current = nullptr;

    for (int i = 0; i < capacity; i++) {
        current = bucketsArray[i].head;

        if (current) {
            cout << "(" << i << ") \t";
            while (current != nullptr) {

                cout << current->value->key << "\t[";
                cout << current->value->data.number << " ";
                cout << current->value->data.color << " ";
                cout << current->value->data.withCharger << "] \t";

                current = current->next;
            }
            cout << endl;
        }
    }
}




