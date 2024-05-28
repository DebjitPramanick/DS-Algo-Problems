package Algo_Problems.BinarySearch;

public class FindCeilAndFloor {
    public static void main(String[] args) {
        int nums[] = { 5, 10, 10, 20, 25, 30, 40 };
        solve(nums, 16);
    }

    static int findFloor(int nums[], int target) {
        int s = 0, e = nums.length - 1;
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                idx = mid;
                break;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                idx = mid;
                s = mid + 1;
            }
        }

        return idx;
    }

    static int findCeil(int nums[], int target) {
        int s = 0, e = nums.length - 1;
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                idx = mid;
                break;
            } else if (nums[mid] > target) {
                idx = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return idx;
    }

    static void solve(int nums[], int target) {
        int floorIdx = findFloor(nums, target);
        int ceilIdx = findCeil(nums, target);

        System.out.println("Floor: " + nums[floorIdx] + " Ceil: " + nums[ceilIdx]);
    }
}
