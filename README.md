# Lingo

## Introduction
Lingo is a class that stores sets of strings for use with different languages which will provide you with the correct string the correct language.

This abstracts the concept of languages and allows you to concentrate on just getting the string you want and the correct one from
the chosen (currently set or directly specified) language will be supplied.

## Usage
The header's methods should be obvious enough but here are some examples:

`Lingo<std::size_t> lingo;`  
creates the Lingo object.
> Note: Lingo requires a template parameter specifying the type used for the key to the string.
> For example, you can use an index (as shown here), an enum (including class) or a string to specify which string.
> It can be left empty (`Lingo<> lingo;`) and it will default to a string type.

### Setup
`lingo.addLanguage();`  
adds another language to Lingo. You do this as for as many languages as you need.
Note that a Lingo object starts with a single language already; you do not need to add the first one.

`lingo.setLanguage(0u);`  
sets the currently active language. This example sets it to index 0: the first language.

`lingo.set(0u, "START");`  
sets the string "START" to be associated with the key [0] (for the current language). You can access this by "get"ting it (see below).

`lingo.set(0u, "START", 1u);`  
sets the string "START" to be associated with the key [0] for the second language (1) regardless of which language is currently active.

### Main Use
`str = lingo.get(0u);`  
assigns "str" with the string associated with the key [0] (for the current language). Changing the current language will change which string is supplied.

`str = lingo.get(0u, 1u);`
assigns "str" with the string associated with the key [0] for the second language (1) regardless of which language is currently active.

`str = lingo.get("start");`
assigns "str" with the string associated with the string key ["start"] (for the current language). Changing the current language will change which string is supplied.
> Note: "start" here is not a string inside Lingo; it is a string key.  
> If `lingo.set("start", "START");` was used to set it up then this get would return the "START" string (if the currently active language is the same).

## Game Language Tables
[GLT (Game Language Tables)](https://github.com/Hapaxia/GameLanguageTables) is a collection of tables that provide translations of words/phrases used in games by game developers.  
Included is [a table parser that adds the languages and strings to Lingo automatically](https://github.com/Hapaxia/GameLanguageTables/blob/main/Parsers/ParseToLingo.cpp).
