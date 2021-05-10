#pragma once
struct SingleNode {
	int data;
	struct SingleNode* next;
};
void insertSingle(int newdata);
void display();