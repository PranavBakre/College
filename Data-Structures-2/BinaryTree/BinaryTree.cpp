// BinaryTree.cpp : This file contains function definition of the functions declared in BinaryTree.h header
//


#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

BinaryTree::BinaryTree() {
	Root = nullptr;
}

void BinaryTree::CreateNR() {
	Node* temp,*nextnode;
	char choice,pos;
	if (Root != nullptr) {
		cout << "\nTree Present. Delete Tree? Y/N" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			cout<<Erase();
		}

	}

	if (Root == nullptr) {
		Root = new Node();
		cout << "Enter the root data" << endl;
		cin >> Root->Data;
	}



	cout << "Add a node? Y/N" << endl;
	cin >> choice;
	while(choice=='y' || choice=='Y') {
		temp = Root;
		nextnode = new Node();
		cout << "Enter the node data" << endl;
		cin >> nextnode->Data;

		while (1) {
			cout << "Enter the position of the node- L/R " << endl;
			cin >> pos;
			if (pos == 'l' || pos == 'L') {
				if (temp->Left == nullptr) {
					temp->Left = nextnode;
					break;
				}
				else {
					cout << "Jumping to next level" << endl;
					temp = temp->Left;
				}
			}
			else if (pos == 'r' || pos == 'R') {
				if (temp->Right == nullptr) {
					temp->Right = nextnode;
					break;
					}
				else {
					cout << "Jumping to next level" << endl;
					temp = temp->Right;
				}

			}
		}
		cout << "Do you want to continue? Y?N" << endl;
		cin >> choice;
	}
}

void BinaryTree::PreorderNR() const
{
	Stack s;
	Node* temp = Root;
	cout << endl;
	while (1) {
		while (temp != nullptr) {
			cout << temp->Data << "\t" << flush;
			s.Push(temp);
			temp = temp->Left;

		}
		if (s.Empty()) {
			break;
		}
		else {
			temp = s.Pop();
			temp = temp->Right;
		}
	}
}

void BinaryTree::InorderNR() const {
	Stack s;
	Node* temp = Root;
	cout << endl;
	while (1) {
		while (temp != nullptr) {
			s.Push(temp);
			temp = temp->Left;
		}
		if (s.Empty()) {
			break;
		}
		temp = s.Pop();
		cout << temp->Data << "\t" << flush;
		temp = temp->Right;

	}
}


void BinaryTree::PostorderNR() const {
	Stack s;
	Node* temp = Root;
	cout << endl;

	while (1) {
		while (temp != nullptr) {
			s.Push(temp);
			temp = temp->Left;
		}
		while (!s.Empty() && s.RetTop()->Right == temp) {
			temp = s.Pop();
			cout << temp->Data << "\t" << flush;
		}
		if (s.Empty()) {
			break;
		}
		temp = s.RetTop()->Right;
	}

}

void BinaryTree::CreateR()
{
	char choice;
	if (Root != nullptr) {
		cout << "\nTree Present. Delete Tree? Y/N" << endl;
		cout << flush;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			Erase();
	;
		}
		
	}

	Root=CreateR(Root);
}

Node* BinaryTree::CreateR(Node* temp)
{
	char choice1;

	if (temp == nullptr) {
		temp = new Node();
		cout << "Enter the data" << endl;
		cin >> temp->Data;
	}
		cout << "Add node on the left of " << temp->Data << endl;
		cin >> choice1;
		if (choice1 == 'y' || choice1 == 'Y')
			temp->Left = CreateR(temp->Left);
		cout << "Add node on the Right of " << temp->Data << endl;
		cin >> choice1;
		if (choice1 == 'y' || choice1 == 'Y')
			temp->Right = CreateR(temp->Right);

	return temp;
}



void BinaryTree::PreorderR() const {
	cout << endl;
	PreorderR(Root);
}
void BinaryTree::PreorderR(Node* temp) const {
	if (temp != nullptr) {
		cout << temp->Data <<"\t"<< flush;
		PreorderR(temp->Left);
		PreorderR(temp->Right);
	}
}

void BinaryTree::InorderR() const {
	cout << endl;
	InorderR(Root);
}

void BinaryTree::InorderR(Node* temp) const {
	if (temp != nullptr) {
		InorderR(temp->Left);
		cout << temp->Data<<"\t"<<flush;
		InorderR(temp->Right);
	}
}

void BinaryTree::PostorderR() const {
	cout << endl;
	PostorderR(Root);
}

void BinaryTree::PostorderR(Node *temp) const {
	if (temp != NULL) {
		PostorderR(temp->Left);
		PostorderR(temp->Right);
		cout << temp->Data << "\t" << flush;
	}
}

int BinaryTree::Erase()
{
	int retval=Erase(Root);
	Root = nullptr;
	return retval;
}

int BinaryTree::Erase(Node* temp) {
	if (temp != nullptr) {
		Erase(temp->Left);
		Erase(temp->Right);
		delete(temp);
		temp = nullptr;

		return 1;
	}
	return 0;
}


void BinaryTree::Height()
{
	cout << "\nHeight of BinaryTree is : " << Height(Root) << endl;
}

int BinaryTree::Height(Node* temp) {

	int h1, h2;
	if (temp == nullptr) {
		return 0;
	}
	return ((h1 = Height(temp->Left)) > (h2 = Height(temp->Right))) ? ++h1 : ++h2;
}

void BinaryTree::Bfs()
{
	Queue q;

	Node* temp = Root;
	q.Enqueue(temp);
	while (!q.Empty()) {
		temp = q.Dequeue();
		cout << temp->Data << "\t" << flush;
		if (temp->Left != nullptr) {
			q.Enqueue(temp->Left);
		}
		if (temp->Right != nullptr) {
			q.Enqueue(temp->Right);
		}
	}
}
