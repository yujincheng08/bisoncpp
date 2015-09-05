#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "scannerbase.h"

// $insert classHead
class Scanner: public ScannerBase
{
    public:
        explicit Scanner(std::istream &in = std::cin,
                                std::ostream &out = std::cout);
        
        // $insert lexFunctionDecl
        int lex();

    private:
        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum__);
};

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out)
{}


inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::postCode(PostEnum__)
{}

inline void Scanner::print() 
{
    print__();
}


#endif // Scanner_H_INCLUDED_