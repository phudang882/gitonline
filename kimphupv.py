#Tập lệnh decimal
from decimal import*
#lấy tối đa 2 số chữ số 
getcontext().prec= 2
#in ra số thập phân có n số hạng
print(Decimal(20)/Decimal(3))
#chỉ cần 1 trong biểu thức có tập hợp lớn nhất ví dụ là:
#tập R> tập N thì trong python sẽ số đó sẽ là tập R
d= Decimal(2)/3
print(d)


