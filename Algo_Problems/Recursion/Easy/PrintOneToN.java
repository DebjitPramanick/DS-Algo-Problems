package Algo_Problems.Recursion.Easy;

public class PrintOneToN {
    public static void main(String[] args) {
        print(10);
    }

    static void print(Integer n) {
        if (n == 1) {
            return;
        }
        print(--n);
        System.out.println(n);
    }
}
