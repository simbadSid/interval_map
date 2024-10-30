#include "file_parser.h"


FileParser::FileParser(const std::string &file_relative_path)
{
    if (!file_relative_path.empty())
    {
        this->file.open(PROJECT_FILE_PATH(file_relative_path), std::ios::in);
        assert(this->file.is_open());
    }
}

FileParser::~FileParser()
{
    if (this->file.is_open())
        this->file.close();
}

std::list<std::string> FileParser::nextLine()
{
    std::list<std::string> result;
    std::string line, tmp;

    // Read the next line
    if (this->file.is_open())
        std::getline(this->file, line);
    else
        std::getline(std::cin, line);

    // Transform the line to a vector
    std::stringstream ss(line);
    while (std::getline(ss, tmp, ' '))
    {
        result.push_back(tmp);
    }

    return result;
}
