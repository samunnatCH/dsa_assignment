# Infix to Postfix Conversion 

## Functions Implemented

**1. void pushOp(char c)**
- Pushes an operator or parenthesis onto the operator stack
- Increments `opTop` and stores `c` at the new top position

**2. char popOp()**
- Pops and returns the top operator from the stack
- Returns `'\0'` if stack is empty

**3. char topOp()**
- Returns the top operator without removing it
- Returns `'\0'` if stack is empty

**4. int isOpStackEmpty()**
- Checks if the operator stack is empty
- Returns 1 if empty, 0 otherwise

**5. int isOp(char c)**
- Checks if a character is an operator (+, -, *, /)
- Returns 1 if operator, 0 otherwise

**6. int priority(char c)**
- Returns the precedence level of an operator
- `*` and `/` have priority 2
- `+` and `-` have priority 1
- Other characters have priority 0

**7. void convertToPostfix(char* input, char* output)**
- Converts an infix expression to postfix notation
- Algorithm:
  - If character is alphanumeric, add to output
  - If `(`, push to operator stack
  - If `)`, pop operators until `(` is found
  - If operator, pop operators with higher or equal priority, then push current operator
  - After processing all characters, pop remaining operators to output

**8. int calculate(char* postfix)**
- Evaluates a postfix expression containing single-digit numbers
- Uses a number stack to store operands
- Process:
  - If digit, push to number stack
  - If operator, pop two operands, perform operation, push result back
- Returns the final result

## Main Method Organization

1. Prints program header
2. Performs four test conversions:
   - Test 1: `"A+B*C"` - Expression with operator precedence
   - Test 2: `"(A+B)*C"` - Expression with parentheses
   - Test 3: `"5+3*2"` - Numeric expression with precedence (also evaluates result)
   - Test 4: `"(5+3)*2"` - Numeric expression with parentheses (also evaluates result)
3. For each test:
   - Resets operator stack (`opTop = -1`)
   - Converts infix to postfix
   - Prints infix and postfix expressions
   - For numeric expressions, calculates and prints the result