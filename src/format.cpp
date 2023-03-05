#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hours = seconds / 3600;
  int minutes = (seconds - hours * 3600) / 60;
  int secs = seconds - hours * 3600 - minutes * 60;
  string secsStr = std::to_string(secs);
  secsStr.insert(0, 2 - secsStr.length(), '0');
  string minStr = std::to_string(minutes);
  minStr.insert(0, 2 - minStr.length(), '0');
  string hoursStr = std::to_string(hours);
  hoursStr.insert(0, 2 - hoursStr.length(), '0');
  return hoursStr + ":" + minStr + ":" + secsStr;
}