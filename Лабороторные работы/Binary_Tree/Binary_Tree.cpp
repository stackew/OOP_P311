#include <iostream>

struct Node
{
	Node* left;
	Node* right;

	int data;
};

Node* CreateNode(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->left = nullptr;
	new_node->right = nullptr;
	return new_node;
}

Node* InsertNode(Node* root, int data)
{
	if (root == nullptr)
	{
		return CreateNode(data);
	}

	if (data > root->data)
	{
		root->right = InsertNode(root->right, data);
	}
	else if(data < root->data)
	{
		root->left = InsertNode(root->left, data);
	}

	return root;
}

void InorderWalk(Node* root)
{
	if (root != nullptr)
	{
		InorderWalk(root->left);
		std::cout << root->data << " ";
		InorderWalk(root->right);
	}
}

Node* SearchNode(Node* root, int val)
{
	if (root == nullptr || root->data == val)
	{
		return root;
	}

	if (root->data < val)
	{
		return SearchNode(root->right, val);
	}
	return SearchNode(root->left, val);
}

Node* DeleteNode(Node* root, int data)
{
	if (root == nullptr)
	{
		return root;
	}

	if (data < root->data)
	{
		root->right = DeleteNode(root->left, data);
	}

	else if (data > root->data)
	{
		root->right = DeleteNode(root->right, data);
	}

	else
	{
		if (root->left == nullptr)
		{
			Node* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == nullptr)
		{
			Node* tmp = root->left;
			delete root;
			return tmp;
		}
		Node* tmp = MinValueNode(root->right);
		root->data = tmp->data;
		root->right = DeleteNode(root->right, tmp->data);
	}
}

Node* MinValueNode(Node* node)
{
	Node* current = node;
	while (current && current->left != nullptr)
	{
		current = current->left;
	}

	return node;
}

int main()
{

}