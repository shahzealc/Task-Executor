#ifndef COMPUTATION_TASK_H
#define COMPUTATION_TASK_H

#include "ITask.h"
#include <string>

class ComputationTask : public ITask {
public:
  ComputationTask(std::string name, int a, int b);

  TaskResult execute() override;

  std::string name() const override;

private:
  std::string name_;
  int a_;
  int b_;
};

#endif // COMPUTATION_TASK_H
