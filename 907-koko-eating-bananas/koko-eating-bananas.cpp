class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int speed) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;   // ceil(pile / speed)

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid)) {
                high = mid - 1;   // Try smaller speed
            } else {
                low = mid + 1;    // Need faster speed
            }
        }

        return low;
    }
};