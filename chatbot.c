#include <stdio.h>
#include <string.h>

int main() {
    char userInput[100];

    printf("Simple Chatbot: Hello! How can I help you today?\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Remove the newline character at the end of the input
        userInput[strcspn(userInput, "\n")] = '\0';

        if (strcmp(userInput, "hello") == 0) {
            printf("Chatbot: Hi there!\n");
        } else if (strcmp(userInput, "how are you") == 0) {
            printf("Chatbot: I'm just a computer program, so I don't have feelings, but I'm here to assist you!\n");
        } else if (strcmp(userInput, "exit") == 0) {
            printf("Chatbot: Goodbye!\n");
            break;
        } else {
            printf("Chatbot: I'm not sure how to respond to that.\n");
        }
    }

    return 0;
}
