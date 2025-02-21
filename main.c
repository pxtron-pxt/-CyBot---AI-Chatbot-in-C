
     #include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESPONSES 10

struct Response {
    char *question;
    char *answer;
};

// Knowledge Base
struct Response responses[MAX_RESPONSES] = {
    {"hello", "Hello! How can I assist you today?"},
    {"how are you", "I'm an AI, so I don't have feelings, but I'm here to help!"},
    {"your name", "I'm CyBot, your AI assistant!"},
    {"what is AI", "Artificial Intelligence (AI) is the simulation of human intelligence in machines."},
    {"what is machine learning", "Machine Learning is a branch of AI that allows computers to learn from data."},
    {"who created you", "I was created using the C programming language!"},
    {"bye", "Goodbye! Have a great day!"},
    {"thank you", "You're welcome! Let me know if I can help with anything else."}
};

// Convert string to lowercase for better matching
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Find the best matching response
char* getResponse(char *input) {
    toLowerCase(input);
    for (int i = 0; i < MAX_RESPONSES; i++) {
        if (strstr(input, responses[i].question)) {
            return responses[i].answer;
        }
    }
    return "I'm not sure about that. Can you ask something else?";
}

int main() {
    char userInput[100];
    printf("Welcome to CyBot AI! Type 'bye' to exit.\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove newline character

        if (strcmp(userInput, "bye") == 0) {
            printf("CyBot: %s\n", getResponse(userInput));
            break;
        }

        printf("CyBot: %s\n", getResponse(userInput));
    }

    return 0;
}
