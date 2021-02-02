#include "Stack.h"

Stack::Stack() {
	Top = - 1;
	for (int i = 0; i < max; i++) {
		Data[i] = nullptr;
	}
}

void Stack::Push(Node* temp) {
	Top++;
	Data[Top] = temp;
	
}

Node* Stack::Pop() {
	Node* temp = Data[this->Top];
	Data[Top] = nullptr;
	Top--;
	return temp;
}

Node* Stack::RetTop()
{
	return Data[Top];
}

int Stack::Empty() {
	if (Top == -1) {
		return 1;
	}
	return 0;
}

int Stack::Full() {
	if (Top == max - 1) {
		return 1;
	}
	return 0;
}