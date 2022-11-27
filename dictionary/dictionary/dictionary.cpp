#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Dictionary {
    size_t counter = 0;
    size_t word_counter = 0;
    size_t translation_counter = 0;
    //language key, language
    map<size_t, const string> languages;
    //input language key, word, word key
    map<pair<size_t, const string>, size_t> words_in_languages;
    //word key in input language, output language key, output language word key
    map<pair<size_t, size_t>, size_t> translations;
    //word key, word
    map<size_t, const string> words;
    //language key, vocabulary
    map<size_t, vector<string>> vocabulary;
public:
    // Insert a new language and returns its ID
    size_t add_language(const string& name)
    {
        languages.insert({ ++counter, name });
        vocabulary.insert({ counter, vector<string>() });
        return counter;
    }

    // Insert new words into a dictionary
    bool add_vocabulary(size_t words1_language_id, const string& word1,
        size_t words2_language_id, const string& word2)
    {
        size_t first_word_code, second_word_code;
        if (words_in_languages.find(pair<size_t, string>(words1_language_id, word1)) == words_in_languages.end())
        {
            words_in_languages.insert({ pair<size_t, string>(words1_language_id, word1), word_counter++ });
            first_word_code = word_counter-1;
            words.insert({ first_word_code, word1 });
            vocabulary.at(words1_language_id).push_back(word1);
        }
        else
        {
            first_word_code = words_in_languages.at(pair<size_t, string>(words1_language_id, word1));
        }

        if (words_in_languages.find(pair<size_t, string>(words2_language_id, word2)) == words_in_languages.end())
        {
            words_in_languages.insert({ pair<size_t, string>(words2_language_id, word2), word_counter++ });
            second_word_code = word_counter-1;
            words.insert({ second_word_code, word2 });
            vocabulary.at(words2_language_id).push_back(word2);
        }
        else
        {
            second_word_code = words_in_languages.at(pair<size_t, string>(words2_language_id, word2));
        }

        if (translations.find(pair<size_t, size_t>(word_counter - 2, words2_language_id)) == translations.end())
        {
            translations.insert({ pair<size_t, size_t>(first_word_code,words2_language_id), second_word_code });
            translations.insert({ pair<size_t, size_t>(second_word_code,words1_language_id), first_word_code });
            return true;
        }
        return false;
    }
    // Translate a given text with the given language into the output language
    string translate(size_t input_language_id, const string& text,
        size_t output_language_id) const
    {
        size_t word_code = words_in_languages.at(pair<size_t, const string>(input_language_id, text));
        size_t translated_word_code = translations.at(pair<size_t, size_t>(word_code, output_language_id));

        return words.at(translated_word_code);
    }
    // Automatically translate a given text into a given language
    string translate(const string& text, size_t output_language_id) const
    {
        size_t word_key;

        for (auto it = words.begin(); it != words.end(); ++it)
            if (it->second == text)
                word_key = it->first;

        size_t translated_word_key = translations.at(pair<size_t, size_t>(word_key, output_language_id));
        return words.at(translated_word_key);
    }
    // Return all vocabularies for a given language
    const vector<string>& all_vocabulary(size_t language_id) const
    {
        return vocabulary.at(language_id);
    }
};

int main() {
    Dictionary dictionary = Dictionary();

    string word1 = "kon";
    string word2 = "horse";

    size_t slovencina = dictionary.add_language("slovencina");
    size_t anglictina = dictionary.add_language("anglictina");
    size_t cestina = dictionary.add_language("cestina");

    dictionary.add_vocabulary(slovencina, word1, anglictina, word2);
    dictionary.add_vocabulary(slovencina, word1, cestina, "kun");

    dictionary.add_vocabulary(slovencina, "auto", anglictina, "car");

    const string horse = dictionary.translate(slovencina,word1, anglictina);
    const string kun = dictionary.translate(slovencina, word1, cestina);
    
    const string kon = dictionary.translate(word2, slovencina);

    const vector<string>& vocabulary = dictionary.all_vocabulary(slovencina);
    cout << horse << " " << kun << " " << kon << " " << vocabulary[1];

    return 0;
}