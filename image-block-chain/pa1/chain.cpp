#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
/* !!! */
    Node* curr = walk(head_, size());

    Node* newNode = new Node(ndata);
    curr->next = newNode;
    newNode->next = head_;

    length_ += 1;
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
/* !!! */

if (i == j) return;

if (i > size() || j > size()) return;

// get node i
Node* node1_prev;
Node* node1 = walk(head_, i);
if (i == 1) {
    node1_prev = head_;
} else {
    node1_prev = walk(head_, i-=1);
}

// get node j
Node* node2_prev;
Node* node2 = walk(head_, j);
if (j == 1) {
    node2_prev = head_;
} else {
    node2_prev = walk(head_, j-=1);
}

if (node1 == NULL || node2 == NULL || node1_prev == NULL || node2_prev == NULL) return;

// reassignment statements that swap node1 and node2

// cases where i and j are directly beside eachother 
if (node1->next == node2){
    node1_prev->next = node2;
    node1->next = node2->next;
    node2->next = node1;;
    return;
} 
if (node2->next == node1){
    node2_prev->next = node1;
    node2->next = node1->next;
    node1->next = node2;
    return;
} 

// case where i and j are not directly beside eachother 
    Node* temp = node2->next; 
    node1_prev->next = node2;
    node2_prev->next = node1;
    node2->next = node1->next;
    node1->next = temp;
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
/* !!! */
Node* prev = head_;
Node* curr = head_->next;

for (int i = 0; i < size(); i++){
    Node* temp = curr->next; 
    curr->next = prev;
    head_->next = curr;
    prev = curr; 
    curr = temp;
}

}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
    /*
    if (empty() || k == 1 || k > length_) return;

    int pos = 1;
    Node * curr = head_->next;
    Node * subStart = head_->next;
    Node * beforeSubStart = head_;
    while (true) {
        if (pos % k == 0) {
            beforeSubStart->next = subStart->next;
            subStart->next = curr->next;
            curr->next = subStart;


            beforeSubStart = subStart;
            curr = subStart;
            subStart = subStart->next;
        }
        if (curr->next == head_) return;
        curr = curr->next;
        pos++;
    }
    */

/* !!! */
if (k == 1 || empty()|| k > length_) return;

int first_index = 1;
int k_index = k;
int remaining_length = size();

while (remaining_length >= k) {
    swap(first_index, k_index);
    first_index += k;
    k_index += k;
    remaining_length -= k;
}

}

/**
 * Destroys ALL dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
/* !!! */
if(head_ == nullptr) return; 

Node* curr = head_->next;
Node* next = nullptr;
int count = length_;
while (count) {
    next = curr->next; 
    delete curr;
    curr = next; 
    count -= 1;
}
delete head_;
head_ = nullptr;
length_ = 0;
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
/* !!! */
cout << __LINE__<<endl;
clear();
cout << __LINE__<<endl;

width_ = other.width_;
height_ = other.height_;
length_ = 0;
head_ = new Node();
head_->next = head_;

for(int i = 0; i < other.length_; i++) {
    Node* curr = walk(other.head_, i+1);
    Block b = curr->data;
    insertBack(b);
}

}


