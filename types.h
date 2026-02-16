#ifndef TYPES_H
#define TYPES_H

#include <variant>
#include <string>

using TaskResult = std::variant<int, std::string, double>;

#endif // TYPES_H
