#include "../inc/DatabaseQueryTask.h"
#include <sstream>

DatabaseQueryTask::DatabaseQueryTask(std::string name,
                                     std::string query,
                                     int recordCount)
    : name_(std::move(name)),
      query_(std::move(query)),
      recordCount_(recordCount) {}

TaskResult DatabaseQueryTask::execute() {
    std::ostringstream result;
    result << "Query executed: " << query_ 
           << " | Records fetched: " << recordCount_;
    return result.str();
}

std::string DatabaseQueryTask::name() const {
    return name_;
}
