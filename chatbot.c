#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char userInput[100];
    srand(time(NULL));

    printf("Stupid Chatbot: Hello! What can I do for you today?\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Remove the newline character at the end of the input
        userInput[strcspn(userInput, "\n")] = '\0';

        if (strstr(userInput, "hello") || strstr(userInput, "hi")) {
            const char *greetings[] = {
                "Hi there!",
                "Hello!",
                "Greetings!",
                "Hey!"
            };
            int randomIndex = rand() % (sizeof(greetings) / sizeof(greetings[0]));
            printf("Stupid Chatbot: %s\n", greetings[randomIndex]);
        } else if (strstr(userInput, "how are you")) {
            const char *feelings[] = {
                "I'm just a computer program, so I don't have feelings.",
                "I'm here to assist you, so I'm doing well!",
                "I'm as good as the code that powers me!"
            };
            int randomIndex = rand() % (sizeof(feelings) / sizeof(feelings[0]));
            printf("Stupid Chatbot: %s\n", feelings[randomIndex]);
        } else if (strstr(userInput, "what is your name")) {
            const char *names[] = {
                "I don't have a name. You can call me Chatbot!",
                "I go by Chatbot. How can I help you today?",
                "I'm just Chatbot, here to assist you!"
            };
            int randomIndex = rand() % (sizeof(names) / sizeof(names[0]));
            printf("Stupid Chatbot: %s\n", names[randomIndex]);
        } else if (strstr(userInput, "exit") || strstr(userInput, "bye")) {
            const char *goodbyes[] = {
                "Goodbye!",
                "Farewell!",
                "See you later!",
                "Adios!"
            };
            int randomIndex = rand() % (sizeof(goodbyes) / sizeof(goodbyes[0]));
            printf("Stupid Chatbot: %s\n", goodbyes[randomIndex]);
            break;
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
