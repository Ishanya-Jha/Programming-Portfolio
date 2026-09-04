class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0){
            return true;
        }
        for (int i = 0; i < flowerbed.size(); i++) {

            if (flowerbed[i] == 0) {

                int left = 0;
                int right = 0;

                if (i > 0) {
                    left = flowerbed[i - 1];
                }

                if (i < flowerbed.size() - 1) {
                    right = flowerbed[i + 1];
                }

                if (left == 0 && right == 0) {
                    flowerbed[i] = 1;
                    n--;

                    if (n == 0) {
                        return true;
                    }
                }
            }
        }

        return n == 0;
    }
};
