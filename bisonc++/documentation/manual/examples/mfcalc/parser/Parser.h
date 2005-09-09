#ifndef Parser_h_included
#define Parser_h_included

// for error()'s inline implementation
#include <iostream>

// for mfcalc's memory
#include <map>
#include <string>

// $insert baseclass
#include "Parserbase.h"


#undef Parser
class Parser: public ParserBase
{
    typedef std::pair<char const *, double (*)(double)> FunctionPair;
    
    std::map<std::string, double> d_symbols;

    static std::map<std::string, double (*)(double)> s_functions;
    static FunctionPair s_funTab[];
            
    public:
        int parse();

    private:
        void error(char const *msg)
        {
            std::cerr << msg << std::endl;
        }

        // $insert lex
        int lex();

        void print()    // d_token, d_loc
        {}

    // support functions for parse():

        void executeAction(int d_production);
        unsigned errorRecovery();
        int lookup(int token);
        int nextToken();
};


#endif
