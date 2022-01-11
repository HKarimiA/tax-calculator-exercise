#pragma once
#include <string_view>
#include <vector>
#include <optional>

class LocalFileReader
{
public:
	LocalFileReader(std::string_view filePath);
	std::optional<std::vector<std::string>> getLines() const;

private:
	const std::string _filePath;
};