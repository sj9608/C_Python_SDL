#%% 1


# python bulitin module (xml parser)

from xml.etree.ElementTree import parse

print(f'module load ok')


# %% 2


# Parsing sheet_tanks.xml in res Folder

tree = parse('../res/tanks/sheet_tanks.xml') # 내부적으로 알아서 그래프 구조로 만들어준다.

rootNode = tree.getroot() # ( 루프노드를 알아야함 )

_node = rootNode.find('SubTexture') # 루트노드 밑에있는 서브텍스쳐를 찾음

print(_node)



# %% 3

# 서브텍스쳐 노드에 attrib

print(_node.attrib) # json file 형식으로 출력된다. 

# 파이썬에서는 dictionary 자료형 이라고한다. 
# 대괄호 -> 리스트  소괄호 -> 튜플

# xml형식은 <> 로 시작해서 </> 로 끝나는 경우와 
# 하나의 꺾쇄로 < 내용 />  으로 끝나는 경우가 있다.
# 자식을 가지고싶으면 1번 처럼 사용한다.
# </> 하나를 attribute 라고 한다. (attribute로 묶였다고 한다.)


# %% 4


# name 항목에 접근하고 싶으면
print(_node.attrib['name'])

# 'x' 항목에 접근하고싶으면
print(_node.attrib['x'])


#%% 5

# 위에 사용했던 find 는 하나에 대해서만 해당하고
# 전부 찾고 싶은경우 findall 함수를 이용한다.

_nodes = rootNode.findall('SubTexture')

print(_nodes)

# %% 6

# 한줄 한줄 출력 하고싶은경우

for node in _nodes :
    print(node.attrib['name'])


# %% 7


# C에서 다룰 수 있도록 만들기 위해서 struct 구조가 필요

from struct import *

_f = open('sheet.bin', 'wb')

for node in _nodes :
    # _f.write(node.attrib['name'])

    buf = pack('hhhh', int(node.attrib['x']),
    int(node.attrib['y']),
    int(node.attrib['width']),
    int(node.attrib['height']))

    _f.write(buf)
    
    # print(node.attrib['name'])

_f.close()


# %%
