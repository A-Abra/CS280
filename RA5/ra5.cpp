#include <map>
#include "lex.h"

using namespace std;

//tokens to print
static map<Token,string> tokenPrint = {
       {PROGRAM, "PROGRAM"},
       {WRITE, "WRITE"},
       {INT, "INT"},
       { FLOAT, "FLOAT" },
       { IF, "IF" },
       {STRING, "STRING"},
       { END, "END" },

       { REPEAT, "REPEAT" },
       { BEGIN, "BEGIN" },
       { IDENT, "IDENT" },

       { ICONST, "ICONST" },
       { RCONST, "RCONST" },
       { SCONST, "SCONST" },
      
       { PLUS, "PLUS" },
       { MINUS, "MINUS" },
       { MULT, "MULT" },
       { DIV, "DIV" },
       { REM, "REM" },
       { ASSOP, "ASSOP" },
       { LPAREN, "LPAREN" },
       { RPAREN, "RPAREN" },
  
       { SEMICOL, "SEMICOL" },
       {COMMA, "COMMA" },
       { EQUAL, "EQUAL" },
       { GTHAN, "GTHAN" },
            
       { ERR, "ERR" },

       { DONE, "DONE" },
};

//keyword map
static map<string,Token> kwmap = {
       {"PROGRAM", PROGRAM},
       {"BEGIN", BEGIN},
       {"WRITE", WRITE},
       {"INT", INT},
       {"FLOAT", FLOAT},
       {"IF", IF},
       {"STRING", STRING},
       {"REPEAT", REPEAT},
       {"END", END},
};

LexItem id_or_kw(const string& lexeme,int linenum){
    //map<string,Token>::iterator iter=kwmap.find(lexeme);
    //if(iter!=kwmap.end()){
    //    return LexItem(iter->second,lexeme,linenum);
    //}
    //if found return Token kw, lexeme, and linenum
    if(kwmap.find(lexeme)!=kwmap.end())
        return LexItem(kwmap.find(lexeme)->second,lexeme,linenum);
    //else its an identifier
    return LexItem(IDENT,lexeme,linenum);
}

ostream& operator<<(ostream& out, const LexItem& tok){
	//prints results
    Token thistok=tok.GetToken();
    out<<tokenPrint[thistok];
    
    if(thistok==IDENT||thistok==ICONST||thistok==RCONST
	||thistok==SCONST||thistok==ERR){
        out<<" ("<<tok.GetLexeme()<<")";
    }
    out<<" Line #: "<< tok.GetLinenum() << endl;
    return out;
}
