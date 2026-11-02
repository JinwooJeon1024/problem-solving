#include <bits/stdc++.h>
using namespace std;

// ======================================
// Problem 1. Merge Sort
// ======================================

void mergeSort(vector<int>& v) {
    // TODO
}


// ======================================
// Problem 2. Quick Sort
// ======================================

int partition(vector<int>& v, int st, int en) {
  int index = st;
  int start = v[st];

  for(int i = st+1; i < en; i++) {
    if(v[i] <= start) {
      index++;
      swap(v[index], v[i]);
    }
  }

  swap(v[st], v[index]);
  return index;
}

void quick(vector<int>& v, int st, int en) {
  if(en - st <= 1) return;

  int pivot = partition(v, st, en);

  quick(v, st, pivot);
  quick(v, pivot+1, en);
}

void quickSort(vector<int>& v) {
  quick(v, 0, v.size());
}


// ======================================
// Problem 3. Heap Sort
// ======================================

void heapSort(vector<int>& v) {
    // TODO
}


// ======================================
// Test Code (수정하지 않아도 됨)
// ======================================

void testSort(const string& name, void (*fn)(vector<int>&)) {
    vector<vector<int>> tests = {
        {},
        {1},
        {2, 1},
        {1, 2},
        {3, 1, 2},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {5, 5, 5, 5, 5},
        {3, 1, 3, 2, 1, 2},
        {-5, 10, 0, -3, 7, -10},
        {100, -100, 50, -50, 0}
    };

    // Random tests
    mt19937 rng(42);

    for (int t = 0; t < 200; t++) {
        int n = rng() % 101;
        vector<int> v(n);

        for (int& x : v) {
            x = static_cast<int>(rng() % 101) - 50;
        }

        tests.push_back(v);
    }

    // Larger tests
    vector<int> ascending(1000);
    iota(ascending.begin(), ascending.end(), 0);

    vector<int> descending = ascending;
    reverse(descending.begin(), descending.end());

    tests.push_back(ascending);
    tests.push_back(descending);

    for (int t = 0; t < (int)tests.size(); t++) {
        vector<int> actual = tests[t];
        vector<int> expected = tests[t];

        sort(expected.begin(), expected.end());

        fn(actual);

        if (actual != expected) {
            cout << "[FAIL] " << name
                 << " - Test " << t << "\n";

            cout << "Input: ";
            for (int x : tests[t]) cout << x << " ";

            cout << "\nExpected: ";
            for (int x : expected) cout << x << " ";

            cout << "\nActual: ";
            for (int x : actual) cout << x << " ";

            cout << "\n";
            return;
        }
    }

    cout << "[PASS] " << name
         << " - All " << tests.size()
         << " tests passed!\n";
}

int main() {
    // testSort("Merge Sort", mergeSort);

    // Merge Sort 완료 후 주석 해제
    testSort("Quick Sort", quickSort);

    // Quick Sort 완료 후 주석 해제
    // testSort("Heap Sort", heapSort);

    return 0;
}
