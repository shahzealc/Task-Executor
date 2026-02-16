#ifndef DATABASE_QUERY_TASK_H
#define DATABASE_QUERY_TASK_H

#include "ITask.h"
#include <string>

class DatabaseQueryTask : public ITask {
public:
    DatabaseQueryTask(std::string name,
                      std::string query,
                      int recordCount);

    TaskResult execute() override;

    std::string name() const override;

private:
    std::string name_;
    std::string query_;
    int recordCount_;
};

#endif // DATABASE_QUERY_TASK_H
