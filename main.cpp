#include <iostream>
#include <memory>

#include "inc/TaskManager.h"
#include "inc/ComputationTask.h"
#include "inc/SleepTask.h"
#include "inc/FileWriteTask.h"
#include "inc/DatabaseQueryTask.h"

int main() {
    try {
        TaskManager manager;

        manager.addTask(std::make_unique<ComputationTask>("AdditionTask", 10, 20));
        manager.addTask(std::make_unique<SleepTask>("SleepTask", 2));
        manager.addTask(std::make_unique<FileWriteTask>(
            "FileTask", "output.txt", "Hello from task engine"));
        manager.addTask(std::make_unique<DatabaseQueryTask>(
            "DatabaseTask", "SELECT * FROM users", 150));

        std::cout << "Executing tasks...\n";

        manager.executeAll();

        std::cout << "\nResults:\n";

        for (const auto& [taskName, result] : manager.getResults()) {
            std::visit([&](auto&& value) {
                std::cout << taskName << " => " << value << "\n";
            }, result);
        }

        std::cout << "\nAll tasks completed successfully.\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << "\n";
    }

    return 0;
}
