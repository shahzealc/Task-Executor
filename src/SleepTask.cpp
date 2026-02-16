#include "../inc/SleepTask.h"
#include <chrono>
#include <thread>

SleepTask::SleepTask(std::string name, int seconds)
    : name_(std::move(name)), seconds_(seconds) {}

TaskResult SleepTask::execute() {
  std::this_thread::sleep_for(std::chrono::seconds(seconds_));
  return std::string("Slept for " + std::to_string(seconds_) + " seconds");
}

std::string SleepTask::name() const { return name_; }
