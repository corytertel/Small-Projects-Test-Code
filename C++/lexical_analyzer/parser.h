#include <string>
#include "lexer.h"

struct Parser {
    void parse_input();
    void read_and_print_all_input();
private:
    LexicalAnalyzer lexer;

    void syntax_error();
    auto expect(TokenType expected_type) -> Token;
    void parse_tokens_section();
    void parse_token_list();
    void parse_token();
    void parse_expr();
};
