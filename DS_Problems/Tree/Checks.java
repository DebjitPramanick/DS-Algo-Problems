package DS_Problems.Tree;

import java.util.LinkedList;
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

class TreeForChecks {

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

    public TreeForChecks() {
        root = new Node(20);
        root.left = new Node(10);
        root.right = new Node(10);
        root.left.left = new Node(3);
        root.left.right = new Node(7);
        root.right.left = new Node(7);
        root.right.right = new Node(3);
    }

    public TreeForChecks displayBFS() {
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

    /*
     * Given a binary tree, write a function that returns true if the
     * tree satisfies below property. For every node, data value must
     * be equal to sum of data values in left and right children.
     */
    public TreeForChecks checkChildrenSum() {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node node = q.poll();

            if (node.left != null || node.right != null) {
                int sum = 0;
                if (node.left != null) {
                    sum += node.left.val;
                }
                if (node.right != null) {
                    sum += node.right.val;
                }
                if (node.val != sum) {
                    System.out.println("Does not meet condition, Node: " + node.val);
                    return this;
                }
            }

            if (node.left != null) {
                q.add(node.left);
            }

            if (node.right != null) {
                q.add(node.right);
            }
        }

        System.out.println("All nodes in tree meet condition.");
        return this;
    }

    /*
     * Given a Binary Tree, check if all leaves are at same level or not.
     */
    public TreeForChecks checkIfAllLeavesAreAtSameLevel() {
        int lastLeaveNodeLevel = -1;
        Queue<Pair<Node, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 0));

        while (!q.isEmpty()) {
            Pair<Node, Integer> pair = q.poll();
            Node node = pair.getFirst();
            Integer level = pair.getSecond();

            if (node.left == null && node.right == null) {
                if (lastLeaveNodeLevel == -1) {
                    lastLeaveNodeLevel = level;
                } else if (level != lastLeaveNodeLevel) {
                    System.out.println("Leave is not at same level, Leave node: " + node.val);
                    return this;
                }
            }

            if (node.left != null) {
                q.add(new Pair<>(node.left, level + 1));
            }

            if (node.right != null) {
                q.add(new Pair<>(node.right, level + 1));
            }
        }

        System.out.println("All leaves are at same level.");

        return this;
    }

    public TreeForChecks checkIfSymmetric() {
        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();

        Node left = root.left;
        Node right = root.right;

        if (left == null || right == null) {
            System.out.println("Not symmetric.");
            return this;
        }

        s1.add(left);
        s2.add(right);

        while (true) {
            while (left != null && right != null) {
                if (left.val != right.val) {
                    System.out.println("Not symmetric.");
                    return this;
                }
                s1.add(left);
                s2.add(right);
                left = left.left;
                right = right.right;
            }

            if (!(left == null && right == null)) {
                System.out.println("Not symmetric.");
                return this;
            }

            if (!s1.isEmpty() && !s2.isEmpty()) {
                left = s1.pop();
                right = s2.pop();

                left = left.right;
                right = right.left;
            } else {
                break;
            }
        }
        System.out.println("Is symmetric.");
        return this;
    }

    public TreeForChecks checkIfCousins(int a, int b) {
        if (getLevel(root, a, 1) == getLevel(root, b, 1) && !isSibling(root, a, b)) {
            System.out.println("These two are cousins.");
        } else {
            System.out.println("Not cousins.");
        }

        return this;
    }

    public TreeForChecks checkIfMirror() {
        System.out.println(checkIfMirrorHelper(root.left, root.right));
        return this;
    }

    private boolean checkIfMirrorHelper(Node head1, Node head2) {
        if (head1 == null && head2 == null) {
            return true;
        }
        if (head1 == null || head2 == null) {
            return false;
        }

        return head1.val == head2.val && checkIfMirrorHelper(head1.left, head2.right)
                && checkIfMirrorHelper(head1.right, head2.left);
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

    private boolean isSibling(Node node, int a, int b) {
        if (node == null) {
            return false;
        }
        if (node.left != null && node.right != null) {
            if ((node.left.val == a && node.right.val == b) || (node.left.val == b && node.right.val == a)) {
                return true;
            }
        }
        return isSibling(node.left, a, b) || isSibling(node.right, a, b);
    }
}

public class Checks {
    public static void main(String[] args) {
        TreeForChecks tree = new TreeForChecks();
        tree
                .displayBFS()
                .checkChildrenSum()
                .checkIfAllLeavesAreAtSameLevel()
                .checkIfSymmetric()
                .checkIfCousins(7, 4)
                .checkIfMirror();

    }
}
