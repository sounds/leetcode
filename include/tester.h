#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED

#include "solution.h"


class Tester {
public:
    /// nb 1
    void NBtest_1() {
        Solution so;
        int A[] = {1,2,3,4,5,6,7,7,7,7,8,13};
        vector<int> AA(A, A + 12);
        for(int i = -1; i < 15; i++) {
            cout << i << "\t" << so.binarySearch(AA, i) << endl;
        }

        return ;
    }
    void Test_2() {
        Solution so;
        ListNode *l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        ListNode *ans = so.addTwoNumbers(l1, l2);

        while(ans) {
            std::cout << ans->val << std::endl;
            ans = ans->next;
        }

    }
    void Test_3() {
        Solution so;
        //std::cout << so.lengthOfLongestSubstring("dvdf") << endl;

        //std::cout << so.lengthOfLongestSubstring("aabaab!bb") << endl;
        std::cout << so.lengthOfLongestSubstring("tmmzuxt") << endl;

    }

    void Test_4() {
        Solution so;
//        int a1[] = {1, 3};
//        int a2[] = {2};
//        vector<int> a(a1, a1 + 2);
//        vector<int> b(a2, a2 + 1);
//        std::cout << so.findMedianSortedArrays(a, b) << std::endl;
//        std::cout << so.findMedianSortedArrays(b, a) << std::endl;
//
//        int b1[] = {1, 2};
//        int b2[] = {3, 4};
//        vector<int> c(b1, b1 + 2);
//        vector<int> d(b2, b2 + 2);
//        std::cout << so.findMedianSortedArrays(c, d) << std::endl;

//        int b1[] = {1, 2};
//        int b2[] = {-1, 3};
//        vector<int> c(b1, b1 + 2);
//        vector<int> d(b2, b2 + 2);
//        std::cout << so.findMedianSortedArrays(c, d) << std::endl; // 1.5

        int c1[] = {1, 2, 3, 4, 6};
        int c2[] = {5};
        vector<int> e(c1, c1 + 5);
        vector<int> f(c2, c2 + 1);
        std::cout << so.findMedianSortedArrays(e, f) << std::endl;

        return ;

    }

    void Test_5() {
        Solution so;
        string s = "abbahopxpo";
        cout << so.longestPalindrome(s) << endl;

        string ss = "cbbd";
        cout << so.longestPalindrome(ss) << endl;

    }
    void Test_7() {
        Solution so;
        long long x = -2147483648;
        cout << so.reverse(x) << endl;

    }
    void Test_11() {
        Solution so;
        int A[] = {1,8,6,2,5,4,8,3,7};
        vector<int> AA(A, A + 9);
        cout << so.maxArea(AA) << endl;
        int B[] = {1,2,4,3};
        vector<int> BB(B, B + 4);
        cout << so.maxArea(BB) << endl;
        int C[] = {1,3,2,5,25,24,5};
        vector<int> CC(C, C + 7);
        cout << so.maxArea(CC) << endl;
        return ;
    }
    ///15

