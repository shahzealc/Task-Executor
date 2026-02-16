#include "../inc/ComputationTask.h"

ComputationTask::ComputationTask(std::string name, int a, int b)
    : name_(std::move(name)), a_(a), b_(b) {}

TaskResult ComputationTask::execute() {
  int result = a_ + b_;
  return result;
}

std::string ComputationTask::name() const { return name_; }
