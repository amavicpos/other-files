#Arithmetic Logic Unit (addition)
def NAND_gate(a, b):
    if a:
        if b:
            return 0
    return 1

def NOT_gate(a):
    return NAND_gate(a,a)

def AND_gate(a, b):
    return NOT_gate(NAND_gate(a, b))

def OR_gate(a, b):
    return NAND_gate(NAND_gate(a, a), NAND_gate(b, b))

def XOR_gate(a, b):
    return AND_gate(NAND_gate(a, b), OR_gate(a, b))

def half_adder(a, b):
    s = XOR_gate(a, b)
    c = AND_gate(a, b)
    return (s, c)

def full_adder(a, b, c):
    s = half_adder(half_adder(a, b)[0], c)[0]
    c_out = OR_gate(half_adder(a, b)[1], half_adder(half_adder(a, b)[0], c)[1])
    return (s, c_out)

def ALU(a, b, c, opcode):
    if opcode == 0:
        return half_adder(a, b)
    if opcode == 1:
        return full_adder(a ,b, c)

#Example: 0 + 1 and carry-in bit = 1
print(full_adder(0, 1, 1))