    void Test_15() {
        Solution so;
        int A[] = {-1, 0, 1, 2, -1, -4};
        vector<int> AA(A, A + 6);
        vector<vector<int> > ans;
        ans = so.threeSum(AA);
        for(size_t i = 0; i < ans.size(); ++i) {
            for(size_t j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return ;
    }

    void Test_22() {
        Solution so;
        vector<string> ans = so.generateParenthesis(2);
        return ;
    }

    /// 33
    void Test_33() {
        Solution so;
        int A[] = {4,5,6,7,8,0,1,2};
        vector<int> AA(A, A + 8);
    //    cout << so.findMin(AA) << endl;
        for(size_t i = 0; i < AA.size(); ++i) {
            cout << so.search(AA, A[i]) << endl;
        }
        cout << so.search(AA, 8) << endl;
        cout << so.search(AA, -1) << endl;
        cout << so.search(AA, 66) << endl;

        return ;

    }
    void Test_41() {
        Solution so;
        int A[] = {3, 4, -1, 1};
        vector<int> AA(A, A + 4);
        cout << so.firstMissingPositive(AA) << endl;
    }

    void Test_42() {
        Solution so;
        // int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        // vector<int> AA(A, A + 12);

        int A[] = {5,4,1,2};
        vector<int> AA(A, A + 4);
        cout << so.trap(AA) << endl;
    }

    void Test_46() {
        Solution so;
        int A[] = {1, 2, 3};
        vector<int> AA(A, A + 3);
        //so.permute(AA);
        so.permute_1(AA);
        return ;
    }
    void Test_53() {
        Solution so;
        int A[] = {-2, -1};
        vector<int> AA(A, A + 2);
        cout << so.maxSubArray(AA) << endl;
    }
    ///138

    void Test_79() {
        Solution so;
        char A[] = {'A','B','C','E','S','F','C','S','A','D','E','E'};
        vector<vector<char>> AA;
        AA.push_back(vector<char>(A, A + 4));
        AA.push_back(vector<char>(A + 4, A + 8));
        AA.push_back(vector<char>(A + 8, A + 12));

        cout << so.exist(AA, "ABCCED") << endl;
    }

    void Test_98() {

        Solution so;
        TreeNode root(1);
        TreeNode left(1);
        root.left = &left;
        cout << so.isValidBST(&root) << endl;
    }

    void Test_127() {
        Solution so;
        char A[][10] = {"hot","dot","dog","lot","log","cog"};
        vector<string> AA(A, A + 6);
        cout << so.ladderLength("hit", "cog", AA) << endl;
    }

    void Test_138() {
        Solution so;
        Node* n1 = new Node(1, NULL, NULL);
        Node* n2 = new Node(2, NULL, NULL);
        n1->next = n2;
        n1->random = n2;
        n2->random = n2;

        Node* ans = so.copyRandomList(n1);
        return ;
    }

    void Test_189() {
        Solution so;
        int A[] = {1, 2, 3, 4, 5, 6, 7};
        vector<int> AA(A, A + 7);
        so.rotate(AA, 3);
        for(size_t i = 0; i < AA.size(); ++i) {
            cout << AA[i] << " ";
        }
        cout << endl;
    }

    /// 200
    void Test_200() {
        Solution so;
        char a[10] = {'1','1','1','0','1','0','1','1','1'};
        vector<vector<char>> vec;
        vector<char> a1(a, a + 3);
        vector<char> a2(a + 3, a + 6);
        vector<char> a3(a + 6, a + 9);
        vec.push_back(a1);
        vec.push_back(a2);
        vec.push_back(a3);

        for(std::size_t i = 0; i < vec.size(); ++i) {
            for(std::size_t j = 0; j < vec[i].size(); ++j) {
                std::cout << vec[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << so.numIslands(vec) <<std::endl;

        for(std::size_t i = 0; i < vec.size(); ++i) {
            for(std::size_t j = 0; j < vec[i].size(); ++j) {
                std::cout << vec[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void Test_297() {
        Solution so;
        int A[] = {1, 2, 3, INT_MIN, INT_MIN, 4, 5};
        vector<int> AA(A, A + 7);

//        string x;
//        x += static_cast<char>(-1);
//        x += static_cast<char>(0);
//        x += static_cast<char>(1);


        TreeNode* root = so.deserialize(AA);
        vector<int> y = so.serialize(root);
        for(int i = 0; i < y.size(); ++i) {
            cout << y[i] << endl;
        }
    }

    void Test_621() {
        Solution so;
//        char A[] = "AAABBB";
        char A[] = "AAAAAABCDEFG";
        vector<char> AA(A, A + 12);
        cout << so.leastInterval(AA, 2) << endl;
    }

    void Test_629() {
        Solution so;
        // cout << so.kInversePairs(3, 1) << endl;
        // so.kInversePairs_test(7);
        cout << so.kInversePairs(5, 6) << endl;
    }

    void Test_680() {
        Solution so;
        // cout << so.validPalindrome("aba") << endl;
        cout << so.validPalindrome("abc") << endl;
        // cout << so.validPalindrome("abca") << endl;
    }

    // 907
    void Test_907() {
        Solution so;
        int A[] = {3, 1, 2, 4};
        vector<int> AA(A, A + 4);

        cout << so.sumSubarrayMins(AA) << endl;
    }
    
    

};

#endif // TESTER_H_INCLUDED
