#include "../inc/FileWriteTask.h"
#include <fstream>
#include <stdexcept>

FileWriteTask::FileWriteTask(std::string name, std::string filename,
                             std::string content)
    : name_(std::move(name)), filename_(std::move(filename)),
      content_(std::move(content)) {}

TaskResult FileWriteTask::execute() {
  std::ofstream file(filename_);
  if (!file)
    throw std::runtime_error("Failed to open file: " + filename_);

  file << content_;
  file.close();

  return std::string("Wrote to file: " + filename_);
}

std::string FileWriteTask::name() const { return name_; }
