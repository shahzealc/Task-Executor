#ifndef SLEEP_TASK_H
#define SLEEP_TASK_H

#include "ITask.h"
#include <string>

class SleepTask : public ITask {
public:
    SleepTask(std::string name, int seconds);

    TaskResult execute() override;

    std::string name() const override;

private:
    std::string name_;
    int seconds_;
};

#endif // SLEEP_TASK_H
