from decimal import Decimal

line = input()
num = float(line)
num = '{:.4E} => '.format(Decimal(num))

print(num)