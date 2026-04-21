// Okay, let me break this down from scratch — the "aha moment" for this problem, the intuition, then a step-by-step visual you can interact with.

// ---

// **The core insight that unlocks everything:**

// The key observation is that `allowedSwaps` is transitive. If you can swap index 0↔1 and also 1↔2, then you can get any element to any of those three positions. This means swaps don't describe individual pairs — they describe **groups of indices** that can freely share their elements.

// So the question becomes: within each such group, how many elements can you match against the corresponding target positions? This is exactly Union-Find territory. Once you see that, the algorithm is almost obvious.

// **The mental model in 3 steps:**
// 1. Use Union-Find to group all indices that are connected via allowed swaps.
// 2. For each group, collect the multiset of `source` values available at those indices.
// 3. For each index, check if `target[i]` exists in that group's pool. If yes — consume it (great match!). If no — that's a +1 to hamming distance.---

// Greedy matching within each group
// For each group, build a frequency map of source values. Then for each index in the group, check if target[i] is available.
// Group A — indices {0, 1}
// Source pool
// 1 ×12 ×1
// Matching
// target[0]=2 → found 2 ✓ (consume)
// target[1]=1 → found 1 ✓ (consume)
// Hamming contribution: 0
// Group B — indices {2, 3}
// Source pool
// 3 ×14 ×1
// Matching
// target[2]=4 → found 4 ✓ (consume)
// target[3]=5 → not found ✗ (+1 distance)
// Hamming contribution: 1

// Why greedy works: within a group, any unmatched element in source can never help any target position outside the group. So we just greedily consume source values when we find a match. Order within the group doesn't matter — just check if the value exists in the pool.

// **Thought process you should train yourself to have:**

// When you see "allowed swaps between indices", your brain should immediately ping — *this is a graph problem on indices, not values*. Indices = nodes, swaps = edges. The moment you think "can elements reach each other transitively?" — that's Union-Find. BFS/DFS also work, but Union-Find is the classic fit.

// The second click is realizing that once you know the groups, the problem collapses into a much simpler subproblem: **within each group, can I match enough source values to target values?** This is just a frequency-map check — no complex reordering needed. The order within the group is irrelevant because we can achieve any permutation via swaps.

// **Complexity:** O(n · α(n)) where α is the inverse Ackermann function from Union-Find — essentially O(n) for all practical purposes.

// watch this video - https://www.youtube.com/watch?v=r0s0BtmTxWk

class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int a,int b){
        parent[find(a)]=find(b);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);

        for(auto& swap: allowedSwaps){
            unite(swap[0],swap[1]);
        }
        int hammingDist = 0;

        //Group source values by their component
        unordered_map<int, unordered_map<int,int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)][source[i]]++;
        }
        for(int i=0;i<n;i++){
            int root = find(i);
            auto& freq= groups[root];
            if(freq.count(target[i]) && freq[target[i]]>0){
                freq[target[i]]--;
            }else{
                hammingDist++;
            }
        }
        return hammingDist;
    }
};