# %%
# 간단한 xor 학습시키는 ai 만들어보기

import tensorflow as tf
import numpy as np

print(f'tf version {tf.__version__}')

#%%

_input = np.array([[0, 0], [0, 1], [1, 0], [1, 1]]).astype(np.float64)

# 데이터를 로드만 하는게 아니라 모델도 필요하다.

import ex04_tf_xor

model = ex04_tf_xor.create_model()

#%%

# 데이터 set 불러오기
model.load_weights('train_data/xor.ckpt')

#%%

print(model(_input))
# %%
