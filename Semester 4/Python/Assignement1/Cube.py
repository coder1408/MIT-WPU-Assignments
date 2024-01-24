list = []
for i in range(1,6,1):
    num = int(input(f"Enter number {i}: \n"))
    list.append(num)
for j in list:
    num = j*j*j
    print(f"Cube of {j} is {num}")