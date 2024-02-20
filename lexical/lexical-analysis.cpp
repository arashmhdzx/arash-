#include <iostream>
#include <string>
#include <vector>

using namespace std; 

// Define token types
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    NUMBER,
    PUNCTUATION,
    END_OF_FILE
};

// Define a structure to represent a token
struct Token {
    TokenType type;
    string lexeme;
};

// Function to perform lexical analysis
vector<Token> lexAnalyze(const string& input) {
    vector<Token> tokens;
    // Iterate through the input string
    for (size_t i = 0; i < input.size(); ++i) {
        char currentChar = input[i];
        // You would implement more complex logic here based on the language specifications
        // For simplicity, let's just identify some basic tokens
        if (isalpha(currentChar)) {
            // Identify keywords or identifiers
            string lexeme;
            while (isalnum(currentChar)) {
                lexeme += currentChar;
                currentChar = input[++i];
            }
            if (lexeme == "if" || lexeme == "else" || lexeme == "while") {
                tokens.push_back({KEYWORD, lexeme});
            } else {
                tokens.push_back({IDENTIFIER, lexeme});
            }
            --i; // Move the index back by one to reprocess the non-alphanumeric character
        } else if (isdigit(currentChar)) {
            // Identify numbers
            string lexeme;
            while (isdigit(currentChar)) {
                lexeme += currentChar;
                currentChar = input[++i];
            }
            tokens.push_back({NUMBER, lexeme});
            --i;
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            // Identify operators
            tokens.push_back({OPERATOR, string(1, currentChar)});
        } else if (ispunct(currentChar)) {
            // Identify punctuation
            tokens.push_back({PUNCTUATION, string(1, currentChar)});
        }
    }

    // Add an end-of-file token
    tokens.push_back({END_OF_FILE, ""});

    return tokens;
}

int main() {
    string code = "if (x > 0) { y = x + 5; } else { y = x - 5; }";

    // Perform lexical analysis
    vector<Token> tokens = lexAnalyze(code);

    // Print the tokens
    for (const auto& token : tokens) {
        cout << "Type: " << token.type << ", Lexeme: " << token.lexeme << endl;
    }

    return 0;
}
