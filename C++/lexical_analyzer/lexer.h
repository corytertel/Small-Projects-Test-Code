#pragma once
#include <vector>
#include <string>

#include "inputbuf.h"

// ------- token types -------------------

enum class TokenType { 
    END_OF_FILE = 0, LPAREN, RPAREN, HASH, ID, COMMA, DOT, STAR,
    OR, UNDERSCORE, SYMBOL, CHAR, INPUT_TEXT, ERROR
};

struct Token {
    std::string lexeme;
    TokenType token_type;
    int line_no;

    void print();
};

struct LexicalAnalyzer {
    auto get_token() -> Token;
    auto peek(int) -> Token;
    LexicalAnalyzer();

private:
    std::vector<Token> token_list;
    int line_no;
    size_t index;
    Token tmp;
    InputBuffer input;

    auto get_token_main() -> Token;
    auto skip_space() -> bool;
    auto scan_id_or_char() -> Token;
    auto scan_symbol() -> Token;
    auto scan_input() -> Token;
};
