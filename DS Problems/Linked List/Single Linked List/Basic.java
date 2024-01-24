import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class LinkedList {

    Node head;

    class Node {
        int val;
        Node next;

        Node(int _val) {
            this.val = _val;
            next = null;
        }
    }

    public LinkedList(int nums[]) {
        for (int i = 0; i < nums.length; i++) {
            this.insert(nums[i]);
        }
    }

    public LinkedList insert(int val) {
        Node node = new Node(val);
        if (head != null) {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = node;
        } else {
            head = node;
        }

        return this;
    }

    public LinkedList delete(int val) {

        if (head != null) {
            Node temp = head, prev = null;

            if (temp.val == val) {
                temp = temp.next;
                head = temp;
                return this;
            }

            prev = temp;
            temp = temp.next;

            while (temp != null && temp.val != val) {
                prev = temp;
                temp = temp.next;
            }

            if (temp != null) {
                prev.next = temp.next;
                temp = temp.next;
                System.out.println("Node is deleted.");
            } else {
                System.out.println("Node not found.");
            }
        }

        return this;
    }

    public LinkedList display() {
        System.out.println("Linked List: ");
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println("");
        return this;
    }

    public LinkedList displayFromNode(Node node) {
        System.out.println("Linked List from node: ");
        Node temp = node;
        while (temp != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println("");
        return this;
    }

    public LinkedList getNthNode(int n) {
        Node temp = head;
        while (temp != null && n > 1) {
            temp = temp.next;
            n--;
        }
        if (temp != null) {
            System.out.println("Nth node: " + temp.val);
        }

        return this;
    }

    public LinkedList isPalindrome() {
        boolean listIsPalindrome = true;
        Stack<Node> s = new Stack<>();

        Node temp = head;
        while (temp != null) {
            s.push(temp);
            temp = temp.next;
        }

        temp = head;

        while (temp != null) {
            if (s.peek().val != temp.val) {
                listIsPalindrome = false;
                break;
            }
            temp = temp.next;
            s.pop();
        }

        System.out.println("List is palindrome: " + listIsPalindrome);
        return this;
    }

    public LinkedList removeDuplicate() {

        Node temp = head, prev = head;
        temp = temp.next;
        Map<Integer, Integer> mp = new HashMap<>();

        while (temp != null) {
            if (mp.get(temp.val) == null) {
                mp.put(temp.val, 1);
                prev = temp;
            } else {
                prev.next = temp.next;
            }
            temp = temp.next;
        }
        return this.display();
    }

    public LinkedList reverse() {
        Node cur = head, prev = null, next = null;
        while (cur != null) {
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;

        return this.display();
    }

    public LinkedList swapKthNode(int k) {
        Node cur = head, firstNode = head, secNode = head, prevOfFirstNode = null, prevOfSecondNode = null;
        int len = 0;

        while (cur != null) {
            len++;
            cur = cur.next;
        }

        int firstNodeIdx = k;
        int secondNodeIdx = len - k + 1;
        cur = head;

        for (int i = 1; i <= len; i++) {
            if (i + 1 == firstNodeIdx) {
                prevOfFirstNode = cur;
                firstNode = cur.next;
            } else if (i + 1 == secondNodeIdx) {
                prevOfSecondNode = cur;
                secNode = cur.next;
            }

            cur = cur.next;
        }

        if (prevOfFirstNode != null)
            prevOfFirstNode.next = secNode;
        if (prevOfSecondNode != null)
            prevOfSecondNode.next = firstNode;

        Node temp = firstNode.next;
        firstNode.next = secNode.next;
        secNode.next = temp;

        if (k == 1)
            head = secNode;
        if (k == len)
            head = firstNode;

        return this.display();
    }

    Node quickSort(Node headNode) {
        if (headNode == null || headNode.next == null) {
            return headNode;
        }

        Node partitionedLists[] = this.getPivot(headNode);

        Node left = partitionedLists[0];
        Node pivot = partitionedLists[1];
        Node right = partitionedLists[2];

        left = quickSort(left);
        right = quickSort(right);

        return this.concatenate(left, pivot, right);
    }

    Node concatenate(Node left, Node pivot, Node right) {
        Node result = left;

        if (left != null) {
            while (left.next != null) {
                left = left.next;
            }
            left.next = pivot;
        } else {
            result = pivot;
        }

        if (pivot != null) {
            while (pivot.next != null) {
                pivot = pivot.next;
            }
            pivot.next = right;
        }

        return result;
    }

    Node[] getPivot(Node headNode) {
        Node pivot = headNode;
        while (pivot.next != null) {
            pivot = pivot.next;
        }

        Node less = new Node(0), equal = new Node(0), greater = new Node(0), cur = headNode;
        Node lessTail = less, equalTail = equal, greaterTail = greater;

        while (cur != null) {
            if (cur.val < pivot.val) {
                lessTail.next = cur;
                lessTail = lessTail.next;
            } else if (cur.val == pivot.val) {
                equalTail.next = cur;
                equalTail = equalTail.next;
            } else if (cur.val > pivot.val) {
                greaterTail.next = cur;
                greaterTail = greaterTail.next;
            }
            cur = cur.next;
        }

        lessTail.next = null;
        equalTail.next = null;
        greaterTail.next = null;

        return new Node[] { less.next, equal.next, greater.next };
    }

    public LinkedList sort() {
        System.out.println("Sorting list: ");
        head = quickSort(head);
        return this.display();
    }
}

class Basic {

    public static void main(String args[]) {
        int nums[] = { 2, 7, 9, 20, 10, 7, 50, 43, 23, 11, 5 };
        LinkedList list = new LinkedList(nums);
        list.display().getNthNode(6).isPalindrome().removeDuplicate().reverse().swapKthNode(1).sort();
    }
}