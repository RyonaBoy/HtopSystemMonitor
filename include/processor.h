#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  int prevIdle{0}, prevIoWait{0}, prevNonIdle{0}, prevUser{0}, prevNice{0}, prevSystem{0}, prevIrq{0}, prevSoftIrq{0}, prevSteal{0}, prevTotal{0};
};

#endif