#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector< vector<int> >& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (int j = 0; j < edges.size(); ++j) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if (maxProb[u] * prob > maxProb[v]) {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true;
                }
                if (maxProb[v] * prob > maxProb[u]) {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        return maxProb[end_node];
    }
};

int main()
{
  Solution solution;

  int edgesArray[][2] = {{0, 1}, {1, 2}, {0, 2}};
  vector< vector<int> > edges(3, vector<int>(2));
  for (int i = 0; i < 3; ++i) {
      edges[i][0] = edgesArray[i][0];
      edges[i][1] = edgesArray[i][1];
  }

  double succProbArray[] = {0.5, 0.5, 0.2};
  vector<double> succProb(succProbArray, succProbArray + 3); 

  cout << solution.maxProbability(3, edges, succProb, 0, 2) << endl;

  return 0;
}
