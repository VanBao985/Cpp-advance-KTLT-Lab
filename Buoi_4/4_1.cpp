#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node *tmp = new Node(data);
    if (head == NULL){
        head = tmp;
        return head;
    }
    tmp -> next = head;
    return tmp;
}
// print the list content on a line
void print(Node* head) {
    Node *tmp = head;
    while (tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}
// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* temp = NULL;
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
    return head;
}
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
    cin >> u;
    head = prepend(head, u);
    }
    cout << "Original list: ";
    print(head);
    head = reverse(head);
    cout << "Reversed list: ";
    print(head);
    return 0;
}