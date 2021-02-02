#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : BinaryTree() {}

void BinarySearchTree::CreateR() {
	char choice;
	string data;
	if (Root != NULL) {
		cout << "Tree not empty.Delete?" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			Erase();
		}
	}


	do {
		cout << "Enter the data" << endl;
		cin >> data;
		Root = CreateR(Root,data);
		cout << "Do you want to continue?" << endl;
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

Node* BinarySearchTree::CreateR(Node* temp,string data)
{
	if (temp == nullptr) {
		temp = new Node();
		temp->Data = data;
		return temp;
	}
	if (temp->Data > data) {
		temp->Left = CreateR(temp->Left, data);
	}
	else if (temp->Data < data) {
		temp->Right = CreateR(temp->Right, data);
	}
	else {
		cout << "Error." << endl;
	}
	return temp;
}

void BinarySearchTree::CreateNR()
{
	Node* temp;
	char choice;
	string data;

	if (Root != nullptr) {
		cout << "Tree Present\nDelete? Y/N" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			Erase();
		}
	}
	if (Root == nullptr) {
		Root = new Node();
		cout << "Enter the root data" << endl;
		cin>>Root->Data;

	}
	do {
		temp = Root;
		cout << "Enter the data" << endl;
		cin >> data;
		while (1) {
			if (temp->Data > data) {
				if (temp->Left == nullptr) {
					temp->Left = new Node();
					temp->Left->Data = data;
					break;
				}
				else {
					temp = temp->Left;
				}
			}
			else if (temp->Data < data) {
				if (temp->Right == nullptr) {
					temp->Right = new Node();
					temp->Right->Data = data;
					break;
				}
				else {
					temp = temp->Right;
				}
			}
			else {
				cout << "Error.Data Exists" << endl;
				break;
			}
		}
		cout << "Do you want to continue? Y/N" << endl;
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void BinarySearchTree::Search()
{
	string data;
	Node** temp;//Stores the node and its parent values
	cout << "\n\nEnter the node to be searched" << endl;
	cin >> data;
	temp = Search(data);
	if(temp[0]==nullptr){
		cout << "Node absent in tree" << endl;
	}
	else {
		cout << "Node->" << temp[0]->Data << flush;
		if (temp[1]!=nullptr)
		cout << "\nParent->" << temp[1]->Data << endl;

	}

}

Node** BinarySearchTree::Search(string data) {
	Node** retvar = new Node * [2];
	retvar[0] = retvar[1] = nullptr;
	Node* temp = Root;
	Node* parent = nullptr;
	while (temp!=nullptr) {
		if (temp->Data == data) {
			retvar[0] = temp;
			retvar[1] = parent;
			break;
		}
		else if (temp->Data > data) {
			parent = temp;
			temp = temp->Left;
		}
		else {
			parent = temp;
			temp = temp->Right;
		}
	}
	return retvar;
}

int BinarySearchTree::Delete()
{
	string delData;
	Node** temp;
	Node* parent,*child;
	
	cout << "\n\nEnter the node to be searched" << endl;
	cin >> delData;
	temp=Search(delData);
	child = temp[0];
	parent = temp[1];

	if (child == Root) {
		if (child->Left == nullptr && child->Right == nullptr) {
			Root = nullptr;
		}
		else if (child->Left == nullptr && child->Right != nullptr) {
			Root = Root->Right;
		}
		else if (child->Left != nullptr && child->Right == nullptr) {
			Root = Root->Left;
		}
		else {
			Node* trvse = child->Right;
			while (trvse->Left != nullptr) {
				trvse = trvse->Left;
			}
			trvse->Left = child->Left;
			Root = Root->Right;
		}
		delete child;
	}
	else {
		if (child->Left == nullptr && child->Right == nullptr) {
			if (parent->Left == child) {
				parent->Left = nullptr;
			}
			else if (parent->Right == child) {
				parent->Right = nullptr;
			}
		}
		else if (child->Left != nullptr && child->Right == nullptr) {
			if (parent->Left == child) {
				parent->Left = child->Left;
			}
			else if (parent->Right == child) {
				parent->Right = child->Left;
			}
		}
		else if (child->Left == nullptr && child->Right != nullptr) {
			if (parent->Left == child) {
				parent->Left = child->Right;
			}
			else if (parent->Right == child) {
				parent->Right = child->Right;
			}
		}
		else {
			Node* trvse;
			trvse = child->Right;
			while (trvse->Left != nullptr) {
				trvse = trvse->Left;
			}
			trvse->Left = child->Left;
			if (parent->Left == child) {
				parent->Left = child->Right;
			}
			else if (parent->Right == child) {
				parent->Right = child->Right;
			}
		}
		delete child;
	}

	return 0;
}

