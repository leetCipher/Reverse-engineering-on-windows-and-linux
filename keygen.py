import random


def main():
    serial_key = []
    # first part of the serial key
    first_part = random.randint(1337, 3337)
    serial_key.append(first_part)

    # second part of the serial key
    second_part = random.randint(7337, 9337)
    serial_key.append(second_part)

    # third part of the serial key
    while True:
        third_part = random.randint(1000, 9999)
        if third_part % 2 != 0:
            serial_key.append(third_part)
            break

    # fourth part of the serial key
    while True:
        fourth_part = random.randint(1000, 9999)
        if fourth_part % 2 == 0:
            serial_key.append(fourth_part)
            break

    serial_key = "-".join([str(num) for num in serial_key])
    print(serial_key)


if __name__ == "__main__":
    main()
