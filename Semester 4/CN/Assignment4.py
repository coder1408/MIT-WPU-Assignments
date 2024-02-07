import numpy as np

def fill_code(code_word, r, data_word):
    for i in range(r):
        code_word[2**i - 1] = 20

    x = 0
    data_word = np.flip(data_word)
    for i in range(len(code_word)):
        if code_word[i] == -1:
            code_word[i] = data_word[x]
            x += 1
    return code_word

def remove_code(code_word, data_word, r):
    x = 0
    for i in range(len(code_word)):
        if i == 2**x - 1:
            x += 1
        else:
            data_word = np.append(data_word, code_word[i])

    data_word = np.flip(data_word)
    return data_word

def get_pos(r, d):
    pos = []
    for i in range(r):
        temp = []
        x = 2**i - 1
        flag = 0
        while x < r + d:
            if flag == 0:
                temp = np.append(temp, np.arange(x, min(x + 2**i, r + d)))
                x += 2**i
                flag = 1
            else:
                x += 2**i
                flag = 0
        pos.append(temp.astype(int))

    return pos

def create_code(data_word):
    r = 0
    while 2**r - r < len(data_word) + 1:
        r += 1

    code_word = np.full(len(data_word) + r, -1)
    code_word = fill_code(code_word, r, data_word)
    pos = get_pos(r, len(data_word))
    
    for i in range(r):
        count = np.count_nonzero(code_word[pos[i]] == 1)
        if count % 2 == 0:
            code_word[2**i - 1] = 0
        else:
            code_word[2**i - 1] = 1

    code_word = np.flip(code_word)
    return code_word

def solve_word(code_word):
    r = 0
    while 2**r < len(code_word):
        r += 1
    d = len(code_word) - r

    code_word = np.flip(code_word)
    data_word = np.array([])
    pos = get_pos(r, d)
    err = 0

    for i in range(r):
        count = np.count_nonzero(code_word[pos[i]] == 1)
        if count % 2 != 0:
            err += 2**i

    if err == 0:
        print("\nNo error found.\n")
    else:
        print(f"\nError found at pos {d + r - err + 1}.\n")

    data_word = remove_code(code_word, data_word, r)
    return data_word.astype(int)

def main():
    n = int(input("Enter data word or code word? (0/1): "))
    
    if n == 0:
        data_word = np.array([], dtype=int)
        x = int(input("Enter length of data word: "))
        print("Enter word:")
        for _ in range(x):
            a = int(input())
            data_word = np.append(data_word, a)

        code_word = create_code(data_word)
        print("\nCode word:")
        print(" ".join(map(str, code_word)))
    else:
        code_word = np.array([], dtype=int)
        x = int(input("Enter length of code word: "))
        print("Enter word:")
        for _ in range(x):
            a = int(input())
            code_word = np.append(code_word, a)

        data_word = solve_word(code_word)
        print("\nData word:")
        print(" ".join(map(str, data_word)))

if __name__ == "__main__":
    main()
