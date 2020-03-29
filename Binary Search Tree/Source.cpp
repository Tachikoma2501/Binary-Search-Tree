//Samuel Aaron Cooper
//10/14/2018
//Binary Search Tree

#include "Header.h"


//main program
//template <class T>
int main()
{

	mainMenu();

	//Sets the root node to NULL
	struct node *root = NULL;

	int rootValue;
	int childValue;
	int character;
	int deleteValue;

	//defines the character yes as y
	char yes = 'y';
	//while statement y to return to menu
	while (yes == 'y') {
		cout << "Enter your choice:"; cin >> character;
		switch (character) { //use of switch/case statement to create user interface

		case 1://Adds a node depending on the position chosen

			cout << "\nPlease input a number value for the root node to insert into the Binary Tree\n";
			cout << "Enter: ";
			cout << "\n";
			cin >> rootValue;

			root = insert(root, rootValue);

			break;

		case 2://Adds a node depending on the position chosen

			cout << "\nPlease input a number value for the child node to insert into the Binary Tree\n";
			cout << "Enter: ";
			cout << "\n";
			cin >> childValue;

			insert(root, childValue);

			break;

		case 3://Adds a node depending on the position chosen

			cout << "\n";
			organize(root);

			break;

		case 4:

			printf("The Largest Value Node is % \n", maximumValue(root));

			break;

		case 5:

			printf("The Largest Value Node is %d \n", minimumValue(root));

			break;

		case 6:

			cout << "\nPlease input a number value that corresponds with a node you wish to delete from the Binary Tree\n";
			cout << "Enter: ";
			cout << "\n";
			cin >> deleteValue;

			printf("\nDelete\n");
			root = deleteBSTNode(root, deleteValue);

			break;

		case 7:
			//System command to clear the screen
			system("CLS");
			mainMenu();//Prints out the menu again after the screen is cleared
			break;

		case 8: exit(0);//Exits the program
		default: cout << "Invalid choice\n";
		}
		cout << "Continue?y/n:"; cin >> yes; //Asks the user if they wish to continue the program or exit
	}

}