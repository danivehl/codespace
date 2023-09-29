#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate Levenshtein distance
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int cost = 0;

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int *d = (int *)malloc((len1 + 1) * sizeof(int));

    for (int i = 0; i <= len1; i++) d[i] = i;

    for (int j = 1; j <= len2; j++) {
        int prev = j;
        for (int i = 1; i <= len1; i++) {
            int temp = d[i - 1];
            d[i - 1] = prev;

            if (s1[i - 1] != s2[j - 1]) {
                cost = 1;
            }

            prev = (prev < d[i] ? (prev < temp ? prev : temp) : (d[i] < temp ? d[i] : temp)) + cost;
            cost = 0;
        }
        d[len1] = prev;
    }

    int result = d[len1];
    free(d);
    return result;
}

int main() {
    char userInput[100];
    srand(time(NULL));

    printf("Stupid Chatbot: Hello! What can I do for you today?\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Remove the newline character at the end of the input
        userInput[strcspn(userInput, "\n")] = '\0';

        const char *responses[] = {
            "Hi there!",
            "Hello!",
            "Greetings!",
            "Hey!",
            "I'm just a computer program, so I don't have feelings.",
            "I'm here to assist you, so I'm doing well!",
            "I'm as good as the code that powers me!",
            "I don't have a name. You can call me Chatbot!",
            "I go by Chatbot. How can I help you today?",
            "I'm just Chatbot, here to assist you!"
        };

        int minDistance = strlen(userInput) + 1;
        int bestResponseIndex = -1;

        for (int i = 0; i < sizeof(responses) / sizeof(responses[0]); i++) {
            int distance = levenshtein(userInput, responses[i]);
            if (distance < minDistance) {
                minDistance = distance;
                bestResponseIndex = i;
            }
        }

        if (bestResponseIndex != -1) {
            printf("Stupid Chatbot: %s\n", responses[bestResponseIndex]);
        } else {
            const char *unknownResponses[] = {
                "Sorry, I don't understand. Can you please rephrase?",
                "I'm not sure what you mean. Could you try again?",
                "Hmmm, that's a bit confusing. Can you provide more details?",
                "I'm just a simple chatbot, and I didn't get that. Can you reword your question?"
            };
            int randomIndex = rand() % (sizeof(unknownResponses) / sizeof(unknownResponses[0]));
            printf("Stupid Chatbot: %s\n", unknownResponses[randomIndex]);
        }
    }

    return 0;
}
