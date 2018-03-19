#ifndef FILEREADER_H_INCLUDED
#define FILEREADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rule.h"
#include "ruleutils.h"
#include "ioutils.h"

typedef enum ReadRulesStates {INITIAL, CAPTURE_RULE, WAITING_COMPONENT, BEGIN_CAPTURE_COMP,
                              CAPTURE_TERMINAL_COMP, CAPTURE_NO_TERMINAL_COMP, END_CAPTURE_COMP, END_CAPTURE_GRAMMAR
                             } State;

void createRules(FILE* input);

#endif // FILEREADER_H_INCLUDED
