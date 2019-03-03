#include <iostream>
struct Node {
int data;
Node* next = NULL;
int max;
};
class int_stack_with_maxim {
private:
Node* head;
int n;
public:
int_stack_with_maxim() : head(NULL), n(0) {}
void push_frt(int x) {
Node* temp = new Node;
if (n == 0) {
temp->max = x;
}
else {
if (x > head->max) {
temp->max = x;
}
else {
temp->max = head->max;
}
}
temp->data = x;
temp->next = head;
head = temp;
n += 1;
}
int pop_frot() {
if (head == NULL) {
return 0;
}
int x = head->data;
head = head->next;
n -= 1;
return x;
}
int maximum() {
int a = head->max;
return a;
}
int number() {
return n;
}
~int_stack_with_maxim() {
while (head != NULL) {
Node* temp = head;
head = head->next;
delete temp;
}
}
}
