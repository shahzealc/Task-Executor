#ifndef ITASK_H
#define ITASK_H

#include <string>
#include "types.h"

class ITask {
public:
    virtual TaskResult execute() = 0;
    virtual std::string name() const = 0;
    virtual ~ITask() = default;
};

#endif // ITASK_H
