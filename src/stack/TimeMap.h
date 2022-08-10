#ifndef NEETCODE_SRC_STACK_TIMEMAP_H_
#define NEETCODE_SRC_STACK_TIMEMAP_H_

#include <map>
#include <string>
#include <unordered_map>

class TimeMap {
 private:
  std::unordered_map<std::string, std::map<int, std::string>> data;

 public:
  TimeMap();
  void set(std::string key, std::string value, int timestamp);
  std::string get(const std::string& key, int timestamp);
};

#endif  // NEETCODE_SRC_STACK_TIMEMAP_H_
