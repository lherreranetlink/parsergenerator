#include "rule.h"

static Rule* firstRule;

Rule* generateRuleInstance(char* symbol, int index)
{
    Rule* newRule = (Rule*) malloc(sizeof(Rule));
    newRule->symbol = (char*) malloc(sizeof(strlen(symbol)));
    strcpy(newRule->symbol, symbol);
    newRule->componentList = NULL;
    newRule->next = NULL;
    newRule->ruleIndex = index;

    return newRule;
}

RuleComponent* generateComponentInstance(char* symbol, RuleComponentType compType)
{
    RuleComponent* newComp = (RuleComponent*) malloc(sizeof(RuleComponent));
    newComp->symbol = (char*) malloc(sizeof(strlen(symbol)));
    strcpy(newComp->symbol, symbol);
    newComp->componentType = compType;
    newComp->next = NULL;
    newComp->rulesList = NULL;

    return newComp;
}

void insertRule(Rule* rule)
{
    if (firstRule == NULL)
        firstRule = rule;
    else
    {
        Rule* aux;
        for (aux = firstRule; aux->next != NULL; aux = aux->next);
        aux->next = rule;
    }

}

void insertRuleComponent(Rule* rule, RuleComponent* component)
{
    RuleComponent* aux = rule->componentList;
    if (aux == NULL)
        rule->componentList = component;
    else
    {
        for(; aux->next != NULL; aux = aux->next);
        aux->next = component;
    }
}

void printRulesList()
{
    if (firstRule != NULL)
    {
        Rule* aux;
        for(aux = firstRule; aux != NULL; aux = aux->next)
        {
            fprintf(stdout, "Rule: %s\n", aux->symbol);
            RuleComponent* aux2;
            for (aux2 = aux->componentList; aux2 != NULL; aux2 = aux2->next)
                fprintf(stdout, "Component: %s\n", aux2->symbol);

            fprintf(stdout, "\n");
        }
    }
}
