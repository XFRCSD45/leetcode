class Solution {
public:
    bool search(vector<int>& arr, int k) {
        // int n=nums.size();
        // int low=0, high=n-1;
        // while(low<=high)
        // {
        //       int mid=low+(high-low)/2;
        //     if(nums[mid]==target)
        //     {
        //          return true;
        //     }
        //     if(nums[mid]==nums[low]==nums[high])
        //     {
        //         low=low+1;
        //         high=high-1;
        //         continue;
        //     }
        //     //check if left part is sorted
        //     if(nums[low]<=nums[mid])
        //     {
        //        if(nums[low]<=target && target<=nums[mid])
        //        {
        //           high=mid-1;
        //        }
        //         else
        //         {
        //            low=mid+1;
        //         }
        //     }
        //     else
        //     {
        //          if(nums[high]>=target && target>=nums[mid])
        //        {
        //           low=mid+1;
        //        }
        //         else
        //         {
        //            high=mid-1;
        //         }
        //     }
        // }
        // return false;
        int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
    }
};