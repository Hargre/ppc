#include <bits/stdc++.h>

using namespace std;

priority_queue<int> gr;
priority_queue<int> bl;
vector<pair<int, int>> bat;

int main() {
    int n;
    int bn, sg, sb;

    cin >> n;

    while (n--) {

        cin >> bn >> sg >> sb;
        for (int i = 0; i < sg; i++) {
            int l;
            cin >> l;
            gr.push(l);
        }

        for (int i = 0; i < sb; i++) {
            int l;
            cin >> l;
            bl.push(l);
        }

        while (!gr.empty() && !bl.empty()) {
            bat.clear();
            for (int i = 0; i < bn; i++) {
                if (gr.empty() || bl.empty()) break;
                int a = gr.top();
                gr.pop();
                int b = bl.top();
                bl.pop();
                bat.push_back(make_pair(a, b));
            }

            for (auto bt : bat) {
                if (bt.first - bt.second > 0) gr.push(bt.first - bt.second);
                else if (bt.first - bt.second < 0) bl.push(bt.second - bt.first);
            }
        }

        if (gr.empty() && bl.empty()) {
            cout << "green and blue died" << endl;
        } else if (gr.empty()) {
            cout << "blue wins" << endl;
            while (!bl.empty()) {
                cout << bl.top() << endl;
                bl.pop();
            }
        } else if (bl.empty()) {
            cout << "green wins" << endl;
            while (!gr.empty()) {
                cout << gr.top() << endl;
                gr.pop();
            }
        }

        if (n) cout << endl;
    }

    return 0;
}