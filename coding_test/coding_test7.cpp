#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;

  for(int i = 0; i < nums.size(); i++) {
    if(i > 0 && nums[i] == nums[i-1]) continue;

    for(int j = i + 1; j < nums.size(); j++) {
      int k = j + 1;
      while(nums[j]+nums[k] < -nums[i]) k++;
      if(nums[j]+nums[k] == -nums[i]){
        vector<int> v = {nums[i], nums[j], nums[k]};
        ans.push_back(v);
      }

    }

  }
}