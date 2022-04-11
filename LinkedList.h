#ifndef LAB2_ASD2_2_LINKEDLIST_H
#define LAB2_ASD2_2_LINKEDLIST_H
#include <string>
#include <cmath>
using namespace std;

long long generateRandLong();

struct Data {
    int number;
    string color;
    bool withCharger;

    Data();
};

struct HashNode {
    Data data;
    long long key;
};

struct Node {
    HashNode *value;
    Node *next;
};

struct LinkedList {
    Node *head;
    Node *tail;

    LinkedList();

    void print();
    void push_back(HashNode *data);
    HashNode* get(long long key);
    int size();
    void remove(long long key);

    ~LinkedList();
};

#endif //LAB2_ASD2_2_LINKEDLIST_H
