address = "1.1.1.1"
output = "1[.]1[.]1[.]1"


def defang(address):
    return "".join(['[.]' if x == '.' else x for x in address])


result = defang(address)
print(result)
