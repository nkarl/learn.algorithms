intervals1 = [[0, 30], [5, 10], [15, 20]]
intervals2 = [[7, 10], [2, 4]]


def meetingRoom(meetings):
    ms = sorted(meetings, key=lambda x: int(x[0]))
    print(ms)
    start = ms[0][0]
    end = ms[-1][1]
    print(start, end)
    rooms = 1
    for i in range(1, len(ms)):
        if ms[i][0] < ms[i-1][0]:
            rooms += 1
    return rooms


res = meetingRoom(intervals1)
print(res)
