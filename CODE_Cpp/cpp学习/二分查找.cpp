class Solution {
public:
    int search(vector<int>& nums, int target) {
            int left = -1,right = nums.size,mid;
            while (left + 1 < right) {
                mid = Math.ceil((left + right) / 2);
                if (nums[mid] < target) {
                    left = mid;
                }else{right = mid;}
            }
            if (nums[right] == target) {return right;}
            if (nums[right] == target) {return left;}
            return -1;
    }
}