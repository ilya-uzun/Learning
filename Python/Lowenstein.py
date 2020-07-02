str1 = "Привет"
str2 = "Приет"

def dist(a, b):
    def rec(i, j):
        if i == 0 or j == 0:
            # если строка пустая, то растояние раняется ее длине (n вставок)
            return max(i, j)
        elif a[i-1] == b[j-1]:
            # если последние символы одинаковые, просто съедаем их
            return rec(i-1, j-1)
        else:
            # иначе считаем минимальный вариант
            return 1+min(
                rec(i, j-1), # удаление символа
                rec(i-1, j), # вставка символа
                rec(i-1, j-1), # замена символа
            )

    return rec(len(a), len(b))

str1 = "Диана"
str2 = "Рита"

lev = dist(str1, str2)
lev = dist(str1, str2)
bigger = max([len(str1), len(str2)])
pct = ((bigger - lev) / bigger)*100

print(
    "Строка #1 : {str1}\nСтрока #2 : {str2}\n===\nСхожеть : {pct}%".format(str1=str1, str2=str2, pct=pct)
)