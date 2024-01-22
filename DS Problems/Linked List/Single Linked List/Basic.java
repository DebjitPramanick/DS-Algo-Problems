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
}

class Basic {

    public static void main(String args[]) {
        LinkedList list = new LinkedList();
        list.insert(20)
                .insert(4)
                .insert(5)
                .insert(4)
                .insert(20);
        list.display().getNthNode(6).isPalindrome();

    }
}