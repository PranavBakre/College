
#include<iostream>
#define max 10
#define max2 100
//#include"node.h"
//#include"stack.h"

using namespace std;

class node
{

	node* left, * right;
	string name, message;
public:
	friend class bst;
	friend class stack;
	friend class queue;
	node();
};

node::node()
{
	left = right = NULL;

}

#define max 10


class stack
{

	int top;
	node* data[max];

public:
	friend class bst;
	stack()
	{
		top = -1;
	}
	void push(node* temp)
	{
		top++;
		data[top] = temp;

	}
	node* pop()
	{
		node* temp;
		temp = data[top];
		data[top] = NULL;
		top--;
		return temp;
	}
	int isemp()
	{
		if (top == -1)
			return 1;
		return 0;
	}
};


class Queue
{

	node* data[max2];
	int f, r;
public:
	friend class bst;
	Queue()
	{

		f = r = -1;
	}
	void enqueue(node* temp)
	{
		r++;
		data[r] = temp;
	}
	node* dequeue()
	{
		node* temp;
		f++;
		temp = data[f];
		data[f] = NULL;
		return temp;

	}
	int isemp()
	{
		if (f == r)
			return 1;
		return 0;

	}


};


stack s;
Queue q;
class bst
{
	node* root;
public:
	bst();
	//Create a BST recursively
	void create();
	node* createR(node* = NULL, node* = NULL);
	//New CreateR
	void newcreateR()
	{
		char ch;
		string wandmean[2];
		if (root != NULL)
		{
			cout << "Create a new tree?\n";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
				erase();//Doubt 2: Segmentation fault in certain cases and doesnt work in others.Please check output
		}

		do {
			cout << "Enter word and meaning\n";
			cin >> wandmean[0] >> wandmean[1];
			root = newCreateR(root, wandmean);
			cout << "Continue?\n";
			cin >> ch;

		} while (ch == 'y' || ch == 'Y');
	}
	node* newCreateR(node* temp, string wordandmean[2])
	{
		if (temp == NULL)
		{
			temp = new node();
			temp->name = wordandmean[0];
			temp->message = wordandmean[1];
			return temp;
		}
		if (wordandmean[0] < temp->name)
			temp->left = newCreateR(temp->left, wordandmean);
		else if (wordandmean[0] > temp->name)
			temp->right = newCreateR(temp->right, wordandmean);
		return temp;
	}
	//Create a BST non-recursively
	void createNR();
	//Recursive Display
	void predisplay();
	void predisplay(node*);
	void indisplay();
	void indisplay(node*);
	void postdisplay();
	void postdisplay(node*);
	//Non-recursive display
	void preNRdisplay();
	void inNRdisplay();
	void postNRdisplay();
	void bfs();
	//Height of the tree
	int height(node*);
	int height();
	//Search function
	node** search();
	node** search(node*, string);
	//Delete a node from the tree
	void delnode();//
	//Recursive Copy tree
	node* copytreeR();
	void copytreeR(bst);
	node* copytreeR(node*);

	//Non-recursive Copy tree
	void copytreeNR(bst);//
	node* copytreeNR();
	//recursive mirror
	void mirrorR();//
	void mirrorR(node*);
	//Non-recursive mirror
	void mirrorNR();

	void erase(node*);
	void erase();


};
bst::bst()
{
	root = NULL;
}


