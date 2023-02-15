from sklearn import svm
from sklearn.externals import joblib
import numpy as np
import cv2
import time

indices = np.load('./recorder/indexe.npy')
times = np.load('./recorder/timee.npy')
times = times *1000

time_each_ractangle = 33.3
ractangle_num = 0

def calculate_ractangle(indexs):
    rows = []
    cols = []
    for i in range(len(indexs)):
        row = indexs[i]/240
        col = indexs[i]%240
        rows.append(row)
        cols.append(col)
    avg_row = np.mean(rows)
    avg_col = np.mean(cols)
    delta_row = np.max(rows)-np.min(rows)
    delta_col = np.max(cols)-np.min(cols)
    delta_mean = (delta_row+delta_col)/2
    left = int(avg_col-delta_mean-1)*8
    upper = int(avg_row-delta_mean-1)*8
    right = int(avg_col+delta_mean+1)*8
    lower = int(avg_row+delta_mean+1)*8
    if left<0:
        left = 0
    if upper<0:
        upper = 0
    if right>=1920:
        right = 1920
    if lower>=1080:
        lower = 1080
    if right<left:
        right = left+1
    if lower<upper:
        lower = upper+1
    return left, upper, right, lower

def cluster(indexs):
    rows = np.zeros((len(indexs)))
    cols = np.zeros((len(indexs)))
    clusters = []
    rectangle = []
    labels = np.zeros((len(indexs)))
    for i in range(len(indexs)):
        row = indexs[i]/240
        col = indexs[i]%240
        rows[i] = row
        cols[i] = col
    add_flag = 0
    for i in range(len(rows)):
        if clusters:
            for j in range(len(clusters)):
                if (abs(rows[i]-clusters[j][0])+abs(cols[i]-clusters[j][1]))<clusters[j][2]:
                    labels[i] = j + 1
                    index = np.where(labels == j+1)
                    index = index[0]
                    clusters[j][0] = np.mean(rows[index])
                    clusters[j][1] = np.mean(cols[index])
                    clusters[j][2] = (len(index)/5)+15
                    add_flag = 1
                    break
            if(add_flag == 0):
                clusters.append([rows[i],cols[i],15])
                labels[i] = len(clusters)
            add_flag = 0
        else:
            clusters.append([rows[0],cols[0],15])
            labels[i] = 1
    for i in range(len(clusters)):
        index = np.where(labels == i+1)
        avg_row = np.mean(rows[index])
        avg_col = np.mean(cols[index])
        delta_row = np.max(rows[index])-np.min(rows[index])
        delta_col = np.max(cols[index])-np.min(cols[index])
        delta_mean = (delta_row+delta_col)/2
        left = int(avg_col-delta_mean+1)*8
        upper = int(avg_row-delta_mean+1)*8
        right = int(avg_col+delta_mean-1)*8
        lower = int(avg_row+delta_mean-1)*8
        if left<0:
            left = 0
        if upper<0:
            upper = 0
        if right>=1920:
            right = 1920
        if lower>=1080:
            lower = 1080
        if right<=left:
            right = left+1
        if lower<=upper:
            lower = upper+1
        rectangle.append([left,upper,right,lower])
    return len(clusters),rectangle


if __name__ == '__main__':
    pic_save_dir_path = 'cut.jpg'
    index_start = 0
    index_end = 0
    model = joblib.load("./train_model.m")
    for i in range(len(indices)):
        if int(times[i]/time_each_ractangle)>ractangle_num:
            index_end = i
            index_a_sample = indices[index_start:index_end]
            #left, upper, right, lower = calculate_ractangle(index_asample)
            start_time = time.time()
            num,rectangles = cluster(index_a_sample)
            end_time = time.time()
            print(end_time-start_time)
            pic_path = './frames/frames_'+(str(ractangle_num).zfill(10))+'.png'
            img = cv2.imread(pic_path)
            for j in range(num):
                box = (rectangles[j][0], rectangles[j][1], rectangles[j][2], rectangles[j][3])
                roi = img[rectangles[j][1]:rectangles[j][3],rectangles[j][0]:rectangles[j][2]]
                roi=cv2.resize(roi,(128,128),interpolation=cv2.INTER_CUBIC)
                hist = cv2.calcHist([roi], [0,1], None, [128,128], [0.0,255.0,0.0,255.0]) 
                x = (hist/255).flatten()
                start_time = time.time()
                y = model.predict(x.reshape(1,-1))
                end_time = time.time()
                print(end_time-start_time)
                if y == 0:
                    cv2.rectangle(img, (rectangles[j][0], rectangles[j][1]), (rectangles[j][2], rectangles[j][3]), (0,0,255), 3)
                    cv2.putText(img, 'UAV', (rectangles[j][0], rectangles[j][1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)
            cv2.imwrite('./result/'+(str(ractangle_num).zfill(10))+'.png', img)
            index_start = index_end
            ractangle_num = int(times[i]/time_each_ractangle)


