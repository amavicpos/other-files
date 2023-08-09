import re
import math
class Category:
    def __init__(self, category) :
        self.category = category
        self.ledger = list()
        self.balance = 0.0
    def __repr__(self):
        line1_length1 = round((30 - len(self.category))/2)
        line1_length2 = 30 - len(self.category) - line1_length1
        line1 = list()
        line1.append('*' * line1_length1 + self.category + '*' * line1_length2)
        sep = ''
        text = list()
        line1 = sep.join(line1)
        text.append(line1)
        for item in self.ledger :
            item = str(item)
            dest = re.split(r'\'description\': ', item)
            print(dest)
            des = re.findall(r".([A-Za-z \,]*).", dest[1])
            des = sep.join(des)
            des = des[:23]
            am = re.findall(r"'amount': (-?\d*\.?\d*?),", item)
            am = float(sep.join(am))
            am = str(format(am, '.2f'))
            am = am[:7]
            sp = 30 - len(des) - len(am)
            line = des + ' ' * sp + am
            text.append(line)
        text.append('Total: ' + str(self.balance))
        text = '\n'.join(text)
        return text
    def deposit(self, amount, description = "") :
        self.ledger.append({"amount": amount, "description": description})
        self.balance = self.balance + amount
    def withdraw(self, amount, description = "") :
        if self.check_funds(amount) == False :
            return False
        else :
            self.ledger.append({"amount": -amount, "description": description})
            self.balance = self.balance - amount
        return True
    def get_balance(self) :
        return self.balance
    def transfer(self, amount, category2) :
        if self.check_funds(amount) == False :
            return False
        else :
            self.withdraw(amount, 'Transfer to ' + str(category2.category))
            category2.deposit(amount, 'Transfer from ' + str(self.category))
        return True
    def check_funds(self, amount) :
        if amount > self.balance :
            return False
        else :
            return True

def create_spend_chart(categories):
    text1 = "Percentage spent by category"
    all = list()
    for category in categories :
        total = 0.0
        for item in category.ledger :
            item = str(item)
            withdr = re.findall(r"'amount': (-\d*\.?\d*?),", item)
            withdr = str(''.join(withdr))
            if withdr != '' :
                total = round(total + float(withdr), 2)
        all.append(total)
    per = list()
    i = 0
    while i < len(all) :
        per.append(math.floor(all[i]/sum(all)*10)*10)
        i = i + 1
    text = list()
    for i in range(0,110,10) :
        yes = list()
        for p in per :
            if p >= i :
                yes.append('o')
            else :
                yes.append(' ')
        a = 3 - len(str(i))
        line = list()
        line.append(' ' * a + str(i) + '| ')
        for el in yes :
            line.append(el + '  ')
        line = ''.join(line)
        text.append(line)
    text.reverse()
    text2 = '\n'.join(text)
    b = len(per)*3
    text3 = '    -' + '---' * len(per)
    lens = list()
    for cat in categories :
        lens.append(len(cat.category))
    i = 0
    text = list()
    while i < max(lens) :
        line = list()
        line.append(' ' * 5)
        for cat in categories :
            if i < len(cat.category) :
                line.append(cat.category[i] + '  ')
            else :
                line.append('   ')
        text.append(''.join(line))
        i = i + 1
    text4 = '\n'.join(text)
    text = text1 + '\n' + text2 + '\n' + text3 + '\n' + text4
    return text
