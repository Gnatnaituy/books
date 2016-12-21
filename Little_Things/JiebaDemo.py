import jieba

def main():
    a=[]
    f=open(r'/Users/Arszrc/Desktop/一些笔记/子查询.txt','r').read()
    words=list(jieba.cut(f))
    for word in words:
        if len(word)>1:
            a.append(word)
    txt=r' '.join(a)

if __name__=='__main__':
    main()
