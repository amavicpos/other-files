# Website of recipe search
# https://developer.edamam.com/edamam-recipe-api
import requests

# Recipe Search and Nutrition Analysis API
def recipe_search(ingredient):
  app_id = 'd56bb5e6'
  app_key = 'e3f81ed71476c191fe6d4b7c64122ad7'
  # Fetch the data
  result = requests.get('https://api.edamam.com/search?q={}&app_id={}&app_key={}'.format(ingredient, app_id, app_key))
  data = result.json()
  return data['hits']

def ingredient_search(ingredient):
  app_id = '6a0cc010'
  app_key = '397585fdd21125d3b58e449b9c05eb94'
  # Fetch the data
  result = requests.get('https://api.edamam.com/api/nutrition-data?app_id={}&app_key={}&nutrition-type=logging&ingr={}'.format(app_id, app_key, ingredient))
  data = result.json()
  return data

def run():
  ingredient = input('Enter an ingredient: ')
  min_weight = input('Enter the minimum weight of all the ingredients combined (grams): ')
  results = recipe_search(ingredient)
  # Filter results by weight:
  results_filtered = list(filter(lambda result: result['recipe']['totalWeight']>float(min_weight), results))
  # Sort results by weight:
  results_sorted_weight = sorted(results_filtered, key=lambda result: result['recipe']['totalWeight'])
  # Nutrition analysis of ingredient:
  nutrition = ingredient_search(ingredient)
  print('Nutrition analysis of ' + ingredient + ':')
  print('Calories: ' + str(nutrition['calories']) + ' in ' + str(nutrition['totalWeight']) + ' grams\n')

  with open('recipe_list.txt', 'w+') as text_file:
    print('Results ordered by weight:')
    # Save results to a file:
    text_file.write('Nutrition analysis of ' + ingredient + ':\n')
    text_file.write('Calories: ' + str(nutrition['calories']) + ' in ' + str(nutrition['totalWeight']) + ' grams\n\n')

    text_file.write('Results ordered by weight:\n')
    for result in results_sorted_weight:
      recipe = result['recipe']

      print(recipe['label'] + '\n' + recipe['url'])
      print('Weight:', recipe['totalWeight'], '\n')

      text_file.write(recipe['label'] + '\n' + recipe['url'] + '\n')
      text_file.write('Weight: {}\n\n'.format(recipe['totalWeight']))

run()
