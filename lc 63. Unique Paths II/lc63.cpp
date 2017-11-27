class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        obstacleGrid[0][0]^=1;
        for(int i=1;i<m;i++)//first column
            obstacleGrid[i][0]=obstacleGrid[i][0]?0:obstacleGrid[i-1][0];
        for(int i=1;i<n;i++)//first row
            obstacleGrid[0][i]=obstacleGrid[0][i]?0:obstacleGrid[0][i-1];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                obstacleGrid[i][j]=obstacleGrid[i][j]?0:obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
        return obstacleGrid[m-1][n-1];
    }
};

/*
Pay attention to the difference between lc62 and lc63.
*/

class BIT {
    vector<int> slots;
public:
    BIT(int n) {
        slots = vector<int>(n, 0);
    }

    int lowBit(int x) {
        return x & -x;
    }

    void update(int pos) {
        int p = pos;
        while (p < slots.size()) {
            slots[p]++;
            p = p + lowBit(p);
        }
    }

    int getPrefixSum(int pos) {
        if (pos == 0) return slots[0];
        int p = pos, sum = 0;
        while (p > 0) {
            sum += slots[p];
            p = p - lowBit(p);
        }
        return sum;
    }

    int getIntervalSum(int begin, int end) {
        return getPrefixSum(end) - getPrefixSum(begin);
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        BIT bit(flowers.size() + 1);
        vector<int> bloom(flowers.size() + 1, 0);
        for (int i = 0; i < flowers.size(); i++) {
            bit.update(flowers[i]);
            bloom[flowers[i]] = 1;
            if (flowers[i] - k - 1 > 0 && bloom[flowers[i] - k - 1] && bit.getIntervalSum(flowers[i] - k - 1, flowers[i] - 1) == 0) {
                return i + 1;
            }
            if (flowers[i] + k + 1 < flowers.size() + 1 && bloom[flowers[i] + k + 1] && bit.getIntervalSum(flowers[i], flowers[i] + k) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};