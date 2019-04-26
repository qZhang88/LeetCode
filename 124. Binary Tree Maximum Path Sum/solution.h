#include <cstddef>
#include <algorithm>
#include <limits.h>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


class Solution {
public:
	int maxPathSum(TreeNode* root){
		ans = INT_MIN;
		arrowSum(root);
		return ans;
	}

private:
	int ans;
	int arrowSum(TreeNode * node) {
		if (!node) return 0;
		int arrowLeft = arrowSum(node->left);
		int arrowRight = arrowSum(node->right);
		ans = std::max(ans, arrowLeft + arrowRight + node->val);
		return std::max(0, std::max(arrowLeft, arrowRight) + node->val);
	}
};
