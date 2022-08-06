#include"Node.h"

class RedBlackTree
{
public:
	Node * root;
	virtual void insert(int) = 0;
	virtual void deleteNode(int) = 0;
};