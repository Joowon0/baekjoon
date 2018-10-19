import sys
ins = sys.stdin.readline().strip()

# input correctness check
stack = []
for l in ins:
    if l == '(' or l == '[':
        stack.append(l)
    elif len(stack) == 0: # l == ')' or ']'
        print(0)
        sys.exit()
    elif l == ')' :
        if stack[-1] == '(':
            stack.pop()
        else :
            print(0)
            sys.exit()
    elif l == ']' :
        if stack[-1] == '[':
            stack.pop()
        else :
            print(0)
            sys.exit()
    else :
        print(0)
        sys.exit()
if len(stack) != 0:
    print(0)
    sys.exit()

# for correct input
stack = []

def addNum(num) :
    global stack
    if len(stack) == 0 :
        stack.append(num)
    elif stack[-1] != '(' and stack[-1] != '[' : # if number
        stack[-1] += num
    else :
        stack.append(num)
        
for l in ins:
    if l == '(' or l == '[' :
        stack.append(l)
    elif l == ')' or l == ']' :
        if stack[-1] == '(' or stack[-1] == '[' :
            stack.pop()
            if l == ')' :
                addNum(2)
            else :
                addNum(3)
        else :
            last = stack.pop()
            stack.pop()
            if l == ')':
                addNum(last * 2)
            else :
                addNum(last * 3)

print(stack[-1])
