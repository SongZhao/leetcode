/*
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

*/

/*
 * Essentially it's the same as two stacks, just combined them together. Note it's x <= minVal, not <
*/

#include "helper.h"
#include <stack>

class MinStack {

public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }

    void push(int x) {
        if (x <= minVal) {
            s.push(minVal);
            minVal = x;
        }
        s.push(x);
    }

    void pop() {
        if (s.top() == minVal) {
            s.pop();
            minVal = s.top();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minVal;
    }

private:
    int minVal;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack s;
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(8);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}
