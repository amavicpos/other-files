def arithmetic_arranger(problems, result = False):
    import re
    line1 = []
    line2 = []
    line3 = []
    line4 = []
    results = []

    #Errors
    if len(problems) > 5 :
        return 'Error: Too many problems.'
        quit()
    for problem in problems :
        if '+' not in problem and '-' not in problem :
            return "Error: Operator must be '+' or '-'."
            quit()
        numbers = re.split(r' . ', problem)
        for number in numbers :
            if re.search(r'\D', number) :
                return 'Error: Numbers must only contain digits.'
                quit()
            if len(number) > 4 :
                return 'Error: Numbers cannot be more than four digits.'
                quit()

    #Arranging
    for problem in problems :
        numbers = re.split(r' . ', problem)
        operator = str(re.findall('[+|-]', problem))
        operator = operator[2]
        length_line = len(max(numbers, key = len)) + 2
        length_space1 = length_line - len(numbers[0])
        length_space2 = length_line - 1 - len(numbers[1])
        line1.append(' ' * length_space1 + numbers[0])
        line2.append(operator + ' ' * length_space2 + numbers[1])
        line3.append('-' * length_line)
        if result == True :
            if operator == '+' :
                results.append(int(numbers[0]) + int(numbers[1]))
            elif operator == '-' :
                results.append(int(numbers[0]) - int(numbers[1]))
            length_space3 = length_line - len(str(results[-1]))
            line4.append(' ' * length_space3 + str(results[-1]))

    sep = '    '
    if result == True :
        arranged_problems = sep.join(line1) + '\n' + sep.join(line2) + '\n' + sep.join(line3) + '\n' + sep.join(line4)
    else :
        arranged_problems = sep.join(line1) + '\n' + sep.join(line2) + '\n' + sep.join(line3)
    return arranged_problems
