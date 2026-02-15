bool isSubsequence(char* word, char* s) {
    int i = 0;
    int j = 0; 
    
 
    while (word[i] != '\0' && s[j] != '\0') {
        if (word[i] == s[j]) {
            i++;
        }
        j++;
    }
    
 
    return word[i] == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char* bestWord = ""; 
    
    for (int i = 0; i < dictionarySize; i++) {
        char* currentWord = dictionary[i];
        
        
        if (isSubsequence(currentWord, s)) {
            int currentLen = strlen(currentWord);
            int bestLen = strlen(bestWord);
            
          
            if (currentLen > bestLen || (currentLen == bestLen && strcmp(currentWord, bestWord) < 0)) {
                bestWord = currentWord;
            }
        }
    }
    
    return bestWord;
}
