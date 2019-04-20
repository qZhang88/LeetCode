使用递归方法


有一个类变量ans记录
1. 求节点左/右子树最长的路径，arrowLeft和arrowRight
2. 判断与当前节点的值是否一直，左/右路径值等于0或路径值+1
3. 如果当前节点作为最终path的根节点的话，那么最长路径max(ans, arrowLeft + arrowRight)
4. 如果当前节点不作为最终path的root节点的话，那么只有左子树或右子树会成为最终的路径，当前可能路径长为max(arrowLeft, arrowRight)
