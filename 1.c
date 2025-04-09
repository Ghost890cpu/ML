import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

import warnings
warnings.filterwarnings('ignore')

df=pd.read_csv("C:\\Users\\Sharath K M\\OneDrive\\Desktop\\Machine Learning\\housing.csv")

df.head()

df.shape

df.info

df.nunique()

df.isnull().sum()

df.duplicated().sum()

df["total_rooms"].mean()

df["total_rooms"].median()

df["total_rooms"].mode()

df["total_rooms"].fillna(df["total_rooms"].median(),inplace=True)

df["total_rooms"].fillna(df["total_rooms"].median(),inplace=False)

for i in df.iloc[:2:7]:
    df[i] = pd.to_numeric(df[i], errors="coerce") 
df.head()

df.describe().T

Numerical=df.select_dtypes(include=[np.number]).columns
print(Numerical)

for col in Numerical:
    plt.figure(figsize=(10,6))
    df[col].plot(kind='hist',title=col,bins=60,edgecolor='black')
    plt.ylabel("frequency")
    plt.show()
    
for col in Numerical:
    plt.figure(figsize=(6,6))
    sns.boxplot(df[col],color='pink')
    plt.title(col)
    plt.ylabel(col)
    plt.show()
