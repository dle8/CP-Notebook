#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

/*
<SRM 153 Tutorial>
The problem asks you to evaluate the probability that a collision will occur in each implementation and return the
difference between the two. It turns out that it is easier to evaluate the probability that there will not be a
collision, and since the difference is the same either way, we will do this. The trick to figuring out how to evaluate
the probabilities is to realize that you can specify that the IDs be assigned in any order that is convenient.

No memory:
First, let sum be the sum of the number of IDs assigned by all components, and ids be the total number of IDs. Without
any loss of generality, we can assume that the IDs are all assigned one at a time in some order, and since the
components have no memory, each assignment is identical to each other assignment. Clearly, the probability that the
first ID will not collide with another ID is 1. The next ID to be assigned, however, has a probability of (ids-1)/ids of
not colliding with the first ID, since there are (ids-1) IDs that don't cause a collision, and ids IDs total, each of
which has an equal probability of being assigned to the second client. Thus, in general, the probability that the ith
(starting at zero) ID to be assigned will not collide is (ids-i)/ids . Now, since each ID must be unique for there to be
no collision, we can simply multiply all of these probabilities together to get the overall probability that there is no
collision. Thus, for the final probability is (ids-0)/ids * (ids-1)/ids * (ids-2)/ids * ... * (ids-sum+1)/ids.

With mem:
In this case, we can safely assume that the IDs are assigned one component at a time (since the probability is the same,
no matter what the order). Let comp[i] represent the number of IDs assigned by the ith component. So, for the first
component, the probability is either 0 (if more IDs are assigned than there are total) or 1. For the second component,
there are ids-comp[0] IDs that have not yet been assigned, so the first ID assigned has a probability of
(ids-comp[0])/ids of not causing a collision. The next ID assigned by the second component has a probability of
(ids-comp[0]-1)/(ids-1) of not causing a collision, since there are (ids-comp[0]-1) available IDs and (ids-1) that the
component might assign. In general, the probability that the ith ID (starting at zero) assigned by the second component
will not cause a collision is (ids-comp[0]-i)/(ids-i) . The third component is similar, except we replace comp[0] with
(comp[0]+comp[1]) in our equations, and so on for the rest of the components. Again, we can take the product of all the
probabilities to get the final probability.
 * */

class Collision {
public:
    double probability(vector<int> assignments, int ids) {
        ld no_mem = 1.0;
        int total = accumulate(assignments.begin(), assignments.end(), 0);
        for (int i = 0; i < total; ++i) {
            no_mem *= (double)(ids - i) / (double)ids;
        }

        ld with_mem = ((total > ids) ? 0.0 : 1.0);
        if (with_mem == 1.0) {
            for (int num_ass = 1; num_ass < assignments.size(); ++num_ass) {
                int cur_total = accumulate(assignments.begin(), assignments.begin() + num_ass, 0);
                for (int i = 0; i < assignments[num_ass]; ++i) {
                    with_mem *= (double)(ids - cur_total - i) / (double)(ids - i);
                }
            }
        }
        return with_mem - no_mem;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> assignments;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        assignments.push_back(x);
    }
    int ids; cin >> ids;
    Collision c;
    cout << fixed << c.probability(assignments, ids);
    return 0;
}