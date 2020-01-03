#include <helper.h>
#include <cassert>
using namespace std;

using T = int;
using ListNode = ymh::GenericListNode<T>;

/*
 * class Solution is the answer
 * class Solution1, Solution2, Solution3 are
 * to evaluate different methods*/

class Solution {
    /*
     * 一起遍历A和B，假设A比较短，A指到nullptr时，将A指向headB，然后继续遍历。
     * 当B指向nullptr时，将B指向headA，此时A和B离第一个交叉节点的距离是相等的。
     * （假设A的长度为m，B的长度为n，m < n。当B指向headA时，A和B都遍历了n个节点，
     * 显然，遍历m + n个节点时，A和B都会再次指向nullptr，因此此时A和B距离第一个交叉节点
     * 的距离相等。）
     * 当B比A短或者相等时，情况类似。
     * 假设重叠部分短长度为x，
     * 时间复杂度O(2(m + n -x)，m，n分别为A和B的长度。
     * （但是，如果A和B长度相等时，复杂度为O(m - x)，
     * 因为在遍历到最后一个节点之前就可以找到答案。）*/
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = (p1 == nullptr) ? headB : p1->next;
            p2 = (p2 == nullptr) ? headA : p2->next;
        }
        return p1;
    }
};

class Solution1 {
    /*
     * same with Solution, but adding a
     * new variable `count` to store the number
     * of the `next` operation*/
public:
    int count;
public:
    Solution1() : count(0) {}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        count = 0;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *p1 = headA, *p2 = headB;

//        calculating count has a bug with following input
//        headA:     0 9 1 2 4
//        headC: 3 -/
//        p2 init as headC and will go to headA in before it get nullptr
//        while (p1 != p2) {
//            p1 = (p1 == nullptr) ? headB : p1->next;
//            p2 = (p2 == nullptr) ? headA : p2->next;
//            if (p1 == headB || p2 == headA) {
//                ++count;
//            } else {
//                count += 2;
//            }
//        }

        while (p1 != p2) {
            if (p1 == nullptr) {
                p1 = headB;
            } else {
                p1 = p1->next;
                ++count;
            }
            if (p2 == nullptr) {
                p2 = headA;
            } else {
                p2 = p2->next;
                ++count;
            }
        }
        return p1;
    }
};

class Solution2 {
    /*
     * 链表n个点，遍历的复杂度为O(n)，（因为进行n次next运算）
     * headA和headB访问到第一个重叠的点时，算法结束。
     * 假设重叠部分有x个点，则后续x - 1个点不会被继续访问。如果遍历
     * 这x - 1个点一共需要x次next运算(因为要先定位到这x - 1个节点的中的第一个节点)
     * 时间复杂度O(2(m + n -x)，m，n分别为A和B的长度 */
public:
    int count;
private:
    ListNode *getTailAndSetLength(ListNode *head, int *len) {
        int n = 1;
        ListNode *t = head->next;
        ++count;
        while (t) {
            ++n;
            head = t;
            t = head->next;
            ++count;
        }
        *len = n;
        return head;
    }
public:
    Solution2() : count(0) {}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        count = 0;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        if (headA == headB) {
            return headA;
        }
        int len1, len2;
        ListNode *tailA = getTailAndSetLength(headA, &len1);
        ListNode *tailB = getTailAndSetLength(headB, &len2);
        if (tailA != tailB) {
            return nullptr;
        }
        while (len1 > len2) {
            headA = headA->next;
            ++count;
            --len1;
        }
        while (len2 > len1) {
            headB = headB->next;
            ++count;
            --len2;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
            count += 2;
        }
        return headA;
    }
};

class Solution2_2 {
    /*
     * 类似于Solution2，只不过求长度时一起求 */
public:
    int count;
private:
    bool setLengthAndJudgeIntersection(ListNode *headA, int *len1, ListNode *headB, int *len2, ListNode **ans) {
        int n1 = 1, n2 = 1;
        ListNode *t1 = headA->next;
        ListNode *t2 = headB->next;
        count +=2;
        while (t1 && t2) {
            ++n1;
            ++n2;
            if (t1 == t2) {
                *ans = t1;
                return true;
            }
            headA = t1;
            headB = t2;
            t1 = headA->next;
            t2 = headB->next;
            count += 2;
        }
        while (t1) {
            ++n1;
            headA = t1;
            t1 = headA->next;
            ++count;
        }
        while (t2) {
            ++n2;
            headB = t2;
            t2 = headB->next;
            ++count;
        }
        if (headA != headB) {
            return false;
        }
        *len1 = n1;
        *len2 = n2;
        return true;
    }

public:
    Solution2_2() : count(0) {}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        count = 0;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        if (headA == headB) {
            return headA;
        }
        int len1, len2;
        ListNode *ans = nullptr;
        if (!setLengthAndJudgeIntersection(headA, &len1, headB, &len2, &ans)) {
            return nullptr;
        }
        if (ans) {
            return ans;
        }
        while (len1 > len2) {
            headA = headA->next;
            ++count;
            --len1;
        }
        while (len2 > len1) {
            headB = headB->next;
            ++count;
            --len2;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
            count += 2;
        }
        return headA;
    }
};

