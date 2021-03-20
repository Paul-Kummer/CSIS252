#pragma once

#include "queue/queueType.h"
#include "stack/stackType.h"
#include "token/token.h"

void populateInfixQ(Token userIn, queueType<Token>& preFixQ);
void populatePostfixQ(queueType<Token>& prefixQ, queueType<Token>& postFixQ, stackType<Token>& conversionStack);
Token evaluatePostFixExpression(queueType<Token>& postfixQ, stackType<Token>& evalStack);