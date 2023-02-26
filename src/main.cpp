#include "ncurses_display.h"
#include "system.h"

int main() {
  System system;
  //std::vector<Process> tmp = system.Processes();
  //tmp[0].CpuUtilization();
  
  NCursesDisplay::Display(system);
}