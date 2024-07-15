package DS_Problems.Tree;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
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

class MiscTree {

    Node root;
    static int kthAncestor = 2;
    static int nextPos = 0;

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

    public MiscTree() {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
    }

    public MiscTree displayBFS() {
        Queue<Node> q = new LinkedList<Node>();

        System.out.println("Displaying MiscTree: ");
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

    public MiscTree findKthAncestor(int nodeVal) {
        findKthAncestorRec(root, nodeVal);
        return this;
    }

    public MiscTree findLCA(int num1, int num2) { // Lowest Common Ancestor
        Node node = findLCARec(root, num1, num2);
        if (node != null) {
            System.out.println("LCA is: " + node.val);
        } else {
            System.out.println("No LCA found.");
        }
        return this;
    }

    public MiscTree pathFromRootToNode(int target) {
        List<Node> list = new ArrayList<>();
        pathFromRootToNodeRec(root, target, list);
        System.out.println();
        return this;
    }

    public MiscTree printAllRootToLeaves() {
        Map<Node, Node> parentByChild = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        parentByChild.put(root, null);
        q.add(root);
        System.out.println("Printing all root to leaves: ");
        while (!q.isEmpty()) {
            Node node = q.poll();
            if (node.left == null && node.right == null) {
                printTopToBottom(node, parentByChild);
            } else {
                if (node.left != null) {
                    parentByChild.put(node.left, node);
                    q.add(node.left);
                }
                if (node.right != null) {
                    parentByChild.put(node.right, node);
                    q.add(node.right);
                }
            }
        }
        return this;
    }

    public MiscTree getCousins(int nodeVal) {
        int level = getLevel(root, nodeVal, 1);
        Node node = findNode(root, nodeVal);
        if (node == null) {
            return this;
        }
        printLevel(level, root, node);
        return this;
    }

    public MiscTree getInorderSuccessor(Integer val) {
        List<Integer> nodes = new ArrayList<>();
        nodes.add(-1);
        storeInorder(root, nodes);
        nodes.add(-1);
        for (Integer i = 1; i < nodes.size() - 1; i++) {
            if (nodes.get(i) == val && nodes.get(i + 1) != -1) {
                System.out.println("Successor is: " + nodes.get(i + 1));
            } else if (nodes.get(i) == val) {
                System.out.println("No successor.");
            }
        }
        return this;
    }

    public MiscTree diameter() {
        System.out.println("Diameter is: " + findDiameter(root));
        return this;
    }

    public MiscTree reverseTreePath(int key) {
        Map<Integer, Integer> map = new HashMap<>();
        reverseUtil(root, 0, key, map);
        return this;
    }

    private Node reverseUtil(Node node, int level, int key, Map<Integer, Integer> map) {
        if (node == null) {
            return null;
        }
        if (node.val == key) {
            map.put(level, node.val);
            node.val = map.get(nextPos);
            nextPos++;
            return node;
        }
        map.put(level, node.val);
        Node right = null, left = null;
        left = reverseUtil(node.left, level + 1, key, map);
        if (left == null) {
            right = reverseUtil(node.right, level + 1, key, map);
        }

        if (left != null || right != null) {
            node.val = map.get(nextPos++);
            return left != null ? left : right;
        }

        return null;
    }

    private void storeInorder(Node node, List<Integer> nodes) {
        if (node == null) {
            return;
        }
        storeInorder(node.left, nodes);
        nodes.add(node.val);
        storeInorder(node.right, nodes);
    }

    private void printLevel(int level, Node parent, Node node) {
        if (node == null || level < 2) {
            return;
        }

        if (level == 2) {
            if (parent.left == node || parent.right == node) {
                return;
            }
            if (parent.left != null) {
                System.out.println(parent.left.val);
            }
            if (parent.right != null) {
                System.out.println(parent.right.val);
            }
        }

        else if (level > 2) {
            printLevel(level - 1, parent.left, node);
            printLevel(level - 1, parent.right, node);
        }
    }

    private int getLevel(Node node, int val, int level) {
        if (node == null) {
            return -1;
        }
        if (node.val == val) {
            return level;
        }
        int lev = getLevel(node.left, val, level + 1);
        if (lev == -1) {
            lev = getLevel(node.right, val, level + 1);
        }
        return lev;
    }

    private Node findNode(Node node, int val) {
        if (node == null) {
            return null;
        }
        if (node.val == val) {
            return node;
        }
        Node left = findNode(node.left, val);
        if (left != null) {
            return left;
        }
        return findNode(node.right, val);
    }

    private void printTopToBottom(Node node, Map<Node, Node> parentByChild) {
        Stack<Node> s = new Stack<>();
        Node curNode = node;
        while (curNode != null) {
            s.add(curNode);
            curNode = parentByChild.get(curNode);
        }

        while (!s.isEmpty()) {
            Node n = s.pop();
            System.out.print(n.val + " -> ");
        }
        System.out.println();
    }

    private void pathFromRootToNodeRec(Node node, int target, List<Node> path) {
        if (node == null) {
            return;
        }
        if (node.val == target) {
            path.add(node);
            for (Node n : path) {
                System.out.print(n.val + " -> ");
            }
            return;
        }

        path.add(node);
        pathFromRootToNodeRec(node.left, target, path);
        pathFromRootToNodeRec(node.right, target, path);
        path.removeLast();
    }

    private Node findLCARec(Node node, int num1, int num2) { // Lowest Common Ancestor
        if (node == null) {
            return null;
        }

        if (node.val == num1 || node.val == num2) {
            return node;
        }

        Node left = findLCARec(node.left, num1, num2);
        Node right = findLCARec(node.right, num1, num2);

        if (left != null && right != null) {
            return node;
        }

        if (left == null && right == null) {
            return null;
        }

        if (left != null) {
            return findLCARec(node.left, num1, num2);
        }

        return findLCARec(node.right, num1, num2);
    }

    private Node findKthAncestorRec(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (node.val == data || findKthAncestorRec(node.left, data) != null
                || findKthAncestorRec(node.right, data) != null) {
            if (kthAncestor > 0) {
                kthAncestor--;
            } else if (kthAncestor == 0) {
                System.out.println("K th ancestor is: " + node.val);
                return null;
            }
            return node;
        }

        return null;
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
}

public class Misc {
    public static void main(String[] args) {
        MiscTree tree = new MiscTree();
        tree.displayBFS().findKthAncestor(5).findLCA(9, 0).pathFromRootToNode(7).printAllRootToLeaves().getCousins(5)
                .getInorderSuccessor(1).diameter().reverseTreePath(5).displayBFS();
    }
}
