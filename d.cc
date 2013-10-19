#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void work(string p1, string p2, string c);
vector<string> rh(string p1, string p2, string c);

int main() {
  
}

void work(string p1, string p2, string c) {
  vector<string> rhs = rh(p1, p2, c);

  for(int i=0; i<rhs.size(); i++) {
    cout << rhs[i] << endl;
  }
}

vector<string> rh_gen(string s) {
  vector<string> result;

  if(s == "-") {
    result.push_back("--");
  } else if(s == "+") {
    result.push_back("++");
    result.push_back("+-");
  }

  return result;
}

bool good(string p1, string p2, string c) {
  map<char, int> from, to;
  from[p1.at(0)]++;
  from[p1.at(1)]++;
  from[p2.at(0)]++;
  from[p2.at(1)]++;
  to[c.at(0)]++;
  to[c.at(1)]++;

  if(from[c.at(0)] < to[c.at(0)])
    return false;
  if(from[c.at(1)] < to[c.at(1)])
    return false;
  
  return true;
}

vector<string> rh(string p1, string p2, string c) {
  vector<string> result;
  
  if(p1 == "") {
    swap(p1, p2);
  }

  vector<string> p1s = rh_gen(p1);
  vector<string> p2s = rh_gen(p2);
  vector<string> cs = rh_gen(c);

  map<string, string> rh_short;
  rh_short["++"] = "+";
  rh_short["+-"] = "+";
  rh_short["--"] = "-";
  

  string cands[3] = {"++", "+-", "--"};
  map<string, bool> result_map;
  if(p2 == "") {
    for(int i=0; i<3; i++) {
      for(int j=0; j<p1s.size(); j++) {
	for(int k=0; k<cs.size(); k++) {
	  if(good(cands[i], p1s[j], cs[k])) {
	    result_map[rh_short[cands[i]]] = true;
	  }
	}
      }
    }
  } else {
    for(int i=0; i<3; i++) {
      for(int j=0; j<p1s.size(); j++) {
	for(int k=0; k<p2s.size(); k++) {
	  if(good(p1s[j], p2s[k], cands[i])) {
	    result_map[rh_short[cands[i]]] = true;
	  }
	}
      }
    }
  }

  for(map<string, bool>::iterator it = result_map.begin(); it != result_map.end(); it++) {
    if(result_map[it->first]) {
      result.push_back(it->first);
    }
  }
  
  return result;
}
