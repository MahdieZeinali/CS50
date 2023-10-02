#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);
float getColemanIndex(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    if (strlen(text) == 0)
    {
        printf("Empty string passed! Please provide a non-empty string.");
        return 1;
    }

    int lettersCount = countLetters(text);
    int wordsCount = countWords(text);
    int sentencesCount = countSentences(text);
    int colemanIndex = getColemanIndex(lettersCount, wordsCount, sentencesCount);

    if (colemanIndex < 16 && colemanIndex >= 1)
    {
        printf("Grade %i\n", colemanIndex);
    }
    else if (colemanIndex >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int countLetters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char currentChar = text[i];
        if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z'))
        {
            count++;
        }
    }

    return count;
}

int countWords(string text)
{
    if (strlen(text) == 0)
    {
        return 0;
    }

    int spacesCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            spacesCount++;
        }
    }

    int wordsCount = spacesCount + 1;

    return wordsCount;
}

int countSentences(string text)
{
    int sentencesCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char currentChar = text[i];
        if (currentChar == '.' || currentChar == '!' || currentChar == '?')
        {
            sentencesCount++;
        }
    }

    return sentencesCount;
}

float getColemanIndex(int letters, int words, int sentences)
{
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}
