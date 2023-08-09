class Rectangle:
    def __init__(self, width, height) :
        self.width = width
        self.height = height
    def __repr__(self):
        text = 'Rectangle(width=' + str(self.width) + ', height=' + str(self.height) + ')'
        return text
    def set_width(self, width):
        self.width = width
    def set_height(self, height):
        self.height = height
    def get_area(self):
        area = self.width * self.height
        return area
    def get_perimeter(self):
        perimeter = self.width * 2 + self.height * 2
        return perimeter
    def get_diagonal(self):
        diagonal = (self.width ** 2 + self.height ** 2) ** .5
        return diagonal
    def get_picture(self):
        if self.height > 50 or self.width > 50 :
            return "Too big for picture."
        else :
            i = 0
            shape = list()
            while i < self.height :
                shape.append('*' * self.width)
                i = i + 1
            shape = '\n'.join(shape) + '\n'
            return shape
    def get_amount_inside(self, template):
        template_area = template.width * template.height
        our_area = self.get_area()
        return our_area // template_area

class Square(Rectangle):
    def __init__(self, side):
        super().__init__(side, side)
    def __repr__(self):
        text = 'Square(side=' + str(self.width) + ')'
        return text
    def set_side(self, side):
        self.width = side
        self.height = side
    def set_width(self, side):
        self.set_side(side)
    def set_height(self, side):
        self.set_side(side)
