#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstdlib>
// #include <limits.h>
#include <climits>
#include <memory>
#include <cstring>
#include <cmath>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// 56
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/// 138
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

/// 297
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

///

class Solution
{
public:
    int binarySearch(const vector<int> &numbers, int target)
    {
        int a = 0, b = numbers.size() - 1;
        while (a <= b)
        {
            int mid = (a + b) / 2;
            if (target == numbers[mid])
                return mid;
            if (target > numbers[mid])
                a = mid + 1;
            else
            {
                b = mid - 1;
            }
        }
        return -1;
    }

    /**
    1
    Two Sum

    Given an array of integers, find two numbers such that they add up to a specific target number.
    The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
    Please note that your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution.
    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
    **/
    bool _1 = true;
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans(2);

        unordered_map<int, int> umap;
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            if (umap.find(target - numbers[i]) != umap.end())
            {
                ans[0] = umap[target - numbers[i]] + 1;
                ans[1] = i + 1;
                break;
            }
            umap[numbers[i]] = i;
        }
        return ans;
    }

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    bool _2 = true;
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = NULL;
        ListNode *f = NULL;
        int ext = 0;
        while (l1 || l2)
        {
            ListNode *now = new ListNode(0);
            int a = (!l1 ? 0 : l1->val);
            int b = (!l2 ? 0 : l2->val);
            now->val += (a + b + ext) % 10;
            ext = (a + b + ext) / 10;
            if (!f)
            {
                ans = now;
                f = now;
            }
            else
            {
                f->next = now;
                f = f->next;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (ext > 0)
            f->next = new ListNode(ext);
        return ans;
    }
    /**
    3. Longest Substring Without Repeating Characters
    Given a string, find the length of the longest substring without repeating characters.

    Example 1:

    Input: "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:

    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
    **/
    int _3 = 3;
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        int _max = 1, last = 0;
        map<char, int> m;
        m[s.at(0)] = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if (m.find(s.at(i)) != m.end() && m[s.at(i)] >= last)
            {
                //                last = i;
                last = max(last, m[s.at(i)] + 1);
                _max = max(_max, i - last);
            }
            else
                _max = max(_max, i - last + 1);
            m[s.at(i)] = i;
        }
        return _max;
    }

    /**
    4
    Median of Two Sorted Arrays

    There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).
    **/
    bool _4 = true;
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m == 1 && n == 1)
            return (nums1[0] + nums2[0]) / 2.0;
        if (m == 0)
            return n % 2 == 0 ? (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0 : nums2[n / 2];
        if (n == 0)
            return m % 2 == 0 ? (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0 : nums1[m / 2];

        int pre_num = (m + n) / 2; /// important position
        int _begin = 0, _end = nums1.size();
        while (_begin != _end)
        {
            int now = (_begin + _end) / 2;
            int l = pre_num - now - 1; /// difficult
            if (l == -1 && nums1[now] <= nums2[l + 1] ||
                l + 1 == n && nums1[now] >= nums2[l] ||
                l >= 0 && l + 1 < n && nums1[now] >= nums2[l] && nums1[now] <= nums2[l + 1])
            {
                if ((m + n) % 2 != 0)
                    return nums1[now];
                else
                {
                    if (l == -1)
                        return (nums1[now] + nums1[now - 1]) / 2.0;
                    if (now == 0)
                        return (nums1[now] + nums2[l]) / 2.0;
                    return (nums1[now] + max(nums1[now - 1], nums2[l])) / 2.0;
                }
            }
            else if (l + 1 >= 0 && l + 1 < n && nums1[now] > nums2[l + 1] || l <= -2)
            {
                _end = now;
            }
            else
            {
                _begin = now + 1;
            }
        }
        _begin = 0;
        _end = nums2.size();
        while (_begin != _end)
        {
            int now = (_begin + _end) / 2;
            int l = pre_num - now - 1;
            /// if((l == -1 ||nums1[l] <= nums2[now]) && nums2[now] <= nums1[l + 1]) {
            if (l == -1 && nums2[now] <= nums1[l + 1] ||
                l + 1 == m && nums2[now] >= nums1[l] ||
                l >= 0 && l + 1 < m && nums2[now] >= nums1[l] && nums2[now] <= nums1[l + 1])
            {
                if ((m + n) % 2 != 0)
                    return nums2[now];
                else
                {
                    if (l == -1)
                        return (nums2[now] + nums2[now - 1]) / 2.0;
                    if (now == 0)
                        return (nums2[now] + nums1[l]) / 2.0;
                    return (nums2[now] + max(nums2[now - 1], nums1[l])) / 2.0;
                }
            }
            else if (l + 1 >= 0 && l + 1 < m && nums2[now] > nums1[l + 1] || l <= -2)
            {
                _end = now;
            }
            else
            {
                _begin = now + 1;
            }
        }
        return 0;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {

        int ai = 0, bi = 0, num = 0;
        double ans = 0.0;
        while (num < (m + n) / 2)
        {
            ans = (A[ai] <= B[bi] && ai < m) ? A[ai++] : B[bi++];
            ++num;
        }
        if ((m + n) % 2 == 0)
            ans = static_cast<double>(ans + ((A[ai] <= B[bi] && ai < m) ? A[ai] : B[bi])) / 2.0;
        else
            ans = static_cast<double>((A[ai] <= B[bi] && ai < m) ? A[ai] : B[bi]);
        return ans;
    }

    //    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //        int ai = 0, bi = 0, num = 0;
    //        int m = nums1.size(), n = nums2.size();
    //        double ans = 0.0;
    //        while(num < (m + n) / 2) {
    //            ans = (nums1[ai] <= nums2[bi] && ai < m)? nums1[ai++]:nums2[bi++];
    //            ++num;
    //        }
    //        if((m + n) % 2 == 0)
    //            ans = static_cast<double>(ans + ((nums1[ai] <= nums2[bi] && ai < m)? nums1[ai]:nums2[bi] )) / 2.0;
    //        else
    //            ans = static_cast<double>((nums1[ai] <= nums2[bi] && ai < m)? nums1[ai]:nums2[bi]);
    //        return ans;
    //    }

    /**
    5. Longest Palindromic Substring

    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

    Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    Example 2:

    Input: "cbbd"
    Output: "bb"
    **/
    bool _5 = true;
    void palindrome(const char cs[], int len[], int n)
    { // len[i] means the max palindrome length centered i/2
        for (int i = 0; i < n * 2; ++i)
        {
            len[i] = 0;
        }
        for (int i = 0, j = 0, k; i < n * 2; i += k, j = max(j - k, 0))
        { ///
            while (i - j >= 0 && i + j + 1 < n * 2 && cs[(i - j) / 2] == cs[(i + j + 1) / 2])
                j++;
            len[i] = j;
            for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; k++)
            {
                len[i + k] = min(len[i - k], j - k); /// 已知范围内最多可以复制的区域
            }
        }

        //        for (int i = 0; i < n * 2; ++i) {
        //            cout << i << " " << len[i] << endl;
        //        }
    }
    /*
    # a # b # b # a # h #  o  #  p  #  x  #  p  #  o #
      0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
      1 0 1 4 1 0 1 0 1 0 1  0  1  0  5  0  1  0  1  0
    */

    string longestPalindrome(string s)
    {
        int a[2002];
        palindrome(s.c_str(), a, s.length());
        int _max = 0, pos = 0;
        for (size_t i = 0; i < s.length() * 2; ++i)
        {
            if (a[i] > _max)
            {
                _max = a[i];
                pos = i / 2;
            }
            //            cout << i/2 << " " << a[i] << endl;
        }
        int _begin = pos - (_max - 1) / 2;

        return s.substr(_begin, _max);
    }

    /**
    6
    ZigZag Conversion
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    **/
    string convert(string s, int nRows)
    {
    }

    /**
    7. Reverse Integer
    Given a 32-bit signed integer, reverse digits of an integer.
    Example 1:

    Input: 123
    Output: 321
    Example 2:

    Input: -123
    Output: -321
    Example 3:

    Input: 120
    Output: 21
    Note:
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
    */
    int reverse(int x)
    {
        int64_t ans = 0;
        while (x)
        {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return ans > INT_MAX || ans < INT_MIN ? 0 : ans;
    }
    /**
    8. String to Integer (atoi)
    Implement atoi which converts a string to an integer.

    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

    The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

    If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

    If no valid conversion could be performed, a zero value is returned.

    Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
    Example 1:

    Input: "42"
    Output: 42
    Example 2:

    Input: "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus sign.
                 Then take as many numerical digits as possible, which gets 42.
    Example 3:

    Input: "4193 with words"
    Output: 4193
    Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
    Example 4:

    Input: "words and 987"
    Output: 0
    Explanation: The first non-whitespace character is 'w', which is not a numerical
                 digit or a +/- sign. Therefore no valid conversion could be performed.
    Example 5:

    Input: "-91283472332"
    Output: -2147483648
    Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
                 Thefore INT_MIN (−231) is returned.

    */
    int myAtoi(string str)
    {
        int _start = 0;
        for (_start = 0; _start < str.length(); ++_start)
        {
            if (str.at(_start) != ' ')
                break;
        }
        if (_start == str.length())
            return 0;
        int flag = 1;
        if (str.at(_start) == '-')
        {
            flag = -1;
            _start++;
        }
        else if (str.at(_start) == '+')
        {
            _start++;
        }

        if (_start == str.length())
            return 0;
        int _end;
        for (_end = _start; _end < str.length(); ++_end)
        {
            if (!(str.at(_end) >= '0' && str.at(_end) <= '9'))
                break;
        }
        if (_end == str.length())
            --_end;
        string tmp = str.substr(_start, _end - _start + 1);
        int64_t ans = atoll(tmp.c_str()) * flag;
        //        cout << _start << " " << _end << endl;
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return ans;
    }

    /**
    9. Palindrome Number
    Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

    Example 1:

    Input: 121
    Output: true
    Example 2:

    Input: -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
    Example 3:

    Input: 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
    Follow up:

    Coud you solve it without converting the integer to a string?
    **/
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        __int64_t y = 0, tmp = x;
        while (tmp)
        {
            __int64_t mod = tmp % 10;
            tmp /= 10;
            y = y * 10 + mod;
        }
        if (x == y)
            return true;
        return false;
    }

    /**
    10. Regular Expression Matching
    Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.
    The matching should cover the entire input string (not partial).

    Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.
    Example 1:

    Input:
    s = "aa"
    p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    Example 2:

    Input:
    s = "aa"
    p = "a*"
    Output: true
    Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
    Example 3:

    Input:
    s = "ab"
    p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".
    Example 4:

    Input:
    s = "aab"
    p = "c*a*b"
    Output: true
    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
    Example 5:

    Input:
    s = "mississippi"
    p = "mis*is*p*."
    Output: false

    **/

    bool isMatch(string &s, string &p)
    {
    }

    /**
    11. Container With Most Water
    Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Note: You may not slant the container and n is at least 2.

    Example:
    Input: [1,8,6,2,5,4,8,3,7]
    Output: 49
    **/
    int maxArea(vector<int> &height)
    {
        int ans = 0, r = height.size() - 1, l = 0;
        while (l < r)
        {
            int now = min(height[l], height[r]) * (r - l);
            ans = max(ans, now);
            if (height[l] > height[r])
                r--;
            else if (height[l] < height[r])
                l++;
            else
            {
                if (height[l + 1] < height[r - 1])
                    r--;
                else
                    l++;
            }
        }

        return ans;
    }
    /*
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;
        int ml = height[l], mr = height[r];
        while(l < r) {
            int now = min(height[l], height[r]) * (r - l);
            if(now > ans)
                ans = now;

            if(min(height[l], height[r - 1]) > min(height[l + 1], height[r]))
                --r;
            else if(min(height[l], height[r - 1]) < min(height[l + 1], height[r]))
                ++l;
            else if(height[l + 1] > height[r - 1])
                ++l;
            else
                --r;

        }

        return ans;
    }
    */
    /**
    13. Roman to Integer
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

    Example 1:

    Input: "III"
    Output: 3
    Example 2:

    Input: "IV"
    Output: 4
    Example 3:

    Input: "IX"
    Output: 9
    Example 4:

    Input: "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.
    Example 5:

    Input: "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    */
    int romanToInt(string s)
    {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0, now = m[s.at(0)];
        for (int i = 1; i < s.length(); ++i)
        {
            //            if(s.at(i - 1) == 'I' && (s.at(i) == 'V' || s.at(i) == 'X') ||
            //               s.at(i - 1) == 'X' && (s.at(i) == 'L' || s.at(i) == 'C') ||
            //               s.at(i - 1) == 'C' && (s.at(i) == 'D' || s.at(i) == 'M')) {
            int tmp = m[s.at(i)];
            if (m[s.at(i - 1)] * 5 == tmp || m[s.at(i - 1)] * 10 == tmp)
            {
                ans += tmp - now;
                now = 0;
            }
            else if (s.at(i - 1) == s.at(i))
            {
                now += tmp;
            }
            else
            {
                ans += now;
                now = tmp;
            }
        }
        return ans + now;
    }
    /**
    14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Example 1:

    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    Example 2:

    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.


    Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.
    **/
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string ans = "";

        int max_len = min(strs[0].length(), strs[strs.size() - 1].length());

        for (int i = 0; i < max_len; ++i)
        {
            if (strs[0].at(i) == strs[strs.size() - 1].at(i))
                ans += strs[0].at(i);
            else
                break;
        }
        return ans;
    }
    /**
    15. 3Sum
    Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
    Find all unique triplets in the array which gives the sum of zero.
    Note:
    The solution set must not contain duplicate triplets.

    Example:
    Given array nums = [-1, 0, 1, 2, -1, -4],
    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]

    **/

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, int> _map;

        set<pair<int, int>> _set;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (_map.find(nums[i]) == _map.end())
            {
                _map[nums[i]] = 1;
            }
            else
            {
                _map[nums[i]]++;
            }
        }
        for (unordered_map<int, int>::iterator it = _map.begin(); it != _map.end(); ++it)
        {
            if (it->second > 1 && _map.find(0 - it->first * 2) != _map.end() && it->first != 0 || it->first == 0 && it->second > 2)
            {
                priority_queue<int, vector<int>, greater<int>> q;
                q.push(it->first);
                q.push(it->first);
                q.push(0 - it->first * 2);
                pair<int, int> item;
                item.first = q.top();
                q.pop();
                item.second = q.top();
                _set.insert(item);
            }
            for (unordered_map<int, int>::iterator it_2 = _map.begin(); it_2 != _map.end(); ++it_2)
            {
                int _num3 = 0 - it->first - it_2->first;
                if (it->first != it_2->first && _map.find(_num3) != _map.end() && it->first != _num3 && it_2->first != _num3)
                {
                    priority_queue<int, vector<int>, greater<int>> q;
                    q.push(it->first);
                    q.push(it_2->first);
                    q.push(_num3);
                    pair<int, int> item;
                    item.first = q.top();
                    q.pop();
                    item.second = q.top();
                    _set.insert(item);
                }
            }
        }
        vector<vector<int>> ans;
        for (set<pair<int, int>>::iterator it = _set.begin(); it != _set.end(); ++it)
        {
            vector<int> item;
            item.push_back(it->first);
            item.push_back(it->second);
            item.push_back(0 - it->first - it->second);
            ans.push_back(item);
        }
        return ans;
    }

    /**
    20. Valid Parentheses
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Note that an empty string is also considered valid.

    Example 1:

    Input: "()"
    Output: true
    Example 2:

    Input: "()[]{}"
    Output: true
    Example 3:

    Input: "(]"
    Output: false
    Example 4:

    Input: "([)]"
    Output: false
    Example 5:

    Input: "{[]}"
    Output: true

    **/
    bool isValid(string s)
    {
        stack<char> st;
        for (size_t i = 0; i < s.length(); ++i)
        {
            switch (s.at(i))
            {
            case '(':
            case '{':
            case '[':
                st.push(s.at(i));
                break;
            case ')':
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
                break;
            case '}':
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
                break;
            default:
                break;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
    /**
    21. Merge Two Sorted Lists
    Merge two sorted linked lists and return it as a new list.
    The new list should be made by splicing together the nodes of the first two lists.

    Example:
    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4
    **/
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode *root;
        // l1->val < l2->val? root = l1, l1 = l1->next: root = l2, l2 = l2->next;
        root = l1->val < l2->val ? l1 : l2;
        l1->val < l2->val ? l1 = l1->next : l2 = l2->next;
        ListNode *now = root;
        while (true)
        {
            if (l1 && l2)
            {
                // l1->val < l2->val? now->next = l1, l1 = l1->next: now->next = l2, l2 = l2->next;
                now->next = l1->val < l2->val ? l1 : l2;
                l1->val < l2->val ? l1 = l1->next : l2 = l2->next;
                now = now->next;
            }
            else if (l1)
            {
                now->next = l1;
                break;
            }
            else if (l2)
            {
                now->next = l2;
                break;
            }
            else
            {
                break;
            }
        }
        return root;
    }
    /**
    22. Generate Parentheses
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    For example, given n = 3, a solution set is:

    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]
    **/
    vector<string> generateParenthesis(int n)
    {
        vector<string> vec(1, "()");
        if (n == 1)
            return vec;
        for (int i = 2; i <= n; ++i)
        {
            vector<string> tmp = vec;
            vec.clear();
            for (int j = 0; j < tmp.size(); ++j)
            {
                for (int k = 0; k < tmp[j].length(); ++k)
                {
                    string s = tmp[j];
                    s.replace(k, 0, "()");
                    vec.push_back(s);
                }
                vec.push_back(string("(") + tmp[j] + ")");
            }
            sort(vec.begin(), vec.end());
            vector<string>::iterator it = unique(vec.begin(), vec.end());
            vec.resize(std::distance(vec.begin(), it));
        }
        return vec;
    }
    /*
    ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())()()","()((()))","()(()())","()(())()","()(())()","()()(())","()()()()"]
    ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
    */

    /**
    23. Merge k Sorted Lists
    Hard
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

    Example:
    Input:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    Output: 1->1->2->3->4->4->5->6
    **/

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = NULL;
        for (size_t i = 0; i < lists.size(); ++i)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }

    /**
    26
    Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

    **/
    int removeDuplicates(vector<int> &nums)
    {
        /*
        if(nums.size() < 2)
            return nums.size();
        size_t pos = -1;
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1] && pos == -1)
                pos = i;
            if(nums[i] != nums[i - 1] && pos != -1)
                nums[pos++] = nums[i];
        }
        if(pos == -1)
            return nums.size();
        return pos;
        */

        if (nums.size() == 0)
            return 0;
        size_t j = 1;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[j - 1])
                nums[j++] = nums[i];
        }
        return j;
    }

    /**
    31. Next Permutation
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

    The replacement must be in-place and use only constant extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
    **/
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() < 2)
            return;
        int mpos, pos = -1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                pos = i - 1;
                mpos = i;
                for (int j = mpos + 1; j < nums.size(); ++j)
                {
                    if (nums[j] > nums[pos])
                        mpos++;
                    else
                        break;
                }
                break;
            }
        }
        if (pos != -1)
            swap(nums[pos], nums[mpos]);
        sort(nums.begin() + pos + 1, nums.end());
        return;
    }

    /**
    33. Search in Rotated Sorted Array
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
    You are given a target value to search. If found in the array return its index, otherwise return -1.
    You may assume no duplicate exists in the array.
    Your algorithm's runtime complexity must be in the order of O(log n).
    Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
    **/
    int binarySearch_33(const vector<int> &numbers, int a, int b, int target)
    {
        if (a < 0 || b >= numbers.size())
            return -1;
        if (a <= b)
        {
            int mid = (a + b) / 2;
            if (target == numbers[mid])
                return mid;
            if (target > numbers[mid])
                return binarySearch_33(numbers, mid + 1, b, target);
            else
                return binarySearch_33(numbers, a, mid - 1, target);
        }
        else
            return -1;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int _begin = 0, _end = nums.size() - 1, mid;
        while (_begin <= _end)
        {
            mid = ceil((_begin + _end) / 2.0);
            if (mid == 0 || nums[mid] < nums[mid - 1])
                break;
            if (nums[mid] <= nums[_end])
                _end = mid - 1;
            else
                _begin = mid + 1;
        }
        int x = binarySearch_33(nums, 0, mid - 1, target);
        if (x != -1)
            return x;
        x = binarySearch_33(nums, mid, nums.size() - 1, target);
        return x;
    }

    /*
    int search(vector<int>& nums, int target) {

        int a = 0, b = nums.size() - 1;
        while(a <= b) {
            size_t mid = (a + b) / 2;
            if(nums[mid] == target) return mid;
            if(nums[a] == target) return a;
            if(nums[b] == target) return b;
            if(a == b - 1 || a == b)   return -1;

            if(nums[a] < nums[b]) {
                if(target < nums[a] || target > nums[b]) return -1;
                if(target < nums[mid])  b = mid;
                else a = mid;
            } else {
                if(nums[a] < target && target < nums[mid] || (target < nums[mid] || target > nums[b] ) && nums[mid] < nums[b])   b = mid;
                else if(target > nums[mid] || target < nums[b]) a = mid;
                else return -1;
            }
        }

        return -1;

    }
    */

    /**
    41. First Missing Positive
    Given an unsorted integer array, find the smallest missing positive integer.

    Example 1:

    Input: [1,2,0]
    Output: 3
    Example 2:

    Input: [3,4,-1,1]
    Output: 2
    Example 3:

    Input: [7,8,9,11,12]
    Output: 1
    Note:

    Your algorithm should run in O(n) time and uses constant extra space.

    */
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
            else
                ++i;
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }

    /**
    42. Trapping Rain Water
    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it is able to trap after raining.

    The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
    6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

    Example:

    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    **/
    int trap(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        std::priority_queue<pair<int, int>> q;

        for (int i = 0; i < height.size(); ++i)
        {
            q.push(make_pair(height[i], i));
        }

        int ans = 0, l = q.top().second, r = q.top().second;

        while (!q.empty())
        {
            auto x = q.top();
            q.pop();
            auto y = q.top();
            if (x.second > y.second)
            {
                swap(x, y);
            }

            int a[4] = {x.second, r, l, y.second};
            sort(a, a + 4);
            for (auto i = 0; i < 3; ++i)
            {
                if (a[i] >= l && a[i + 1] <= r)
                    continue;
                for (auto j = a[i] + 1; j < a[i + 1]; ++j)
                {
                    ans += min(x.first, y.first) - height[j];
                }
            }
            // cout << x.first << " " << x.second << " " << y.first << " " << y.second << " " << ans << endl;
            l = min(l, x.second);
            r = max(r, y.second);
        }
        return ans;
    }

    int trap_v2(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        vector<int> l(height.size());
        vector<int> r(height.size());

        l[0] = height[0];
        for (int i = 1; i < height.size(); ++i)
        {
            l[i] = max(l[i - 1], height[i]);
        }
        r[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i)
        {
            r[i] = max(r[i + 1], height[i]);
        }

        int ans = 0;
        for (auto i = 0; i < height.size(); ++i)
        {
            ans += min(l[i], r[i]) - height[i];
        }
        return ans;
    }

    /**
    46. Permutations
    Given a collection of distinct integers, return all possible permutations.

    Example:

    Input: [1,2,3]
    Output:
    [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
    ]

    **/
    void full_permutation(vector<int> &nums, int l, vector<vector<int>> &ans, vector<bool> &used, vector<int> &rcd)
    {
        int n = nums.size();
        if (l == n)
        {
            ans.push_back(rcd);

            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                rcd[l] = nums[i];
                full_permutation(nums, l + 1, ans, used, rcd);
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), 0);
        vector<int> rcd(nums.size(), 0);
        vector<vector<int>> ans;
        full_permutation(nums, 0, ans, used, rcd);
        return ans;
    }

    void full_permutation(vector<int> &nums, int n, vector<vector<int>> &ans)
    {
        cout << n << " " << nums.size() << endl;
        if (n == nums.size())
        {
            ans.push_back(nums);
            for (int i = 0; i < nums.size(); ++i)
                cout << nums[i] << " ";
            cout << endl;
            return;
        }
        for (int i = n; i < nums.size(); ++i)
        {
            swap(nums[i], nums[n]);
            full_permutation(nums, n + 1, ans);
            swap(nums[n], nums[i]);
        }
    }
    vector<vector<int>> permute_1(vector<int> &nums)
    {
        vector<vector<int>> ans;
        full_permutation(nums, 0, ans);
        return ans;
    }

    /**
    47. Permutations II
    Given a collection of numbers that might contain duplicates, return all possible unique permutations.

    Example:

    Input: [1,1,2]
    Output:
    [
      [1,1,2],
      [1,2,1],
      [2,1,1]
    ]
    */
    void full_permutation_unique(vector<int> &nums, int n, vector<vector<int>> &ans)
    {
        if (n == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = n; i < nums.size(); ++i)
        {
            if (n != i && nums[i] == nums[n])
                continue;
            swap(nums[i], nums[n]);
            full_permutation_unique(nums, n + 1, ans);
            swap(nums[n], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        full_permutation_unique(nums, 0, ans);
        return ans;
    }

    /**
    49. Group Anagrams
    Given an array of strings, group anagrams together.

    Example:

    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
      ["ate","eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
    Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

    */
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (umap.find(s) == umap.end())
                umap[s] = vector<string>();
            umap[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (unordered_map<string, vector<string>>::iterator it = umap.begin(); it != umap.end(); ++it)
        {
            ans.push_back(it->second);
        }
        return ans;
    }

    /**
    53. Maximum Subarray
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    Example:

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
    Follow up:

    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

    **/
    int maxSubArray(vector<int> &nums)
    {
        vector<int> sums;
        sums.push_back(0);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int total = sums[i] + nums[i];
            sums.push_back(total);
        }
        int _min = 0, _max = sums[1];
        for (size_t i = 1; i < sums.size(); ++i)
        {
            _max = max(_max, sums[i] - _min);
            _min = min(_min, sums[i]);
        }
        return _max;
    }
    /**
    54. Spiral Matrix
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    Example 1:

    Input:
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    Output: [1,2,3,6,9,8,7,4,5]
    Example 2:

    Input:
    [
      [1, 2, 3, 4],
      [5, 6, 7, 8],
      [9,10,11,12]
    ]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    */
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> used(n, vector<bool>(m, false));

        int i = 0, j = 0;
        bool flag = true;
        used[i][j] = true;
        ans.push_back(matrix[i][j]);
        while (flag)
        {
            flag = false;
            while (j + 1 < m && !used[i][j + 1])
            {
                used[i][++j] = true;
                ans.push_back(matrix[i][j]);
                flag = true;
            }
            while (i + 1 < n && !used[i + 1][j])
            {
                used[++i][j] = true;
                ans.push_back(matrix[i][j]);
                flag = true;
            }
            while (j - 1 >= 0 && !used[i][j - 1])
            {
                used[i][--j] = true;
                ans.push_back(matrix[i][j]);
                flag = true;
            }
            while (i - 1 >= 0 && !used[i - 1][j])
            {
                used[--i][j] = true;
                ans.push_back(matrix[i][j]);
                flag = true;
            }
        }

        return ans;
    }
    /***
    55. Jump Game
    You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.

    Example 1:

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

    Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105
    */
    bool canJump(vector<int> &nums)
    {
        int max_pos = 0;
        for (auto i = 0; i < nums.size() - 1; ++i)
        {
            max_pos = max(max_pos, i + nums[i]);
            if (max_pos == i)
                return false;
        }
        return true;
    }

    /**
    56. Merge Intervals
    Given a collection of intervals, merge all overlapping intervals.

    Example 1:

    Input: [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
    Example 2:

    Input: [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    **/
    static bool CmpInterval(const Interval &a, const Interval &b)
    {
        if (a.start < b.start)
            return true;
        if (a.start == b.start)
            return a.end < b.end;
        return false;
    }
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), CmpInterval);
        vector<Interval> ans;
        if (!intervals.empty())
            ans.push_back(intervals[0]);
        int cur = 0;

        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start > ans[cur].end)
            {
                ans.push_back(intervals[i]);
                ++cur;
            }
            else
            {
                ans[cur].end = max(ans[cur].end, intervals[i].end);
            }
        }
        return ans;
    }

    /**
    67. Add Binary
    Given two binary strings, return their sum (also a binary string).

    The input strings are both non-empty and contains only characters 1 or 0.

    Example 1:

    Input: a = "11", b = "1"
    Output: "100"
    Example 2:

    Input: a = "1010", b = "1011"
    Output: "10101"
    */
    string addBinary(string a, string b)
    {
        int al = a.length() - 1, bl = b.length() - 1;
        string ans = "";
        int top = 0;
        while (al >= 0 && bl >= 0)
        {
            int tmp = top + a.at(al--) - '0' + b.at(bl--) - '0';
            top = tmp / 2;
            tmp = tmp % 2;
            ans = static_cast<char>(tmp + '0') + ans;
        }
        while (al >= 0)
        {
            int tmp = top + a.at(al--) - '0';
            top = tmp / 2;
            tmp = tmp % 2;
            ans = static_cast<char>(tmp + '0') + ans;
        }
        while (bl >= 0)
        {
            int tmp = top + b.at(bl--) - '0';
            top = tmp / 2;
            tmp = tmp % 2;
            ans = static_cast<char>(tmp + '0') + ans;
        }
        if (top == 1)
            ans = "1" + ans;
        return ans;
    }

    /*
    70. Climbing Stairs
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Example 1:

    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
    Example 2:

    Input: n = 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

    Constraints:

    1 <= n <= 45
    */
    int climbStairs(int n)
    {
        // if (n == 1) return 1;
        // if (n == 2) return 2;
        // return climbStairs(n - 1) + climbStairs(n - 2);
        vector<int> res(50);
        res[1] = 1;
        res[2] = 2;
        for (auto i = 3; i <= n; ++i)
            res[i] = res[i - 1] + res[i - 2];
        return res[n];
    }
    /**
    74. Search a 2D Matrix
    Write an efficient algorithm that searches for a value in an m x n matrix.
    This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    Example 1:

    Input:
    matrix = [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    target = 3
    Output: true

    **/
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if (n == 0)
            return false;

        // int i = 1, j = m * n;
        int i = 0, j = m * n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            // int v = matrix[(mid + n - 1) / n - 1 ][(mid + n - 1)% n];
            int v = matrix[mid / n][mid % n];
            // cout << mid << endl;
            // cout << ((mid + n - 1) / n - 1) << " " << (mid + n - 1) % n << endl;
            if (v == target)
                return true;
            if (v > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return false;
    }

    /**
    76. Minimum Window Substring
    Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

    Example:

    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"
    Note:

    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
    **/
    string minWindow(string s, string t)
    {
        vector<vector<int>> vec(s.length(), vector<int>(t.length(), 0));
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; i < t.length(); ++j)
            {
            }
        }

        return "";
    }

    /**
    79. Word Search
    Given a 2D board and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Example:

    board =
    [
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]

    Given word = "ABCCED", return true.
    Given word = "SEE", return true.
    Given word = "ABCB", return false.

    */

    bool DFS_79(vector<vector<char>> &board, string &word, int pos, int i, int j)
    {
        if (pos < word.length() && board[i][j] != word.at(pos))
            return false;
        if (pos == word.size() - 1)
            return true;
        board[i][j] = '$';
        int n = board.size(), m = board[0].size();
        if (i + 1 < n && board[i + 1][j] != '$' && DFS_79(board, word, pos + 1, i + 1, j))
            return true;
        if (i - 1 >= 0 && board[i - 1][j] != '$' && DFS_79(board, word, pos + 1, i - 1, j))
            return true;
        if (j + 1 < m && board[i][j + 1] != '$' && DFS_79(board, word, pos + 1, i, j + 1))
            return true;
        if (j - 1 >= 0 && board[i][j - 1] != '$' && DFS_79(board, word, pos + 1, i, j - 1))
            return true;
        board[i][j] = word.at(pos);

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (DFS_79(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    /**
    80.
    Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
    **/
    int removeDuplicates_2(vector<int> &nums)
    {
        /*
        if(nums.size() == 0)    return 0;
        size_t j = 1, num = 1;
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i - 1]) {
                nums[j++] = nums[i];
                num = 1;
            } else {
                num++;
                if(num <= 2)
                    nums[j++] = nums[i];
            }
        }
        return j;
        */
        if (nums.size() <= 2)
            return nums.size();
        size_t j = 2;
        for (size_t i = 2; i < nums.size(); ++i)
        {
            if (nums[i] != nums[j - 2])
                nums[j++] = nums[i];
        }
        return j;
    }
    /**
    88. Merge Sorted Array
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
    Example:

    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    Output: [1,2,2,3,5,6]
    **/
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; --k)
        {
            if (j < 0 || i >= 0 && nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
        }
        return;
    }

    /**
    98. Validate Binary Search Tree
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    Example 1:

    Input:
        2
       / \
      1   3
    Output: true
    Example 2:

        5
       / \
      1   4
         / \
        3   6
    Output: false
    Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
                 is 5 but its right child's value is 4.

    */
    bool dfs_inorder_98(TreeNode *root, long &v)
    {
        if (root)
        {
            if (!dfs_inorder_98(root->left, v))
                return false;
            if (root->val <= v)
                return false;
            v = root->val;
            //            cout << root << " " << v << endl;
            if (!dfs_inorder_98(root->right, v))
                return false;
        }
        return true;
    }

    bool isValidBST(TreeNode *root)
    {
        long v = LONG_MIN;
        return dfs_inorder_98(root, v);
    }
    /**
    101. Symmetric Tree
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

        1
       / \
      2   2
     / \ / \
    3  4 4  3


    But the following [1,2,2,null,3,null,3] is not:

        1
       / \
      2   2
       \   \
       3    3


    Note:
    Bonus points if you could solve it both recursively and iteratively.
    */
    bool isMirror_101(TreeNode *r1, TreeNode *r2)
    {
        if (NULL == r1 && NULL == r2)
            return true;
        if (NULL == r1 || NULL == r2)
            return false;
        if (r1->val == r2->val &&
            isMirror_101(r1->left, r2->right) &&
            isMirror_101(r1->right, r2->left))
            return true;
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return isMirror_101(root, root);
    }

    /**
    104. Maximum Depth of Binary Tree
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 3
    Example 2:

    Input: root = [1,null,2]
    Output: 2

    */

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    /**
    113. Path Sum II
    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

    Note: A leaf is a node with no children.

    Example:

    Given the below binary tree and sum = 22,

          5
         / \
        4   8
       /   / \
      11  13  4
     /  \    / \
    7    2  5   1
    Return:

    [
       [5,4,11,2],
       [5,8,4,5]
    ]

    */
    void dfs_113(TreeNode *root, int sum, int tmp_sum, vector<int> &a, vector<vector<int>> &ans)
    {
        if (NULL == root)
            return;
        tmp_sum += root->val;
        a.push_back(root->val);
        if (NULL == root->left && NULL == root->right && tmp_sum == sum)
            ans.push_back(a);
        dfs_113(root->left, sum, tmp_sum, a, ans);
        dfs_113(root->right, sum, tmp_sum, a, ans);
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> a;
        dfs_113(root, sum, 0, a, ans);
        return ans;
    }

    /**
    121. Best Time to Buy and Sell Stock
    Say you have an array for which the ith element is the price of a given stock on day i.
    If you were only permitted to complete at most one transaction
    (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
    Note that you cannot sell a stock before you buy one.

    Example 1:

    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                 Not 7-1 = 6, as selling price needs to be larger than buying price.
    Example 2:

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.

    **/
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int ans = 0, _min = prices[0];
        for (size_t i = 1; i < prices.size(); ++i)
        {
            ans = max(ans, prices[i] - _min);
            _min = min(_min, prices[i]);
        }
        return ans;
    }

    /**
    122. Best Time to Buy and Sell Stock II
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

    Find and return the maximum profit you can achieve.



    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.
    Example 2:

    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Total profit is 4.
    Example 3:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.


    Constraints:

    1 <= prices.length <= 3 * 104
    0 <= prices[i] <= 104
    */
    int maxProfit2(vector<int> &prices)
    {
        int ans = 0;
        for (auto i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }

    /**
    124. Binary Tree Maximum Path Sum
    Given a non-empty binary tree, find the maximum path sum.

    For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

    Example 1:

    Input: [1,2,3]

           1
          / \
         2   3

    Output: 6
    Example 2:

    Input: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7

    Output: 42

    */
    int search_124(TreeNode *root, int &_max)
    {
        if (NULL == root)
            return 0;
        int l = max(search_124(root->left, _max), 0);
        int r = max(search_124(root->right, _max), 0);
        _max = max(_max, l + r + root->val);
        return max(l, r) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        int _max = INT_MIN;
        search_124(root, _max);
        return _max;
    }
    /**
    125. Valid Palindrome
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Note: For the purpose of this problem, we define empty string as valid palindrome.

    Example 1:

    Input: "A man, a plan, a canal: Panama"
    Output: true
    Example 2:

    Input: "race a car"
    Output: false

    */
    bool isPalindrome_char(char c)
    {
        if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
            return true;
        return false;
    }
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = s.length() - 1;
        if (i >= j)
            return true;
        while (true)
        {
            // cout << i << " " << j << endl;
            while (i < s.length() && !isPalindrome_char(s.at(i)))
                ++i;
            while (j >= 0 && !isPalindrome_char(s.at(j)))
                --j;
            if (i >= j || j < 0 || i == s.length())
                break;
            if (s.at(i++) != s.at(j--))
                return false;
        }
        return true;
    }

    /**
    127. Word Ladder
    Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
    Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
    Example 1:

    Input:
    beginWord = "hit",
    endWord = "cog",
    wordList = ["hot","dot","dog","lot","log","cog"]

    Output: 5

    Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
    return its length 5.
    Example 2:

    Input:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]

    Output: 0

    Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
    */

    /// dfs TLE
    void dfs_127(vector<vector<int>> &m, int _begin, int _end, int step, vector<int> &ans, vector<bool> &used)
    {
        if (_begin == _end)
        {
            ans.push_back(step);
            return;
        }
        used[_begin] = true;
        int n = m.size();
        for (int i = 0; i < m[_begin].size(); ++i)
        {
            if (!used[m[_begin][i]])
                dfs_127(m, m[_begin][i], _end, step + 1, ans, used);
        }
        used[_begin] = false;
    }
    bool compare_127(const string &a, const string &b)
    {
        int total = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a.at(i) != b.at(i))
                ++total;
            if (total > 1)
                return false;
        }
        if (total == 1)
            return true;
        return false;
    }
    /// bfs
    void bfs_127(vector<vector<int>> &m, int _begin, int _end, vector<int> &ans)
    {
        queue<int> q;
        queue<int> qs;
        vector<bool> used(m.size(), false);
        q.push(_begin);
        qs.push(2);
        used[_begin] = true;
        int step = 2;

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            int step = qs.front();
            qs.pop();
            if (now == _end)
            {
                ans.push_back(step);
                return;
            }
            for (int i = 0; i < m[now].size(); ++i)
            {
                if (!used[m[now][i]])
                {
                    q.push(m[now][i]);
                    used[m[now][i]] = true;
                    qs.push(step + 1);
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        int n = wordList.size();
        if (n == 0)
            return 0;
        unordered_map<string, int> wordMap;
        vector<vector<int>> m(n, vector<int>());
        for (int i = 0; i < n; ++i)
        {
            wordMap[wordList[i]] = i;
            for (int j = 0; j < n; ++j)
            {
                if (i != j && compare_127(wordList[i], wordList[j]))
                {
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }
        if (wordMap.find(endWord) == wordMap.end())
            return 0;
        int _begin = -1;
        vector<int> ans;

        for (int i = 0; i < wordList.size(); ++i)
        {
            if (compare_127(beginWord, wordList[i]))
                bfs_127(m, i, wordMap[endWord], ans);
            //                dfs_127(m, i, wordMap[endWord], 2, ans, used);
        }
        if (ans.empty())
            return 0;
        return min_element(ans.begin(), ans.end())[0];
    }

    /**
    138. Copy List with Random Pointer
    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
    Return a deep copy of the list.
    Example 1:

    Input:
    {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

    Explanation:
    Node 1's value is 1, both of its next and random pointer points to Node 2.
    Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

    Note:
    You must return the copy of the given head as a reference to the cloned list.
    **/
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        unordered_map<Node *, Node *> umap;
        Node *root = new Node(head->val, NULL, NULL);
        umap[head] = root;
        umap[NULL] = NULL;
        Node *cur_new = root, *cur_old = head->next;

        while (cur_old)
        {
            Node *tmp = new Node(cur_old->val, NULL, NULL);
            cur_new->next = tmp;
            cur_new = cur_new->next;
            umap[cur_old] = cur_new;
            cur_old = cur_old->next;
        }
        cur_new = root, cur_old = head;
        while (cur_old)
        {
            cur_new->random = umap[cur_old->random];
            cur_new = cur_new->next;
            cur_old = cur_old->next;
        }
        return root;
    }
    /**
    141. Linked List Cycle
    Given a linked list, determine if it has a cycle in it.

    To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

    Example 1:

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where tail connects to the second node.

    Example 2:

    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where tail connects to the first node.

    Example 3:

    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.

    Follow up:

    Can you solve it using O(1) (i.e. constant) memory?

    */
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        ListNode *p1 = head, *p2 = head->next;
        while (p1 != p2)
        {
            if (!p1->next || !p2->next || !p2->next->next)
                return false;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return true;
    }

    /**
    153. Find Minimum in Rotated Sorted Array

    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
    Find the minimum element.
    You may assume no duplicate exists in the array.

    **/
    int findMin(vector<int> &nums)
    {
        size_t a = 0, b = nums.size() - 1;
        while (a < b)
        {
            if (nums[a] < nums[b])
                return nums[a];
            if (a == b - 1 && nums[a] > nums[b])
                return nums[b];
            size_t mid = (a + b) / 2;
            if (nums[mid] > nums[a])
                a = mid;
            else if (nums[mid] < nums[b])
                b = mid;
        }
        return nums[a];
    }

    /**
    167. Two Sum II - Input array is sorted

    Given an array of integers that is already sorted in ascending order,
    find two numbers such that they add up to a specific target number.
    The function twoSum should return indices of the two numbers such that they add up to the target,
    where index1 must be less than index2.

    Note:
    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.
    Example:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

    **/
    int bs_167(vector<int> &a, int val, int i, int j)
    {
        if (i > j)
            return -1;
        int mid = (i + j) / 2;
        if (a[mid] == val)
            return mid;
        if (a[mid] > val)
            return bs_167(a, val, i, mid - 1);
        else
            return bs_167(a, val, mid + 1, j);
    }
    vector<int> twoSum_2(vector<int> &numbers, int target)
    {
        vector<int> ans;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int x = bs_167(numbers, target - numbers[i], i + 1, numbers.size() - 1);
            if (x > 0)
            {
                ans.push_back(i + 1);
                ans.push_back(x + 1);
                return ans;
            }
        }
        return ans;
    }
    /**
    169. Majority Element
    Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element always exist in the array.

    Example 1:

    Input: [3,2,3]
    Output: 3
    Example 2:

    Input: [2,2,1,1,1,2,2]
    Output: 2
    */
    int majorityElement(vector<int> &nums)
    {
        int k = 0, num = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[k] == nums[i])
                ++num;
            else if (num == 1)
                k = i;
            else
                --num;
        }
        return nums[k];
    }

    /**
    189. Rotate Array
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
    Example 2:

    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation:
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]


    Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

    */
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
    /***
    200. Number of Islands
    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    You may assume all four edges of the grid are all surrounded by water.
    Example 1:

    Input:
    11110
    11010
    11000
    00000

    Output: 1
    Example 2:

    Input:
    11000
    11000
    00100
    00011

    Output: 3
    ***/
    void dfs_numIslands(vector<vector<char>> &grid, std::size_t i, std::size_t j, char val)
    {
        if (grid[i][j] != '1')
            return;
        if (grid[i][j] == '1')
            grid[i][j] = val;
        if (i > 0 && grid[i - 1][j] == '1')
            dfs_numIslands(grid, i - 1, j, val);
        if (j > 0 && grid[i][j - 1] == '1')
            dfs_numIslands(grid, i, j - 1, val);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1')
            dfs_numIslands(grid, i + 1, j, val);
        if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
            dfs_numIslands(grid, i, j + 1, val);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        char x = '2'; /// for debug
        for (std::size_t i = 0; i < grid.size(); ++i)
        {
            for (std::size_t j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    x++;
                    dfs_numIslands(grid, i, j, x);
                }
            }
        }
        return ans;
    }
    /**
    202. Happy Number
    Write an algorithm to determine if a number is "happy".
    A happy number is a number defined by the following process: Starting with any positive integer,
    replace the number by the sum of the squares of its digits,
    and repeat the process until the number equals 1 (where it will stay),
    or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy numbers.
    Example:

    Input: 19
    Output: true
    Explanation:
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

    **/
    bool isHappy(int n)
    {
        set<int> s;

        while (n != 1)
        {
            s.insert(n);
            int x = 0;
            while (n != 0)
            {
                int m = n % 10;
                x += m * m;
                n /= 10;
            }
            n = x;
            if (s.find(n) != s.end())
                return false;
        }
        return true;
    }

    /**
    206. Reverse Linked List
    Reverse a singly linked list.

    Example:

    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL
    Follow up:

    A linked list can be reversed either iteratively or recursively. Could you implement both?
    **/
    ListNode *reverseList(ListNode *head)
    {
        ListNode *last = NULL, *tmp = head;
        while (head)
        {
            tmp = head;
            head = head->next;
            tmp->next = last;
            last = tmp;
        }
        return last;
    }
    /**
    212. Word Search II
    Given a 2D board and a list of words from the dictionary, find all words in the board.

    Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



    Example:

    Input:
    board = [
      ['o','a','a','n'],
      ['e','t','a','e'],
      ['i','h','k','r'],
      ['i','f','l','v']
    ]
    words = ["oath","pea","eat","rain"]

    Output: ["eat","oath"]


    Note:

    All inputs are consist of lowercase letters a-z.
    The values of words are distinct.

    */
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
    }

    /**
    215. Kth Largest Element in an Array
    Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Example 1:

    Input: [3,2,1,5,6,4] and k = 2
    Output: 5
    Example 2:

    Input: [3,2,3,1,2,4,5,5,6] and k = 4
    Output: 4
    Note:
    You may assume k is always valid, 1 ≤ k ≤ array's length.

    */
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (pq.size() < k)
                pq.push(nums[i]);
            else if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
    /**
    226. Invert Binary Tree
    Invert a binary tree.

    Example:

    Input:

         4
       /   \
      2     7
     / \   / \
    1   3 6   9
    Output:

         4
       /   \
      7     2
     / \   / \
    9   6 3   1
    Trivia:
    This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew),
    but you can’t invert a binary tree on a whiteboard so f*** off.
    **/
    void mirror_226(TreeNode *root)
    {
        if (root)
        {
            swap(root->left, root->right);
            mirror_226(root->left);
            mirror_226(root->right);
        }
    }
    TreeNode *invertTree(TreeNode *root)
    {
        mirror_226(root);
        return root;
    }

    /**
    233. Number of Digit One
    Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

    Example:

    Input: 13
    Output: 6
    Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
    */
    int countDigitOne(int n)
    {
        if (n <= 0)
            return 0;
        else if (n < 10)
            return 1;

        int tmp = n, a = 0, b = 0;
        while (tmp)
        {
            b = tmp;
            tmp /= 10;
            ++a;
        }
        long long ten_pow = pow(10, a - 1);
        int remain = n - b * ten_pow;
        int ans = 0;
        if (b == 1)
            ans += remain + 1;
        else
            ans += ten_pow;
        ans += b * (a - 1) * ten_pow / 10;
        // cout << a << " " << b << " " << remain << " " << ten_pow << endl;
        // cout << "ans：" << ans << endl;
        return ans + countDigitOne(remain);
    }
    //
    bool _236 = true;
    TreeNode *wlowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> vp, vq;
        DFS_236(root, p, vp);
        DFS_236(root, q, vq);
        auto len = min(vp.size(), vq.size());
        cout << len << endl;
        for (auto i = 0; i < len; i++)
        {
            if (i == len - 1 || vp[i + 1] != vq[i + 1])
                return vp[i];
        }
        return root;
    }
    bool DFS_236(TreeNode *root, TreeNode *p, vector<TreeNode *> &v)
    {
        if (root == NULL)
            return false;
        v.push_back(root);
        if (root == p)
            return true;
        if (DFS_236(root->left, p, v) || DFS_236(root->right, p, v))
            return true;
        v.pop_back();
        return false;
    }
    /**
    238. Product of Array Except Self
    Given an array nums of n integers where n > 1,
    return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

    Example:

    Input:  [1,2,3,4]
    Output: [24,12,8,6]
    Note: Please solve it without division and in O(n).

    Follow up:
    Could you solve it with constant space complexity?
    (The output array does not count as extra space for the purpose of space complexity analysis.)
    **/
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int all = 1, zero_num = 0;
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
                all *= nums[i];
            else
                ++zero_num;
        }
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (zero_num == 1)
                ans.push_back(nums[i] == 0 ? all : 0);
            else if (zero_num > 1)
                ans.push_back(0);
            else
                ans.push_back(all / nums[i]);
        }
        return ans;
    }

    /**
    252. Meeting Rooms
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
    determine if a person could attend all meetings.

    Example 1:

    Input: [[0,30],[5,10],[15,20]]
    Output: false
    Example 2:

    Input: [[7,10],[2,4]]
    Output: true
    **/
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), CmpInterval);
        vector<Interval> ans;
        if (!intervals.empty())
            ans.push_back(intervals[0]);
        int cur = 0;

        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start > ans[cur].end)
            {
                ans.push_back(intervals[i]);
                ++cur;
            }
            else
            {
                if (intervals[i].start < ans[cur].end)
                    return false;
                ans[cur].end = max(ans[cur].end, intervals[i].end);
            }
        }
        return true;
    }

    /**
    253. Meeting Rooms II
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
    find the minimum number of conference rooms required.

    Example 1:

    Input: [[0, 30],[5, 10],[15, 20]]
    Output: 2
    Example 2:

    Input: [[7,10],[2,4]]
    Output: 1
    **/

    int minMeetingRooms(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), CmpInterval);
        int res = 0;
        vector<Interval> tmp = intervals;
        while (!tmp.empty())
        {
            ++res;
            Interval last;
            vector<Interval> tmp_1;
            if (!tmp.empty())
                last = tmp[0];
            for (size_t i = 1; i < tmp.size(); ++i)
            {
                if (tmp[i].start >= last.end)
                {
                    last = tmp[i];
                }
                else
                {
                    tmp_1.push_back(tmp[i]);
                }
            }
            tmp = tmp_1;
        }
        return res;
    }
    /**
    263. Ugly Number
    Write a program to check whether a given number is an ugly number.

    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

    Example 1:

    Input: 6
    Output: true
    Explanation: 6 = 2 × 3
    Example 2:

    Input: 8
    Output: true
    Explanation: 8 = 2 × 2 × 2
    Example 3:

    Input: 14
    Output: false
    Explanation: 14 is not ugly since it includes another prime factor 7.
    */
    bool isUgly(int num)
    {
        if (num == 0)
            return false;
        while (num % 5 == 0)
            num /= 5;
        while (num % 3 == 0)
            num /= 3;
        while (num % 2 == 0)
            num /= 2;
        if (num == 1)
            return true;
        return false;
    }

    /**
    264. Ugly Number II

    Write a program to find the n-th ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

    Example:
    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
    Note:

        1 is typically treated as an ugly number.
        n does not exceed 1690.
    **/
    bool _264 = true;
    int nthUglyNumber(int n)
    {
        vector<int> num;
        num.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;
        int a[3] = {2, 3, 5};
        int b[3] = {0, 0, 0};
        for (int i = 1; i < n; ++i)
        {
            int _min = 0;
            for (int j = 0; j < 3; ++j)
                while (a[j] * num[b[j]] <= num.back())
                    ++b[j];
            for (int j = 1; j < 3; ++j)
            {
                if (a[j] * num[b[j]] < a[_min] * num[b[_min]])
                {
                    _min = j;
                    b[_min];
                }
            }
            num.push_back(a[_min] * num[b[_min]]);

            cout << num.back() << endl;
        }
        return num[n - 1];
    }

    /**
    268
    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

    For example,
    Given nums = [0, 1, 3] return 2.

    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
    **/
    int missingNumber(vector<int> &nums)
    {
        bool is_in[nums.size() + 1] = {};
        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            is_in[nums[i]] = true;
        }
        for (std::size_t i = 0; i < nums.size() + 1; ++i)
        {
            if (!is_in[i])
                return i;
        }
    }

    /**
    269. Alien Dictionary
    There is a new alien language which uses the latin alphabet. However,
    the order among letters are unknown to you. You receive a list of non-empty words from the dictionary,
    where words are sorted lexicographically by the rules of this new language.
    Derive the order of letters in this language.

    Example 1:

    Input:
    [
      "wrt",
      "wrf",
      "er",
      "ett",
      "rftt"
    ]

    Output: "wertf"
    Example 2:

    Input:
    [
      "z",
      "x"
    ]

    Output: "zx"
    Example 3:

    Input:
    [
      "z",
      "x",
      "z"
    ]

    Output: ""

    Explanation: The order is invalid, so return "".
    Note:

    You may assume all letters are in lowercase.
    You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
    If the order is invalid, return an empty string.
    There may be multiple valid order of letters, return any one of them is fine.

    **/
    string alienOrder(vector<string> &words)
    {
        //        int pos = 0, len_max = 1;
        //        set<pair<char, char>> _set;
        //
        //
        //
        //        for(int j = 0; j < len_max; ++j) {
        //            for(int i = 0; i < words.size(); ++i) {
        //                if(j == 0)
        //                    len_max = max(len_max, static_cast<int>(words[i].length()));
        //                if(j < words[i].length()) {
        //                    char b = words[i].at(j);
        //                    if(_set.find(make_pair(b, b)) == _set.end()) {
        ////                        _set[b] = pos++;
        //                        _set.insert(make_pair(b, b));
        //                    }else if(i != 0
        //                       && j < words[i - 1].length()
        //                       && (j == 0 || words[i].at(j - 1) == words[i - 1].at(j - 1))){
        //                        if(_set[b] < _set[words[i - 1].at(j)])
        //                        if(_set.find(make_pair(b, a)) != _set.end()) {
        //                            return "";
        //                        } else {
        //                            _set.insert(make_pair(a, b));
        //                        }
        //                    }
        //                }
        //
        //            }
        //        }
        //
        //
        //
        //
        //        vector<char> vec(umap.size(), '\0');
        //        for(unordered_map<char, int>::iterator it = umap.begin(); it != umap.end(); it++) {
        //            vec[it->second] = it->first;
        //        }
        //        return string(vec.begin(), vec.end());
    }

    /**
    273. Integer to English Words
    Convert a non-negative integer to its english words representation.
    Given input is guaranteed to be less than 231 - 1.

    Example 1:
    Input: 123
    Output: "One Hundred Twenty Three"
    Example 2:

    Input: 12345
    Output: "Twelve Thousand Three Hundred Forty Five"

    Example 3:
    Input: 1234567
    Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

    Example 4:
    Input: 1234567891
    Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
    **/
    string numberToWords(int num)
    {
        return "";
    }

    /**
    283. Move Zeroes
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Example:

    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
    **/
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, j = 0; i < nums.size();)
        {
            while (j < nums.size() && nums[j] == 0)
            {
                ++j;
            }
            if (j == nums.size())
                return;
            else
                swap(nums[i++], nums[j++]);
        }
    }

    /**
    289. Game of Life
    According to the Wikipedia's article: "The Game of Life,
    also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

    Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
    Each cell interacts with its eight neighbors (horizontal, vertical,
                                                  diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    Write a function to compute the next state (after one update) of the board given its current state.
    The next state is created by applying the above rules simultaneously to every cell in the current state,
    where births and deaths occur simultaneously.

    Example:

    Input:
    [
      [0,1,0],
      [0,0,1],
      [1,1,1],
      [0,0,0]
    ]
    Output:
    [
      [0,0,0],
      [1,0,1],
      [0,1,1],
      [0,1,0]
    ]
    Follow up:

    Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
    **/
    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            int ie = board.size();
            for (int j = 0; j < board[i].size(); ++j)
            {
                int sum = 0, je = board[i].size();
                if (i - 1 >= 0)
                    sum += board[i - 1][j] % 2;
                if (i - 1 >= 0 && j - 1 >= 0)
                    sum += board[i - 1][j - 1] % 2;
                if (i - 1 >= 0 && j + 1 < je)
                    sum += board[i - 1][j + 1] % 2;
                if (j - 1 >= 0)
                    sum += board[i][j - 1] % 2;
                if (i + 1 < ie)
                    sum += board[i + 1][j] % 2;
                if (i + 1 < ie && j - 1 >= 0)
                    sum += board[i + 1][j - 1] % 2;
                if (i + 1 < ie && j + 1 < je)
                    sum += board[i + 1][j + 1] % 2;
                if (j + 1 < je)
                    sum += board[i][j + 1] % 2;

                if (board[i][j] % 2 == 1 && sum >= 2 && sum <= 3 ||
                    board[i][j] % 2 == 0 && sum == 3)
                {
                    board[i][j] += 2;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                board[i][j] = board[i][j] >> 1;
            }
        }
        return;
    }

    /**
    297. Serialize and Deserialize Binary Tree
    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
    or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree.
    There is no restriction on how your serialization/deserialization algorithm should work.
    You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

    Example:

    You may serialize the following tree:

        1
       / \
      2   3
         / \
        4   5

    as "[1,2,3,null,null,4,5]"
    Clarification: The above format is the same as how LeetCode serializes a binary tree.
    You do not necessarily need to follow this format,
    so please be creative and come up with different approaches yourself.

    Note: Do not use class member/global/static variables to store states.
    Your serialize and deserialize algorithms should be stateless.
    **/

    // Encodes a tree to a single string.
    vector<int> serialize(TreeNode *root)
    {
        vector<int> c;
        if (root == NULL)
            return c;
        c.resize(1024, INT_MIN);
        queue<TreeNode *> q;
        q.push(root);
        int pos = 0;
        c[pos++] = root->val;
        while (!q.empty())
        {
            TreeNode *now = q.front();
            q.pop();

            while (pos + 2 >= c.size())
                c.resize(c.size() + 1024, INT_MIN);
            if (now->left)
            {
                q.push(now->left);
                c[pos++] = now->left->val;
            }
            else
            {
                c[pos++] = INT_MIN;
            }
            if (now->right)
            {
                q.push(now->right);
                c[pos++] = now->right->val;
            }
            else
            {
                c[pos++] = INT_MIN;
            }
        }
        return vector<int>(c.begin(), c.begin() + pos);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(vector<int> data)
    {
        if (data.empty())
            return NULL;
        int pos = 0;
        TreeNode *root = new TreeNode(data.at(pos++));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *now = q.front();
            q.pop();
            if (pos < data.size() && data.at(pos) != INT_MIN)
            {
                TreeNode *tmp = new TreeNode(data.at(pos));
                now->left = tmp;
                q.push(now->left);
            }
            else
            {
                now->left = NULL;
            }
            pos++;
            if (pos < data.size() && data.at(pos) != INT_MIN)
            {
                TreeNode *tmp = new TreeNode(data.at(pos));
                now->right = tmp;
                q.push(now->right);
            }
            else
            {
                now->right = NULL;
            }
            pos++;
        }
        return root;
    }

    /*
    // Memory Limit Exceeded
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        vector<char> c(1024, -127);
        queue<TreeNode*> q;
        queue<int> qp;
        q.push(root);
        qp.push(0);
        int pos = 0;
        while(!q.empty()) {
            TreeNode* now = q.front();
            pos = qp.front();
            c[pos] = static_cast<char>(now->val);
            q.pop();
            qp.pop();
            while(2 * pos + 2 >= c.size())
                c.resize(c.size() + 1024, '\127');
            if(now->left)    {
                q.push(now->left);
                qp.push(pos * 2 + 1);

            }
            if(now->right)   {
                q.push(now->right);
                qp.push(pos * 2 + 2);
            }
        }
        return string(c.begin(), c.begin() + pos + 1);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> q;
        queue<int> qp;
        q.push(root);
        qp.push(0);
        int pos = 0;
        while(!q.empty()) {
            TreeNode* now = q.front();
            pos = qp.front();
            now->val = static_cast<int>(data.at(pos));
            q.pop();
            qp.pop();
            if(pos * 2 + 1 < data.length() && data.at(pos * 2 + 1) != '\127')    {
                TreeNode* tmp = new TreeNode(0);
                now->left = tmp;
                q.push(now->left);
                qp.push(pos * 2 + 1);
            }else {
                now->left = NULL;
            }
            if(pos * 2 + 2 < data.length() && data.at(pos * 2 + 2) != '\127')    {
                TreeNode* tmp = new TreeNode(0);
                now->right = tmp;
                q.push(now->right);
                qp.push(pos * 2 + 2);
            }else {
                now->right = NULL;
            }
        }
        return root;
    }
    */

    /**
    301. Remove Invalid Parentheses
    Remove the minimum number of invalid parentheses in order to make the input string valid.
    Return all possible results.

    Note: The input string may contain letters other than the parentheses ( and ).

    Example 1:

    Input: "()())()"
    Output: ["()()()", "(())()"]
    Example 2:

    Input: "(a)())()"
    Output: ["(a)()()", "(a())()"]
    Example 3:

    Input: ")("
    Output: [""]
    */
    vector<string> removeInvalidParentheses(string s)
    {
    }

    /**
    314. Binary Tree Vertical Order Traversal

    Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

    If two nodes are in the same row and column, the order should be from left to right.

    Example 1:

    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Example 2:

    Input: root = [3,9,8,4,0,1,7]
    Output: [[4],[9],[3,0,1],[8],[7]]
    Example 3:

    Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
    Output: [[4],[9,5],[3,0,1],[8,2],[7]]

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
    */
    void midOrder(TreeNode *root)
    {
    }
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
    }

    /**
    322. Coin Change
    You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    Example 1:

    Input: coins = [1, 2, 5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
    Example 2:

    Input: coins = [2], amount = 3
    Output: -1
    Note:
    You may assume that you have an infinite number of each kind of coin.
    **/

    // F(S)=F(S−C)+1
    int coinChange(vector<int> &coins, int amount)
    {
        //        sort(coins.begin(), coins.end(), greater<int>());
        vector<int> dp;
        dp.push_back(0);
        for (int i = 1; i <= amount; ++i)
        {
            int _min = i + 1;
            for (int j = 0; j < coins.size(); ++j)
            {
                if (i >= coins[j] && dp[i - coins[j]] != -1)
                    _min = min(_min, dp[i - coins[j]] + 1);
            }
            if (_min == i + 1)
                _min = -1;
            dp.push_back(_min);
        }
        return dp[amount];
    }

    /**
    344. Reverse String
    Write a function that reverses a string. The input string is given as an array of characters char[].

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

    You may assume all the characters consist of printable ascii characters.



    Example 1:

    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
    Example 2:

    Input: ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]
    */
    void reverseString(vector<char> &s)
    {
        for (int i = 0; i < s.size() / 2; ++i)
        {
            swap(s[i], s[s.size() - i - 1]);
        }
    }

    /**
    408. Valid Word Abbreviation
    A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

    For example, a string such as "substitution" could be abbreviated as (but not limited to):

    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)
    The following are not valid abbreviations:

    "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
    "s010n" (has leading zeros)
    "s0ubstitution" (replaces an empty substring)
    Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

    A substring is a contiguous non-empty sequence of characters within a string.



    Example 1:

    Input: word = "internationalization", abbr = "i12iz4n"
    Output: true
    Explanation: The word "internationalization" can be abbreviated as "i12iz4n" ("i nternational iz atio n").
    Example 2:

    Input: word = "apple", abbr = "a2e"
    Output: false
    Explanation: The word "apple" cannot be abbreviated as "a2e".


    Constraints:

    1 <= word.length <= 20
    word consists of only lowercase English letters.
    1 <= abbr.length <= 10
    abbr consists of lowercase English letters and digits.
    All the integers in abbr will fit in a 32-bit integer.
    */
    bool _408 = true;
    bool validWordAbbreviation(string word, string abbr)
    {
        size_t j = 0;
        string offset = "";
        for (auto i = 0; i < abbr.size(); ++i)
        {
            if (abbr[i] >= 'a' && abbr[i] <= 'z')
            {
                j += atoi(offset.c_str());
                offset = "";
                if (abbr[i] != word[j++])
                    return false;
            }
            else
            {
                if (offset.empty() && abbr[i] == '0')
                    return false;
                offset += abbr[i];
            }
        }
        j += atoi(offset.c_str());
        if (j != word.size())
            return false;
        return true;
    }

    /**
    412. Fizz Buzz
    Write a program that outputs the string representation of numbers from 1 to n.

    But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

    Example:

    n = 15,

    Return:
    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]
    */
    vector<string> fizzBuzz(int n)
    {
        static vector<string> ans;
        for (int i = ans.size() + 1; i <= n; ++i)
        {
            if (i % 15 == 0)
                ans.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ans.push_back("Fizz");
            else if (i % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }
        ans.resize(n);
        return ans;
    }
    /**
    426. Convert Binary Search Tree to Sorted Doubly Linked List
    Convert a BST to a sorted circular doubly-linked list in-place.
    Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.

    Let's take the following BST as an example, it may help you understand the problem better:





    We want to transform this BST into a circular doubly linked list.
    Each node in a doubly linked list has a predecessor and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

    The figure below shows the circular doubly linked list for the BST above.
    The "head" symbol means the node it points to is the smallest element of the linked list.


    Specifically, we want to do the transformation in place. After the transformation,
    the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.

    The figure below shows the transformed BST.
    The solid line indicates the successor relationship,
    while the dashed line means the predecessor relationship.

    **/

    /*
    void inorder_426(Node* root, vector<Node*> &a) {
        if(root)  {
            inorder_426(root->left, a);
            a.push_back(root);
            inorder_426(root->right, a);
        }

    }
    Node* treeToDoublyList(Node* root) {
        if(NULL == root)
            return root;
        vector<Node*> a;
        inorder_426(root, a);
        int n = a.size();
        for(int i = 0; i < n; ++i) {

            a[i]->left = a[(i + n - 1) % n];
            a[i]->right = a[(i + 1) % n];
            //cout << a[i]->val  << " " << a[i]->left->val << " " << a[i]->right->val  << endl;
        }
        return a[0];
    }
    */

    /**
    560. Subarray Sum Equals K
    Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

    Example 1:
    Input:nums = [1,1,1], k = 2
    Output: 2
    Note:
    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
    **/
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> sums;
        sums.push_back(0);
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            sums.push_back(sums[i] + nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < sums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (sums[i] - sums[j] == k)
                    ++ans;
            }
        }
        return ans;
    }
    /**
    572. Subtree of Another Tree
    Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

    Example 1:
    Given tree s:

         3
        / \
       4   5
      / \
     1   2
    Given tree t:
       4
      / \
     1   2
    Return true, because t has the same structure and node values with a subtree of s.
    Example 2:
    Given tree s:

         3
        / \
       4   5
      / \
     1   2
        /
       0
    Given tree t:
       4
      / \
     1   2
    Return false.

    */
    bool isEqual_572(TreeNode *s, TreeNode *t)
    {
        if (NULL == t && NULL == s)
            return true;
        if (NULL == t || NULL == s)
            return false;
        if (s->val == t->val && isEqual_572(s->left, t->left) && isEqual_572(s->right, t->right))
            return true;
        return false;
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (isEqual_572(s, t))
            return true;
        if (s && isSubtree(s->left, t))
            return true;
        if (s && isSubtree(s->right, t))
            return true;
        return false;
    }

    /**
    621. Task Scheduler
    Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

    However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

    You need to return the least number of intervals the CPU will take to finish all the given tasks.

    Example:

    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
    Note:

    The number of tasks is in the range [1, 10000].
    The integer n is in the range [0, 100].
    */
    int leastInterval_1(vector<char> &tasks, int n)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); ++i)
        {
            if (m.find(tasks[i]) == m.end())
                m[tasks[i]] = 1;
            else
                ++m[tasks[i]];
        }
        int _max = 0, _sum = 0, _total = m.size();
        for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            if (it->second == _max)
                ++_sum;
            else if (it->second > _max)
            {
                _max = it->second;
                _sum = 1;
            }
        }
        return max(static_cast<int>(tasks.size()), (_max - 1) * (n + 1) + _sum);
    }

    static bool comp_value(const pair<char, int> &a, const pair<char, int> &b)
    {
        return a.second > b.second;
    }
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); ++i)
        {
            if (m.find(tasks[i]) == m.end())
                m[tasks[i]] = 1;
            else
                ++m[tasks[i]];
        }
        multiset<pair<char, int>, bool (*)(const pair<char, int> &, const pair<char, int> &)> sm(comp_value);
        for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            //            sm[it->first] = sm[it->second];
            sm.insert(*it);
        }
        vector<char> ans;
        vector<bool> exist(26, false);
        while (!sm.empty())
        {
            bool flag = false;
            for (multiset<pair<char, int>, bool (*)(const pair<char, int> &, const pair<char, int> &)>::iterator it = sm.begin(); it != sm.end(); it++)
            {

                if (!exist[it->first - 'A'])
                {
                    ans.push_back(it->first);
                    exist[it->first - 'A'] = true;
                    pair<char, int> tmp = *it;
                    sm.erase(it);
                    --tmp.second;
                    //                  cout << tmp.first << " " << tmp.second << endl;
                    if (tmp.second > 0)
                        sm.insert(tmp);
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                ans.push_back('$');
            }
            if (ans.size() > n && ans[ans.size() - n - 1] != '$')
                exist[ans[ans.size() - n - 1] - 'A'] = false;
        }
        //        for(int i = 0; i < ans.size(); ++i) {
        //            cout << ans[i] ;
        //        }
        //        cout << endl;

        return ans.size();
    }

    /*
    629. K Inverse Pairs Array
    For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

    Given two integers n and k, return the number of different arrays consisting of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

    Example 1:

    Input: n = 3, k = 0
    Output: 1
    Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
    Example 2:

    Input: n = 3, k = 1
    Output: 2
    Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.


    Constraints:

    1 <= n <= 1000
    0 <= k <= 1000
    */
    int kInversePairs(int n, int k)
    {
        int a[2][k + 1];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 2; ++i)
        {
            a[i][0] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= (i - 1) * i / 2; ++j)
            {
                a[i % 2][j] = (a[(i - 1) % 2][j] + a[i % 2][j - 1]) % 1000000007;
                if (j >= i)
                    a[i % 2][j] = (a[i % 2][j] - a[(i - 1) % 2][j - i] + 1000000007) % 1000000007;
                // cout << i << " " << j << " " << a[i][j] << endl;
            }
        }
        return a[n % 2][k];
    }
    void kInversePairs_test(int n)
    {

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            v[i] = i + 1;
        }

        vector<int> x(n * (n - 1) / 2 + 1, 0);
        x[0] = 1;
        while (next_permutation(v.begin(), v.end()))
        {
            for (int i = 0; i < v.size(); ++i)
            {
                cout << v[i] << " ";
            }
            cout << endl;
            // print num of inverse pairs
            int ans = 0;
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = i + 1; j < v.size(); ++j)
                {
                    if (v[i] > v[j])
                        ++ans;
                }
            }
            x[ans] = x[ans] + 1;
            cout << ans << endl;
        }

        for (int i = 0; i < x.size(); ++i)
        {
            cout << i << ' ' << x[i] << endl;
        }
    }

    /**
    642. Design Search Autocomplete System
    Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

    The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
    If less than 3 hot sentences exist, then just return as many as you can.
    When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
    Your job is to implement the following functions:

    The constructor function:

    AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

    Now, the user wants to input a new sentence. The following function will provide the next character the user types:

    List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


    Example:
    Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
    The system have already tracked down the following sentences and their corresponding times:
    "i love you" : 5 times
    "island" : 3 times
    "ironman" : 2 times
    "i love leetcode" : 2 times
    Now, the user begins another search:

    Operation: input('i')
    Output: ["i love you", "island","i love leetcode"]
    Explanation:
    There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.

    Operation: input(' ')
    Output: ["i love you","i love leetcode"]
    Explanation:
    There are only two sentences that have prefix "i ".

    Operation: input('a')
    Output: []
    Explanation:
    There are no sentences that have prefix "i a".

    Operation: input('#')
    Output: []
    Explanation:
    The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.


    Note:

    The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
    The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
    Please use double-quote instead of single-quote when you write test cases even for a character input.
    Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.
    */

    /// TRIE
    // AutocompleteSystem(vector<string>& sentences, vector<int>& times) {

    // }

    // vector<string> input(char c) {

    // }

    /*
    680. Valid Palindrome II
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.

    Example 1:

    Input: s = "aba"
    Output: true
    Example 2:

    Input: s = "abca"
    Output: true
    Explanation: You could delete the character 'c'.
    Example 3:

    Input: s = "abc"
    Output: false

    Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    */
    bool validPalindrome(string s)
    {
        // auto n = s.length() / 2;
        // for(auto i = 1; i <= n; ++i) {
        //     cout << s[i-1] << ' ' << s[s.length() - i] << endl;
        //     if(s[i - 1] != s[s.length() - i])
        //         return false;
        // }

        int l = 0, r = s.length() - 1;
        bool opt = true;
        bool res = true;

        while (l < r)
        {
            cout << s[l] << ' ' << s[r] << endl;
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else
            {
                if (opt)
                {
                    ++l;
                    opt = false;
                }
                else
                {
                    res = false;
                    break;
                }
            }
        }
        if (res)
            return true;
        l = 0, r = s.length() - 1;
        opt = true;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else
            {
                if (opt)
                {
                    --r;
                    opt = false;
                }
                else
                    return false;
            }
        }

        return true;
    }
    /*
    767. Reorganize String
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

    Return any possible rearrangement of s or return "" if not possible.

    Example 1:

    Input: s = "aab"
    Output: "aba"
    Example 2:

    Input: s = "aaab"
    Output: ""

    Constraints:

    1 <= s.length <= 500
    s consists of lowercase English letters.
    */
    string reorganizeString(string s)
    {
        vector<int> m(26, 0);
        priority_queue<pair<int, char>> q;
        for (int i = 0; i < s.size(); ++i)
        {
            m[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (m[i] > 0)
            {
                q.push(make_pair(m[i], i + 'a'));
            }
        }
        string ans = "";
        while (q.size() >= 2)
        {
            pair<int, char> a = q.top();
            q.pop();
            pair<int, char> b = q.top();
            q.pop();
            ans += a.second;
            ans += b.second;
            if (--a.first > 0)
            {
                q.push(a);
            }
            if (--b.first > 0)
            {
                q.push(b);
            }
        }
        if (!q.empty())
        {
            if (q.top().first > 1)
            {
                return "";
            }
            ans += q.top().second;
        }
        return ans;
    }

    /**
    771. Jewels and Stones
    You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

    The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

    Example 1:

    Input: J = "aA", S = "aAAbbbb"
    Output: 3
    Example 2:

    Input: J = "z", S = "ZZ"
    Output: 0
    Note:

    S and J will consist of letters and have length at most 50.
    The characters in J are distinct.

    **/
    int numJewelsInStones(string &J, string &S)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < S.length(); ++i)
        {
            if (m.find(S.at(i)) == m.end())
                m[S.at(i)] = 1;
            else
                m[S.at(i)]++;
        }
        int ans = 0;
        for (int i = 0; i < J.length(); ++i)
        {
            if (m.find(J.at(i)) != m.end())
            {
                ans += m[J.at(i)];
                m.erase(J.at(i));
            }
        }
        return ans;
    }
    /*
    791. Custom Sort String
    You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
    Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
    Return any permutation of s that satisfies this property.

    Example 1:

    Input: order = "cba", s = "abcd"

    Output: "cbad"

    Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

    Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

    Example 2:

    Input: order = "bcafg", s = "abcd"

    Output: "bcad"

    Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

    Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.



    Constraints:

    1 <= order.length <= 26
    1 <= s.length <= 200
    order and s consist of lowercase English letters.
    All the characters of order are unique.
    */
    string customSortString(string order, string s)
    {
        string res = "";
        for (auto i = 0; i < order.length(); ++i)
        {
            // if (s.find(order[i]) != string::npos)
            //     res += order[i];
            int start = 0;
            while ((start = s.find(order[i], start)) != string::npos)
            {
                res += order[i];
                start++;
            }
        }
        for (auto i = 0; i < s.length(); ++i)
        {
            if (order.find(s[i]) == string::npos)
                res += s[i];
        }
        return res;
    }
    /**
    811. Subdomain Visit Count
    A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

    Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

    We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

    Example 1:
    Input:
    ["9001 discuss.leetcode.com"]
    Output:
    ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
    Explanation:
    We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

    Example 2:
    Input:
    ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    Output:
    ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
    Explanation:
    We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

    Notes:

    The length of cpdomains will not exceed 100.
    The length of each domain name will not exceed 100.
    Each address will have either 1 or 2 "." characters.
    The input count in any count-paired domain will not exceed 10000.
    The answer output can be returned in any order.
    **/
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int64_t> m;
        for (int i = 0; i < cpdomains.size(); ++i)
        {
            int pos = cpdomains[i].find(" ");
            int64_t num = atoll(cpdomains[i].substr(0, pos).c_str());
            int point = 0;
            string domain = cpdomains[i].substr(pos + 1);
            if (m.find(domain) != m.end())
                m[domain] += num;
            else
                m[domain] = num;
            while (true)
            {
                point = cpdomains[i].find(".", point + 1);
                if (point == string::npos)
                    break;
                string subdomain = cpdomains[i].substr(point + 1);
                if (m.find(subdomain) != m.end())
                    m[subdomain] += num;
                else
                    m[subdomain] = num;
            }
        }
        vector<string> ans;
        for (unordered_map<string, int64_t>::iterator it = m.begin(); it != m.end(); ++it)
        {
            string item = to_string(it->second) + " " + it->first;
            ans.push_back(item);
        }
        return ans;
    }

    /**
    829. Consecutive Numbers Sum
    Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

    Example 1:

    Input: 5
    Output: 2
    Explanation: 5 = 5 = 2 + 3
    Example 2:

    Input: 9
    Output: 3
    Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
    Example 3:

    Input: 15
    Output: 4
    Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
    Note: 1 <= N <= 10 ^ 9.

    */
    int consecutiveNumbersSum(int N)
    {
        int ans = 0;
        for (int i = 1, p = 1; i <= N; i += ++p)
        {
            if (N % i == 0)
                ans++;
        }
        return ans;
    }

    /**
    904. Fruit Into Baskets

    In a row of trees, the i-th tree produces fruit with type tree[i].
    You start at any tree of your choice, then repeatedly perform the following steps:

    Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
    Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
    Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

    You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

    What is the total amount of fruit you can collect with this procedure?



    Example 1:

    Input: [1,2,1]
    Output: 3
    Explanation: We can collect [1,2,1].
    Example 2:

    Input: [0,1,2,2]
    Output: 3
    Explanation: We can collect [1,2,2].
    If we started at the first tree, we would only collect [0, 1].
    Example 3:

    Input: [1,2,3,2,2]
    Output: 4
    Explanation: We can collect [2,3,2,2].
    If we started at the first tree, we would only collect [1, 2].
    Example 4:

    Input: [3,3,3,1,2,1,1,2,3,3,4]
    Output: 5
    Explanation: We can collect [1,2,1,1,2].
    If we started at the first tree or the eighth tree, we would only collect 4 fruits.


    Note:

    1 <= tree.length <= 40000
    0 <= tree[i] < tree.length
    **/
    int totalFruit(vector<int> &tree)
    {
        vector<pair<int, int>> a;
        size_t now = 0;
        a.push_back(make_pair(tree[0], 1));
        for (size_t i = 1; i < tree.size(); ++i)
        {
            if (tree[i] == tree[i - 1])
                a[now].second++;
            else
            {
                a.push_back(make_pair(tree[i], 1));
                now++;
            }
        }
        if (a.size() == 1)
            return a[0].second;
        if (a.size() == 2)
            return a[0].second + a[1].second;

        int _max = a[0].second + a[1].second, _now = _max;
        for (size_t i = 2; i < a.size(); ++i)
        {
            if (a[i].first == a[i - 2].first)
                _now += a[i].second;
            else
                _now = a[i].second + a[i - 1].second;
            _max = max(_max, _now);
        }
        return _max;
    }

    /**
    907. Sum of Subarray Minimums
    Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.
    Since the answer may be large, return the answer modulo 10^9 + 7.

    Example 1:

    Input: [3,1,2,4]
    Output: 17
    Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.


    Note:

    1 <= A.length <= 30000
    1 <= A[i] <= 30000
    **/
    int sumSubarrayMins(vector<int> &A)
    {
        vector<int> L(A.size(), 0), R(A.size(), 0);
        stack<int> s;
        A.push_back(INT_MIN);
        for (int i = 0; i < A.size(); ++i)
        {
            while (!s.empty() && A[i] <= A[s.top()])
            {
                int pos = s.top();
                s.pop();
                L[pos] = s.empty() ? pos : pos - s.top() - 1;
                R[pos] = i - pos - 1;
            }
            s.push(i);
        }

        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < L.size(); ++i)
        {
            ans = ans + A[i] * (L[i] + 1) * (R[i] + 1) % mod;
            ans %= mod;
        }
        return ans;
    }

    /**
    929. Unique Email Addresses
    Every email consists of a local name and a domain name, separated by the @ sign.
    For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
    Besides lowercase letters, these emails may contain '.'s or '+'s.
    If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.
    For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
    (Note that this rule does not apply for domain names.)
    If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
    This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.
    (Again, this rule does not apply for domain names.)

    It is possible to use both of these rules at the same time.

    Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?



    Example 1:

    Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    Output: 2
    Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails


    Note:

    1 <= emails[i].length <= 100
    1 <= emails.length <= 100
    Each emails[i] contains exactly one '@' character.
    **/
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> ans;
        for (size_t i = 0; i < emails.size(); ++i)
        {
            string email = "";
            bool flag = true;
            for (size_t j = 0; j < emails[i].length(); ++j)
            {
                if (emails[i].at(j) == '@')
                {
                    email += emails[i].substr(j);
                    break;
                }
                else if (emails[i].at(j) == '+')
                {
                    flag = false;
                }
                else if (emails[i].at(j) != '.' && flag)
                {
                    email += emails[i].at(j);
                }
            }
            ans.insert(email);
        }
        return ans.size();
    }
    /*
    938. Range Sum of BST
    Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

    Example 1:
    Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
    Output: 32
    Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

    Example 2:

    Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
    Output: 23
    Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

    Constraints:

    The number of nodes in the tree is in the range [1, 2 * 104].
    1 <= Node.val <= 105
    1 <= low <= high <= 105
    All Node.val are unique.

    */
    // #define _938 938
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return 0;
        int v = 0;
        if (root->val >= low && root->val <= high)
            v = root->val;
        return v + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    /**
    946. Validate Stack Sequences
    Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

    Example 1:

    Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    Output: true
    Explanation: We might do the following sequence:
    push(1), push(2), push(3), push(4), pop() -> 4,
    push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
    Example 2:

    Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    Output: false
    Explanation: 1 cannot be popped before 2.


    Note:

    0 <= pushed.length == popped.length <= 1000
    0 <= pushed[i], popped[i] < 1000
    pushed is a permutation of popped.
    pushed and popped have distinct values.

    */
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        for (int i = 0, j = 0; i < popped.size(); ++i)
        {
            if (st.empty() || st.top() != popped[i])
            {
                while (j < pushed.size() && pushed[j] != popped[i])
                {
                    st.push(pushed[j++]);
                }
                if (j == pushed.size())
                    return false;
                ++j;
            }
            else
            {
                st.pop();
            }
        }
        return true;
    }

    /**
    973. K Closest Points to Origin
    We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

    (Here, the distance between two points on a plane is the Euclidean distance.)

    You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)



    Example 1:

    Input: points = [[1,3],[-2,2]], K = 1
    Output: [[-2,2]]
    Explanation:
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
    Example 2:

    Input: points = [[3,3],[5,-1],[-2,4]], K = 2
    Output: [[3,3],[-2,4]]
    (The answer [[-2,4],[3,3]] would also be accepted.)


    Note:

    1 <= K <= points.length <= 10000
    -10000 < points[i][0] < 10000
    -10000 < points[i][1] < 10000

    **/
    bool _973 = true;
    static bool EuclideanCmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        sort(points.begin(), points.end(), EuclideanCmp);
        vector<vector<int>> ans;
        for (size_t i = 0; i < K; ++i)
        {
            ans.push_back(points[i]);
        }
        return ans;
    }

    /**
    975. Odd Even Jump
    You are given an integer array A.  From some starting index, you can make a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.

    You may from index i jump forward to index j (with i < j) in the following way:

    During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
    During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
    (It may be the case that for some index i, there are no legal jumps.)
    A starting index is good if, starting from that index, you can reach the end of the array (index A.length - 1) by jumping some number of times (possibly 0 or more than once.)

    Return the number of good starting indexes.

    Example 1:

    Input: [10,13,12,14,15]
    Output: 2
    Explanation:
    From starting index i = 0, we can jump to i = 2 (since A[2] is the smallest among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), then we can't jump any more.
    From starting index i = 1 and i = 2, we can jump to i = 3, then we can't jump any more.
    From starting index i = 3, we can jump to i = 4, so we've reached the end.
    From starting index i = 4, we've reached the end already.
    In total, there are 2 different starting indexes (i = 3, i = 4) where we can reach the end with some number of jumps.
    Example 2:

    Input: [2,3,1,1,4]
    Output: 3
    Explanation:
    From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:

    During our 1st jump (odd numbered), we first jump to i = 1 because A[1] is the smallest value in (A[1], A[2], A[3], A[4]) that is greater than or equal to A[0].

    During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because A[2] is the largest value in (A[2], A[3], A[4]) that is less than or equal to A[1].  A[3] is also the largest value, but 2 is a smaller index, so we can only jump to i = 2 and not i = 3.

    During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because A[3] is the smallest value in (A[3], A[4]) that is greater than or equal to A[2].

    We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.

    In a similar manner, we can deduce that:
    From starting index i = 1, we jump to i = 4, so we reach the end.
    From starting index i = 2, we jump to i = 3, and then we can't jump anymore.
    From starting index i = 3, we jump to i = 4, so we reach the end.
    From starting index i = 4, we are already at the end.
    In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) where we can reach the end with some number of jumps.
    Example 3:

    Input: [5,1,3,4,2]
    Output: 3
    Explanation:
    We can reach the end from starting indexes 1, 2, and 4.


    Note:

    1 <= A.length <= 20000
    0 <= A[i] < 100000
    **/
    int oddEvenJumps(vector<int> &A)
    {
    }
    /**
    1235. Maximum Profit in Job Scheduling
    We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

    You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

    If you choose a job that ends at time X you will be able to start another job that starts at time X.



    Example 1:

    Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
    Output: 120
    Explanation: The subset chosen is the first and fourth job.
    Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
    Example 2:

    Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
    Output: 150
    Explanation: The subset chosen is the first, fourth and fifth job.
    Profit obtained 150 = 20 + 70 + 60.
    Example 3:

    Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
    Output: 6

    Constraints:

    1 <= startTime.length == endTime.length == profit.length <= 5 * 104
    1 <= startTime[i] < endTime[i] <= 109
    1 <= profit[i] <= 104
    */
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
    }

    /**
    1249. Minimum Remove to Make Valid Parentheses
    Medium
    Topics
    Companies
    Hint
    Given a string s of '(' , ')' and lowercase English characters.

    Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

    Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.


    Example 1:

    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de"
    Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
    Example 2:

    Input: s = "a)b(c)d"
    Output: "ab(c)d"
    Example 3:

    Input: s = "))(("
    Output: ""
    Explanation: An empty string is also valid.


    Constraints:

    1 <= s.length <= 105
    s[i] is either '(' , ')', or lowercase English letter.
    */
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = '`';
            }
        }
        while (!st.empty())
        {
            s[st.top()] = '`';
            st.pop();
        }

        s.erase(std::remove(s.begin(), s.end(), '`'), s.end());
        // std::remove(s.begin(),s.end(), '`');

        return s;
    }
    /*
    1291. Sequential Digits
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.



    Example 1:

    Input: low = 100, high = 300
    Output: [123,234]
    Example 2:

    Input: low = 1000, high = 13000
    Output: [1234,2345,3456,4567,5678,6789,12345]


    Constraints:

    10 <= low <= high <= 10^9
    */
    vector<int> sequentialDigits(int low, int high)
    {
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> aa(a, a + 9);
        vector<vector<int>> res;
        res.push_back(aa);
        for (int i = 1; i < 9; ++i)
        {
            vector<int> temp;
            for (auto j = 0; j < res[i - 1].size(); ++j)
            {
                if (res[i - 1][j] % 10 != 9)
                    temp.push_back(res[i - 1][j] * 10 + res[i - 1][j] % 10 + 1);
            }
            res.push_back(temp);
        }
        vector<int> ans;
        for (int i = 0; i < res.size(); ++i)
        {
            for (int j = 0; j < res[i].size(); ++j)
            {
                if (res[i][j] >= low && res[i][j] <= high)
                    ans.push_back(res[i][j]);
            }
        }
        return ans;
    }

    /*
    1650. Lowest Common Ancestor of a Binary Tree III

    Hint
    Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

    Each node will have a reference to its parent node. The definition for Node is below:

    class Node {
        public int val;
        public Node left;
        public Node right;
        public Node parent;
    }
    According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."



    Example 1:


    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.
    Example 2:


    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.
    Example 3:

    Input: root = [1,2], p = 1, q = 2
    Output: 1


    Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q exist in the tree.
    */
    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        // vector<Node*> pp,qq;
        // while(p) {
        //     // pp.push_back(p);
        //     pp.insert(pp.begin(), p);
        //     p = p->parent;
        // }
        // while(q) {
        //     // qq.push_back(q);
        //     qq.insert(qq.begin(), q);
        //     q = q->parent;
        // }
        // for(int i = 1; i < max(pp.size(), qq.size()); ++i) {
        //     if(qq.size() < i + 1 || pp.size() < i + 1 || pp[i] != qq[i])
        //         return pp[i - 1];

        // }
        // return pp[pp.size() - 1];
    }

    /*
    1762. Buildings With an Ocean View
    There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

    The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

    Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

    Example 1:

    Input: heights = [4,2,3,1]
    Output: [0,2,3]
    Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
    Example 2:

    Input: heights = [4,3,2,1]
    Output: [0,1,2,3]
    Explanation: All the buildings have an ocean view.
    Example 3:

    Input: heights = [1,3,2,4]
    Output: [3]
    Explanation: Only building 3 has an ocean view.


    Constraints:

    1 <= heights.length <= 105
    1 <= heights[i] <= 109
    */
    vector<int> findBuildings(vector<int> &heights)
    {
        vector<int> max_right(heights.size(), 0);
        for (int i = heights.size() - 1, max_h = 0; i >= 0; --i)
        {
            max_right[i] = max_h;
            if (heights[i] >= max_h)
                max_h = heights[i];
        }
        vector<int> ans;
        for (int i = 0; i < heights.size(); ++i)
        {
            if (heights[i] > max_right[i])
                ans.push_back(i);
        }
        return ans;
    }
    /*
    1768. Merge Strings Alternately
    You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

    Return the merged string.
    Example 1:

    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r
    Example 2:

    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
    Explanation: Notice that as word2 is longer, "rs" is appended to the end.
    word1:  a   b
    word2:    p   q   r   s
    merged: a p b q   r   s
    Example 3:

    Input: word1 = "abcd", word2 = "pq"
    Output: "apbqcd"
    Explanation: Notice that as word1 is longer, "cd" is appended to the end.
    word1:  a   b   c   d
    word2:    p   q
    merged: a p b q c   d


    Constraints:

    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
    */
    string mergeAlternately(string word1, string word2)
    {
        int n1 = min(word1.length(), word2.length());
        string res = "";
        for (auto i = 0; i < n1; ++i)
        {
            res += word1[i];
            res += word2[i];
        }
        res += word1.substr(n1);
        res += word2.substr(n1);
        return res;
    }
};

