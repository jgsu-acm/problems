from datetime import date, timedelta

d1 = date(1921, 7, 23)
d2 = date(2020, 7, 1)
cnt = 0
while d1 < d2:
    cnt += 24*60
    d1 += timedelta(days=1)
print(cnt)
