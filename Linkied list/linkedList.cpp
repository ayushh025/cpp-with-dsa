#include<iostream>
using namespace std;

/* Node Class */
class Node{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

/* Linked List Class */
class LinkedList{
private:
    Node* head;

public:
    // Constructor
    LinkedList(){
        head = NULL;
    }

    // Insert at beginning
    void insert_at_beginning(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Append at end
    void append(int data){
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display list
    void display(){
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        while (temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search element
    void search(int key){
        Node* temp = head;
        int pos = 1;

        while (temp != NULL){
            if (temp->data == key) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found" << endl;
    }

    // Delete node by value
    void delete_node(int key){
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == key){
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Node deleted" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key){
            temp = temp->next;
        }

        if (temp->next == NULL){
            cout << "Node not found" << endl;
        } else {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "Node deleted" << endl;
        }
    }

    // Reverse linked list
    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
        cout << "Linked list reversed" << endl;
    }
};

/* Main Function */
int main(){
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.insert_at_beginning(5);

    cout << "Linked List: ";
    list.display();

    list.search(20);

    list.delete_node(10);
    list.display();

    list.reverse();
    list.display();

    return 0;
}

