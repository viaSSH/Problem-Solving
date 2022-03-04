#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

vector<int> nums;
int n;
int maxAns = -1000000000;
int minAns = 1000000000;
// 3
// 3 4 5
// 1 0 1 0

// 2 1 1 1

// 5 4 3 2 1
// 2

void dfs(vector<int> visited,  int sum, int numIdx) {
    if(numIdx == n) {
        // cout << "reach end" << endl;
        if(sum > maxAns) {
            maxAns = sum;
        }
        if(sum < minAns) {
            minAns = sum;
        }
        return;
    }
    if(visited[0] > 0) {
        visited[0]--;
        dfs(visited, sum + nums[numIdx], numIdx+1);
        visited[0]++;
    }

    if(visited[1] > 0) {
        visited[1]--;
        dfs(visited, sum - nums[numIdx], numIdx+1);
        visited[1]++;
    }

    if(visited[2] > 0) {
        visited[2]--;
        dfs(visited, sum * nums[numIdx], numIdx+1);
        visited[2]++;
    }

    if(visited[3] > 0) {
        visited[3]--;
        dfs(visited, sum / nums[numIdx], numIdx+1);
        visited[3]++;
    }

}

int main() {
    int answer = 0;

    
    cin >> n;
    
    vector<int> ops(4,0);
    vector<int> visited(4,0);
    for(int i=0 ; i<n ; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);

    }
    cin >> ops[0] >> ops[1] >> ops[2] >> ops[3] ;
    for(int i=0 ; i<4 ; i++) {
        visited[i] = ops[i];
    }
    dfs(visited, nums[0], 1);
    cout << maxAns << endl;
    cout << minAns << endl;
    return 0;
}