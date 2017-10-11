import sys
from datetime import date

xmas = date(2016, 12, 25)

for line in sys.stdin:
    line = line.split()
    
    month = int(line[0])
    day = int(line[1])

    in_date = date(2016, month, day)
    days_passed = (xmas - in_date).days

    if days_passed == 0:
        print('E natal!')
    elif days_passed == 1:
        print('E vespera de natal!')
    elif days_passed < 0:
        print('Ja passou!')
    else:
        print('Faltam {} dias para o natal!'.format(days_passed))
