#include"RBT.h"
void menu();
int  main()
{
	RBT bst;

	int ch = 0;
	int k = 0;
	bst.inorder();
	while (ch != 14){
		menu();
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter key to insert: ";
			cin >> k;
			bst.insert(k);
			cout << "\nNode Inserted.\n";
			break;

		case 2: 	cout << "Enter key to delete: ";
			cin >> k;
			bst.deleteNode(k);
			break;
		case 3:
			cout << "Enter number to search: ";
			cin >> k;
			bst.searchTree(k);
			break;
		case 4: 	bst.preorder();
			break;
		case 5: 	bst.inorder();
			break;
		case 6: 	bst.postorder();
			break;
		case 7: 	bst.preorder2();
			break;
		case 8: 	bst.inorder2();
			break;
		case 9: 	bst.postorder2();
			break;
		case 10: bst.RemoveTree();

			break;
		case 11:  bst.DeleteAllGreaterthanKey();
			break;
		case 12: bst.findparent();
			break;
		case 13: bst.getInput();
			break;
		case 14:
			break;
		default: cout << "\n InValid Choice.";
		}

	}
	cout << endl << endl << endl << endl;
	bst.prettyPrint();
	system("pause");
}
void menu()
{
	cout << "\n\t RED BLACK TREE ";
	cout << "\n Press 1 to insert values one by one in the tree";
	cout << "\n Press 2 to delete a value from the tree (bonus/optional)";
	cout << "\n Press 3 for searching a value from the tree";
	cout << "\n Press 4 for pre-order traversal NLR ";
	cout << "\n Press 5 for in-order traversal LNR";
	cout << "\n Press 6 for post-order traversal LRN";
	cout << "\n Press 7 for pre-order traversal 2 NRL";
	cout << "\n Press 8 for in-order traversal 2 RNL";
	cout << "\n Press 9 for post-order traversal 2 RLN";
	cout << "\n Press 10 to Destroy Tree";
	cout << "\n Press 11 to delete all values greater than key Destroy Tree ";
	cout << "\n Press 12 for displaying parent of node present in tree ";
	cout << "\n Press 13 to read integer values from the file input.txt to create a red-black tree ";
	cout << "\n Press 14 to EXIT ";
	cout << "\nEnter Your Choice: ";
}