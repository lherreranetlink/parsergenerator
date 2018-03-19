#include "ruleutils.h"

static RuleRelatedNoTerm* relatedListHeader;

RuleRelatedNoTerm* generateNewRuleRelatedNoTerm(Rule* rule, char* symbol)
{
    RuleRelatedNoTerm* newRelated = (RuleRelatedNoTerm*) malloc(sizeof(RuleRelatedNoTerm));
    newRelated->rule = rule;
    newRelated->noTermSymbol = (char*) malloc(sizeof(strlen(symbol)));
    strcpy(newRelated->noTermSymbol, symbol);
    newRelated->next = NULL;

    return newRelated;
}

void insertNextRuleRelatedNoTerm(RuleRelatedNoTerm* node)
{
    if (relatedListHeader == NULL)
        node = relatedListHeader;
    else
    {
        RuleRelatedNoTerm* aux;
        for (aux = relatedListHeader; aux->next != NULL; aux = aux->next);
        aux->next = node;
    }
}
