#include "Lingo.hpp"
#include <assert.h>

Lingo::Lingo()
	: m_languages(1u)
{
}

std::size_t Lingo::addLanguage(const bool makeCurrent)
{
	m_languages.emplace_back();
	if (makeCurrent)
		m_currentLanguage = m_languages.size() - 1u;
	return m_languages.size() - 1u;
}

bool Lingo::setLanguage(const std::size_t languageIndex)
{
	assert(languageIndex < m_languages.size()); // languageIndex must be valid index
	if (languageIndex >= m_languages.size())
		return false;
	m_currentLanguage = languageIndex;
	return true;
}

bool Lingo::setString(const std::string& key, const std::string& string, const std::size_t languageIndex)
{
	assert(languageIndex < m_languages.size()); // languageIndex must be valid index
	if (languageIndex >= m_languages.size())
		return false;
	m_languages[languageIndex][key] = string;
	return true;
}

bool Lingo::setStrings(const std::vector<std::pair<std::string, std::string>>& data)
{
	bool fail{ false };
	for (auto& pair : data)
	{
		if (!setString(pair.first, pair.second, m_currentLanguage))
			fail = true;
	}
	return !fail;
}

bool Lingo::setStrings(const std::vector<std::pair<std::size_t, std::pair<std::string, std::string>>>& data)
{
	bool fail{ false };
	for (auto& set : data)
	{
		if (set.first >= m_languages.size())
		{
			fail = true;
			continue;
		}
		m_languages[set.first][set.second.first] = set.second.second;
	}
	return !fail;
}

std::string Lingo::get(const std::string& key, const std::size_t languageIndex)
{
	assert(languageIndex < m_languages.size()); // languageIndex must be valid index
	if (languageIndex >= m_languages.size())
		return "";
	else if (m_languages[languageIndex].count(key))
		return m_languages[languageIndex][key];
	else if (m_languages[0].count(key))
		return m_languages[0][key];
	else
		return "";
}
