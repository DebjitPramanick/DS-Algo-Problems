package DS_Problems.Tree;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

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
        root = new Node(3);
        root.left = new Node(2);
        root.right = new Node(5);
        root.left.left = new Node(7);
        root.right.left = new Node(23);
        root.right.right = new Node(12);
    }

    public Tree bfs() {
        Queue<Node> q = new ArrayDeque<Node>();

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

    public Tree inorderNormal() {
        Stack<Node> s = new Stack<Node>();

        System.out.println("Displaying tree: ");

        Node cur = root;

        while (true) {
            while (cur != null) {
                s.push(cur);
                cur = cur.left;
            }
            if (s.isEmpty())
                break;
            cur = s.pop();
            System.out.print(cur.val + " ");
            cur = cur.right;
        }

        System.out.println();

        return this;
    }

    public Tree postOrderNormal() {
        Stack<Node> s1 = new Stack<Node>();
        Stack<Node> s2 = new Stack<Node>();

        System.out.println("Displaying tree: ");

        s1.push(root);

        while (!s1.isEmpty()) {
            Node node = s1.pop();
            s2.push(node);

            if (node.left != null) {
                s1.push(node.left);
            }

            if (node.right != null) {
                s1.push(node.right);
            }
        }

        while (!s2.isEmpty()) {
            Node node = s2.pop();
            System.out.print(node.val + " ");
        }

        System.out.println("");

        return this;
    }
}

public class Basic {
    public static void main(String args[]) {
        Tree tree = new Tree();
        tree.bfs().inorderNormal().postOrderNormal();
    }
}
