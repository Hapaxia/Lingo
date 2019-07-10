#ifndef LINGO_LINGO_HPP
#define LINGO_LINGO_HPP

#include <string>
#include <vector>
#include <unordered_map>

template <class KeyT = std::string>
class Lingo
{
public:
	Lingo();

	std::size_t addLanguage(bool makeCurrent = true);
	bool setLanguage(std::size_t languageIndex);
	std::size_t getCurrentLanguage() const;
	std::size_t getNumberOfLanguages() const;
	bool setString(const KeyT& key, const std::string& string);
	bool setString(const KeyT& key, const std::string& string, std::size_t languageIndex);
	bool setStrings(const std::vector<std::pair<KeyT, std::string>>& strings); // first in pair is key, second is string
	bool setStrings(const std::vector<std::pair<std::size_t, std::pair<KeyT, std::string>>>& strings); // first in inner pair is key, second is string. first in outer pair is languageIndex and second is inner pair.
	std::string get(const KeyT& key);
	std::string get(const KeyT& key, std::size_t languageIndex);

private:
	using Language = std::unordered_map<KeyT, std::string>;
	std::vector<Language> m_languages;
	std::size_t m_currentLanguage;
};

#include "Lingo.inl"
#endif // LINGO_LINGO_HPP
