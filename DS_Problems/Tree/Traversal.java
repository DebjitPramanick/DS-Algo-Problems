package DS_Problems.Tree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

class Pair<T, U> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }
}

class Tree {

    Node root;

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

    public Tree() {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
    }

    public Tree displayBFS() {
        Queue<Node> q = new LinkedList<Node>();

        System.out.println("Displaying tree: ");
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

    public void inorder(Node node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        System.out.print(node.val + " ");
        inorder(node.right);
        return;
    }

    public void preorder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.val + " ");
        inorder(node.left);
        inorder(node.right);
    }

    public void postorder(Node node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        inorder(node.right);
        System.out.print(node.val + " ");
    }

    public Tree inorderBFS() {
        Stack<Node> s = new Stack<>();
        Node curNode = root;
        while (true) {
            while (curNode != null) {
                s.push(curNode);
                curNode = curNode.left;
            }
            if (s.empty())
                break;
            Node node = s.pop();
            curNode = node.right;
            System.out.print(node.val + " ");
        }
        System.out.println();
        return this;
    }

    public Tree preorderBFS() {
        Stack<Node> s = new Stack<Node>();
        s.push(root);

        while (!s.isEmpty()) {
            Node node = s.pop();
            System.out.print(node.val + " ");
            if (node.right != null) {
                s.push(node.right);
            }
            if (node.left != null) {
                s.push(node.left);
            }
        }

        System.out.println();
        return this;
    }

    public Tree postorderBFS() {
        Stack<Node> s = new Stack<Node>();
        Stack<Node> res = new Stack<Node>();
        s.push(root);

        while (!s.isEmpty()) {
            Node node = s.pop();
            res.push(node);
            if (node.left != null) {
                s.push(node.left);
            }
            if (node.right != null) {
                s.push(node.right);
            }
        }
        while (!res.isEmpty()) {
            System.out.print(res.pop().val + " ");
        }

        System.out.println();
        return this;
    }

    public Tree diagonalTraversal() {
        Queue<Node> q = new LinkedList<>();
        Node cur = root;

        while (true) {
            while (cur != null) {
                q.add(cur);
                cur = cur.right;
            }

            if (q.isEmpty()) {
                break;
            }

            Node node = q.poll();
            System.out.print(node.val + " ");
            cur = node.left;
        }
        System.out.println("");
        return this;
    }

    public Tree diagonalTraversalV2() {
        Queue<Node> q = new LinkedList<>();
        Node node = root;

        while (node != null) {
            System.out.print(node.val + " ");
            if (node.left != null)
                q.add(node.left);
            if (node.right != null)
                node = node.right;
            else {
                if (!q.isEmpty()) {
                    node = q.poll();
                } else
                    node = null;
            }
        }
        System.out.println("");
        return this;
    }

    public Tree displaySpiral() {
        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();
        s1.push(root);
        while (!s1.isEmpty() || !s2.isEmpty()) {

            while (!s1.isEmpty()) {
                Node node = s1.pop();
                System.out.print(node.val + " ");
                if (node.left != null) {
                    s2.push(node.left);
                }
                if (node.right != null) {
                    s2.push(node.right);
                }
            }

            while (!s2.isEmpty()) {
                Node node = s2.pop();
                System.out.print(node.val + " ");
                if (node.right != null) {
                    s1.push(node.right);
                }
                if (node.left != null) {
                    s1.push(node.left);
                }
            }
        }
        System.out.println();

        return this;
    }

    // Given a Binary Tree, find its Boundary Traversal. The traversal
    // should be in the following order:

    // Left boundary nodes: defined as the path from the root to the left-most
    // node ie- the leaf node you could reach when you always travel preferring
    // the left subtree over the right subtree.

    // Leaf nodes: All the leaf nodes except for the ones that are part of left
    // or right boundary.

    // Reverse right boundary nodes: defined as the path from the right-most node
    // to the root. The right-most node is the leaf node you could reach when you
    // always travel preferring the right subtree over the left subtree. Exclude
    // the root from this as it was already included in the traversal of left
    // boundary nodes.

    // Note: If the root doesn't have a left subtree or right subtree, then the root
    // itself is the left or right boundary.

    public Tree boundaryTraversal() {
        List<Node> nodes = new ArrayList<>();
        nodes.add(root);
        traverseLeft(root.left, nodes);
        traverseLeaves(root.left, nodes);
        traverseLeaves(root.right, nodes);
        traverseRight(root.right, nodes);

        for (Node node : nodes) {
            System.out.print(node.val + " ");
        }
        System.out.println();
        return this;
    }

    private void traverseLeft(Node node, List<Node> nodes) {
        if (node == null) {
            return;
        }
        if (node.left != null) {
            nodes.add(node);
            traverseLeft(node.left, nodes);
        } else if (node.right != null) {
            nodes.add(node);
            traverseLeft(node.right, nodes);
        }
    }

    private void traverseRight(Node node, List<Node> nodes) {
        if (node == null) {
            return;
        }
        if (node.right != null) {
            nodes.add(node);
            traverseRight(node.right, nodes);
        } else if (node.left != null) {
            nodes.add(node);
            traverseRight(node.left, nodes);
        }
    }

    private void traverseLeaves(Node node, List<Node> nodes) {
        if (node == null) {
            return;
        }
        traverseLeaves(node.left, nodes);
        if (node.left == null && node.right == null) {
            nodes.add(node);
        }
        traverseLeaves(node.right, nodes);
    }

}

public class Traversal {
    public static void main(String args[]) {
        Tree tree = new Tree();
        tree.displayBFS().inorderBFS().preorderBFS().postorderBFS().diagonalTraversal().displaySpiral()
                .boundaryTraversal();
    }
}
