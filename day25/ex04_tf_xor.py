# %%
# 간단한 xor 학습시키는 ai 만들어보기

import tensorflow as tf
import numpy as np

print(f'tf version {tf.__version__}')

''' 데이터셋 만들기 '''
# 먼저 인풋 데이터가 필요하다.
# 인풋데이터는 2가지가 있는데 학습용 데이터와, 검증요 데이터가 있다.
# 현재 지도학습 공부. ( 비지도학습은 나중에 )

# 우선 학습용 데이터를 만들 예정.
_input = np.array([[0, 0], [0, 1], [1, 0], [1, 1]]).astype(np.float64)
# 검증데이터 (output)
_output = np.array([[0], [1], [1], [0]]).astype(np.float64)

train_dataset = tf.data.Dataset.from_tensor_slices((_input, _output))
test_dataset = tf.data.Dataset.from_tensor_slices((_input, _output))

BATCH_SIZE = 1  # 데이터 단위라고 보면 된다.

#4개니깐 4번섞는다.   # train_data 섞기 (섞어주는 의미: 오버퀴팅? 오버피팅이란 문제가 발생함 순서를 갖지 않도록 섞어준다. #
# 무작위데이터를 받기때문에 실제로는 , ai 학습용 데이터셋은 정렬된 데이터를 집어넣으면 안된다. 다양하게 생각하는 패턴이 사라지고 기계적이게 된다.)
train_dataset = train_dataset.shuffle(4).batch(BATCH_SIZE)
test_dataset = test_dataset.batch(1)  # batch size ai가 학습하는 단위


''' 모델 만들기 '''
# 이신경망은 레이어를 2개 쓸것임.

def create_model() :
  layers = []
  #레이어 2단계로 모델을 생성함
  # 2개를 입력받는 레이어라는 뜻 액ㅌ배이션은 시그모이드 함수(가장 많이쓰임) 멜브라는 함수도있다?? (어떤 값 이상이면 액티베이션 아니면 넌액티베이션)
  
  layers.append(tf.keras.layers.Dense(2,activation=tf.nn.sigmoid)) 
  layers.append(tf.keras.layers.Dense(1,activation=tf.nn.sigmoid))
  
  model = tf.keras.Sequential(layers)
 
  print('layer setup')

  sgd = tf.keras.optimizers.SGD(lr=0.01,decay=0,momentum=0.99,nesterov=True)
  
  model.compile(optimizer=sgd,loss='mse',metrics=['mae','mse'])
  return model


# %%

# 이제 모델에다 데이터셋을 넣어서 출력시키면된다
if __name__ == '__main__':

    # 모델 객체를 만ㄷ,ㄹ거
    model = create_model()

    print(model(_input))  # 학습 전

#%%
    # fit 은 학습시키는 함수 epochs는 학습 횟수 (적당한 선을 찾고) 멈춰야함
    model.fit(train_dataset, epochs=500, validation_data=test_dataset)

    print(model(_input))  # 학습 후
# %%

    # 훈련 데이터만 따로 저장
    model.save_weights('train_data/xor.ckpt') #ckpt --> checkPoint
# %%
