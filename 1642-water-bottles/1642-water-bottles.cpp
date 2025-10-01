class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consume=0;
        while(numBottles>=numExchange){
            consume+=numExchange;
            numBottles-=numExchange;

            numBottles++;
        }

        return consume+numBottles;
    }
};