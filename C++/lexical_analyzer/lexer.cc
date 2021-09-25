#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <cctype>

#include "lexer.h"
#include "inputbuf.h"

std::string reserved[] = { "END_OF_FILE",
    "LPAREN", "RPAREN", "HASH", "ID", "COMMA", "DOT", "STAR",
    "OR", "UNDERSCORE", "SYMBOL", "CHAR", "INPUT_TEXT", "ERROR"};

void Token::print() {
    std::cout << "{" << this->lexeme << " , "
         << reserved[(int) this->token_type] << " , "
         << this->line_no << "}\n";
}

// The constructor function will get all token in the input and stores them in an
// internal vector. This faciliates the implementation of peek()
LexicalAnalyzer::LexicalAnalyzer() {
    this->line_no = 1;
    tmp.lexeme = "";
    tmp.line_no = 1;
    tmp.token_type = TokenType::ERROR;

    Token token = get_token_main();
    index = 0;

    while (token.token_type != TokenType::END_OF_FILE) {
        token_list.push_back(token);     // push token into internal list
        token = get_token_main();        // and get next token from standatd input
    }
    // pushes END_OF_FILE is not pushed on the token list

}

auto LexicalAnalyzer::skip_space() -> bool {
    char c;
    bool space_encountered = false;

    input.get_char(c);
    line_no += (c == '\n');

    while (!input.end_of_input() && isspace(c)) {
        space_encountered = true;
        input.get_char(c);
        line_no += (c == '\n');
    }

    if (!input.end_of_input()) {
        input.unget_char(c);
    }
    return space_encountered;
}

auto LexicalAnalyzer::scan_id_or_char() -> Token {
    char c;
    input.get_char(c);

    if (isalpha(c)) {
        tmp.lexeme = "";
        int no = 0;

        while (!input.end_of_input() && isalnum(c)) {
            tmp.lexeme += c;
            input.get_char(c);
            no++;
        }
        tmp.line_no = line_no;
        if(no == 1)
            tmp.token_type = TokenType::CHAR;
        else
            tmp.token_type = TokenType::ID;


        if (!input.end_of_input()) {

            input.unget_char(c);
        }

    } else {
        if (!input.end_of_input()) {
            input.unget_char(c);
        }
        tmp.lexeme = "";
        tmp.token_type = TokenType::ERROR;
    }
    return tmp;
}

auto LexicalAnalyzer::scan_input() -> Token {
    char c;
    input.get_char(c);
    std::string lexeme = "";
    if (c == '"') {
        tmp.lexeme = "";
        lexeme += '"';
        Token symbol = scan_symbol();
        while (symbol.token_type == TokenType::SYMBOL) {
            lexeme += symbol.lexeme;
            symbol = scan_symbol();
        }
        if (!input.end_of_input()) {
            input.get_char(c);
            if (c == '"') {
                lexeme += c;
                tmp.lexeme += lexeme;
                tmp.token_type = TokenType::INPUT_TEXT;
            }
            else{
                tmp.lexeme = "";
                tmp.token_type = TokenType::ERROR;
            }

        }
        else{
            tmp.lexeme = "";
            tmp.token_type = TokenType::ERROR;
        }

        tmp.line_no = line_no;

    } else {
        if (!input.end_of_input()) {
            input.unget_char(c);
        }
        tmp.lexeme = "";
        tmp.token_type = TokenType::ERROR;
    }
    return tmp;
}

auto LexicalAnalyzer::scan_symbol() -> Token {
    char c;
    input.get_char(c);
    tmp.lexeme = "";
    if (isspace(c) || isalnum(c)) {
        //tmp.lexeme += c;
        while (!input.end_of_input() && (isspace(c) || isalnum(c))) {
            line_no += (c == '\n');
            tmp.lexeme += c;
            input.get_char(c);
        }
        if (!input.end_of_input()) {
            input.unget_char(c);
        }
        tmp.line_no = line_no;

        tmp.token_type = TokenType::SYMBOL;
    } else {
        if (!input.end_of_input()) {
            input.unget_char(c);
        }
        tmp.lexeme = "";
        tmp.token_type = TokenType::ERROR;
    }
    return tmp;
}


// GetToken() accesses tokens from the tokenList that is populated when a 
// lexer object is instantiated
auto LexicalAnalyzer::get_token() -> Token {
    Token token;
    if (index == token_list.size()){       // return end of file if
        token.lexeme = "";                // index is too large
        token.line_no = line_no;
        token.token_type = TokenType::END_OF_FILE;
    }
    else {
        token = token_list[index];
        index = index + 1;
    }
    return token;
}



// peek requires that the argument "howFar" be positive.
auto LexicalAnalyzer::peek(int howFar) -> Token {
    if (howFar <= 0) {      // peeking backward or in place is not allowed
        std::cout << "LexicalAnalyzer:peek:Error: non positive argument\n";
        exit(-1);
    } 

    size_t peek_index = index + howFar - 1;
    if (peek_index > (token_list.size()-1)) { // if peeking too far
        Token token;                        // return END_OF_FILE
        token.lexeme = "";
        token.line_no = line_no;
        token.token_type = TokenType::END_OF_FILE;
        return token;
    } else
        return token_list[peek_index];
}

auto LexicalAnalyzer::get_token_main() -> Token {
    char c;

    skip_space();
    tmp.lexeme = "";
    tmp.line_no = line_no;
    tmp.token_type = TokenType::END_OF_FILE;
    if (!input.end_of_input())
        input.get_char(c);
    else
        return tmp;

    switch (c) {
        case '(': tmp.token_type = TokenType::LPAREN;    return tmp;
        case ')': tmp.token_type = TokenType::RPAREN;    return tmp;
        case ',': tmp.token_type = TokenType::COMMA;     return tmp;
        case '.': tmp.token_type = TokenType::DOT;      return tmp;
        case '*': tmp.token_type = TokenType::STAR;     return tmp;
        case '|': tmp.token_type = TokenType::OR;     return tmp;
        case '#': tmp.token_type = TokenType::HASH;     return tmp;
        case '_': tmp.token_type = TokenType::UNDERSCORE; return tmp;
        case '"': 
                input.unget_char(c);
                return scan_input();
        default:
            if (isdigit(c)) {
                //CHAR
                //input.UngetChar(c);
                //return ScanNumber();
                tmp.token_type = TokenType::CHAR;
                tmp.lexeme = c;
            } else if (isalpha(c)) {
                input.unget_char(c);
                return scan_id_or_char();
            }
            else if (input.end_of_input())
                tmp.token_type = TokenType::END_OF_FILE;
            else
                tmp.token_type = TokenType::ERROR;

            return tmp;
    }
}
