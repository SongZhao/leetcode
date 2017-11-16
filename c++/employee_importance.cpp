/*
You are given a data structure of employee information, which includes the employee's unique id, his importance value
 and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance
 value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]],
 and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this
 employee and all his subordinates.

Example 1:
Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have
 importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
Note:
One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.
*/

/*
 * count + 1 if one's neighbour is 0 or edge
 */

#include "helper.h"


// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> dict;
        for (auto employee: employees) {
            dict[employee->id] = employee;
        }
        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            res += dict[q.front()]->importance;
            for (int i:dict[q.front()]->subordinates) {
                q.push(i);
            }
            q.pop();
        }
        return res;
    }
};


int main() {
    Solution s;

    vector<int> subordinates;
    Employee e1;
    e1.id = 1;
    e1.importance = 10;
    subordinates = {2, 3, 4};
    e1.subordinates = subordinates;

    Employee e2;
    e2.id = 2;
    e2.importance = -1;
    e2.subordinates = {};

    Employee e3;
    e3.id = 3;
    e3.importance = -2;
    e3.subordinates = {};

    Employee e4;
    e4.id = 4;
    e4.importance = -3;
    e4.subordinates = {};

    vector<Employee *> employees({&e1, &e2, &e3, &e4});
    cout << s.getImportance(employees, 1) << endl;

    return 0;
}
