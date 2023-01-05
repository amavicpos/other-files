# NAIVE BAYES CLASSIFIER WITH SKLEARN
from sklearn.datasets import fetch_20newsgroups
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import CountVectorizer
import random

first_object = fetch_20newsgroups()
targets = first_object.target_names
target1, target2 = random.sample(targets, 2)
print("Targets:", target1 + ",", target2, "\n")
train_emails = fetch_20newsgroups(subset='train', shuffle = True, random_state = 108, categories=[target1, target2])
test_emails = fetch_20newsgroups(subset='test', shuffle = True, random_state = 108, categories=[target1, target2])
print(train_emails.data[5])
print("Label of this data:", train_emails.target_names[train_emails.target[5]], "\n")

counter = CountVectorizer()
counter.fit(test_emails.data + train_emails.data)
train_counts = counter.transform(train_emails.data)
test_counts = counter.transform(test_emails.data)
classifier = MultinomialNB()
classifier.fit(train_counts, train_emails.target)
print("Score:", classifier.score(test_counts, test_emails.target))
