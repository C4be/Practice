def run(p: int):
    q = (p - 1) // 2
    for x in range(1, p - 1):
        print(f'{x} - {pow(x, q, p)}')


def is_prime(number):
    if number <= 1:
        return False
    if number <= 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False

    i = 5
    while i * i <= number:
        if number % i == 0 or number % (i + 2) == 0:
            return False
        i += 6

    return True


if __name__ == '__main__':
    i = 0
    for p in range(1, 100):
        if is_prime(p):
            i += 1
            print(f'Experiment - {i}')
            run(p)
            print()
