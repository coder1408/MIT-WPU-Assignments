import time

class SlidingWindow:
    def __init__(self, window_size):
        self.window_size = window_size
        self.window = [None] * window_size
        self.timeout = 1  # Timeout in seconds
        self.sequence_number = 0
        self.base = 0
        self.next_seq_num = 0

    def send(self, data):
        while self.next_seq_num < self.base + self.window_size:
            self.window[self.next_seq_num % self.window_size] = (self.next_seq_num, data)
            print("Sending packet with sequence number:", self.next_seq_num)
            self.next_seq_num += 1

    def receive(self, ack):
        print("Received ACK:", ack)
        if ack >= self.base and ack < self.base + self.window_size:
            self.base = ack + 1
            print("Updated base to:", self.base)

    def timeout_handler(self):
        time.sleep(self.timeout)
        print("Timeout occurred. Resending packets from:", self.base)
        for i in range(self.base, self.next_seq_num):
            print("Resending packet with sequence number:", i)
        if self.base == self.next_seq_num:
            print("All packets are acknowledged.")

def main():
    window_size = 4
    sender = SlidingWindow(window_size)
    receiver = SlidingWindow(window_size)
    sender.send("Packet 0")
    sender.send("Packet 1")
    sender.send("Packet 2")
    sender.send("Packet 3")

    # Simulating ACK reception
    receiver.receive(0)
    receiver.receive(1)
    receiver.receive(2)
    receiver.receive(3)

    # Simulating a timeout
    sender.timeout_handler()

    # Simulating a successful transmission
    receiver.receive(4)

if __name__ == "__main__":
    main()
