// Generated by Bisonc++ V2.09.04 on Mon, 13 Feb 2012 21:57:57 +0100

#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <vector>
#include <iostream>

// $insert preincludes
#include "preheaders.h"

namespace // anonymous
{
    struct PI__;
}


class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
    enum Tokens__
    {
        BASECLASS_HEADER = 257,
        BASECLASS_PREINCLUDE,
        BLOCK,
        CLASS_HEADER,
        CLASS_NAME,
        DEBUGFLAG,
        ERROR_VERBOSE,
        EXPECT,
        FILENAMES,
        FLEXCPP,
        IDENTIFIER,
        IMPLEMENTATION_HEADER,
        LEFT,
        LINES,
        LOCATIONSTRUCT,
        LSP_NEEDED,
        LTYPE,
        NAMESPACE,
        NEG_DOLLAR,
        NONASSOC,
        NUMBER,
        PARSEFUN_SOURCE,
        PREC,
        PRINT,
        QUOTE,
        REQUIRED,
        RIGHT,
        SCANNER_INCLUDE,
        SCANNER_MATCHED_TEXT_FUNCTION,
        SCANNER_TOKEN_FUNCTION,
        START,
        STRING,
        STYPE,
        TARGET_DIRECTORY,
        TOKEN,
        TWO_PERCENTS,
        TYPE,
        UNION,
    };

// $insert STYPE
union STYPE__
{
 std::string *sp;
 FBB::PTag *tag;
 int type;
 bool logic;
};


    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;

        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool ParserBase::debug() const
{
    return d_debug__;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


