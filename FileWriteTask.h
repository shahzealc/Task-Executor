#ifndef FILE_WRITE_TASK_H
#define FILE_WRITE_TASK_H

#include "ITask.h"
#include <string>

class FileWriteTask : public ITask {
public:
    FileWriteTask(std::string name,
                  std::string filename,
                  std::string content);

    TaskResult execute() override;

    std::string name() const override;

private:
    std::string name_;
    std::string filename_;
    std::string content_;
};

#endif // FILE_WRITE_TASK_H
