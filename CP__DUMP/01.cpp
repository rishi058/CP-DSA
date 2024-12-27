#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> operations(q);
        for (int i = 0; i < q; ++i) {
            cin >> operations[i];
        }

        unordered_set<int> possible_joker_positions;
        possible_joker_positions.insert(m);

        vector<int> result(q);
        for (int i = 0; i < q; ++i) {
            int card_position = operations[i];

            // Calculate the potential new joker positions after moving the card
            unordered_set<int> new_positions;
            for (int pos : possible_joker_positions) {
                if (pos < card_position) {
                    new_positions.insert(pos);
                    new_positions.insert(pos + 1);
                } else if (pos > card_position) {
                    new_positions.insert(pos);
                    new_positions.insert(pos - 1);
                } else {
                    // Joker is on the moved card
                    new_positions.insert(1);
                    new_positions.insert(n);
                }
            }

            possible_joker_positions = new_positions;
            result[i] = possible_joker_positions.size();
        }

        for (int i = 0; i < q; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}