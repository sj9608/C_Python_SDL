#%%
from xml.etree.ElementTree import parse

print(f'module load ok')

tree = parse('../res/tanks/sheet_tanks.xml') # 내부적으로 알아서 그래프 구조로 만들어준다.

rootNode = tree.getroot() # ( 루프노드를 알아야함 )

_nodes = rootNode.findall('SubTexture')

for node in _nodes:
    _name = node.attrib['name']
    _x = node.attrib['x']
    _y = node.attrib['y']
    _width = node.attrib['width']
    _height = node.attrib['height']
    print(f"{_name:32}, {_x:4}, {_y:4}, {_width:3}, {_height:3} ")

#%%

type(_x)

# %%

from PIL import Image,ImageDraw
from IPython.display import display

# 이미지 불러오기
_img = Image.open('../res/tanks/sheet_tanks.png')

for node in _nodes:
    _name = node.attrib['name']
    _x = int(node.attrib['x'])
    _y = int(node.attrib['y'])
    _width = int(node.attrib['width'])
    _height = int(node.attrib['height'])

    # _img_crop = _img.crop(int(_x), int(_y), int(_width), int(_height))
    _img_crop = _img.crop((_x,_y,_width+_x, _height+_y))

    _img_crop.save()
    
# %%
