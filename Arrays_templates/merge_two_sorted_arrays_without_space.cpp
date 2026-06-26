// LEETCODE 88: https://leetcode.com/problems/merge-sorted-array/description/
// Here, extra space is given in one of the arrays as zeroes.
//solution for this leetcode
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        
        while (i>=0 && j>=0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // nums2 lo migili untey 
        while(j>=0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        } 
        // nums1 ki rayalsina avasaram ledhu
    }
};



/*
MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE
(Gap Method / Shell Sort Technique)
HERE, NO EXTRA SPACE IS GIVEN IN EITHER OF THE ARRAYS AS ZEROES.

TIME COMPLEXITY: O((n+m) log(n+m))
SPACE COMPLEXITY: O(1)

Idea:

Treat both arrays as one combined array.

Initially,
gap = ceil((n+m)/2)

Compare elements that are 'gap' distance apart.

If they are out of order,
swap them.

After every pass,

gap = ceil(gap/2)

Repeat until gap becomes 1.

Finally both arrays become sorted without using any extra space.
*/

class Solution {
public:

    int nextGap(int gap) {
        if (gap <= 1)
            return 0;
        return (gap + 1) / 2;
    }

    void merge(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();

        int gap = nextGap(n + m);

        while (gap > 0) {

            int left = 0;
            int right = gap;

            while (right < n + m) {

                // Both pointers in arr1
                if (left < n && right < n) {
                    if (arr1[left] > arr1[right])
                        swap(arr1[left], arr1[right]);
                }

                // left in arr1, right in arr2
                else if (left < n && right >= n) {
                    if (arr1[left] > arr2[right - n])
                        swap(arr1[left], arr2[right - n]);
                }

                // Both pointers in arr2
                else {
                    if (arr2[left - n] > arr2[right - n])
                        swap(arr2[left - n], arr2[right - n]);
                }

                left++;
                right++;
            }

            gap = nextGap(gap);
        }
    }
};
