#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:
  void log(const std::string &message) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "[LOG] " << message << std::endl;
  }

private:
  std::mutex mutex_;
};

#endif // LOGGER_H
