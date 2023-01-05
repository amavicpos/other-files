from random import randrange, shuffle

def quicksort_two_lists(list, list2, start, end):
  # this portion of list has been sorted
  if start >= end:
    return
  # select random element to be pivot
  pivot_idx = randrange(start, end + 1)
  pivot_element = list[pivot_idx]
  # swap random element with last element in sub-lists
  list[end], list[pivot_idx] = list[pivot_idx], list[end]
  list2[end], list2[pivot_idx] = list2[pivot_idx], list2[end]

  # tracks all elements which should be to left (greater than) pivot
  greater_than_pointer = start
  
  for i in range(start, end):
    # we found an element out of place
    if list[i] > pivot_element:
      # swap element to the right-most portion of greater elements
      list[i], list[greater_than_pointer] = list[greater_than_pointer], list[i]
      list2[i], list2[greater_than_pointer] = list2[greater_than_pointer], list2[i]
      # tally that we have one more greater element
      greater_than_pointer += 1
  # move pivot element to the right-most portion of greater elements
  list[end], list[greater_than_pointer] = list[greater_than_pointer], list[end]
  list2[end], list2[greater_than_pointer] = list2[greater_than_pointer], list2[end]
  # recursively sort left and right sub-lists
  quicksort_two_lists(list, list2, start, greater_than_pointer - 1)
  quicksort_two_lists(list, list2, greater_than_pointer + 1, end)

class Restaurant:
    def __init__(self, name, location, price, type, space, reviews):
        self.name = name
        self.location = location
        self.price = price
        self.type = type
        self.space = space
        self.reviews = reviews

    def __repr__(self):
        description = "{}\nLocation: {}\nValue for money: {}/5\nType: {}\nSpace: {}/5\nOverall rate of reviews: {}/5".format(self.name, self.location, self.price, self.type, self.space, self.reviews)
        return description

veggie_world = Restaurant("Veggie World", "London City", 3, "Vegan", 3, 4)
tomato_love = Restaurant("Tomato Love", "Greenwich", 4, "Ovo-lacto vegetarian", 4, 4)
plant_rainbow = Restaurant("Plant Rainbow", "Camden", 2, "Ovo-lacto vegetarian", 5, 3)
vegan_teriyaki = Restaurant("Vegan Teriyaki", "Greenwich", 4, "Vegan", 4, 5)
peace_for_you = Restaurant("Peace for You", "London City", 3, "Vegan", 4, 4)
green_madness = Restaurant("Green Madness", "Camden", 3, "Ovo-lacto vegetarian", 4, 4)
sauce_for_the_soul = Restaurant("Sauce for the Soul", "London City", 4, "Ovo-lacto vegetarian", 2, 4)
kill_the_salad = Restaurant("Kill the Salad", "London City", 3, "Vegan", 3, 4)
seitan_and_co = Restaurant("Seitan and Company", "Camden", 3, "Ovo-lacto vegetarian", 4, 4)
eat_your_greens = Restaurant("Eat your Greens", "London City", 4, "Ovo-lacto vegetarian", 3, 5)

restaurants_dict = {veggie_world: 0, tomato_love: 0, plant_rainbow: 0, vegan_teriyaki: 0, peace_for_you: 0, green_madness: 0, \
    sauce_for_the_soul: 0, kill_the_salad: 0, seitan_and_co: 0, eat_your_greens: 0}

while True:
  location = input("Is location important? Enter yes/no: ")
  if location in {"yes", "no"}:
    break
  print("Please enter a valid answer: yes/no.")

if location == "yes":
  while True:
    location = input("Where would you like to eat?\n1. London City\n2. Greenwich\n3. Camden\nEnter the corresponding number: ")
    if location in {"1", "2", "3"}:
      break
    print("Please enter a valid answer: 1, 2 or 3.")

  if location == "1":
    for key in restaurants_dict.keys():
      if key.location == "London City":
        restaurants_dict[key] += 5
      elif key.location == "Greenwich":
        restaurants_dict[key] += 1
      elif key.location == "Camden":
        restaurants_dict[key] += 2
  elif location == "2":
    for key, value in restaurants_dict.items():
      if key.location == "London City":
        restaurants_dict[key] += 1
      elif key.location == "Greenwich":
        restaurants_dict[key] += 5
  elif location == "3":
    for key, value in restaurants_dict.items():
      if key.location == "London City":
        restaurants_dict[key] += 2
      elif key.location == "Camden":
        restaurants_dict[key] += 5

while True:
  price = input("Is quality for money important? Enter yes/no: ")
  if price in {"yes", "no"}:
    break
  print("Please enter a valid answer: yes/no.")

while True:
  type = input("What type of cuisine do you prefer? Enter vegan/ovo-lacto vegetarian: ")
  if type in {"vegan", "ovo-lacto vegetarian"}:
    break
  print("Please enter a valid answer: vegan/ovo-lacto vegetarian.")

while True:
  space = input("Is having space and being comfortable important? Enter yes/no: ")
  if space in {"yes", "no"}:
    break
  print("Please enter a valid answer: yes/no.")

while True:
  reviews = input("Is the general rating of customers important? Enter yes/no: ")
  if reviews in {"yes", "no"}:
    break
  print("Please enter a valid answer: yes/no.")

for key in restaurants_dict.keys():
  if price == "yes":
    restaurants_dict[key] += key.price
  if key.type == type:
    restaurants_dict[key] += 3
  if space == "yes":
    restaurants_dict[key] += key.space
  if reviews == "yes":
    restaurants_dict[key] += key.reviews

keys = list(restaurants_dict.keys())
values = list(restaurants_dict.values())

quicksort_two_lists(values, keys, 0, len(values)-1)
order = 1
pre_value = values[0]
print("\nRestaurant recommendations, from most suitable to least:")
for key, value in zip(keys, values):
  if pre_value != value:
    order += 1
  print(str(order) + ".", key, "\n")
  pre_value = value