//Create a BST recursively
void bst::create()
{
	char ch;

	if (root != NULL)
	{
		cout << "Create a new tree?\n";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			erase();//Doubt 2: Segmentation fault in certain cases and doesnt work in others.Please check output
	}

	do
	{
		root = createR(root);

		cout << "Create a node?\n";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');//Do while loop to add more nodes
}
node* bst::createR(node* root, node* temp)
{
	if (root == NULL)
	{
		root = new node();
		cout << "Enter the name\n";
		cin >> root->name;
		cout << "Enter the description\n";
		cin >> root->message;
		root->left = root->right = NULL;
		createR(root);
	}
	else
	{

		if (temp == NULL)
		{
			temp = new node();
			temp->left = temp->right = NULL;
			cout << "Enter the node name\n";
			cin >> temp->name;
			cout << "Enter the node description\n";
			cin >> temp->message;

		}



		if (temp->name > root->name)
		{
			if (root->right == NULL)
				root->right = temp;
			else
			{
				createR(root->right, temp);
			}
		}
		else if (temp->name < root->name)
		{
			if (root->left == NULL)
				root->left = temp;
			else
			{
				createR(root->left, temp);
			}
		}
		else
		{
			cout << "Error.name exists\n";
		}
	}
	return root;
}

//Create a BST non-recursively
void bst::createNR()
{
	int flag = 0;
	char choice, ch;
	node* curr, * temp;
	if (root != NULL)
	{
		cout << "Create a new tree?\n";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			this->erase();
	}
	do
	{
		if (root == NULL)
		{
			root = new node();
			cout << "Enter the root name\n";
			cin >> root->name;
			cout << "Enter the root meaning\n";
			cin >> root->message;
			root->left = root->right = NULL;
		}
		else
		{
			flag = 0;
			curr = root;
			temp = new node();
			cout << "Enter the name\n";
			cin >> temp->name;
			cout << "Enter the meaning\n";
			cin >> temp->message;
			temp->left = temp->right = NULL;
			while (flag == 0)
			{

				if (curr->name > temp->name)
				{
					if (curr->left == NULL)
					{
						curr->left = temp;
						flag = 1;
					}
					else
					{
						curr = curr->left;
					}

				}
				else if (curr->name < temp->name)
				{
					if (curr->right == NULL)
					{
						curr->right = temp;
						flag = 1;
					}
					else
					{
						curr = curr->right;

					}
				}
				else if (curr->name == temp->name)
				{
					cout << "Error.Duplicate key\n";
					delete(temp);
					flag = 1;
				}
			}
		}
		cout << "Do you want to add a node\n";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

//Recursive Display
void bst::predisplay(node* root)
{
	if (root != NULL)
	{
		cout << root->name << "-" << root->message << endl;

		predisplay(root->left);


		predisplay(root->right);

	}
}

void bst::predisplay()
{
	predisplay(root);
}

void bst::indisplay()
{
	indisplay(root);
}

void bst::indisplay(node* root)
{
	if (root != NULL)
	{
		indisplay(root->left);
		cout << root->name << "-" << root->message << endl;
		indisplay(root->right);
	}
}

void bst::postdisplay()
{
	postdisplay(root);
}
void bst::postdisplay(node* root)
{
	if (root != NULL)
	{
		postdisplay(root->left);
		postdisplay(root->right);
		cout << root->name << "-" << root->message << endl;
	}
}


//Non-Recursive Display
void bst::preNRdisplay()
{
	node* temp = root;
	while (1) {
		while (temp != NULL)
		{
			cout << temp->name << "-" << temp->message << endl;
			s.push(temp);
			temp = temp->left;
		}
		if (s.isemp())
		{
			break;
		}
		if (!s.isemp())
		{
			temp = s.pop();
			temp = temp->right;
		}


	}

}

void bst::inNRdisplay()
{
	node* temp = root;
	while (1)
	{
		while (temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
		if (s.isemp())
			break;
		if (!s.isemp())
		{
			temp = s.pop();
			cout << temp->name << "-" << temp->message << endl;
			temp = temp->right;
		}


	}
}

void bst::postNRdisplay()
{
	node* temp = root;
	if (temp == NULL)
		return;
	while (1)
	{
		while (temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
		if (s.data[s.top]->right == NULL)
		{
			temp = s.pop();
			cout << temp->name << "-" << temp->message << endl;
		}
		while (!s.isemp() && s.data[s.top]->right == temp)
		{
			temp = s.pop();
			cout << temp->name << "-" << temp->message << endl;
		}
		if (s.isemp())
			break;

		temp = s.data[s.top]->right;
	}
}


void bst::bfs()
{
	node* temp = root;
	q.enqueue(temp);
	while (!q.isemp())
	{
		temp = q.dequeue();
		cout << temp->name << "-" << temp->message << endl;
		if (temp->left != NULL)
			q.enqueue(temp->left);
		if (temp->right != NULL)
			q.enqueue(temp->right);
	}
}

//Height of the tree
int bst::height()
{
	int h = height(root);
	cout << h << "\n";
	return 0;
}

int bst::height(node* root)
{
	int h1, h2;
	if (root == NULL)
		return 0;
	h1 = height(root->left);
	h2 = height(root->right);
	return h1 > h2 ? ++h1 : ++h2;

}

//Search a node in the tree
node** bst::search()
{
	node** srch;
	string key;
	cout << "\nEnter the key\n";
	cin >> key;
	srch = search(root, key);
	if (srch != NULL)
	{
		cout << srch[0]->name << "-" << srch[0]->message << endl;
	}
	else
		cout << "Word not found\n";
	return srch;
}

node** bst::search(node* root, string key)
{
	node** rtn = new node * [2];
	node* temp, * parent;
	temp = root;
	parent = NULL;
	while (temp != NULL)
	{
		if (temp->name == key)
		{
			rtn[0] = temp;

			rtn[1] = parent;

			//  cout<<rtn[0]->name<<flush;

			return rtn;
		}
		else if (temp->name > key)
		{
			parent = temp;
			temp = temp->left;
		}
		else
		{
			parent = temp;
			temp = temp->right;
		}
	}
	return NULL;
}


//Delete a node from the tree
void bst::delnode()
{
	node** searchnode;
	node* curr, * temp, * parent, * trvse;
	searchnode = search();
	curr = searchnode[0];
	parent = searchnode[1];
	if (curr != root)
	{
		if (curr->left == NULL && curr->right == NULL)
		{
			if (parent->left == curr)
				parent->left = NULL;
			else if (parent->right == curr)
				parent->right = NULL;
			delete(curr);

		}
		else if (curr->left == NULL && curr->right != NULL)
		{
			if (parent->left == curr)
				parent->left = curr->right;
			else if (parent->right == curr)
				parent->right = curr->right;
			curr->left = NULL;
			curr->right = NULL;
			delete(curr);
		}
		else if (curr->left != NULL & curr->right == NULL)
		{
			if (parent->left == curr)
				parent->left = curr->left;
			else if (parent->right == curr)
				parent->right = curr->left;
			curr->left = NULL;
			curr->right = NULL;
			delete(curr);
		}
		else
		{
			temp = curr->left;

			trvse = curr->right;
			while (trvse->left != NULL)
			{
				trvse = trvse->left;
			}
			trvse->left = temp;
			if (curr == parent->right)
			{
				parent->right = curr->right;
			}
			else
				parent->left = curr->right;

			curr->left = NULL;
			curr->right = NULL;
			delete(curr);

		}
	}
	else
	{
		if (curr->left != NULL && curr->right == NULL)
		{
			root = root->left;
			curr->left = NULL;
			delete(curr);
		}
		else if (curr->left == NULL && curr->right != NULL)
		{
			root = root->right;
			curr->right = NULL;
			delete(curr);
		}
		else if (curr->left == NULL && curr->right == NULL)
		{
			delete(root);
		}
		else
		{
			temp = root->left;
			root = root->right;

			trvse = curr->right;
			while (trvse->left != NULL)
			{
				trvse = trvse->left;
			}
			trvse->left = temp;
			delete(curr);
		}
	}

}
//Copy tree recursively
void bst::copytreeR(bst t)
{
	root = t.copytreeR();
}
node* bst::copytreeR()
{
	node* root2 = copytreeR(root);
	return root2;
}
node* bst::copytreeR(node* root)
{
	node* temp = NULL;
	if (root != NULL)
	{
		temp = new node();
		temp->name = root->name;
		temp->message = root->message;
		temp->left = copytreeR(root->left);
		temp->right = copytreeR(root->right);

	}
	return temp;
}


//Copy tree non-recursively
void bst::copytreeNR(bst t)
{
	root = t.copytreeNR();
}
node* bst::copytreeNR()
{
	node* temp1, * temp2, * newroot;
	stack s2;
	temp1 = root;
	temp2 = new node();
	newroot = temp2;
	temp2->name = temp1->name;
	temp2->message = temp1->message;
	while (1)
	{
		while (temp1 != NULL)
		{
			if (temp1->left != NULL)
			{
				temp2->left = new node();
				temp2->left->name = temp1->left->name;
				temp2->left->message = temp1->left->message;

			}
			if (temp1->right != NULL)
			{
				temp2->right = new node();
				temp2->right->name = temp1->right->name;
				temp2->right->message = temp1->right->message;

			}
			s.push(temp1);
			s2.push(temp2);
			temp1 = temp1->left;
			temp2 = temp2->left;

		}
		if (s.isemp())
			break;

		if (!s.isemp())
		{
			temp1 = s.pop();
			temp2 = s2.pop();
			temp1 = temp1->right;
			temp2 = temp2->right;
		}
	}
	return newroot;
}


//Recursive Mirror
void bst::mirrorR()
{
	mirrorR(root);
}

void bst::mirrorR(node* root)
{

	node* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left != NULL)
		mirrorR(root->left);
	if (root->right != NULL)
		mirrorR(root->right);
}

//Non recursive mirror
void bst::mirrorNR()
{
	node* temp, * swapper;
	q.enqueue(root);
	while (!q.isemp())
	{
		temp = q.dequeue();
		swapper = temp->right;
		temp->right = temp->left;
		temp->left = swapper;

		if (temp->left != NULL)
			q.enqueue(temp->left);
		if (temp->right != NULL)
			q.enqueue(temp->right);
	}


}


void bst::erase(node* temp)
{

	if (temp != NULL)
	{

		erase(temp->left);
		erase(temp->right);
		temp->name = "";
		temp->message = "";
		delete(temp);
		temp = NULL;

	}

}

void bst::erase()
{
	if (root != NULL)
	{
		erase(root);
		root = NULL;
	}
}
int main()
{
	int choice;

	bst t1, t2;
	do
	{

		cout << "Menu: \n0.Exit\n1.Recursive Create\n2.Non-recursive Create\n3.Recursive Display\n4.Non-recursive display\n5.Height of the tree\n6.Search a node\n7.Delete a node\n8.Copy a tree recursively\n9.Copy tree Non-recursively\n10.Mirror(recursive)\n11.Mirror(Non-recursive)\n12.Erase a tree\nEnter your choice\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
			break;
		case 1:
			t1.create();
			break;
		case 2:
			t1.createNR();
			break;
		case 3:
			cout << "Preorder:\n";
			t1.predisplay();
			cout << "Inorder:\n";
			t1.indisplay();
			cout << "Postorder:\n";
			t1.postdisplay();
			break;
		case 4:
			cout << "Preorder:\n";
			t1.preNRdisplay();
			cout << "Inorder:\n";
			t1.inNRdisplay();
			cout << "Postorder:\n";
			t1.postNRdisplay();
			break;
		case 5:
			t1.height();
			break;
		case 6:
			t1.search();
			break;
		case 7:
			t1.delnode();
			break;
		case 8:
			t2.copytreeR(t1);
			cout << "Preorder:\n";
			t2.predisplay();
			cout << "Inorder:\n";
			t2.indisplay();
			cout << "Postorder:\n";
			t2.postdisplay();
			break;
		case 9:
			t2.copytreeNR(t1);
			cout << "Preorder:\n";
			t2.predisplay();
			cout << "Inorder:\n";
			t2.indisplay();
			cout << "Postorder:\n";
			t2.postdisplay();
			break;
		case 10:
			cout << "Tree mirrored\n\n";
			t1.mirrorR();
			break;
		case 11:
			cout << "Tree mirrored\n";
			t1.mirrorNR();
			break;
		case 12:
			t1.erase();
			break;


		default:
			cout << "Error.Please retry\n";

		}
		cout << "Do you want to continue?- 1/0\n";
		cin >> choice;
	} while (choice == 1);
	return 0;
}

