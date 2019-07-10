/*


convert to template that allows key type to be customised
make sure that strings can be used with UTF-8
add ability to remove strings
add ability to remove/unload entire language






*/




#ifndef LINGO_LINGO_HPP
#define LINGO_LINGO_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Lingo
{
public:
	Lingo();

	std::size_t addLanguage(bool makeCurrent = true);
	bool setLanguage(std::size_t languageIndex);
	std::size_t getCurrentLanguage() const;
	std::size_t getNumberOfLanguages() const;
	bool setString(const std::string& key, const std::string& string);
	bool setString(const std::string& key, const std::string& string, std::size_t languageIndex);
	bool setStrings(const std::vector<std::pair<std::string, std::string>>& strings); // first string in pair is key, second is string
	bool setStrings(const std::vector<std::pair<std::size_t, std::pair<std::string, std::string>>>& strings); // first string in pair is key, second is string
	std::string get(const std::string& key);
	std::string get(const std::string& key, std::size_t languageIndex);

private:
	using Language = std::unordered_map<std::string, std::string>;
	std::vector<Language> m_languages;
	std::size_t m_currentLanguage;
};

#include "Lingo.inl"
#endif // LINGO_LINGO_HPP
