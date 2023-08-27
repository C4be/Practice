import matplotlib.pyplot as plt

x = []  # Минимальная длина
y = []  # Простое число

# Чтение данных из файла
with open("results.txt", "r") as file:
    for line in file:
        min_length, prime = map(int, line.split())
        x.append(min_length)
        y.append(prime)

# Построение графика
plt.plot(y, x, marker='o', linestyle='-', color='b')
plt.xlabel('Prime Number')
plt.ylabel('Minimum Length')
plt.title('Minimum Length vs Prime Number')
plt.grid(True)
plt.show()