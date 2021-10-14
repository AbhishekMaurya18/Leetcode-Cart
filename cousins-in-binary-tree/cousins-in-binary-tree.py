# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict
class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        
        hash_table=defaultdict(list)
        if not root:
            return 0
        def dfs(root,vd,flag):
            if not flag:
                return False
            if not root:
                return flag
            if root.left and root.right:
                l=root.left.val
                r=root.right.val
                if (l==x and r==y) or (l==y and r==x):
                    flag=False
            hash_table[vd].append(root.val)
            dfs(root.left,vd+1,flag)
            dfs(root.right,vd+1,flag)
            
        dfs(root,0,True)
        print(hash_table)
        for j in hash_table:
            if x in hash_table[j] and y in hash_table[j]:
                return 1
        return 0
        
            
        
            