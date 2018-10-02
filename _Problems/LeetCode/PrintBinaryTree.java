/**
 * Author: Hung Duc Vu
 * Case Western Reserve University
 * Created: 10/02/2018
 *
 * LeetCode 655. Print Binary Tree https://leetcode.com/problems/print-binary-tree/description/
 * Difficulty: Medium. Beats 100% Java. O(N)
 * Steps:
 * 1. Find the height of the tree to find the size of the 2D array (findHeight)
 * 2. Then build the 2D array by traverse from top to bottom, mid is location of the node on the row,
 *    start is where children nodes of that node can start, call recursive function build to traverse
 *    through the tree.
 * Notes:
 *      It's better to use a 2D array then transform to a list because get in array is O(1)
 */


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class PrintBinaryTree {
    public List<List<String>> printTree(TreeNode root) {

        // Find the size of 2D array
        int m = findHeight(root);
        int n = (int) Math.pow(2, m) - 1; // The maximum numbers of highest node is 2^height
        String[][] res = new String[m][n];
        for (String[] row: res)
            Arrays.fill(row, "");

        build(res, 0, n/2, 0, root);

        List<List<String>> list = new LinkedList<>();
        for (String[] row : res) {
            list.add(Arrays.asList(row));
        }

        return list;
    }

    public void build(String[][] res, int row, int mid, int start, TreeNode node) {
        if (node == null)
            return;

        res[row][mid] = Integer.toString(node.val);

        build(res, row + 1, start + (mid - start) / 2, start, node.left);
        build(res, row + 1, mid + (mid - start) / 2 + 1, mid + 1, node.right);
    }

    public int findHeight(TreeNode node) {
        if (node == null)
            return 0;
        return Math.max(findHeight(node.left), findHeight(node.right)) + 1;
    }

}