class Solution3 {
    /* when headA reaches nullptr, let headA point to headB(make a circle)
     * then find the entry of circle
     *
     * to find the circle
     * let m = length of listA
     * let n = length of listB
     * to traverse headA, time complexity O(m)
     *
     * let x = the length of stacking part
     * let l = m - x, which means the length of not stacking part of A
     * initialization:
     * slow = headA, fast = headA->next
     * to move slow pointer to then entry of circle, it steps O(l) nodes
     * meanwhile, fast pointer will step O(2l + 1) nodes,
     * thus time complexity O(3l + 1)
     *
     * when slow pointer and fast pointer encounter each other,
     * fast pointer moves k laps and r nodes (kn + r = l + 1),
     * time complexity O(3(n - (l + 1) % n),
     *
     * reset slow pointer continue stepping,
     * we can assume there is a virtual dummy node, dummy->next = headA,
     * and the virtual initialization of the algorithm would be fast = slow = dummy
     * so, in the real case, we can think slow pointer is one step ahead of
     * fast pointer, so to find the entry of circle, we first should move
     * fast pointer to the next node, time complexity O(1)
     * then let fast pointer and slow pointer have the same speed
     * step fast pointer and slow pointer until the encounter each other at the entry
     * time complexity (2l + 1)
     * to make and then break the circle, time complexity O(2)
     * overall, time complexity is O(6m + 3n - 5x - 3[(m  - x + 1) % n] + 4)*/
public:
    int count;
public:
    Solution3() : count(0) {}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        count = 0;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        if (headA == headB) {
            return headA;
        }
        ListNode *tail = headA, *tmp = tail->next;
        ++count;
        while (tmp) {
            tail = tmp;
            tmp = tail->next;
            ++count;
        }
        tail->next = headB;
        tmp = getEntryOfCircle(headA);
        tail->next = nullptr;
        count += 2;
        return tmp;
    }
private:
    ListNode *getEntryOfCircle(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        ++count;
        while (fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
            count += 3;
        }
        slow = head;
        fast = fast->next;
        ++count;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
            count += 2;
        }
        return slow;
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    Solution2_2 solution2_2;
    Solution3 solution3;

    /* construct headA & headB:
     * headA: 0 9 1 -\
     *                 2 4
     * headB:     3 -/  */
    string s1 = "[0,9,1,2,4]";
    string s2 = "[3]";
    int pos = 3;
    ListNode *headA = getList(s1);
    ListNode *headB = getList(s2);
    ListNode *p = headA;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }
    headB->next = p;

    cout << "lists:\n"
            "headA: 0 9 1 -\\\n"
            "               2 4\n"
            "headB:     3 -/\n";
    ListNode *ans = solution1.getIntersectionNode(headA, headB);
    assert(ans->val == 2);
    cout << "solution1 counts " << solution1.count << endl;
    ans = solution2.getIntersectionNode(headA, headB);
    assert(ans->val == 2);
    cout << "solution2 counts " << solution2.count << endl;
    ans = solution2_2.getIntersectionNode(headA, headB);
    assert(ans->val == 2);
    cout << "solution2_2 counts " << solution2_2.count << endl;
    ans = solution3.getIntersectionNode(headA, headB);
    assert(ans->val == 2);
    cout << "solution3 counts " << solution3.count << endl;
    cout << endl;

    /* construct headC*/
    string s3 = "[3]";
    ListNode *headC = getList(s3);
    headC->next = headA;

    cout << "lists:\n"
            "headA:     0 9 1 2 4\n"
            "headC: 3 -/\n";
    ans = solution1.getIntersectionNode(headA, headC);
    assert(ans->val == 0);
    cout << "solution1 counts " << solution1.count << endl;
    ans = solution2.getIntersectionNode(headA, headC);
    assert(ans->val == 0);
    cout << "solution2 counts " << solution2.count << endl;
    ans = solution2_2.getIntersectionNode(headA, headC);
    assert(ans->val == 0);
    cout << "solution2_2 counts " << solution2_2.count << endl;
    ans = solution3.getIntersectionNode(headA, headC);
    assert(ans->val == 0);
    cout << "solution3 counts " << solution3.count << endl;
    cout << endl;

    /* construct headD:
     * headA : 0 9 1 -\
     *                 2 4
     * headD : 5 6 7 -/   */
    string s4 = "[5,6,7]";
    ListNode *headD = getList(s4);
    pos = 3;
    p = headA;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }
    ListNode *q = headD;
    while (q->next) {
        q = q->next;
    }
    q->next = p;

    cout << "lists:\n"
            "headA: 0 9 1 -\\\n"
            "               2 4\n"
            "headD: 5 6 7 -/\n";
    ans = solution1.getIntersectionNode(headA, headD);
    assert(ans->val == 2);
    cout << "solution1 counts " << solution1.count << endl;
    ans = solution2.getIntersectionNode(headA, headD);
    assert(ans->val == 2);
    cout << "solution2 counts " << solution2.count << endl;
    ans = solution2_2.getIntersectionNode(headA, headD);
    assert(ans->val == 2);
    cout << "solution2_2 counts " << solution2_2.count << endl;
    ans = solution3.getIntersectionNode(headA, headD);
    assert(ans->val == 2);
    cout << "solution3 counts " << solution3.count << endl;
    cout << endl;
    return 0;
}
