#include <bits/stdc++.h>

using namespace std;

string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

string dec_to_B(long long int N, int B) {
    if (!N) return "";
    else return dec_to_B(N/B, B) + symbols[N%B];
}

int main() {
    
}
