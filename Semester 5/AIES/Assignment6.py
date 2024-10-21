from newspaper import Article
import random
import string
import nltk
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np
import warnings
warnings.filterwarnings('ignore')

nltk.download('punkt', quiet=True)
article = Article("https://www.mayoclinic.org/diseases-conditions/chronic-kidney-disease/symptoms-causes/syc-20354521")

article.download()
article.parse()
article.nlp()
corpus = article.text
#print(corpus)

text = corpus
sentence_list = nltk.sent_tokenize(text)
#print(sentence_list)

def bot_response(user_input):
    user_input = user_input.lower()
    sentence_list.append(user_input)
    bot_response = ''
    cm = CountVectorizer().fit_transform(sentence_list)
    similarity_scores = cosine_similarity(cm[-1], cm)
    similarity_scores_list = similarity_scores.flatten()
    index = np.argsort(similarity_scores_list)[::-1]
    index = index[1:]
    response_flag = 0
    j = 0

    for i in range(len(index)):
        if similarity_scores_list[index[i]] > 0.0:
            bot_response = bot_response + ' ' + sentence_list[index[i]]
            response_flag = 1
            j = j + 1
            if j > 2: 
                break
    if response_flag == 0:
        bot_response = bot_response + " I apologize, I don't understand."
    
    sentence_list.remove(user_input)
    return bot_response

def greeting_response(text):
    text = text.lower()
    bot_greetings = ["hi", "hey", "hello", "hola"]
    user_greetings = ["hi", "hey", "hello", "hola", "greetings"]
    
    for word in text.split():
        if word in user_greetings:
            return random.choice(bot_greetings)

print("Doc Bot: I am a doc bot for your services. I will answer your questions.")
exit_list = ["exit", "see you", "bye", "quit", "break"]

while True:
    user_input = input()

    if user_input.lower() in exit_list:
        print("Doc Bot: Chat with you later!")
        break
    else:
        if greeting_response(user_input) is not None:
            print('Doc Bot: ' + greeting_response(user_input))
        else:
            print('Doc Bot: ' + bot_response(user_input))
