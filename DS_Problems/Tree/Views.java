package DS_Problems.Tree;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Stack;

public class Views {
    public static void main(String[] args) {
        Tree tree = new Tree();
        tree.topView().bottomView().leftView().rightView();
    }
}

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

    public Tree topView() {
        Stack<Pair<Node, Integer>> s = new Stack<>();
        Map<Integer, Node> mp = new HashMap<>();
        s.push(new Pair<>(root, 0));
        while (!s.isEmpty()) {
            Pair<Node, Integer> pair = s.pop();
            int horDist = pair.getSecond();
            Node node = pair.getFirst();
            if (!mp.containsKey(horDist)) {
                mp.put(horDist, node);
            }
            if (node.left != null) {
                s.push(new Pair<>(node.left, horDist - 1));
            }
            if (node.right != null) {
                s.push(new Pair<>(node.right, horDist + 1));
            }
        }
        for (Node node : mp.values()) {
            System.out.print(node.val + " ");
        }
        System.out.println("");
        return this;
    }

    public Tree bottomView() {
        Stack<Pair<Node, Integer>> s = new Stack<>();
        Map<Integer, Node> mp = new HashMap<>();
        s.push(new Pair<>(root, 0));
        while (!s.isEmpty()) {
            Pair<Node, Integer> pair = s.pop();
            int horDist = pair.getSecond();
            Node node = pair.getFirst();
            mp.put(horDist, node);
            if (node.left != null) {
                s.push(new Pair<>(node.left, horDist - 1));
            }
            if (node.right != null) {
                s.push(new Pair<>(node.right, horDist + 1));
            }
        }
        for (Node node : mp.values()) {
            System.out.print(node.val + " ");
        }
        System.out.println("");
        return this;
    }

    public Tree leftView() {
        Queue<Pair<Node, Integer>> q = new LinkedList<>();
        Map<Integer, Node> mp = new HashMap<>();
        q.add(new Pair<>(root, 0));
        while (!q.isEmpty()) {
            Pair<Node, Integer> pair = q.poll();
            int verDist = pair.getSecond();
            Node node = pair.getFirst();
            if (!mp.containsKey(verDist)) {
                mp.put(verDist, node);
            }
            if (node.left != null) {
                q.add(new Pair<>(node.left, verDist + 1));
            }
            if (node.right != null) {
                q.add(new Pair<>(node.right, verDist + 1));
            }
        }
        for (Node node : mp.values()) {
            System.out.print(node.val + " ");
        }
        System.out.println("");
        return this;
    }

    public Tree rightView() {
        Queue<Pair<Node, Integer>> q = new LinkedList<>();
        Map<Integer, Node> mp = new HashMap<>();
        q.add(new Pair<>(root, 0));
        while (!q.isEmpty()) {
            Pair<Node, Integer> pair = q.poll();
            int verDist = pair.getSecond();
            Node node = pair.getFirst();
            mp.put(verDist, node);
            if (node.left != null) {
                q.add(new Pair<>(node.left, verDist + 1));
            }
            if (node.right != null) {
                q.add(new Pair<>(node.right, verDist + 1));
            }
        }
        for (Node node : mp.values()) {
            System.out.print(node.val + " ");
        }
        System.out.println("");
        return this;
    }

}