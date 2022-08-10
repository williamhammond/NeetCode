#include "TimeMap.h"

#include <string>

TimeMap::TimeMap() = default;

void TimeMap::set(std::string key, std::string value, int timestamp) {
  data[key].insert({timestamp, value});
}

std::string TimeMap::get(const std::string& key, int timestamp) {
  auto it = data[key].upper_bound(timestamp);
  return it == data[key].begin() ? "" : prev(it)->second;
}
