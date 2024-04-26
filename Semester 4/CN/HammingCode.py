# %% [markdown]
# ## Hamming's Code for error detection and correction

# %%
# Taking input from user
num = input("Enter binary data with spaces: ")
binary_list = num.split()
num = num.replace(" ", "")
d = len(num)
print(binary_list)
print(d)

# %%
# Finding value of r
r = 0
while(2**r < d + r + 1):
    r += 1
n = d + r
print(r)
print("Code Word Length: ", n)

# %%
# placing parity bits in the code
reversed_list = binary_list[::-1]
pos = 1
for i in range(r):
    reversed_list.insert(2**i - 1, f'r{pos}')
    pos += 1
print(reversed_list)

# %%
# converting str to int
pos = 0
for i, element in enumerate(reversed_list):
    if element == f'r{pos}':
        continue
    elif element == '0' or element == '1':
        reversed_list[i] = int(element)
    pos += 1
print(reversed_list)

# %%
pos = 0
for i in range(r):
    # Calculate the value of each parity bit
    parity_bit_pos = 2**i
    parity_bit_value = 0

    for j in range(parity_bit_pos - 1, n, 2 * parity_bit_pos):
        for k in range(j, min(j + parity_bit_pos, n)):
            if isinstance(reversed_list[k], int):
                parity_bit_value ^= reversed_list[k]

    reversed_list[parity_bit_pos - 1] = parity_bit_value
    pos += 1
print(reversed_list)

# %%
binary_list = reversed_list[::-1]
print("Final Code Word: ", binary_list)

# %%
#introducing error in data
error_index = input("Enter the position to change: ")
changed_list = list(binary_list)
error_index = int(error_index)
if changed_list[error_index] == 0:
    changed_list[error_index] = 1
else:
    changed_list[error_index] = 0
print("Code Word after changing: ", changed_list)

# %%
error = 0
for i in range(r):
    # Calculate the value of each parity bit
    parity_bit_pos = 2**i
    parity_bit_value = 0

    for j in range(parity_bit_pos - 1, n, 2 * parity_bit_pos):
        for k in range(j, min(j + parity_bit_pos, n)):
            if isinstance(changed_list[k], int):
                parity_bit_value ^= changed_list[k]
    
    if(parity_bit_value != changed_list[parity_bit_pos - 1]):
        error += parity_bit_pos

# If the error is non-zero, correct the error
if error != 0:
    error = error_index
    changed_list[error_index] = 1 - changed_list[error_index]  # Correct the error
corrected_list = changed_list

print("Error Found at index:", error_index)
print("Corrected Codeword is:", corrected_list)


