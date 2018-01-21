#include <iostream>
#include <string>
// #include<bits/stdc++.h>

using std::string;
using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

int edit_distance(const string &str1, const string &str2, int length1, int length2) {

  // table to hold results of subproblems
  int table[length1 + 1][length2 + 1];

  for (int i = 0; i <= length1; i++) {
    for (int j = 0; j <= length2; j++) {
      // condition where first string is empty, then simply insert characters of second string
      if (i == 0) {
        table[i][j] = j;
      }
      // condition where second string is empty, then simply remove all chars of second string
      else if (j == 0) {
        table[i][j] = i;
      }
      // if last chars of both strings are the same, ignore last ones and get count for remaining strings
      else if (str1[i - 1] == str2[j - 1]) {
        table[i][j] = table[i - 1][j - 1];
      }
      else {
        table[i][j] = 1 + min(table[i][j-1], table[i-1][j], table[i-1][j-1]);
      }
    }
  }

  return table[length1][length2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2, str1.length(), str2.length()) << std::endl;
  return 0;
}
