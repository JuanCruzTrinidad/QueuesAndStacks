#pragma once
struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};
void insert(int newdata);
void displayLIFO();
void displayFIFO();