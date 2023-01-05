# ConnectFour.py
import numpy as np

class player:
    def __init__(self, name, symbol):
        self.name = name
        self.symbol = symbol

def droppiece(playeer):
    err = True
    while err == True:
        position = int(input("{}: Drop your piece in the desired position: 1 2 3 4 5 6 7 ".format(playeer.name))) - 1
        try:
            row_position = np.where(table[:, position] == "-")[0][-1]
            err = False
        except: #Computer throws an exception if the position is not valid:
            print("Column full or invalid position! Program will end because of the error. Please choose another position.")
            err = True
        
    table[row_position, position] = "{}".format(playeer.symbol)

def showtable(table, rows_table):
    for x in range(rows_table):
        print(" ".join(table[x]))

def chechwin(table, rows_table, columns_table):
    for x in range(rows_table):
        for y in range(columns_table-3):
            if table[x,y] != "-" and table[x,y] == table[x,y+1] == table[x,y+2] == table[x,y+3]: return True

    for y in range(columns_table):
        for x in range(rows_table-3):
            if table[x,y] != "-" and table[x,y] == table[x+1,y] == table[x+2,y] == table[x+3,y]: return True
    
    for x in range(rows_table-3):
        for y in range(columns_table-3):
            if table[x,y] != "-" and table[x,y] == table[x+1,y+1] == table[x+2,y+2] == table[x+3,y+3]: return True
    
    for x in range(rows_table-3):
        for y in range(3,columns_table):
            if table[x,y] != "-" and table[x,y] == table[x+1,y-1] == table[x+2,y-2] == table[x+3,y-3]: return True

    return False

#Set up the table and players for the game:
table = np.array([["-", "-", "-", "-", "-", "-", "-"]] * 6)
rows_table = np.size(table, axis = 0)
columns_table = np.size(table, axis = 1)
player1 = player("Player 1", "x")
player2 = player("Player 2", "o")

print("Welcome to Connect Four! Let's start the game...")

while True: #Loops game until someone wins
    #First player drops their piece:
    droppiece(player1)
    showtable(table, rows_table)
    if chechwin(table, rows_table, columns_table) == True:
        print("Game ended! Congratulations to {}.".format(player1.name))
        sys.exit()

    #Second player drops their piece:
    droppiece(player2)
    showtable(table, rows_table)
    if chechwin(table, rows_table, columns_table) == True:
        print("Game ended! Congratulations to {}.".format(player2.name))
        sys.exit()
    
    if len(np.where(table == "-")[0]) == 0:
        print("Game ended! It's a draw.")
