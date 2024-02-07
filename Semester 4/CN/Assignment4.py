def hamming_encode(data):
    m = len(data)
    r = 1
    while 2**r < m + r + 1:
        r += 1

    # Create a list to store the encoded message with placeholders for parity bits
    encoded_message = [0] * (m + r)
    j = 0

    # Fill in the data bits in the encoded message
    for i in range(1, m + r + 1):
        if i == 2**j:
            j += 1
        else:
            # Check if there are still data bits left
            if j < m:
                encoded_message[i - 1] = int(data[j])
                j += 1

    # Calculate parity bits
    for i in range(r):
        parity_index = 2**i - 1
        parity = 0
        for j in range(1, m + r + 1):
            if (j & (2**i)) == (2**i):
                parity ^= encoded_message[j - 1]

        encoded_message[parity_index] = parity

    return encoded_message



def hamming_decode(encoded_message):
    r = 1
    while 2**r <= len(encoded_message):
        r += 1

    # Calculate parity bits
    for i in range(r):
        parity_index = 2**i - 1
        parity = 0
        for j in range(1, len(encoded_message) + 1):
            if (j & (2**i)) == (2**i):
                parity ^= encoded_message[j - 1]

        # If parity doesn't match, flip the bit
        if parity != encoded_message[parity_index]:
            encoded_message[parity_index] ^= 1

    decoded_message = [0] * (len(encoded_message) - r)
    j = 0

    for i in range(1, len(encoded_message) + 1):
        if i != 2**j:
            if j < len(decoded_message):
                decoded_message[j] = encoded_message[i - 1]
                j += 1

    return decoded_message


def simulate_error(encoded_message):
    error_position = int(input("Enter the position to simulate an error (1-indexed): "))
    if 1 <= error_position <= len(encoded_message):
        encoded_message[error_position - 1] ^= 1
        print("Simulated Error:", encoded_message)
        return True
    else:
        print("Invalid position. No error simulated.")
        return False

# Take user input for the data word
data = input("Enter the binary data word: ")
encoded_message = hamming_encode(data)
print("Code Word:", encoded_message)

# Simulate an error
if simulate_error(encoded_message):
    # Decode and correct the error
    decoded_message = hamming_decode(encoded_message)
    print("Decoded Message:", decoded_message)
    print("Error Detected and Corrected.")
    print("Correct Code Word:", encoded_message)
    print("Correct Data Word:", ''.join(map(str, decoded_message)))
