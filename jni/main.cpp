#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define MEMINFO_FILE "/proc/meminfo"

string read_meminfo(void) {
  string meminfo_out = "";
  fstream meminfo_file;
  meminfo_file.open(MEMINFO_FILE, ios::in);
  if (meminfo_file.is_open()){
    string line;
    while(getline(meminfo_file, line)){
      meminfo_out += line + "\n";
    }
    meminfo_file.close();
  }
  return meminfo_out;
}

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

unordered_map<string, int> vec2dict(vector<std::string> lines) {
  unordered_map<string, int> m;

  for (size_t i = 0; i < lines.size(); i++) {
    // key is the very first token ending with an ':'
    std::size_t pos = lines[i].find(':');
    string key = lines[i].substr(0, pos);

    // val is surrounded by whitespace and ends with unit characters (e.g., kB)
    string val = lines[i].substr(pos+1, lines[i].length() - (pos+1) - 2 );
    m.insert(std::pair<string, int>(key, stoi(val)));
  }
  return m;
}

int main(int argc, char **argv) {
  string meminfo_out = read_meminfo();
  vector<std::string> lines = split(meminfo_out, '\n');
  unordered_map<string, int> m = vec2dict(lines);
  /*
  for (auto it = m.begin(); it != m.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  */
  cout << "MemTotal: " << m["MemTotal"] << endl;
  cout << "MemAvailable: " << m["MemAvailable"] << endl;
  return 0;
}
