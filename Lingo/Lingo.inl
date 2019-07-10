#ifndef LINGO_LINGO_INL
#define LINGO_LINGO_INL

inline std::size_t Lingo::getCurrentLanguage() const
{
	return m_currentLanguage;
}

inline std::size_t Lingo::getNumberOfLanguages() const
{
	return m_languages.size();
}

inline bool Lingo::setString(const std::string& key, const std::string& string)
{
	return setString(key, string, m_currentLanguage);
}

inline std::string Lingo::get(const std::string& key)
{
	return get(key, m_currentLanguage);
}





#endif // LINGO_LINGO_INL
