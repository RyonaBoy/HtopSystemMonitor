#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  //extract numbers from proc/stat
  std::vector<std::string> fields = LinuxParser::CpuUtilization();
  int fieldUser = std::stoi(fields[0]);
  int fieldNice = std::stoi(fields[1]);
  int fieldSystem = std::stoi(fields[2]);
  int fieldIdle = std::stoi(fields[3]);
  int fieldIoWait = std::stoi(fields[4]);
  int fieldIrq = std::stoi(fields[5]);
  int fieldSoftIrq = std::stoi(fields[6]);
  int fieldSteal = std::stoi(fields[7]);
  
  //cpu usage calculation, source https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
  prevIdle = prevIdle + prevIoWait;
  int idle = fieldIdle + fieldIoWait;
  prevNonIdle = prevUser + prevNice + prevSystem + prevIrq + prevSoftIrq + prevSteal;
  int nonIdle = fieldUser + fieldNice + fieldSystem + fieldIrq + fieldSoftIrq + fieldSteal;  
  prevTotal = prevIdle + prevNonIdle;
  int total = idle + nonIdle;
  int totalDiff = total - prevTotal;
  int idleDiff = idle - prevIdle;
  
  //current numbers become previous ones in next iteration
  prevIdle = idle;
  prevIoWait = fieldIoWait;
  prevNonIdle = nonIdle;
  prevUser = fieldUser;
  prevNice = fieldNice;
  prevSystem = fieldSystem;
  prevIrq = fieldIrq;
  prevSoftIrq = fieldSoftIrq;
  prevSteal = fieldSteal;
  prevTotal = total;
  
  return (static_cast<float>(totalDiff) - static_cast<float>(idleDiff))/static_cast<float>(totalDiff);
}