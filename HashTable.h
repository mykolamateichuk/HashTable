#ifndef LAB2_ASD2_2_HASHTABLE_H
#define LAB2_ASD2_2_HASHTABLE_H
#include "LinkedList.h"

struct HashTable {
    int capacity = 2;
    int currentSize = 0;
    const float maxLoadFactor = 4;
    float loadFactor;

    LinkedList *bucketsArray = new LinkedList[capacity];

    int hash(long long key);
    void insert(long long key, Data data);
    void resize(HashNode *node);
    Data *find(long long key);
    void erase(long long key);
    int size();
    void print();

    ~HashTable();
};

#endif //LAB2_ASD2_2_HASHTABLE_H
