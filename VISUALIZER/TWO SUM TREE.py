class TreeNode:
    """Definition of TreeNode for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BSTIterator:
    """BSTIterator class for iterating through BST nodes."""
    def __init__(self, root, reverse=False):
        self.stack = []
        self.reverse = reverse
        self.push_all(root)

    def has_next(self):
        """Checks if there exists a next element in the BST."""
        return len(self.stack) > 0

    def next(self):
        """Retrieves the next smallest or largest element based on the traversal direction."""
        node = self.stack.pop()
        if not self.reverse:
            self.push_all(node.right)
        else:
            self.push_all(node.left)
        return node.val
    
    def push_all(self, node):
        """Helper function to push nodes into the stack."""
        while node:
            self.stack.append(node)
            if self.reverse:
                node = node.right
                
            else:
                node = node.left


class Solution:
    """Solution class for performing operations on the BST."""
    def find_target(self, root, k):
        if not root:
            return False

        left_iter = BSTIterator(root, reverse=False)
        right_iter = BSTIterator(root, reverse=True)

        i, j = left_iter.next(), right_iter.next()
        while i < j:
            if i + j == k:
                return True
            elif i + j < k:
                i = left_iter.next()
            else:
                j = right_iter.next()
        return False


def print_in_order(root):
    """Function to perform an in-order traversal of a binary tree and print its nodes."""
    if not root:
        return
    print_in_order(root.left)
    print(root.val, end=" ")
    print_in_order(root.right)


# Sample usage
if __name__ == "__main__":
    # Sample binary search tree: 7 3 15 -1 -1 9 20
    root = TreeNode(7)
    root.left = TreeNode(3)
    root.right = TreeNode(10)

    root.left.left = TreeNode(2)
    root.left.left.left = TreeNode(1)
    root.left.right = TreeNode(5)
    root.left.right.right = TreeNode(4)

    root.right.left = TreeNode(9)
    root.right.right = TreeNode(16)
    root.right.left.left = TreeNode(6)
    root.right.left.right = TreeNode(8)

    print("Tree Initialized: ", end="")
    print_in_order(root)
    print()

    solution = Solution()
    target = 16
    exists = solution.find_target(root, target)
    if exists:
        print(f"Pair with sum {target} exists.")
    else:
        print(f"Pair with sum {target} does not exist.")
