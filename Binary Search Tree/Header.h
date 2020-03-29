#pragma once
#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 


using namespace std;

//template <class T>
struct node {
	int key; //key identifier 
	int data;
	struct node* right; //points to the right node
	struct node* left; //points to the left node
	struct node* parent; //points to the parent node
};

//structure node for key, left, right, and parent
//template <class T>
struct node *newNode(int item)
{
	struct node* data = new node;
	data->key = item;
	data->left = NULL;
	data->right = NULL;
	data->parent = NULL;
	return data;
}


// structure class for inserting a new node into the binary tree
//template <class T>
struct node* insert(struct node* binaryNode, int key)
{
	// If statement for if the tree is empty, return newNode
	if (binaryNode == NULL) return newNode(key);

	// if statement for if the binary tree contains a node, navigate down to insert the child node
	if (key < binaryNode->key) //if statement is the child node is less than the root node
	{
		node *leftNode = insert(binaryNode->left, key);
		binaryNode->left = leftNode;

		// Sets the parent node of root of the left child node
		leftNode->parent = binaryNode;
	}
	else if (key > binaryNode->key)
	{
		node *rightNode = insert(binaryNode->right, key);
		binaryNode->right = rightNode;

		// Sets the parent node of root of the right child node
		rightNode->parent = binaryNode;
	}

	/* returns the Node pointer */
	return binaryNode;
}
//This will organize the Binary Search Tree and display the current Nodes in it.
//template <class T>
void organize(struct node *root)
{	//if statement for if the root node is NULL
	if (root != NULL)
	{	//Displays the Node and their parent Node
		organize(root->left); //organizes to the left
		printf("Node : %d, ", root->key);
		if (root->parent == NULL) //if statement for the root/parent node
			printf("Parent Node : NULL \n");
		else //else statement for parent node
			printf("Parent Node : %d \n", root->parent->key);
		organize(root->right); //organizes to the right
	}
}


//Searches out the largest value within the Binary Search Tree
//template <class T>
	int maximumValue(struct node* root)
{
	if (root == NULL)
		cout << "\nThe Binary Tree is empty\n";
	return INT_MIN;

	int maxSearch = root->key;
	int leftMaxSearch = maximumValue(root->left);
	int rightMaxSearch = maximumValue(root->right);
	if (leftMaxSearch > maxSearch)
		leftMaxSearch = maxSearch;
	if (rightMaxSearch > maxSearch)
		rightMaxSearch = maxSearch;
	return maxSearch;
}
//Searches out the smallest value within the Binary Search Tree
//template <class T>
struct node* minimumValue(struct node* node)
{

	struct node* current = node;

	// while statement to find the node at the far left (which will be the smallest value)
	while (current->left != NULL)
		current = current->left;

	return current;

}

//template <class T>
struct node* deleteBSTNode(struct node* root, int key)
{

	if (root == NULL) return root;

	// If statement to delete a node if the key is smaller than the root node 
	if (key < root->key)
		root->left = deleteBSTNode(root->left, key);

	// If statement to delete a node if the key is greater than the root node  
	else if (key > root->key)
		root->right = deleteBSTNode(root->right, key);

	// else statement
	else
	{
		// if statement for if the left node in the tree is NULL
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}//Else if statement if the right node if set to NULL
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children values
		struct node* temp = minimumValue(root->right);

		root->key = temp->key;

		// Deletes the node
		root->right = deleteBSTNode(root->right, temp->key);
	}
	return root;
}

//The main menu for the user to interact
void mainMenu()
{
	//Prints out the options available to the user
	cout << "\nBinary Search Tree Main Menu.\n";
	cout << "1. Insert a New Root Node \n";
	cout << "2. Insert a New Child Node \n";
	cout << "3. Display the Current Binary Tree \n";
	cout << "4. Display the Largest Value \n";
	cout << "5. Display the Smallest Value \n";
	cout << "6. Delete Binary Tree Nodes \n"; //I still need to add this function
	cout << "7. Clear the screen \n";
	cout << "8. Exit Program";
	cout << "\nEnter Choice: ";
}