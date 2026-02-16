#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "ITask.h"
#include "Logger.h"
#include <vector>
#include <map>
#include <memory>
#include <future>
#include <mutex>

class TaskManager {
public:
    TaskManager();

    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    void addTask(std::unique_ptr<ITask> task);

    void executeAll();

    const std::map<std::string, TaskResult>& getResults() const;

private:
    std::vector<std::unique_ptr<ITask>> tasks_;
    std::map<std::string, TaskResult> results_;
    std::mutex resultsMutex_;
    Logger logger_;
};

#endif // TASK_MANAGER_H
