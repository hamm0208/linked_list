#include <iostream>
#include "NodeIterator.h"
#include "Node.h"
using namespace std;

void insertMiddle(Node* prevNode, int value) {
	if (prevNode == (Node*)0) {
		cout << "The given previous node cannot be a null Node pointer.";
		return;
	}
	Node* newNode = new Node(value);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void displayList(Node* head) {
	for (NodeIterator iter(head); iter != iter.end(); ++iter) {
		cout << *iter << "-> ";
	}
	cout << "End" << endl;
}

void removeNode(Node* prevNode) {
	Node* temp = prevNode->next;
	prevNode->next = prevNode->next->next;
	delete temp;
}

int main() {
	int arr[] = { 1, 2, 2, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Node* head = (Node*)0;
	/*	
	for (int x = 0; x < size; x++) {
		Node* newNode = new Node(arr[x]);
		newNode->next = head;
		head = newNode;
	}
	*/
	
	/**/
	for (int x = 0; x < size; x++) {
		Node* newNode = new Node(arr[x]);
		newNode->next = (Node*)0;
		if (head == (Node*)0) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != (Node*)0) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	Node* ptr = head;

	ptr = head->next->next->next;
	insertMiddle(ptr, 99);
	removeNode(head->next);
	displayList(head);
	/*
	while (ptr != (Node*)0) {
		cout << ptr->value << endl;
		ptr = ptr->next;
	}

	ptr = head;
	*/
	while (ptr != (Node*)0) {
		Node* temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
	return 0;
}