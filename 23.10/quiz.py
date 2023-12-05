import json
import random

# Чтение данных из файла JSON
def read_quiz_data(file_name):
    try:
        with open(file_name, 'r') as file:
            quiz_data = json.load(file)
        return quiz_data
    except FileNotFoundError:
        print(f"Файл {file_name} не найден.")
        return []

# Создание викторины на основе данных
def create_quiz(quiz_data, num_questions=5):
    quiz = random.sample(quiz_data, num_questions)  # Случайно выбираем вопросы
    return quiz

# Отображение вопросов и вариантов ответов для викторины
def display_quiz(quiz):
    for i, question in enumerate(quiz, 1):
        print(f"Вопрос {i}: {question['question']}")
        for option, answer in question['answers'].items():
            print(f"{option}. {answer}")
        print()

# Проверка ответов
def check_answers(quiz, responses):
    correct_answers = 0
    for i, question in enumerate(quiz, 1):
        user_answer = responses[i - 1]
        correct_answer = question['rightAnswer']
        if user_answer == correct_answer:
            correct_answers += 1
    return correct_answers

if __name__ == "__main__":
    file_name = "questions.json"
    quiz_data = read_quiz_data(file_name)

    if quiz_data:
        num_questions = 3  # Число вопросов для викторины
        quiz = create_quiz(quiz_data, num_questions)

        print("Добро пожаловать в викторину!")
        display_quiz(quiz)

        responses = []
        for i in range(1, num_questions + 1):
            response = input(f"Введите ответ на вопрос {i}: ")
            responses.append(response)

        correct = check_answers(quiz, responses)
        print(f"Вы правильно ответили на {correct} из {num_questions} вопросов.")
    else:
        print("Не удалось загрузить вопросы для викторины.")
