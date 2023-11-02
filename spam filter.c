f spam words
const char *spamWords[] = {
    "gambling",
    "insurance",
    "loan",
    "credit",
    // Add more spam words here
};

// Function to check if a word is a spam word
int isSpamWord(const char *word) {
    for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
        if (strstr(word, spamWords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char email[1000];
    printf("Enter the email text: ");
    fgets(email, sizeof(email), stdin);

    char *word = strtok(email, " "); // Split the email into words
    int foundSpamWord = 0;

    while (word != NULL) {
        if (isSpamWord(word)) {
            foundSpamWord = 1;
            break;
        }

        word = strtok(NULL, " "); // Get the next word
    }

    if (foundSpamWord) {
        printf("The email is likely spam.\n");
    } else {
        printf("The email is likely not spam.\n");
    }

    return 0;
}

