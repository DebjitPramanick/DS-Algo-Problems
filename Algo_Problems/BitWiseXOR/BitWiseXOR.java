package Algo_Problems.BitWiseXOR;

/*
 * In an array, find the element that occurs only once in the array,
 * given that each element occurs twice
 * 
 * Properties:
 * a XOR 0 = a
 * a XOR a = 0
 * XOR is associative
 */

public class BitWiseXOR {
    public static void main(String[] args) {
        int nums[] = { 2, 6, 2, 7, 6 };
        solve(nums);
    }

    static void solve(int nums[]) {
        int num = 0;
        for (int i = 0; i < nums.length; i++) {
            num = num ^ nums[i];
        }

        System.out.println(num);
    }
}

/*
 * 0010 XOR 0110 = 0100
 * 0100 XOR 0010 = 0110
 * 0110 XOR 0111 = 0001
 * 0001 XOR 0110 = 0111 (7)
 * 
 * So (2 XOR 6) XOR (2 XOR 6) XOR 7 = 0 XOR 0 XOR 7
 * = 0 XOR 7 = 7
 */
