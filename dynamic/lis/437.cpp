/*
 * Tower of Babylon - A reaaally forced LIS. Get all permutations of blocks,
 * Sort the fuck out of them, compare x and y axis, add z axis on sum.
 */ 

#include <bits/stdc++.h>

#define MAX 1000

using namespace std;

int memo[MAX];

typedef struct block {
    int x, y, z;

    block(int a, int b, int c) {
        x = a; 
        y = b;
        z = c;
    }
} block;

vector<block> blocks;

bool comp(block a, block b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.z < b.z;
}

int lis(int n) {
    int max_lis = 0;
    
    for (int i = 0; i < n; i++) {
        memo[i] = blocks[i].z;

        for (int j = i - 1; j >= 0; j--) {
            if (blocks[j].x < blocks[i].x && blocks[j].y < blocks[i].y) {
                memo[i] = max(memo[i], memo[j] + blocks[i].z);
            }
        }

        max_lis = max(max_lis, memo[i]);
    }

    return max_lis;
}

int main() {
    int n;
    int c = 1;

    cin >> n;
    
    while (n != 0) {
        memset(memo, 0, sizeof memo);
        blocks.clear();

        int x, y, z;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            
            blocks.push_back(block(x, y, z));
            blocks.push_back(block(x, z, y));
            blocks.push_back(block(y, x, z));
            blocks.push_back(block(y, z, x));
            blocks.push_back(block(z, y, x));
            blocks.push_back(block(z, x, y));
        }

        sort(blocks.begin(), blocks.end(), comp);

        cout << "Case " << c << ": maximum height = " << lis(blocks.size()) << endl;
        c++;

        cin >> n;
    }

    return 0;
}