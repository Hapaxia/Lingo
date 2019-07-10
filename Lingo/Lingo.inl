#ifndef LINGO_LINGO_INL
#define LINGO_LINGO_INL

#include "Lingo.hpp"
#include <assert.h>

template <class KeyT>
Lingo<KeyT>::Lingo()
	: m_languages(1u)
{
}

template <class KeyT>
std::size_t Lingo<KeyT>::addLanguage(const bool makeCurrent)
{
	m_languages.emplace_back();
	if (makeCurrent)
		m_currentLanguage = m_languages.size() - 1u;
	return m_languages.size() - 1u;
}

template <class KeyT>
bool Lingo<KeyT>::setLanguage(const std::size_t languageIndex)
{
	assert(languageIndex < m_languages.size()); // languageIndex must be valid index
	if (languageIndex >= m_languages.size())
		return false;
	m_currentLanguage = languageIndex;
	return true;
}

template <class KeyT>
bool Lingo<KeyT>::setString(const KeyT& key, const std::string& string, const std::size_t languageIndex)
{
	assert(languageIndex < m_languages.size()); // languageIndex must be valid index
	if (languageIndex >= m_languages.size())
		return false;
	m_languages[languageIndex][key] = string;
	return true;
}

template <class KeyT>
bool Lingo<KeyT>::setStrings(const std::vector<std::pair<KeyT, std::string>>& data)
{
	bool fail{ false };
	for (auto& pair : data)
	{
		if (!setString(pair.first, pair.second, m_currentLanguage))
			fail = true;
	}
	return !fail;
}

template <class KeyT>
bool Lingo<KeyT>::setStrings(const std::vector<std::pair<std::size_t, std::pair<KeyT, std::string>>>& data)
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

template <class KeyT>
std::string Lingo<KeyT>::get(const KeyT& key, const std::size_t languageIndex)
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

template <class KeyT>
inline std::size_t Lingo<KeyT>::getCurrentLanguage() const
{
	return m_currentLanguage;
}

template <class KeyT>
inline std::size_t Lingo<KeyT>::getNumberOfLanguages() const
{
	return m_languages.size();
}

template <class KeyT>
inline bool Lingo<KeyT>::setString(const KeyT& key, const std::string& string)
{
	return setString(key, string, m_currentLanguage);
}

template <class KeyT>
inline std::string Lingo<KeyT>::get(const KeyT& key)
{
	return get(key, m_currentLanguage);
}

#endif // LINGO_LINGO_INL
