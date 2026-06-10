class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), m = matrix.size();
        int left = 0, right = m*n - 1;
        while(left <= right){
            int mid = left + (right-left)/2;
            int row = mid/n, col = mid%n;
            if(matrix[row][col] < target) left = mid + 1;
            else if(matrix[row][col] > target) right = mid - 1;
            else{
                return true;
            }
        }
        return false;
    }
};
