#include <iostream>
struct Node {
char data;
Node* next;
Node* prev = NULL;
}
class char_deque {
private:
Node* head;
Node* tail;
public:
char_deque(): head(NULL) {}
void push_front(char x) {
Node* temp = new Node;
temp->next = head;
head->prev = temp;
temp->data = x;
head = temp;
}
void push_back(char x) {
Node* temp = new Node;
temp->prev = head;
head->next = temp;
temp->data = x;
head = temp;
}
char pop_front() {
Node* temp = head;
while (temp->next) {
temp = temp->next;
}
char x = temp->data;
delete temp;
return x;
}
char pop_back() {
Node* temp = tail;
while (temp->prev) {
temp = temp->prev;
}
char x = temp->data;
delete temp;
return x;
}
}
