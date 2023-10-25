romans = ['M', 'CM', 'D', 'CD', 'C', 'XC',
          'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
dec = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]


def toRoman(value: int) -> str:
    result = ''
    i = 0
    while (value > 0):
        if value - dec[i] >= 0:
            result += str(romans[i])
            value -= dec[i]
        else:
            i += 1
    return result


def toRoman2(value: int) -> str:
    I = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
    X = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
    C = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
    M = ['', 'M', 'MM', 'MMM']
    return M[value // 1000] + C[(value % 1000)//100] + X[(value % 100)//10] + I[value % 10]
