import os
import pandas as pd
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from sklearn.model_selection import train_test_split

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = nn.Linear(1, 1)

    def forward(self, x):
        return self.linear(x)


if __name__ == "__main__":

    # csv 파일 불러오기
    data = pd.read_csv("weight-height.csv")

    device = 'cuda' if torch.cuda.is_available() else 'cpu'

    # 만든 모델 사용하기
    model = Model()
    model = model.to(device)

    # Mean Squared Error
    criterion = nn.MSELoss(reduction = "mean")

    # Optimizer
    optimizer = optim.SGD(model.parameters(), lr=0.01)

    checker = SubmittedApp()

    # Epoch 수 설정하기
    EPOCH = 1000000

    # CSV 파일에서 Height과 Weight Column 각각 X, y로 뽑아내기
    X = data[['Height']]
    y = data[['Weight']]

    # train set / test set으로 데이터를 나눕니다.
    # 비율은 8:2
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    #tensor형태로 바꿔주기
    X_train = torch.from_numpy(data['Height'].values).unsqueeze(dim=1).float()
    y_train = torch.from_numpy(data['Weight'].values).unsqueeze(dim=1).float()


    for epoch in range(EPOCH +1):
        y_pred = model(X_train)

        #Loss function
        cost = criterion(y_pred, y_train) / y_pred.shape[0]

        ## cost로 H(x) 개선
        # 미분을 통해 얻은 기울기를 0으로 초기화.
        optimizer.zero_grad()

        # 모델의 parameter에 대해 Loss의 gradient를 계산
        cost.backward()

        # 위를 바탕으로 parameters 업데이트하기
        optimizer.step()
        
        if(epoch % 1000 ==0):
            print(f'Epoch: {epoch}|Loss:{cost.item()}|')

    # 정확도 측정
    print("Accuracy: ", checker.metric(y_pred, y_train))
    #저장    
    path = os.path.join('./', "model.pth") 
    print("saving..")
    torch.save(model.state_dict(), path)