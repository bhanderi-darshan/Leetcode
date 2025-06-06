#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent;

    // Find operation with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Returns the lexicographically smallest equivalent string
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);

        // Initialize each character as its own parent
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        // Union characters from s1 and s2
        for (int i = 0; i < (int)s1.size(); ++i) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            int pu = find(u);
            int pv = find(v);

            // Keep the smaller character as parent
            if (pu < pv)
                parent[pv] = pu;
            else
                parent[pu] = pv;
        }

        // Convert baseStr using smallest equivalents
        string result;
        for (char ch : baseStr) {
            char mapped = (char)(find(ch - 'a') + 'a');
            result.push_back(mapped);
        }

        return result;
    }
};