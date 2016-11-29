#include <iostream>
#include <climits>
using namespace std;


struct Node {
	int data;
	struct Node* right_child;
	struct Node* left_child; 
};

struct Node* newNode(int data) {
	struct Node* node = (struct Node*)(malloc(sizeof(struct Node)));
	node->data = data;
	node->left_child = NULL;
	node->right_child = NULL;
	return(node);
}

int is_bst_util(Node* node, int small_lim, int upper_lim) {
	if (node == NULL) {
		return 1;
	}
	
	if (node->data < small_lim || node->data > upper_lim) {
		return 0;
	}

	return (is_bst_util(node->left_child, small_lim, node->data-1) 
		 && is_bst_util(node->right_child, node->data+1, upper_lim)); 
}

int is_bst(Node* node) {
	return is_bst_util(node, INT_MIN, INT_MAX);
}

int main(int argc, char* argv[]) {

	// Graph 1
	struct Node* root = newNode(4);
	root->left_child = newNode(1);
	root->right_child = newNode(7);
	root->left_child->right_child = newNode(3);
	root->right_child->left_child = newNode(5);
	//

	int ans = is_bst(root);
	cout << "1 if graph 1 is a bst, 0 if not: " << ans << endl;
	return 0;
}
