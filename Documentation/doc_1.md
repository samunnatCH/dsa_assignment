# Parentheses Balance Checker


## Functions Implemented

**1. void add(char ch)**
- Pushes a character onto the stack
- Increments stackTop and stores ch at the new top position

**2. char removeTop()**
- Pops and returns the top character from the stack
- Returns '\0' if stack is empty

**3. int match(char a, char b)**
- Checks if two brackets form a valid pair
- Valid pairs: (), {}, []
- Returns 1 if match, 0 otherwise

**4. int isBalanced(char str[])**
- Main algorithm to check bracket balance
- Process:
  - Push opening brackets (, {, [ onto stack
  - For closing brackets ), }, ]: pop from stack and check if they match
  - Return 1 if stack is empty at end (balanced), 0 otherwise (not balanced)

## Main Method Organization

1. Prints program header
2. Defines three test cases:
   - Test 1: "a+(b-c)*(d" - Missing closing parenthesis
   - Test 2: "m+[a-b*(c+d*{m)]" - Mismatched brackets
   - Test 3: "a+(b-c)" - Properly balanced
3. For each test:
   - Displays the test string
   - Calls isBalanced() and prints result