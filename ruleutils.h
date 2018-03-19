#ifndef RULEUTILS_H_INCLUDED
#define RULEUTILS_H_INCLUDED
#include <string.h>
#include "rule.h"

typedef struct RuleRelatedNoTerm
{
    Rule* rule;
    char* noTermSymbol;
    struct RuleRelatedNoTerm* next;
} RuleRelatedNoTerm;

RuleRelatedNoTerm* generateNewRuleRelatedNoTerm(Rule* rule, char* symbol);
void insertNextRuleRelatedNoTerm(RuleRelatedNoTerm* node);

#endif // RULEUTILS_H_INCLUDED
