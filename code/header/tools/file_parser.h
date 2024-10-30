#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <cassert>

#define PROJECT_FILE_PATH(file_relative_path) \
    std::filesystem::path("../") / std::filesystem::path(file_relative_path)


class FileParser
{
    /**
     * @brief Class wrapper to access a file content (including stdin).
     * @param Path to the file to access, or None if accessing stdin. The path is relative to the root of the project
     */

private:
    std::fstream file;

public:
    explicit FileParser(const std::string &file_relative_path="");
    ~FileParser();

    std::list<std::string> nextLine();
};
#endif //FILE_PARSER_H
