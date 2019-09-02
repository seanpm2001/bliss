/*
 * Copyright (C) 2019 Jonathan D. Belanger
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation,
    either version 3 of the License,
    or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,

 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
 */
#include "Lexer/Lexer.h"

using namespace std;
using namespace bliss;

KeywordTable keywords[] =
{
    _KWD_TABLE(ALLOCATION, Lexer::LTKeyword, true),
    _KWD_TABLE(ASCIC, Lexer::LTKeyword, true),
    _KWD_TABLE(ASCID, Lexer::LTKeyword, true),
    _KWD_TABLE(ASCII, Lexer::LTKeyword, true),
    _KWD_TABLE(ASCIZ, Lexer::LTKeyword, true),
    _KWD_TABLE(ASSIGN, Lexer::LTKeyword, true),
    _KWD_TABLE(B, Lexer::LTKeyword, true),
    _KWD_TABLE(BLISS, Lexer::LTKeyword, true),
    _KWD_TABLE(BLISS32, Lexer::LTKeyword, true),
    _KWD_TABLE(BLISS64, Lexer::LTKeyword, true),
    _KWD_TABLE(BPADDR, Lexer::LTKeyword, true),
    _KWD_TABLE(BPUNIT, Lexer::LTKeyword, true),
    _KWD_TABLE(BPVAL, Lexer::LTKeyword, true),
    _KWD_TABLE(C, Lexer::LTKeyword, true),
    _KWD_TABLE(CHAR, Lexer::LTKeyword, true),
    _KWD_TABLE(CHARCOUNT, Lexer::LTKeyword, true),
    _KWD_TABLE(COUNT, Lexer::LTKeyword, true),
    _KWD_TABLE(CTCE, Lexer::LTKeyword, true),
    _KWD_TABLE(DECIMAL, Lexer::LTKeyword, true),
    _KWD_TABLE(DECLARED, Lexer::LTKeyword, true),
    _KWD_TABLE(ELSE, Lexer::LTKeyword, true),
    _KWD_TABLE(ERROR, Lexer::LTKeyword, true),
    _KWD_TABLE(ERRORMACRO, Lexer::LTKeyword, true),
    _KWD_TABLE(EXACTSTRING, Lexer::LTKeyword, true),
    _KWD_TABLE(EXITITERATION, Lexer::LTKeyword, true),
    _KWD_TABLE(EXITMACRO, Lexer::LTKeyword, true),
    _KWD_TABLE(EXPAND, Lexer::LTKeyword, true),
    _KWD_TABLE(EXPLODE, Lexer::LTKeyword, true),
    _KWD_TABLE(FI, Lexer::LTKeyword, true),
    _KWD_TABLE(FIELDEXPAND, Lexer::LTKeyword, true),
    _KWD_TABLE(IDENTICAL, Lexer::LTKeyword, true),
    _KWD_TABLE(IF, Lexer::LTKeyword, true),
    _KWD_TABLE(INFORM, Lexer::LTKeyword, true),
    _KWD_TABLE(ISSTRING, Lexer::LTKeyword, true),
    _KWD_TABLE(LENGTH, Lexer::LTKeyword, true),
    _KWD_TABLE(LTCE, Lexer::LTKeyword, true),
    _KWD_TABLE(MESSAGE, Lexer::LTKeyword, true),
    _KWD_TABLE(NAME, Lexer::LTKeyword, true),
    _KWD_TABLE(NBITS, Lexer::LTKeyword, true),
    _KWD_TABLE(NBITSU, Lexer::LTKeyword, true),
    _KWD_TABLE(NULL, Lexer::LTKeyword, true),
    _KWD_TABLE(NUMBER, Lexer::LTKeyword, true),
    _KWD_TABLE(O, Lexer::LTKeyword, true),
    _KWD_TABLE(P, Lexer::LTKeyword, true),
    _KWD_TABLE(PRINT, Lexer::LTKeyword, true),
    _KWD_TABLE(QUOTE, Lexer::LTKeyword, true),
    _KWD_TABLE(QUOTENAME, Lexer::LTKeyword, true),
    _KWD_TABLE(REF, Lexer::LTKeyword, true),
    _KWD_TABLE(REMAINING, Lexer::LTKeyword, true),
    _KWD_TABLE(REMOVE, Lexer::LTKeyword, true),
    _KWD_TABLE(REQUIRE, Lexer::LTKeyword, true),
    _KWD_TABLE(S, Lexer::LTKeyword, true),
    _KWD_TABLE(SBTTL, Lexer::LTKeyword, true),
    _KWD_TABLE(SIZE, Lexer::LTKeyword, true),
    _KWD_TABLE(STRING, Lexer::LTKeyword, true),
    _KWD_TABLE(SWITCHES, Lexer::LTKeyword, true),
    _KWD_TABLE(T, Lexer::LTKeyword, true),
    _KWD_TABLE(THEN, Lexer::LTKeyword, true),
    _KWD_TABLE(TITLE, Lexer::LTKeyword, true),
    _KWD_TABLE(UNQUOTE, Lexer::LTKeyword, true),
    _KWD_TABLE(UPVAL, Lexer::LTKeyword, true),
    _KWD_TABLE(VARIANT, Lexer::LTKeyword, true),
    _KWD_TABLE(WARN, Lexer::LTKeyword, true),
    _KWD_TABLE(X, Lexer::LTKeyword, true),
    KWD_TABLE(ABS,Lexer::LTPredeclared, false),
    KWD_TABLE(ABSOLUTE, Lexer::LTKeyword, false),
    KWD_TABLE(ACTUALCOUNT, Lexer::LTPredeclared, true),
    KWD_TABLE(ACTUALPARAMETER, Lexer::LTPredeclared, true),
    KWD_TABLE(ADDRESSING_MODE, Lexer::LTKeyword, true),
    KWD_TABLE(ALIGN, Lexer::LTKeyword, true),
    KWD_TABLE(ALWAYS, Lexer::LTKeyword, true),
    KWD_TABLE(AND, Lexer::LTKeyword, true),
    KWD_TABLE(ARGPTR, Lexer::LTPredeclared, true),
    KWD_TABLE(ASSEMBLY, Lexer::LTKeyword, false),
    KWD_TABLE(BEGIN, Lexer::LTKeyword, true),
    KWD_TABLE(BINARY, Lexer::LTKeyword, false),
    KWD_TABLE(BIND, Lexer::LTKeyword, true),
    KWD_TABLE(BIT, Lexer::LTKeyword, true),
    KWD_TABLE(BITVECTOR, Lexer::LTPredeclared, false),
    KWD_TABLE(BLISS, Lexer::LTPredeclared, false),
    KWD_TABLE(BLISS32, Lexer::LTKeyword, false),
    KWD_TABLE(BLISS64, Lexer::LTKeyword, false),
    KWD_TABLE(BLOCK, Lexer::LTPredeclared, false),
    KWD_TABLE(BLOCKVECTOR, Lexer::LTPredeclared, false),
    KWD_TABLE(BUILTIN, Lexer::LTKeyword, true),
    KWD_TABLE(BY, Lexer::LTKeyword, true),
    KWD_TABLE(BYTE, Lexer::LTKeyword, true),
    KWD_TABLE(CALL, Lexer::LTKeyword, false),
    KWD_TABLE(CASE, Lexer::LTKeyword, true),
    KWD_TABLE(CH$A_RCHAR, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$A_WCHAR, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$ALLOCATION, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$COMPARE, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$COPY, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$DIFF, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$EQL, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$FAIL, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$FILL, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$FIND_CH, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$FIND_NOT_CH, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$FIND_SUB, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$GEQ, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$GTR, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$LEQ, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$LSS, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$MOVE, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$NEQ, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$PLUS, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$PTR, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$RCHAR, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$RCHAR_A, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$SIZE, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$TRANSLATE, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$TRANSTABLE, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$WCHAR, Lexer::LTPredeclared, false),
    KWD_TABLE(CH$WCHAR_A, Lexer::LTPredeclared, false),
    KWD_TABLE(CODE, Lexer::LTKeyword, false),
    KWD_TABLE(CODECOMMENT, Lexer::LTKeyword, true),
    KWD_TABLE(COMMENTARY, Lexer::LTKeyword, false),
    KWD_TABLE(COMPILETIME, Lexer::LTKeyword, true),
    KWD_TABLE(CONCATENATE, Lexer::LTKeyword, false),
    KWD_TABLE(DEBUG, Lexer::LTKeyword, false),
    KWD_TABLE(DECR, Lexer::LTKeyword, true),
    KWD_TABLE(DECRA, Lexer::LTKeyword, true),
    KWD_TABLE(DECRU, Lexer::LTKeyword, true),
    KWD_TABLE(DO, Lexer::LTKeyword, true),
    KWD_TABLE(ELSE, Lexer::LTKeyword, true),
    KWD_TABLE(ELUDOM, Lexer::LTKeyword, true),
    KWD_TABLE(ENABLE, Lexer::LTKeyword, true),
    KWD_TABLE(END, Lexer::LTKeyword, true),
    KWD_TABLE(EQL, Lexer::LTKeyword, true),
    KWD_TABLE(EQLA, Lexer::LTKeyword, true),
    KWD_TABLE(EQLU, Lexer::LTKeyword, true),
    KWD_TABLE(EQV, Lexer::LTKeyword, true),
    KWD_TABLE(ERRS, Lexer::LTKeyword, false),
    KWD_TABLE(EXECUTE, Lexer::LTKeyword, false),
    KWD_TABLE(EXITLOOP, Lexer::LTKeyword, true),
    KWD_TABLE(EXPAND, Lexer::LTKeyword, false),
    KWD_TABLE(EXTERNAL, Lexer::LTKeyword, true),
    KWD_TABLE(FIELD, Lexer::LTKeyword, true),
    KWD_TABLE(FORWARD, Lexer::LTKeyword, true),
    KWD_TABLE(FROM, Lexer::LTKeyword, true),
    KWD_TABLE(GENERAL, Lexer::LTKeyword, false),
    KWD_TABLE(GEQ, Lexer::LTKeyword, true),
    KWD_TABLE(GEQA, Lexer::LTKeyword, true),
    KWD_TABLE(GEQU, Lexer::LTKeyword, true),
    KWD_TABLE(GLOBAL, Lexer::LTKeyword, true),
    KWD_TABLE(GTR, Lexer::LTKeyword, true),
    KWD_TABLE(GTRA, Lexer::LTKeyword, true),
    KWD_TABLE(GTRU, Lexer::LTKeyword, true),
    KWD_TABLE(IDENT, Lexer::LTKeyword, false),
    KWD_TABLE(IF, Lexer::LTKeyword, true),
    KWD_TABLE(INCR, Lexer::LTKeyword, true),
    KWD_TABLE(INCRA, Lexer::LTKeyword, true),
    KWD_TABLE(INCRU, Lexer::LTKeyword, true),
    KWD_TABLE(INITIAL, Lexer::LTKeyword, true),
    KWD_TABLE(INRANGE, Lexer::LTKeyword, true),
    KWD_TABLE(INTERRUPT, Lexer::LTKeyword, false),
    KWD_TABLE(IOPAGE, Lexer::LTKeyword, true),
    KWD_TABLE(IOT, Lexer::LTKeyword, false),
    KWD_TABLE(JSB, Lexer::LTKeyword, false),
    KWD_TABLE(KEYWORDMACRO, Lexer::LTKeyword, true),
    KWD_TABLE(LABEL, Lexer::LTKeyword, true),
    KWD_TABLE(LANGUAGE, Lexer::LTKeyword, false),
    KWD_TABLE(LEAVE, Lexer::LTKeyword, true),
    KWD_TABLE(LEQ, Lexer::LTKeyword, true),
    KWD_TABLE(LEQA, Lexer::LTKeyword, true),
    KWD_TABLE(LEQU, Lexer::LTKeyword, true),
    KWD_TABLE(LIBRARY, Lexer::LTKeyword, true),
    KWD_TABLE(LINKAGE, Lexer::LTKeyword, true),
    KWD_TABLE(LIST, Lexer::LTKeyword, false),
    KWD_TABLE(LITERAL, Lexer::LTKeyword, true),
    KWD_TABLE(LOCAL, Lexer::LTKeyword, true),
    KWD_TABLE(LONG, Lexer::LTKeyword, true),
    KWD_TABLE(LONG_RELATIVE, Lexer::LTKeyword, false),
    KWD_TABLE(LSS, Lexer::LTKeyword, true),
    KWD_TABLE(LSSA, Lexer::LTKeyword, true),
    KWD_TABLE(LSSU, Lexer::LTKeyword, true),
    KWD_TABLE(MACRO, Lexer::LTKeyword, true),
    KWD_TABLE(MAIN, Lexer::LTKeyword, false),
    KWD_TABLE(MAP, Lexer::LTKeyword, true),
    KWD_TABLE(MAX, Lexer::LTPredeclared, false),
    KWD_TABLE(MAXA, Lexer::LTPredeclared, false),
    KWD_TABLE(MAXU, Lexer::LTPredeclared, false),
    KWD_TABLE(MIN, Lexer::LTPredeclared, false),
    KWD_TABLE(MINA, Lexer::LTPredeclared, false),
    KWD_TABLE(MINU, Lexer::LTPredeclared, false),
    KWD_TABLE(MOD, Lexer::LTKeyword, true),
    KWD_TABLE(MODULE, Lexer::LTKeyword, true),
    KWD_TABLE(NEQ, Lexer::LTKeyword, true),
    KWD_TABLE(NEQA, Lexer::LTKeyword, true),
    KWD_TABLE(NEQU, Lexer::LTKeyword, true),
    KWD_TABLE(NOASSEMBLY, Lexer::LTKeyword, false),
    KWD_TABLE(NOBINARY, Lexer::LTKeyword, false),
    KWD_TABLE(NOCODE, Lexer::LTKeyword, false),
    KWD_TABLE(NOCOMMENTARY, Lexer::LTKeyword, false),
    KWD_TABLE(NODEBUG, Lexer::LTKeyword, false),
    KWD_TABLE(NODEFAULT, Lexer::LTKeyword, false),
    KWD_TABLE(NOERRS, Lexer::LTKeyword, false),
    KWD_TABLE(NOEXECUTE, Lexer::LTKeyword, false),
    KWD_TABLE(NOEXPAND, Lexer::LTKeyword, false),
    KWD_TABLE(NOLIBRARY, Lexer::LTKeyword, false),
    KWD_TABLE(NONEXTERNAL, Lexer::LTKeyword, false),
    KWD_TABLE(NOOBJECT, Lexer::LTKeyword, false),
    KWD_TABLE(NOOPTIMIZE, Lexer::LTKeyword, false),
    KWD_TABLE(NOPIC, Lexer::LTKeyword, false),
    KWD_TABLE(NOPRESERVE, Lexer::LTKeyword, false),
    KWD_TABLE(NOREAD, Lexer::LTKeyword, false),
    KWD_TABLE(NOREQUIRE, Lexer::LTKeyword, false),
    KWD_TABLE(NOSAFE, Lexer::LTKeyword, false),
    KWD_TABLE(NOSHARE, Lexer::LTKeyword, false),
    KWD_TABLE(NOSOURCE, Lexer::LTKeyword, false),
    KWD_TABLE(NOSYMBOLIC, Lexer::LTKeyword, false),
    KWD_TABLE(NOT, Lexer::LTKeyword, true),
    KWD_TABLE(NOTRACE, Lexer::LTKeyword, false),
    KWD_TABLE(NOTUSED, Lexer::LTKeyword, false),
    KWD_TABLE(NOUNAMES, Lexer::LTKeyword, false),
    KWD_TABLE(NOVALUE, Lexer::LTKeyword, true),
    KWD_TABLE(NOWRITE, Lexer::LTKeyword, false),
    KWD_TABLE(NOZIP, Lexer::LTKeyword, false),
    KWD_TABLE(NULLPARAMETER, Lexer::LTPredeclared, true),
    KWD_TABLE(OBJECT, Lexer::LTKeyword, false),
    KWD_TABLE(OF, Lexer::LTKeyword, true),
    KWD_TABLE(OPTIMIZE, Lexer::LTKeyword, false),
    KWD_TABLE(OPTLEVEL, Lexer::LTKeyword, false),
    KWD_TABLE(OR, Lexer::LTKeyword, true),
    KWD_TABLE(OTHERWISE, Lexer::LTKeyword, true),
    KWD_TABLE(OUTRANGE, Lexer::LTKeyword, true),
    KWD_TABLE(OVERLAY, Lexer::LTKeyword, false),
    KWD_TABLE(OWN, Lexer::LTKeyword, true),
    KWD_TABLE(PIC, Lexer::LTKeyword, false),
    KWD_TABLE(PLIT, Lexer::LTKeyword, true),
    KWD_TABLE(PRESERVE, Lexer::LTKeyword, false),
    KWD_TABLE(PRESET, Lexer::LTKeyword, true),
    KWD_TABLE(PSECT, Lexer::LTKeyword, true),
    KWD_TABLE(READ, Lexer::LTKeyword, false),
    KWD_TABLE(RECORD, Lexer::LTKeyword, true),
    KWD_TABLE(REF, Lexer::LTKeyword, true),
    KWD_TABLE(REP, Lexer::LTKeyword, true),
    KWD_TABLE(REQUIRE, Lexer::LTKeyword, true),
    KWD_TABLE(RETURN, Lexer::LTKeyword, true),
    KWD_TABLE(ROUTINE, Lexer::LTKeyword, true),
    KWD_TABLE(SAFE, Lexer::LTKeyword, false),
    KWD_TABLE(SELECT, Lexer::LTKeyword, true),
    KWD_TABLE(SELECTA, Lexer::LTKeyword, true),
    KWD_TABLE(SELECTONE, Lexer::LTKeyword, true),
    KWD_TABLE(SELECTONEA, Lexer::LTKeyword, true),
    KWD_TABLE(SELECTONEU, Lexer::LTKeyword, true),
    KWD_TABLE(SELECTU, Lexer::LTKeyword, true),
    KWD_TABLE(SET, Lexer::LTKeyword, true),
    KWD_TABLE(SETUNWIND, Lexer::LTPredeclared, false),
    KWD_TABLE(SHARE, Lexer::LTKeyword, false),
    KWD_TABLE(SHOW, Lexer::LTKeyword, true),
    KWD_TABLE(SIGN, Lexer::LTPredeclared, false),
    KWD_TABLE(SIGNAL, Lexer::LTPredeclared, false),
    KWD_TABLE(SIGNAL_STOP, Lexer::LTPredeclared, false),
    KWD_TABLE(SIGNED, Lexer::LTKeyword, true),
    KWD_TABLE(SOURCE, Lexer::LTKeyword, false),
    KWD_TABLE(STACKLOCAL, Lexer::LTKeyword, true),
    KWD_TABLE(STANDARD, Lexer::LTKeyword, false),
    KWD_TABLE(STRUCTURE, Lexer::LTKeyword, true),
    KWD_TABLE(SWITCHES, Lexer::LTKeyword, true),
    KWD_TABLE(SYMBOLIC, Lexer::LTKeyword, false),
    KWD_TABLE(TES, Lexer::LTKeyword, true),
    KWD_TABLE(THEN, Lexer::LTKeyword, true),
    KWD_TABLE(TO, Lexer::LTKeyword, true),
    KWD_TABLE(TRACE, Lexer::LTKeyword, false),
    KWD_TABLE(UNAMES, Lexer::LTKeyword, false),
    KWD_TABLE(UNDECLARE, Lexer::LTKeyword, true),
    KWD_TABLE(UNSIGNED, Lexer::LTKeyword, true),
    KWD_TABLE(UNTIL, Lexer::LTKeyword, true),
    KWD_TABLE(UPLIT, Lexer::LTKeyword, true),
    KWD_TABLE(VECTOR, Lexer::LTPredeclared, false),
    KWD_TABLE(VERSION, Lexer::LTKeyword, false),
    KWD_TABLE(VOLATILE, Lexer::LTKeyword, true),
    KWD_TABLE(WEAK, Lexer::LTKeyword, true),
    KWD_TABLE(WHILE, Lexer::LTKeyword, true),
    KWD_TABLE(WITH, Lexer::LTKeyword, true),
    KWD_TABLE(WORD, Lexer::LTKeyword, true),
    KWD_TABLE(WORD_RELATIVE, Lexer::LTKeyword, false),
    KWD_TABLE(XOR, Lexer::LTKeyword, true),
    KWD_TABLE(ZIP, Lexer::LTKeyword, false)
};

void dump()
{
    for (int ii = 0; ii < KWD_MAX; ii++)
    {
        cout << ii <<
                ": " <<
                keywords[ii].keywordStr <<
                "(" <<
                keywords[ii].keyword <<
                ", " <<
                keywords[ii].keywordVal <<
                ", " <<
                (keywords[ii].reserved_builtin ? "True" : "False") <<
                ")\n";
    }
    return;
}