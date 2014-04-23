//
//  Print.cpp
//  Lab4
//
//  Created by Bryce Holton.
//	Updated by:
//	Savannah Puckett (snpucket)
//	Ashley Kruger (alkruege)
//	Emily Falkner (emilymarie)
//	Scott Dexhimer (SDexh)
//	Git Hub URL: https://github.com/Thelandofsunshine/Revenge-of-the-Sunshine

#include "Print.h"
#include "Literal.h"

const char* const SYMBOL_STRINGS[] =
{
    "<no token>", "<IDENTIFIER>", "<NUMBER>", "<STRING>",
    "^","*","(",")","-","+","=","[","]",":",";",
    "<",">",",",".","/",":=","<=",">=","<>","..",
    "<END OF FILE>", "<ERROR>",
    "AND","ARRAY","BEGIN","CASE","CONST","DIV","DO","DOWNTO",
    "ELSE","END","FILE","FOR","FUNCTION","GOTO","IF","IN",
    "LABEL","MOD","NIL","NOT","OF","OR","PACKED","PROCEDURE",
    "PROGRAM","RECORD","REPEAT","SET","THEN","TO","TYPE","UNTIL",
    "VAR","WHILE","WITH",
};

Print::Print(char source_name[], char date[])
{
    this->sourceFileName = string(source_name);
    this->currentDate = string(date);
    this->pageNumber = 0;
    this->lineCount = MAX_LINES_PER_PAGE;
}
Print::~Print()
{
    
}
void Print::printLine(char line[])
{
    char save_ch = '\0';
    char *save_chp = NULL;
    
    if (++lineCount > MAX_LINES_PER_PAGE)
    {
        printPageHeader();
        lineCount = 1;
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH)
    {
        save_chp = &line[MAX_PRINT_LINE_LENGTH];
    }
    if (save_chp)
    {
        save_ch = *save_chp;
        *save_chp = '\0';
    }
	//null is used as an indicator that the token
	//will be printed elsewhere
	if('\0' != line[0])
	{
		printf("%s", line);
	}
    if (save_chp)
    {
        *save_chp = save_ch;
    }
}
void Print::printPageHeader()
{
    putchar(FORM_FEED_CHAR);
    printf("Page    %d  %s  %s\n\n", ++pageNumber, sourceFileName.c_str(), currentDate.c_str());
}
void Print::printLit(Literal *token)
{
	//calls a blank print to advance the line number tracker
    printLine('\0');
	//actually prints the token
	token->print();
}
int Print::getLineCount()
{
    return this->lineCount;
}
void Print::printTreeRecursive(Literal *identifier)
{
    char line[MAX_SOURCE_LINE_LENGTH + 32];
    
    if (identifier->getLeftChild() != NULL)
    {
        printTreeRecursive(identifier->getLeftChild());
    }
    sprintf(line, " %-16s %-s", identifier->getTokenString().c_str(), " ");
    printLine(line);
    
    LineNumberList *list = identifier->getLineNumberList();
    while (list != NULL)
    {
        cout << list->getLineNumber() << "\t";
        list = list->getNextLineNumber();
    }
    cout << "\n";
    if (identifier->getRightChild() != NULL)
    {
        printTreeRecursive(identifier->getRightChild());
    }
}
void Print::printTree(Literal *identifier)
{
    cout << "\n Cross Reference Information\n";
    cout << " Identifier \t\tLine Numbers\n";
    cout << " -----------\t\t------------\n";
    printTreeRecursive(identifier);
}
