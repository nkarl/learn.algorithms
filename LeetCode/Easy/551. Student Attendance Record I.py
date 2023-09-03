s = "PPALLL"
output = True


def reduce(s: str):
    return s.count('A') <= 1 and s.count('LLL') == 0


def reduce2(s: str):
    absent = 0
    for i in range(len(s)):
        absent += 1 if s[i] == 'A' else 0
        if absent > 1:
            return False
        if s[i:i+3] == 'LLL':
            return False
    return True


result = reduce2(s)
print(s, result)
