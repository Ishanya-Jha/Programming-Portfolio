class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int ans = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {

            int newBottle = empty / numExchange;

            ans = ans + newBottle;

            empty = (empty % numExchange) + newBottle;
        }

        return ans;
    }
};
