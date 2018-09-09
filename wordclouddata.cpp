#include <iostream>
#include <string>
#include <map>
using namespace std;

#define DELIMITERS ".,?!:;—[](){}\"… "

map<string, int> wordCloudGenerator(string words)
{
    int firstCharacterOfWordIndex = 0;
    int lastCharacterOfWordIndex;

    map<string, int> wordCloudMap;

    do
    {

        firstCharacterOfWordIndex = words.find_first_not_of(DELIMITERS, firstCharacterOfWordIndex);
        lastCharacterOfWordIndex = words.find_first_of(DELIMITERS, firstCharacterOfWordIndex);
        string key = words.substr(firstCharacterOfWordIndex, lastCharacterOfWordIndex - firstCharacterOfWordIndex);

        for(int i = 0; i < key.length(); i++)
        {
            key[i] = tolower(key[i]);
        }

        wordCloudMap[key]++;
        firstCharacterOfWordIndex = lastCharacterOfWordIndex + 1;

    } while (firstCharacterOfWordIndex < words.length());

    return wordCloudMap;
}

void printMapContents(map<string, int> mapToBePrinted)
{
    for(map<string, int>::iterator itr = mapToBePrinted.begin(); itr != mapToBePrinted.end(); itr++)
    {
        cout << itr->first << ": " << itr->second << endl;
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    map<string, int> worldCloudMap;

    worldCloudMap = wordCloudGenerator("We came, we saw, we conquered…then we ate Bill's (Mille-Feuille) cake.");
    printMapContents(worldCloudMap);

    worldCloudMap = wordCloudGenerator("The bill came to five dollars.");
    printMapContents(worldCloudMap);
    
    return 0;
}
