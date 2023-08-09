import copy
import random
# Consider using the modules imported above.

class Hat:
    def __init__(self, **colors):
        self.contents = list()
        for color, number in colors.items():
            l = [color for x in range(number)]
            self.contents.extend(l)
    def draw(self, number):
        try :
            removed_balls = random.sample(self.contents, number)
            for each in removed_balls :
                self.contents.remove(each)
            return removed_balls
        except : return self.contents

def experiment(hat, expected_balls, num_balls_drawn, num_experiments):
    M = 0
    for i in range(num_experiments):
        expected_copy = copy.deepcopy(expected_balls)
        hat_copy = copy.deepcopy(hat)
        drawn = hat_copy.draw(num_balls_drawn)
        for color in drawn :
            if color in expected_copy :
                expected_copy[color] -= 1
        boolean = list()
        for i in expected_copy.values() :
            if i <= 0 :
                boolean.append(1)
            else : boolean.append(0)
        if sum(boolean) == len(boolean) :
            M += 1
    return M / num_experiments
