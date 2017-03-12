class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def add_two_numbers(self, l1, l2):
        """:Type l1: ListNode
            :Type l2: ListNode"""
        dummy = ListNode(0)
        current, carry = dummy, 0

        while l1 or l2:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            carry, val = val / 10, val % 10
            current.next = ListNode(val)
            current = current.next

        if carry == 1:
            current.next = ListNode(1)

        return dummy.next


if __name__ == "__main__":
    a, a.next, a.next.next = ListNode(2), ListNode(4), ListNode(3)
    b, b.next, b.next.next = ListNode(5), ListNode(3), ListNode(1)
    result = Solution().add_two_numbers(a, b)
    print("{0} --> {1} --> {2}".format(result.val, result.next.val, result.next.next.val))