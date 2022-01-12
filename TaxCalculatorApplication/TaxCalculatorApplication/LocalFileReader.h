#pragma once
#include <string_view>
#include <vector>
#include <optional>

// NOTE: This class reads a local text file
class LocalFileReader
{
public:
	LocalFileReader(std::string_view filePath);
	std::optional<std::vector<std::string>> getLines() const;

private:
	const std::string _filePath;
};