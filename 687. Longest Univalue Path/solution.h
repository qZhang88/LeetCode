#include <cstddef>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int ans;

	int arrowLength(TreeNode *node){
		if (!node) return 0;
		int left = arrowLength(node->left);
		int right = arrowLength(node->right);
		int arrowLeft = 0, arrowRight = 0;
		if (node->left != NULL and node->val == node->left->val){
			arrowLeft += left + 1;
		}
		if (node->right != NULL and node->val == node->right->val){
			arrowRight += right + 1;
		}
		ans = std::max(ans, arrowLeft + arrowRight);
		return std::max(arrowLeft, arrowRight);
	}


public:
	int longestUnivaluePath(TreeNode *root){
		ans = 0;
		arrowLength(root);
		return ans;
	}
};
