#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate how similar two words are
int calculateSimilarity(const char *word1, const char *word2) {
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    int matrix[99] = {length1};

    for (int i = 1; i <= length1; i++) {
        matrix[i] = i;
    }

    for (int i = 1; i <= length2; i++) {
        for (int j = length1, matrix[0] = i; j; j--) {
            matrix[j] = (word1[j - 1] == word2[i - 1]) ? matrix[j - 1] : 1 + ((matrix[j] < matrix[j - 1]) ? matrix[j] : matrix[j - 1]);
        }
        matrix[length1] = matrix[length1 - 1];
    }

    return matrix[length1];
}

int main() {
    char userInput[100];
    srand(time(NULL));

    printf("Chatbot: Hi! How can I help you today?\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strlen(userInput) - 1] = '\0';

        const char *responses[] = {
            "Hi there!", "Hello!", "Greetings!", "Hey!",
            "I'm just a computer program, so I don't have feelings.",
            "I'm here to assist you, so I'm doing well!",
            "I'm as good as the code that powers me!",
            "I don't have a name. You can call me Chatbot!",
            "I go by Chatbot. How can I help you today?",
            "I'm just Chatbot, here to assist you!"
        };

        int minSimilarity = 99;
        int bestResponseIndex = -1;

        for (int i = 0; i < sizeof(responses) / sizeof(responses[0]); i++) {
            int similarity = calculateSimilarity(userInput, responses[i]);
            if (similarity < minSimilarity) {
                minSimilarity = similarity;
                bestResponseIndex = i;
            }
        }

        if (bestResponseIndex != -1) {
            printf("Chatbot: %s\n", responses[bestResponseIndex]);
        } else if (minSimilarity > 5) {
            const char *unknownResponses[] = {
                "I'm not sure what you mean. Can you try again?",
                "Can you rephrase that, please?",
                "I didn't quite catch that. Could you provide more details?",
                "I'm a simple chatbot, and that's a bit confusing. Can you ask differently?"
            };
            int randomIndex = rand() % (sizeof(unknownResponses) / sizeof(unknownResponses[0]));
            printf("Chatbot: %s\n", unknownResponses[randomIndex]);
        } else {
            printf("Chatbot: Sorry, I don't know how to respond to that.\n");
        }
    }

    return 0;
}
