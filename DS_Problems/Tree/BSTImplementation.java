package DS_Problems.Tree;

import java.util.LinkedList;
import java.util.Queue;

class BinarySearchTree {

    Node root;
    static int kthAncestor = 2;

    class Node {
        int val;
        Node left;
        Node right;

        Node(int _val) {
            this.val = _val;
            this.left = null;
            this.right = null;
        }
    }

    public BinarySearchTree() {
        root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(16);
        root.left.left = new Node(2);
        root.left.right = new Node(6);
        root.right.left = new Node(12);
        root.right.right = new Node(18);
    }

    public BinarySearchTree displayBFS() {
        Queue<Node> q = new LinkedList<Node>();

        System.out.println("Displaying BinarySearchTree: ");
        q.add(root);

        while (!q.isEmpty()) {
            Node node = q.poll();
            System.out.print(node.val + " ");

            if (node.left != null) {
                q.add(node.left);
            }

            if (node.right != null) {
                q.add(node.right);
            }
        }

        System.out.println();

        return this;
    }

    public void checkIfBST() {
        if (isBST(root)) {
            System.out.println("Is BST.");
        } else {
            System.out.println("Not BST");
        }
    }

    private boolean isBST(Node node) {
        if (node == null) {
            return true;
        }

        return isGreater(node.right, node.val) && isLesser(node.left, node.val) && isBST(node.right)
                && isBST(node.left);
    }

    private boolean isLesser(Node node, int key) {
        if (node == null) {
            return true;
        }

        System.out.println(" " + node.val + "<=" + key);

        return node.val <= key && isLesser(node.left, key) && isLesser(node.right, key);
    }

    private boolean isGreater(Node node, int key) {
        if (node == null) {
            return true;
        }

        System.out.println(" " + node.val + ">=" + key);

        return node.val >= key && isGreater(node.left, key) && isGreater(node.right, key);
    }
}

public class BSTImplementation {
    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        tree.displayBFS().checkIfBST();
    }
}
