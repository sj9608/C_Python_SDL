#type 1
'''
data = input("원하시는 계산을 입력해 주세요 \n")
_data = data.split()

print(f'당신은 {_data}를 입력 하셨습니다.')

if _data[1] == '+' :
    rst = int(_data[0]) + int(_data[2])
    print(f"결과 값은 {rst} 입니다.")

elif _data[1] == '-' :
    rst = int(_data[0]) + int(_data[2])
    print(f"결과 값은 {rst} 입니다.")

elif _data[1] == '-' :
    rst = int(_data[0]) + int(_data[2])
    print(f"결과 값은 {rst} 입니다.")

elif _data[1] == '-' :
    rst = int(_data[0]) + int(_data[2])
    print(f"결과 값은 {rst} 입니다.")
'''

#type 2
'''
while 1:
    data = input("원하시는 계산을 적으세요.\n")
    data = data.split()

    if (data[1] == '+') :
        rst = int(data[0]) + int(data[2])
        print("결과는 " + str(rst) + " 입니다.")
        break

    elif (data[1] == '-') :
        rst = int(data[0]) - int(data[2])
        print("결과는 " + str(rst) + " 입니다.")
        break

    elif (data[1] == '*') :
        rst = int(data[0]) * int(data[2])
        print("결과는 " + str(rst) + " 입니다.")
        break

    elif (data[1] == '/') :
        rst = int(data[0]) / int(data[2])
        print("결과는 " + str(rst) + " 입니다.")
        break

    else : print("값을 다시 입력해 주세요.\n")
'''

#type3

data = input("원하시는 계산을 입력해 주세요.\n")
_data = data.split()

#print(len(_data))
# 일반적인 두 수의 연산 길이 = 3 연산자는 1번째 배열에 들어감

if (len(_data) == 3 & _data[1] == '='):
    print(f'')

# 세 수의 연산  연산자가 1번째 배열 , 3번째 배열에 들어감
# 길이가 더 길어지면??
# 연산 마다 이프문 처리해줘야하나 ??
