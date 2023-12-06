# Tic-Tac-Toe game

import random
import os
import time


def display_board(board):
    # Очистка консоли в зависимости от ОС
    os.system('cls' if os.name == 'nt' else 'clear')

    # Выведем пример доски с нумерацией ячеек, чтобы было легче ориентироваться
    for i in range(0, 9, 3):
        row = [f"{j}" for j in range(i, i + 3)]
        print(' | '.join(row))
        if i < 6:
            print('--+---+--')

    print("\n")

    # Выводим доску в текущем состоянии
    print(board[0] + ' | ' + board[1] + ' | ' + board[2])
    print('--+---+--')
    print(board[3] + ' | ' + board[4] + ' | ' + board[5])
    print('--+---+--')
    print(board[6] + ' | ' + board[7] + ' | ' + board[8])


def player_move(board, player):
    while True:
        try:
            move = int(
                input(f'Игрок {player}, выберите пустую ячейку (0-8): '))
            if board[move] == ' ':
                board[move] = player
                break
            else:
                print('Эта ячейка уже занята. Попробуйте другую.')
        except (ValueError, IndexError):
            print('Номер ячейки должен быть от 0 до 8.')


def computer_move(board, player, computer):
    # пытаемся найти следующий выигрышный ход
    for move in range(0, 9):
        if board[move] == ' ':
            board[move] = computer
            if check_winner(board, computer):
                return
            board[move] = ' '

    # смотрим нет ли у игрока следующего выигрышного ходи и блокируем если есть
    for move in range(0, 9):
        if board[move] == ' ':
            board[move] = player
            if check_winner(board, player):
                board[move] = computer
                return
            board[move] = ' '

    # занимаем случайную свободную угловую клетку 
    corners = [0, 2, 6, 8]
    random.shuffle(corners)
    for move in corners:
        if board[move] == ' ':
            board[move] = computer
            return

    # если друние варианты не подошли - забиваем центр
    if board[4] == ' ':
        board[4] = computer
    else:
        # если не вышло - занимаем любую свободную четную клетку
        for move in range(0, 9, 2):
            if board[move] == ' ':
                board[move] = computer
                return


def check_winner(board, player):
    # проверяем по горизонтали
    for i in range(0, 9, 3):
        if all(board[i + j] == player for j in range(3)):
            return True
    
    # проверяем по вертикали
    for i in range(3):
        if all(board[i + j] == player for j in range(0, 8, 3)):
            return True
    
    # проверяем обе диагонали
    if all(board[i] == player for i in range(0, 9, 4)) or all(board[i] == player for i in range(2, 7, 2)):
        return True
    return False


def is_board_full(board):
    return ' ' not in board


def main():
    board = [' '] * 9
    player = 'X'
    computer = 'O'

    display_board(board)
    while True:
        player_move(board, player)
        display_board(board)
        if check_winner(board, player):
            print(f'Поздравляю, человек, ты выиграл!')
            break
        if is_board_full(board):
            print('Ничья!')
            break
        
        print('Думаю...')
        time.sleep(1.5) # небольшая задержка перед ходом компьютера
        computer_move(board, player, computer)
        display_board(board)
        if check_winner(board, computer):
            print(f'Компьютер выиграл. Попробуй в другой раз.')
            break
        if is_board_full(board):            
            print('Ничья!')
            break


if __name__ == '__main__':
    main()
