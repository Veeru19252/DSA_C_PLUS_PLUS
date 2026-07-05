/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            int x = arr.get(m);
            if (x < arr.get(m + 1)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int p = l;
        l = 0, r = p;
        while (l <= r) {
            int m = (l + r) >> 1;
            int x = arr.get(m);
            if (x == target) return m;
            if (x < target) l = m + 1;
            else r = m - 1;
        }
        l = p + 1, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            int x = arr.get(m);
            if (x == target) return m;
            if (x > target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};