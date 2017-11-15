#include <bits/stdc++.h>

using namespace std;

using ui = unsigned int;

int main() {
    ios_base::sync_with_stdio(false);

    ui n, l, u, sol;

    while (cin >> n >> l >> u) {
        sol = 0;

        for (int i = 1; i <= 32; i++) {
            ui is_set = (n & (1 << (32 - i)));

            if (is_set) {
                ui aux = is_set - 1;
                aux |= sol;

                if (aux < l) sol |= is_set;
            } else {
                ui aux = sol;
                aux |= (1 << (32 - i));

                if (aux <= u) sol = aux;
            }
        }

        cout << sol << endl;
    }


    return 0;
}