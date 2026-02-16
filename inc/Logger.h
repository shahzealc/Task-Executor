#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:

  static Logger &instance() {
    static Logger logger;
    return logger;
  }
  
  void log(const std::string &message) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "[LOG] " << message << std::endl;
  }

  Logger() = default;
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

private:
  std::mutex mutex_;
};

#endif // LOGGER_H
