#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

//問題は158.cc
//
vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while(getline(ss, buffer, sep)) {
        v.push_back(buffer);
    }
    return v;
}

int main()
{ int nline;
  string ncommand;
  vector<string> comsplit, present;
  scanf("%d", &nline);

  for (int i = 0; i < nline; i++) {
    cin >> ncommand;
    if (ncommand == "pwd") {
      string final = "/";
      for (int i = 0; i < present.size(); i++) {
        final += present[i] + "/";
      }
      cout << final << endl;
    } else if (ncommand == "cd") {
      cin >> ncommand;
      comsplit = split(ncommand, '/');
      int i = 0;
      if (comsplit[0] == "") {
        present.clear();
        i = 1;
      }
      for (; i < comsplit.size(); i++) {
        if (comsplit[i] != "..") {
          present.push_back(comsplit[i]);
        } else {
          present.pop_back();
        }
      }
    }
  }
  return 0;
}
