#ifndef RULE_H_INCLUDED
#define RULE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum RuleComponentType {TERMINAL, NO_TERMINAL} RuleComponentType;

typedef struct Rule {
    char* symbol;
    struct RuleComponent* componentList;
    int ruleIndex;
    struct Rule* next;
} Rule;

typedef struct RuleComponent {
    char* symbol;
    RuleComponentType componentType;
    struct Rule* rulesList;
    struct RuleComponent* next;
} RuleComponent;

Rule* generateRuleInstance(char* symbol, int index);
RuleComponent* generateComponentInstance(char* symbol, RuleComponentType compType);
void insertRule(Rule* rule);
void insertRuleComponent(Rule* rule, RuleComponent* component);
void printRulesList();

#endif // RULE_H_INCLUDED
