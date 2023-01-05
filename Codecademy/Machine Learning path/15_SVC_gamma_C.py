# Support Vector Classifier: finding gamma and C parameters to improve score
# The code can't be run because some files can't be copied to the repository

import matplotlib.pyplot as plt
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
# from svm_visualization import draw_boundary
# from players import aaron_judge, jose_altuve, david_ortiz
from itertools import permutations


def find_gamma_C_SVC(dataset):
    fig, ax = plt.subplots()
    dataset['type'] = dataset['type'].map({'S': 1, 'B': 0})
    dataset = dataset.dropna(subset=['type', 'plate_x', 'plate_z'])
    plt.scatter(dataset['plate_x'], dataset['plate_z'], c=dataset['type'], cmap=plt.cm.coolwarm, alpha=0.25)
    training_set, validation_set = train_test_split(dataset, test_size=0.33, random_state=1)

    max_score = 0
    max_gamma = 0
    max_C = 0
    for gamma, C in permutations(range(1, 10), 2):
        classifier = SVC(kernel='rbf', gamma=gamma, C=C)
        classifier.fit(training_set[['plate_x', 'plate_z']], training_set['type'])
        current_score = classifier.score(validation_set[['plate_x', 'plate_z']], validation_set['type'])
        if current_score > max_score:
            max_score = current_score
            max_gamma = gamma
            max_C = C

    print("Max score:", max_score)
    print("Gamma of max score:", max_gamma)
    print("C of max score:", max_C, "\n")
    classifier = SVC(kernel='rbf', gamma=max_gamma, C=max_C)
    classifier.fit(training_set[['plate_x', 'plate_z']], training_set['type'])
    ax.set_ylim(-2, 6)
    ax.set_xlim(-3, 3)
    # draw_boundary(ax, classifier)
    plt.xlabel('Plate x')
    plt.ylabel('Plate z')
    plt.show()


''' find_gamma_C_SVC(aaron_judge)
find_gamma_C_SVC(jose_altuve)
find_gamma_C_SVC(david_ortiz) '''
