import threading

t = threading.current_thread()
print('Thread Name:', t.name)
print('Thread ID:', t.ident)
print('Thread is alive:', t.is_alive())

t.name = 'MyThread'
print('After name change:', t.name)