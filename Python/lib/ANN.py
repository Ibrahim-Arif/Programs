from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense,Flatten
import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

dataset = datasets.load_iris()
x_train,x_test,y_train,y_test = train_test_split(dataset.data,dataset.target,test_size=0.2,random_state=0)

modal = Sequential()
modal.add(Dense(units=18,activation="relu"))
modal.add(Dense(units=6,activation="relu"))
modal.add(Dense(units=3,activation="softmax"))

modal.compile(optimizer="adam", loss="mse",metrics=['accuracy'])
modal.fit(x_train,y_train,epochs=300)

pred_y = modal.predict(x_test)

prediction = []

for i in pred_y:
    prediction.append(np.argmax(i))

print(accuracy_score(y_test,prediction))























