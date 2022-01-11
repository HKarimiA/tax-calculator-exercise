#include "LocalFileReader.h"
#include <fstream>
#include <string>

LocalFileReader::LocalFileReader(std::string_view filePath) : _filePath{ filePath }
{
}

std::optional<std::vector<std::string>> LocalFileReader::getLines() const
{
	return std::nullopt;
}
