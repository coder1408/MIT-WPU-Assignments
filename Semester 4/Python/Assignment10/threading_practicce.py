import threading

def print_one():
    for i in range(10):
        print(1)

def print_two():
    for i in range(10):
        print(2)

t1 = threading.Thread(target=print_one)
t2 = threading.Thread(target=print_two)

t1.start()
t2.start()

t1.join()
t2.join()

print("Done!")