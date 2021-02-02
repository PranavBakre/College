#include "Graph.h"

Graph::Graph()
{
	n = 0;
	for (int i = 0; i < max; i++) {
		Users[i] = nullptr;
	}
}

void Graph::CreateAL()
{
	int AccountCounter, iterator = 0, frndPtr = 0;
	char choice;
	string frname;
	Node* frtemp, *temp;
	cout << "\n\nEnter the number of users" << endl;
	cin >> n;
	for (AccountCounter = 0; AccountCounter < n; AccountCounter++) {
		Users[AccountCounter] = new Node();
		cout << "Enter the user name" << endl;
		cin >> Users[AccountCounter]->name;
	}
	while (iterator < AccountCounter) {
		cout << "Enter the friends of User: " << Users[iterator]->name << endl;
		do {
			cin >> frname;
			if (frname == Users[iterator]->name) {
				cout << "Error.One cannot be a friend of himself" << endl;
			}
			else if (Friend_Exists(iterator,frname)) {
				cout << "Error.Friend already present\n\n" << endl;
			}
			else {
				if (Account_Exists(frname)<0) {
					cout << "User doesnt exist\n\nCreate a new user\n\n" << endl;
					cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						Users[AccountCounter] = new Node();
						Users[AccountCounter++]->name = frname;
						n++;
					}
				}
				if ((frndPtr=Account_Exists(frname))>=0) {
					temp = new Node();
					temp->name = Users[frndPtr]->name;
					temp->friends = Users[iterator]->friends;
					Users[iterator]->friends = temp;
					if (!Friend_Exists(frndPtr, Users[iterator]->name)) {
						frtemp = new Node();
						frtemp->name = Users[iterator]->name;
						frtemp->friends = Users[frndPtr]->friends;
						Users[frndPtr]->friends = frtemp;
					}
				}
			}

			cout << "Do you want to add another friend ? Y/N \n\n" << endl;
			cin >> choice;
		} while (choice=='y' || choice=='Y');
		iterator++;
	}


}

bool Graph::Friend_Exists(int i, string chfriend)
{
	Node* temp = Users[i]->friends;
	while (temp != nullptr) {
		if (temp->name == chfriend) {
			return true;
		}
		temp = temp->friends;
	}
	return false;
}

int Graph::Account_Exists(string name)
{
	int i;
	for (i = 0; i < n; i++) {
		if (Users[i]->name == name)
			return i;
	}
	return -1;
}

void Graph::displayF(int i)
{
	Node* temp = Users[i]->friends;
	while (temp != nullptr) {
		
		cout << temp->name << flush;
		if (temp->friends != nullptr)
			cout << "," << flush;
		else 
			cout << endl;
		temp = temp->friends;
	}
}

void Graph::displayALL()
{
	int i;
	for (i = 0; i < n; i++) {
		cout << "Friends of " << Users[i]->name<< " : \t" << flush;
		displayF(i);
	}
}

void Graph::BFS()
{

	Queue q;
	Node* temp;// , * next;
	string username;

	bool visited[max] = {false};

	int i;
	do {
		cout << "Enter the starting user\n" << endl;
		cin >> username;
		i = Account_Exists(username);
	} while (i < 0);
	temp = Users[i];
	q.Enqueue(temp);
	visited[i] = true;
	while (!q.Empty()) {
		temp = q.Dequeue();
		cout << temp->name;
		temp = temp->friends;
		while (temp != nullptr) {
			i = Account_Exists(temp->name);
			if (!visited[i]) {
				q.Enqueue(Users[i]);
				visited[i] = true;
			}
			temp = temp->friends;
		}
		
	}
	cout << endl;
}

void Graph::DFSNR()
{
	Stack s;
	Node* temp;
	string username;
	int i;
	bool visited[max] = {false};
	do {
		cout << "Enter the start user name" << endl;
		cin >> username;
		i = Account_Exists(username);
	} while (i < 0);
	temp = Users[i];
	visited[i] = true;
	s.Push(temp);
	while (!s.Empty()) {
		temp = s.Pop();
		cout << temp->name;
		temp = temp->friends;
		while (temp != nullptr) {
			i = Account_Exists(temp->name);
			if (!visited[i]) {
				s.Push(Users[i]);
				visited[i] = true;
			}
			temp = temp->friends;
		}
		
	}
	cout << endl;


}
void Graph::DFSR() {
	string username;
	int i;
	bool visited[max] = { false };
	cout << "Enter the starting user" << endl;
	cin >> username;
	do {
		i = Account_Exists(username);
	} while (i < 0);
	visited[i] = true;
	cout << Users[i]->name << flush;
	DFSR(visited, i);
}
void Graph::DFSR(bool visited[], int i)
{
	Node* temp = Users[i];
	while (i >= 0) {
		if (temp->friends == nullptr) {
			return;
		}

		i = Account_Exists(temp->friends->name);
		if (!visited[i]) {
			cout << Users[i]->name;
			visited[i] = true;
			DFSR(visited, i);
		}
		temp = temp->friends;
		

	}

}
