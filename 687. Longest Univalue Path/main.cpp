#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    TreeNode root(5);
    TreeNode node1(4);
    TreeNode node2(5);
    TreeNode node3(1);
    TreeNode node4(1);
    TreeNode node5(5);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;

    std::cout << s.longestUnivaluePath(&root) << std::endl;
}

