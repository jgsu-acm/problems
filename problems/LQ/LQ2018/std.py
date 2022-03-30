from datetime import date, timedelta

begin = date(2000, 1, 1)
end = date(2020, 10, 1)
cnt = 0
while begin <= end:
    cnt += 2 if begin.isoweekday() == 1 or begin.day == 1 else 1
    begin += timedelta(days=1)
print(cnt)
