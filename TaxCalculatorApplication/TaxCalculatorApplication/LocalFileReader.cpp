#include "LocalFileReader.h"
#include <fstream>
#include <string>

LocalFileReader::LocalFileReader(std::string_view filePath) : _filePath{ filePath }
{
}

std::optional<std::vector<std::string>> LocalFileReader::getLines() const
{
	std::ifstream iFile(_filePath);
	if (iFile.is_open())
	{
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(iFile, line))
			lines.push_back(line);

		iFile.close();
		return lines;
	}
	return std::nullopt;
}