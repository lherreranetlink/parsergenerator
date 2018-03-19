#include "rulecreator.h"

void createRules(FILE* input)
{
    int state = INITIAL, continueRead = 1, rulesCount = 0;
    char c, symbol[BUFSIZ], *symbolp;
    Rule* currentRule;
    symbolp = symbol;
    initializeBuffer();
    while (!feof(input) && continueRead)
    {
        if ((state != CAPTURE_TERMINAL_COMP) && (state != END_CAPTURE_COMP))
            while (isspace(c = getnextchar(input)));
        else
            c = getnextchar(input);
        switch(state)
        {
        case INITIAL:
        {
            if (c == '<')
            {
                state = CAPTURE_RULE;
                break;
            }
            else if (c == EOF)
            {
                state = END_CAPTURE_GRAMMAR;
                break;
            }
            continueRead = 0;
        }
        break;
        case CAPTURE_RULE:
        {
            if (isalnum(c))
            {
                *symbolp++ = c;
                break;
            }
            else if(c == '>')
            {
                state = WAITING_COMPONENT;
                break;
            }
            continueRead = 0;
        }
        break;
        case WAITING_COMPONENT:
        {
            *symbolp = '\0';
            currentRule = generateRuleInstance(symbol, ++rulesCount);
            insertRule(currentRule);
            symbolp = symbol;
            if (c == '=')
            {
                state = BEGIN_CAPTURE_COMP;
                break;
            }
            continueRead = 0;
        }
        break;
        case BEGIN_CAPTURE_COMP:
        {
            if (c == '<')
                state = CAPTURE_NO_TERMINAL_COMP;
            else
            {
                state = CAPTURE_TERMINAL_COMP;
                ungetchar(c);
            }
        }
        break;
        case CAPTURE_TERMINAL_COMP:
        {
            for (; c == ' ' && symbolp == symbol; c = getnextchar(input));
            if (isspace(c))
            {
                state = END_CAPTURE_COMP;
                *symbolp = '\0';
                RuleComponent* newComp = generateComponentInstance(symbol, TERMINAL);
                insertRuleComponent(currentRule, newComp);
                symbolp = symbol;
                if (c == '\n')
                    ungetchar(c);
                break;
            }
            else
                *symbolp++ = c;
        }
        break;
        case CAPTURE_NO_TERMINAL_COMP:
        {
            if (isalnum(c))
            {
                *symbolp++ = c;
                break;
            }
            else if (c == '>')
            {
                state = END_CAPTURE_COMP;
                *symbolp = '\0';
                RuleComponent* newComp = generateComponentInstance(symbol, NO_TERMINAL);
                insertRuleComponent(currentRule, newComp);
                symbolp = symbol;
                break;
            }
            continueRead = 0;
        }
        break;
        case END_CAPTURE_COMP:
        {
            for (; c == ' '; c = getnextchar(input));
            switch(c)
            {
            case '\r':
            case '\n':
                state = INITIAL;
                break;
            case '<':
                state = CAPTURE_NO_TERMINAL_COMP;
                break;
            case EOF:
                state = END_CAPTURE_GRAMMAR;
                continueRead = 0;
                break;
            default:
                state = CAPTURE_TERMINAL_COMP;
                ungetchar(c);
            }
        }
        }
    }
    if (state != END_CAPTURE_GRAMMAR)
    {
        fprintf(stderr, "Unexpected symbol: %c\n", c);
        exit(1);
    }
    printRulesList();
}

