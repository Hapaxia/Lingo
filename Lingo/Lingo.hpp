//////////////////////////////////////////////////////////////////////////////
//
// Lingo (https://github.com/Hapaxia/Lingo
//
// Copyright(c) 2019-2023 M.J.Silk
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions :
//
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software.If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
// M.J.Silk
// MJSilk2@gmail.com
//
//////////////////////////////////////////////////////////////////////////////

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
	bool removeString(const KeyT& key); // remove from current language
	bool removeString(const KeyT& key, std::size_t languageIndex); // remove from specific language
	bool removeString(const KeyT& key, const std::vector<std::size_t>& languageIndices); // remove from multiple languages
	bool removeStrings(const std::vector<KeyT>& keys); // remove multiple from current language
	bool removeStrings(const std::vector<KeyT>& keys, std::size_t languageIndex); // remove multiple from specific language
	bool removeStrings(const std::vector<std::pair<KeyT, std::size_t>>& keys); // remove multiple from specific languages. first in pair is key, second is language index
	bool removeLanguage(); // removes current language
	bool removeLanguage(std::size_t languageIndex); // removes specific language
	bool clearLanguage(); // clears current language. language remains available but empty
	bool clearLanguage(std::size_t languageIndex); // clears specific language. language remains available but empty
	std::vector<KeyT> getKeys() const; // gets all keys in current language
	std::vector<KeyT> getKeys(std::size_t languageIndex) const; // gets all keys in specific language

private:
	using Language = std::unordered_map<KeyT, std::string>;
	std::vector<Language> m_languages;
	std::size_t m_currentLanguage;
};

#include "Lingo.inl"
#endif // LINGO_LINGO_HPP
