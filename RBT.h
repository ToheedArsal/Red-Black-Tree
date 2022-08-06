#include"RedBlackTree.h"

class RBT :public RedBlackTree
{
	void preOrderHelper(Node * node) {
		if (node != nullptr) {
			cout << node->data << node->color << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	void inOrderHelper(Node * node) {
		if (node != nullptr) {
			inOrderHelper(node->left);
			cout << node->data << node->color << " ";
			inOrderHelper(node->right);
		}
	}
	void postOrderHelper(Node * node) {
		if (node != nullptr) {
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			cout << node->data << node->color << " ";
		}
	}
	void deletegreaterthankey(Node* temp, Node *node, int key)
	{

		if (node != nullptr) {

			deletegreaterthankey(temp, node->left, key);
			deletegreaterthankey(temp, node->right, key);
			if (node->data > key)
				deleteNodeHelper(temp, node->data);
		}
	}
	void preOrderHelper2(Node * node) {
		if (node != nullptr) {
			cout << node->data << node->color << " ";
			preOrderHelper(node->right);
			preOrderHelper(node->left);
		}
	}

	void inOrderHelper2(Node * node) {
		if (node != nullptr) {
			inOrderHelper(node->right);
			cout << node->data << node->color << " ";
			inOrderHelper(node->left);
		}
	}

	void postOrderHelper2(Node * node) {
		if (node != nullptr) {
			postOrderHelper(node->right);
			postOrderHelper(node->left);
			cout << node->data << node->color << " ";
		}
	}
	void Removetree(Node * temp)
	{
		if (temp != nullptr)
		{
			if (temp->left != nullptr)
				Removetree(temp->left);
			if (temp->right != nullptr)
				Removetree(temp->right);
			delete[]temp;
		}
	}

	Node * searchTreeHelper(Node * node, int key) {
		if (node == nullptr || key == node->data) {
			return node;
		}

		if (key < node->data) {
			return searchTreeHelper(node->left, key);
		}
		return searchTreeHelper(node->right, key);
	}
	Node* parent(Node *node, int key)
	{
		if (node == nullptr)
			return nullptr;
		Node *getparent = nullptr;
		while (node != nullptr)
		{
			if (key < node->data)
			{
				getparent = node;
				node = node->left;
			}
			else if (key > node->data)
			{
				getparent = node;
				node = node->right;
			}
			else break;
		}
		return getparent;
	}
	void fixDelete(Node * x) {
		Node * s;
		while (x && x != root && x->color == 'b') {
			if (x == parent(this->root, x->data)->left) {
				s = parent(this->root, x->data)->right;
				if (s->color == 'r') {
					// case 3.1
					s->color = 'b';
					parent(this->root, x->data)->color = 'r';
					leftRotate(parent(this->root, x->data));
					s = parent(this->root, x->data)->right;
				}

				if (s->left->color == 'b' && s->right->color == 'b') {
					// case 3.2
					s->color = 'r';
					x = parent(this->root, x->data);
				}
				else {
					if (s->right->color == 'b') {
						// case 3.3
						s->left->color = 'b';
						s->color = 'r';
						rightRotate(s);
						s = parent(this->root, x->data)->right;
					}

					// case 3.4
					s->color = parent(this->root, x->data)->color;
					parent(this->root, x->data)->color = 'b';
					s->right->color = 'b';
					leftRotate(parent(this->root, x->data));
					x = root;
				}
			}
			else {
				s = parent(this->root, x->data)->left;
				if (s->color == 'r') {
					// case 3.1
					s->color = 'b';
					parent(this->root, x->data)->color = 'r';
					rightRotate(parent(this->root, x->data));
					s = parent(this->root, x->data)->left;
				}

				if (s->right->color == 'b' && s->right->color == 'b') {
					// case 3.2
					s->color = 'r';
					x = parent(this->root, x->data);
				}
				else {
					if (s->left->color == 'b') {
						// case 3.3
						s->right->color = 'b';
						s->color = 'r';
						leftRotate(s);
						s = parent(this->root, x->data)->left;
					}

					// case 3.4
					s->color = parent(this->root, x->data)->color;
					parent(this->root, x->data)->color = 'b';
					s->left->color = 'b';
					rightRotate(parent(this->root, x->data));
					x = root;
				}
			}
		}
		if (x)
			x->color = 'b';
	}
	void rbTransplant(Node * u, Node * v){
		if (parent(this->root, u->data) == NULL) {
			root = v;
		}
		else if (u == parent(this->root, u->data)->left){
			parent(this->root, u->data)->left = v;
		}
		else {
			parent(this->root, u->data)->right = v;
		}
		if (v)
		{
			Node *temp = parent(this->root, v->data);
			temp = parent(this->root, u->data);
		}
	}
	void deleteNodeHelper(Node * node, int key) {
		// find the node containing key
		Node * z = nullptr;
		Node * x, *y;
		while (node != nullptr){
			if (node->data == key) {
				z = node;
				break;
			}

			if (node->data <= key) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}

		if (z == nullptr) {
			cout << "Couldn't find key in the tree" << endl;
			return;
		}

		y = z;
		char y_original_color = y->color;
		if (z->left == nullptr) {
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == nullptr) {
			x = z->left;
			rbTransplant(z, z->left);
		}
		else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (parent(this->root, y->data) == z) {
				Node *temp = parent(this->root, x->data);
				temp = y;
			}
			else {
				rbTransplant(y, y->right);
				y->right = z->right;
				Node* yrp = parent(this->root, y->right->data);
				yrp = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			Node* ylp = parent(this->root, y->left->data);
			ylp = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 'b'){
			fixDelete(x);
		}
	}
	void fixInsert(Node * k){
		Node * u = nullptr, *pk = nullptr;
		pk = parent(this->root, k->data);
		if (pk)
		while (pk->color == 'r') {
			pk = parent(this->root, k->data);

			if (pk == parent(this->root, pk->data)->right) {
				u = parent(this->root, pk->data)->left; // uncle
				if (u && u->color == 'r') {
					// case 3.1
					u->color = 'b';
					pk->color = 'b';
					parent(this->root, pk->data)->color = 'r';
					k = parent(this->root, pk->data);
					pk = parent(this->root, k->data);
				}
				else {
					if (k == pk->left) {
						// case 3.2.2
						k = pk;
						/*pk = parent(this->root, k->data);*/
						rightRotate(k);
					}
					// case 3.2.1
					pk->color = 'b';
					parent(this->root, pk->data)->color = 'r';
					leftRotate(parent(this->root, pk->data));
				}
			}
			else {
				u = parent(this->root, pk->data)->right; // uncle

				if (u && u->color == 'r') {
					// mirror case 3.1
					u->color = 'b';
					pk->color = 'b';
					parent(this->root, pk->data)->color = 'r';
					k = parent(this->root, pk->data);
					pk = parent(this->root, k->data);
				}
				else {
					if (k == pk->right) {
						// mirror case 3.2.2
						k = pk;
						/*pk = parent(this->root, k->data);*/
						leftRotate(k);
					}
					// mirror case 3.2.1
					pk->color = 'b';
					parent(this->root, pk->data)->color = 'r';
					rightRotate(parent(this->root, pk->data));
				}
			}
			if (k == root) {
				break;
			}
		}
		this->root->color = 'b';
	}
	void printHelper(Node * root, string indent, bool last) {
		// print the tree structure on the screen
		if (root != nullptr) {
			cout << indent;
			if (last) {
				cout << "R----";
				indent += "     ";
			}
			else {
				cout << "L----";
				indent += "|    ";
			}

			string sColor;
			if (root->color == 'r')
				sColor = "RED";
			else
				sColor = "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}
public:
	Node * maximum(Node * node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	// find the successor of a given node
	Node * successor(Node * x) {
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x->right != nullptr) {
			return minimum(x->right);
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		Node * y = parent(this->root, x->data);
		while (y != nullptr && x == y->right) {
			x = y;
			y = parent(this->root, y->data);
		}
		return y;
	}

	// rotate left at node x
	void leftRotate(Node * x) {
		Node * y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			Node *ylp = parent(this->root, y->left->data);
			ylp = x;
		}
		Node *yp = parent(this->root, y->data);
		Node *xp = parent(this->root, x->data);
		yp = xp;
		if (xp == NULL) {
			this->root = y;
		}
		else if (x == xp->left) {
			xp->left = y;
		}
		else {
			xp->right = y;
		}
		y->left = x;
		xp = y;
	}

	// rotate right at node x
	void rightRotate(Node * x) {
		Node * y = x->left;
		Node *yp = parent(this->root, y->data);
		Node *xp = parent(this->root, x->data);
		x->left = y->right;
		if (y->right != nullptr) {
			Node* yrp = parent(this->root, y->right->data);
			yrp = x;
		}
		yp = xp;
		if (xp == NULL) {
			this->root = y;
		}
		else if (x == xp->right) {
			xp->right = y;
		}
		else {
			xp->left = y;
		}
		y->right = x;
		xp = y;
	}

	//insert the key to the tree in its appropriate position
	//and fix the tree
	void insert(int value)
	{
		Node* newNode;
		newNode = new Node;
		newNode->data = value;
		newNode->color = 'r';
		newNode->left = nullptr;
		newNode->right = nullptr;
		if (root == nullptr)
		{
			root = newNode;
			root->color = 'b';
		}
		else
		{
			Node* temp = root;
			while (1)
			{
				if (value >= temp->data)
				{
					if (temp->right == nullptr)
					{
						temp->right = newNode;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
				else
				{
					if (temp->left == nullptr)

					{
						temp->left = newNode;
						break;
					}
					else
					{
						temp = temp->left;

					}
				}
			}
		}
		fixInsert(newNode);
		this->root->color = 'b';
	}
	Node * getRoot(){
		return this->root;
	}

	// delete the node from the tree
	void deleteNode(int data) {
		deleteNodeHelper(this->root, data);
	}
	void findparent()
	{
		int key;
		cout << "Enter node's key: ";
		cin >> key;
		Node* par = parent(this->root, key);
		if (par)
			cout << "parent of " << key << " : " << par->data << endl;
		else
			cout << "Parent does not exist....\n";
	}
	RBT() {

		root = nullptr;
	}

	void preorder() {
		preOrderHelper(this->root);
	}

	
	void inorder() {
		inOrderHelper(this->root);
	}

	void postorder() {
		postOrderHelper(this->root);
	}

	
	void preorder2() {
		preOrderHelper2(this->root);
	}
	void inorder2() {
		inOrderHelper2(this->root);
	}
	void prettyPrint() {
		if (root) {
			printHelper(this->root, "", true);
		}
	}
	void RemoveTree()
	{
		if (root)
		{
			Removetree(root);
			cout << "Tree Destroyed Successfully......\n";
		}
		else
			cout << "Tree is already Empty......\n";
	}
	void DeleteAllGreaterthanKey()
	{
		int key;
		cout << "Enter key: ";
		cin >> key;
		deletegreaterthankey(this->root, this->root, key);
	}
	void postorder2() {
		postOrderHelper2(this->root);
	}
	void searchTree(int k) {
		Node * a = searchTreeHelper(this->root, k);
		if (a && a->data)
			cout << "Data found" << endl;
		else
			cout << "Not found" << endl;
	}

	Node * minimum(Node * node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	void getInput() {
		int val = 0;
		ifstream fin;
		fin.open("input.txt");
		if (!fin)
		{
			cout << "file not found.....\n";
			return;
		}
		while (fin >> val){
			insert(val);
		}
		fin.close();
	}
};