class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 1) continue;
            
            bool leftSafe  = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightSafe = (i == size - 1) || (flowerbed[i + 1] == 0);
            
            if (leftSafe && rightSafe) {
                flowerbed[i] = 1;
                if (++count >= n) return true;
            }
        }
        return false;
    }
};