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
#print(len(_data))
# 일반적인 두 수의 연산 길이 = 3 연산자는 1번째 배열에 들어감 
# 세 수의 연산  연산자가 1번째 배열 , 3번째 배열에 들어감 
# 세 수 이상의 연산 --> 결국 연산자는 1, 3, 5 ,7 ''' 순서로 홀수로 들어감 따라서 2로 나머지 연산했을때 1이 나오면 
# 길이가 더 길어지면??
# 연산 마다 이프문 처리해줘야하나 ??

data = input("원하시는 계산을 입력해 주세요.\n")
_data = data.split()
for i in range(len(_data)):
    if ((_data[i] == ('+') | ('-') | ('*' ) | ('/'))):
        rst = int(_data[i-1])  
