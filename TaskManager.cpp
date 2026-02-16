#include "TaskManager.h"
#include <exception>

TaskManager::TaskManager() = default;

void TaskManager::addTask(std::unique_ptr<ITask> task) {
    tasks_.push_back(std::move(task));
}

void TaskManager::executeAll() {
    std::vector<std::future<void>> futures;

    for (auto& task : tasks_) {
        futures.push_back(std::async(std::launch::async,
            [this, &task]() {
                try {
                    logger_.log("Starting task: " + task->name());
                    TaskResult result = task->execute();

                    {
                        std::lock_guard<std::mutex> lock(resultsMutex_);
                        results_[task->name()] = result;
                    }

                    logger_.log("Finished task: " + task->name());
                }
                catch (const std::exception& ex) {
                    logger_.log("Error in task " + task->name() + ": " + ex.what());
                }
            }
        ));
    }

    for (auto& f : futures) {
        f.get();
    }
}

const std::map<std::string, TaskResult>& TaskManager::getResults() const {
    return results_;
}
