#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

//constructor
Process::Process(int pid): pid_(pid){}

// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const {
  //extract numbers from /proc/[pid]/stat
  std::tuple<long, long, long, long> processTimes = LinuxParser::ActiveJiffies(pid_);
  unsigned long uTime = std::get<0>(processTimes);
  unsigned long sTime = std::get<1>(processTimes);
  long cuTime = std::get<2>(processTimes);
  long csTime = std::get<3>(processTimes);
  
  //calculate cpu usage of process, source https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
  return static_cast<float>(uTime + sTime + cuTime + csTime)/static_cast<float>(LinuxParser::UpTime() - LinuxParser::UpTime(pid_));
}

// TODO: Return the command that generated this process
string Process::Command() const { return LinuxParser::Command(pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() const { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() const { return LinuxParser::User(pid_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const{ return LinuxParser::UpTime() - LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return stoi(this->Ram()) > stoi(a.Ram()) ? true : false; }