#include "Queue.h"

Queue::Queue()
{
	for (int i = 0; i < max; i++) {
		Data[i] = nullptr;
	}
	Rear = Front = max - 1;
}

void Queue::Enqueue(Node *temp){
	Rear = (Rear + 1) % max;
	Data[Rear] = temp;

}
Node* Queue::Dequeue() {
	Front = (Front + 1) % max;
	Node* temp=Data[Front];
	Data[Front] = nullptr;
	return temp;


}

int Queue::Empty() {
	if (Rear == Front) {
		return 1;
	}
	return 0;
}

int Queue::Full() {
	if ((Rear + 1) % max == Front) {
		return 1;
	}
	return 0;
}