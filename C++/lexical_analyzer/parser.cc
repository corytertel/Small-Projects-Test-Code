#include <iostream>
#include <cstdlib>
#include "parser.h"

using namespace std;

void Parser::syntax_error() {
    cout << "SYNTAX ERROR\n";
    exit(1);
}

// this function gets a token and checks if it is
// of the expected type. If it is, the token is
// returned, otherwise, synatx_error() is generated
// this function is particularly useful to match
// terminals in a right hand side of a rule.
// Written by Mohsen Zohrevandi
auto Parser::expect(TokenType expected_type) -> Token {
    Token t = lexer.get_token();
    if (t.token_type != expected_type)
        syntax_error();
    return t;
}

void Parser::parse_expr() {

}

void Parser::parse_token() {
   
}

void Parser::parse_token_list() {

}

void Parser::parse_tokens_section() {
    
}

void Parser::parse_input() {
    
}

// This function simply reads and prints all tokens
// I included it as an example. You should compile the provided code
// as it is and then run ./a.out < tests/test0.txt to see what this function does

void Parser::read_and_print_all_input() {
    Token t;

    // get a token
    t = lexer.get_token();

    // while end of input is not reached
    while (t.token_type != TokenType::END_OF_FILE) {
        t.print();         	// pringt token
        t = lexer.get_token();	// and get another one
    }
        
    // note that you should use END_OF_FILE and not EOF
}

auto main() -> int {
    // note: the parser class has a lexer object instantiated in it (see file
    // parser.h). You should not be declaring a separate lexer object. 
    // You can access the lexer object in the parser functions as shown in 
    // the example  method Parser::readAndPrintAllInput()
    // If you declare another lexer object, lexical analysis will 
    // not work correctly
    Parser parser;

    parser.read_and_print_all_input();
	
    return 0;
}
