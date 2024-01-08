#include <iostream>
#include <vector>

// LeetCOde Solutions 
void fucntion()
{
    int a;
    int b[90000000000000];

}
/*class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int>ans;
        for(int i =0; i < nums.size(); i++)
        {
            for(int j = 1; j <nums.size(); j++) {

                if ( (nums[i] + nums[j]) == target&& i != j){
                    // std::vector<int> a{i, j};
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;


                }

            }
        }
        return ans;
    }
};*/



/*  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Dummy nodes is using for the reaching the first element
       ListNode *dummy = new ListNode();
       ListNode *temp = dummy;
       int carry = 0;
       while(l1 != nullptr || l2 != nullptr || carry)
       {
           int sum =0;
           if(l1 != nullptr)
           {
               sum+= l1->val;
               l1 = l1->next;

           }

           if(l2 != nullptr)
           {
               sum+=l2->val;
               l2 = l2->next;
           }

           sum+=carry;
           carry = sum/10;
           //
           ListNode *newnode = new ListNode(sum % 10);
           temp->next = newnode;
           temp = temp->next;

       }
        return dummy->next;

    }

};*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *dummy = new ListNode();
       ListNode *temp = dummy;
       int carry = 0;
       while(l1 != nullptr || l2 != nullptr || carry)
       {
           int sum =0;
           if(l1 != nullptr)
           {
               sum+= l1->val;
               l1 = l1->next;

           }

           if(l2 != nullptr)
           {
               sum+=l2->val;
               l2 = l2->next;
           }

           sum+=carry;
           carry = sum/10;
           //
           ListNode *newnode = new ListNode(sum % 10);
           temp->next = newnode;
           temp = temp->next;

       }
        return dummy->next;

    }

};
 int reverse(int x) {
        int t =0;

        while(x != 0)
        {
            int digit = x % 10;
            if((t > INT_MAX/10) || (t < INT_MIN/10)){
                return 0;
            }
            t = t * 10 + digit;
            x = x / 10;

        }
        return t;
    }

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector <int>merged;
        int i = 0, j =0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }
        
         int n = merged.size();
        if (n% 2 == 0) {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        } else {
            return merged[n / 2];
        }

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
   /// fucntion();
std::string s = "abcabcbb";
std::string p = "bbbbb";
std::string ss = "pwwkew";
int t = aka(s);
std::cout<<t<<std::endl;


    return 0;
}
