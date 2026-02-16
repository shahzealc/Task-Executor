#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <variant>

using TaskResult = std::variant<int, std::string, double>;

#endif // TYPES_H
