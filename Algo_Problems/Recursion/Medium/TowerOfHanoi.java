package Algo_Problems.Recursion.Medium;

/*
Tower of Hanoi is a mathematical puzzle where we have three rods 
(A, B, and C) and N disks. Initially, all the disks are stacked 
in decreasing value of diameter i.e., the smallest disk is placed 
on the top and they are on rod A. The objective of the puzzle is 
to move the entire stack to another rod (here considered C), 
obeying the following simple rules: 

- Only one disk can be moved at a time.
- Each move consists of taking the upper disk from one of the stacks 
and placing it on top of another stack i.e. a disk can only be moved 
if it is the uppermost disk on a stack.
- No disk may be placed on top of a smaller disk.
 */

public class TowerOfHanoi {
    static Integer numOfMoves = 0;

    public static void main(String[] args) {
        solve(3, 0, 2, 1);
        System.out.println("Total " + numOfMoves + " moves are required");
    }

    static void solve(Integer nDisks, Integer fromRod, Integer toRod, Integer auxRod) {
        if (nDisks == 0) {
            return;
        }

        solve(nDisks - 1, fromRod, auxRod, toRod);
        System.out.println("Move disk " + nDisks + " from " + fromRod + " to " + toRod);
        numOfMoves++;
        solve(nDisks - 1, auxRod, toRod, fromRod);
    }
}
