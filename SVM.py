#SVM train and test
 
import datetime

 
import numpy as np
import os
import cv2
import sklearn.model_selection as ms
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, classification_report
 
X = []
Y = []
 
for i in range(0, 2):
    #遍历文件夹，读取图片
    for f in os.listdir("E:\pythonproject\DNF\svmdata\%s" % i):
        #打开一张图片并灰度化
        Images = cv2.imread("E:\pythonproject\DNF\svmdata\%s/%s" % (i, f)) 
        image=cv2.resize(Images,(128,128),interpolation=cv2.INTER_CUBIC)
        hist = cv2.calcHist([image], [0,1], None, [128,128], [0.0,255.0,0.0,255.0]) 
        X.append(((hist/255).flatten()))
        Y.append(i)
X = np.array(X)
Y = np.array(Y)

#切分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.3, random_state=1)
#随机率为100%选取其中的30%作为测试集
 
from sklearn import svm
from sklearn.externals import joblib
#普通的一次性模型训练预测
# clf = svm.SVC(kernel='rbf',gamma=0.001,C=1000,probability=True)
# clf.fit(X_train, y_train)#训练

# joblib.dump(clf,"./train_model.m")
model = joblib.load("./train_model.m")
starttime = datetime.datetime.now()
predictions0 = model.predict(X_test)
endtime = datetime.datetime.now()
print (endtime - starttime)
#predictions0=pred_test_y
print(confusion_matrix(y_test, predictions0))
print (classification_report(y_test, predictions0))



 
 
#自动调参函数
# tuned_parameters = [{'kernel': ['rbf'], 'gamma': [1e-3, 1e-4],
#                       'C': [1, 10, 100, 1000]},
#                     {'kernel': ['linear'], 'C': [1, 10, 100, 1000]}]
# scores = ['precision', 'recall']
# for score in scores:
#     print("# Tuning hyper-parameters for %s" % score)
#     print()

#     # 调用 GridSearchCV，将 SVC(), tuned_parameters, cv=5, 还有 scoring 传递进去，
#     clf = ms.GridSearchCV(svm.SVC(), tuned_parameters, cv=10,
#                        scoring='%s_macro' % score) #cv为迭代次数。#基于交叉验证的网格搜索，cv:确定交叉验证拆分策略。
#     # 用训练集训练这个学习器 clf
#     clf.fit(X_train, y_train)
  
#     print("Best parameters set found on development set:")
#     print()
  
#     # 再调用 clf.best_params_ 就能直接得到最好的参数搭配结果
#     print(clf.best_params_)
     
#     print()
#     print("Grid scores on development set:")
#     print()
#     means = clf.cv_results_['mean_test_score']
#     stds = clf.cv_results_['std_test_score']
  
#     # 看一下具体的参数间不同数值的组合后得到的分数是多少
#     for mean, std, params in zip(means, stds, clf.cv_results_['params']):
#         print("%0.3f (+/-%0.03f) for %r"
#              % (mean, std * 2, params))
  
#     print()
  
#     print("Detailed classification report:")
#     print()
#     print("The model is trained on the full development set.")
#     print("The scores are computed on the full evaluation set.")
#     print()
#     y_true, y_pred = y_test, clf.predict(X_test)
   
#     # 打印在测试集上的预测结果与真实值的分数
#     print(classification_report(y_true, y_pred))
   
#     print()
 
 
