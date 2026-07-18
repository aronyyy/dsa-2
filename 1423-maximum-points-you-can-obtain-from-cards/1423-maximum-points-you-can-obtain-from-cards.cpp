class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0;
        int right = 0;
        int maxS = 0;
        int n = cardPoints.size();

        // Take first k cards
        for (int i = 0; i < k; i++)
            left += cardPoints[i];

        maxS = left;

        // Replace left cards with right cards one by one
        for (int i = 0; i < k; i++) {
            left -= cardPoints[k - 1 - i];
            right += cardPoints[n - 1 - i];

            maxS = max(maxS, left + right);
        }

        return maxS;
    }
};