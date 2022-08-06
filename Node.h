#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	char color;
};