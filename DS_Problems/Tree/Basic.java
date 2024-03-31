package DS_Problems.Tree;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
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
        root = new Node(12);
        root.left = new Node(9);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(2);
        root.right.right = new Node(1);
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

    private int height(Node node) {
        if (node == null) {
            return 0;
        }

        return 1 + Math.max(height(node.left), height(node.right));
    }

    private int findDiameter(Node node) {
        if (node == null) {
            return 0;
        }

        int lh = height(node.left);
        int rh = height(node.right);
        int ld = findDiameter(node.left);
        int rd = findDiameter(node.right);

        return Math.max(lh + rh + 1, Math.max(ld, rd));
    }

    public Tree diameter() {
        System.out.println("Diameter is: " + findDiameter(root));
        return this;
    }

}

public class Basic {
    public static void main(String args[]) {
        Tree tree = new Tree();
        tree.bfs().diameter();
    }
}
