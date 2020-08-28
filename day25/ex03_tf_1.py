#%%
# 모듈 로딩
import tensorflow as tf
print(f'version : {tf.__version__}')

# %%
# 지포스 gpu만 사용가능
print('gpu ', '사용가능' if tf.config.experimental.list_physical_devices("GPU") else "사용불가")


# %%

print(tf.config.list_physical_devices('GPU'))

# %%

# numpy 비슷한 자체적 연산시스템을 가지고 있는 집합체 (tensorflow)
# 텐서(라고불림) 생성 ( 상수형으로 만듦)

tensor_a = tf.constant(100)
print(tensor_a) #개체

# %%

print(tensor_a.numpy()) #실제적인 값을 출력


# %%

# 상수 텐서3, 2 생성하고 두개를 더할수 있음.

tensor_b = tf.constant(3)
tensor_c = tf.constant(2)

tensor_d = tf.add(tensor_b, tensor_c)
tnesor_f = tensor_b + tensor_c

print(tensor_d.numpy())
print(tensor_f.numpy())

# %%

# 행렬을 표현할 수 있다.
tensor_ma = tf.constant([[1,2], [3,4]])
tensor_mb = tf.constant([[2,0], [0,2]]) # 단위 행렬
tensor_mc = tensor_ma * tensor_mb # 행렬간의 곱셈이 가능하다. ( 벡터 곱)

print(tensor_mc.numpy())

# 행렬곱
tensor_md = tf.matmul(tensor_ma, tensor_mb)
print(tensor_md.numpy())

# %%