/**
146. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2    );  // capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

**/
class LRUCache
{
public:
    // deque<int> dq;
    list<pair<int, int>> lis;
    unordered_map<int, list<pair<int, int>>::iterator> m;

    int cap = 0;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            pair<int, int> now = *(m[key]);
            lis.erase(m[key]);
            lis.push_front(now);
            m[key] = lis.begin();
            return now.second;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            pair<int, int> now = *(m[key]);
            lis.erase(m[key]);
            lis.push_front(make_pair(key, value));
            m[key] = lis.begin();
        }
        else
        {
            lis.push_front(make_pair(key, value));
            m[key] = lis.begin();
            if (lis.size() > cap)
            {
                pair<int, int> last = lis.back();
                lis.pop_back();
                m.erase(last.first);
            }
        }
    }
};

/**
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

**/
class MinStack
{
public:
    /** initialize your data structure here. */

    multiset<int> ms;
    stack<int> s;
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        ms.insert(x);
    }

    void pop()
    {
        int x = s.top();
        ms.erase(ms.find(x));
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        multiset<int>::iterator p = ms.begin();
        return *p;
    }
};
class MinStack_1
{
public:
    /** initialize your data structure here. */

    stack<pair<int, int>> s;
    MinStack_1()
    {
    }

    void push(int x)
    {
        if (s.empty())
        {
            s.push(make_pair(x, x));
        }
        else
        {
            s.push(make_pair(x, min(x, s.top().second)));
        }
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

/**
295. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.


Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2


Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

*/
class MedianFinder
{
public:
    /** initialize your data structure here. */
    multiset<int> _set;
    multiset<int>::iterator mid;
    std::multiset<int>::key_compare mycomp = _set.key_comp();
    MedianFinder()
    {
        mid = _set.end();
    }

    void addNum(int num)
    {
        _set.insert(num);
        int n = _set.size();
        if (n == 1)
            mid = _set.begin();
        else if (0 == n % 2)
        {
            if (mycomp(num, *mid))
                mid--;
        }
        else
        {
            if (!mycomp(num, *mid))
                mid++;
        }
    }
    double findMedian()
    {
        int n = _set.size();
        if (n == 0)
            return 0;
        if (0 == n % 2)
        {
            double ans = (*(mid++) + *mid) / 2.0;
            --mid;
            return ans;
        }
        return *mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
380. Insert Delete GetRandom O(1)
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

*/

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }
    set<int> _set;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
    }

    /** Get a random element from the set. */
    int getRandom()
    {
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
716. Max Stack

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5);
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
**/
class MaxStack
{
public:
    /** initialize your data structure here. */

    stack<int> s;
    stack<int> m;
    MaxStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (m.empty())
            m.push(x);
        else
            m.push(m.top());
    }

    int pop()
    {
        int x = s.top();
        s.pop();
        m.pop();
        return x;
    }

    int top()
    {
        return s.top();
    }

    int peekMax()
    {
    }

    int popMax()
    {
    }
};

#endif // SOLUTION_H_INCLUDED
