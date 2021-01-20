// This code references the standard solution from USACO official
// Link to the original solution:
// http://www.usaco.org/current/data/sol_evolution_bronze_open19.html

#include <bits/stdc++.h>
using namespace std;

int n;
int num[30];
vector<string> features[30];
vector<string> dict; // all features mentioned in the input

bool isvalid(int a, int b) {
    // return false if three cases
    //    1. species only with feature a;
    //    2. species only with feature b;
    //    3. species with both feature a and feature b.
    // exist.
    bool onlyina = false;
    bool onlyinb = false;
    bool bothfound = false;

    for (int i = 1; i <= n; i++) {
        bool hasa = false;
        bool hasb = false;
        for (int j = 0; j < features[i].size(); j++) {
            if (features[i][j] == dict[a]) {
                hasa = true;
            }
            if (features[i][j] == dict[b]) {
                hasb = true;
            }
            if (hasa && hasb) break;
        }

        if (hasa && hasb) {
            bothfound = true;
        } else if (hasa) {
            onlyina = true;
        } else if (hasb) {
            onlyinb = true;
        }

        if (bothfound && onlyina && onlyinb) return false;
    }
    return true;
}



int main(void)
{
  	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);

	// input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		for (int j = 1; j <= num[i]; j++) {
			string str;
			cin >> str;
			features[i].push_back(str);

			// push features[i] into dict if it is the feature
			// never shown before
			bool isvisited = false;
			for (int k = 0; k < dict.size(); k++) {
				if (dict[k] == str) {
					isvisited = true;
					break;
				}
			}
			if (!isvisited) {
				dict.push_back(str);
			}
		}
	}

	// consider all combinations of two features,
	// and check if they are valid
	for (int i = 0; i < dict.size() - 1; i++) {
		for (int j = i + 1; j < dict.size(); j++) {
			if (!isvalid(i, j)) {
				cout << "no" << endl;
				return 0;
			}
		}
	}

	cout << "yes" << endl;
	return 0;
}
