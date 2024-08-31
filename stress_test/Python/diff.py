from os import system

it = 1000
for t in range(it):
    system("./input>in")
    system("./good<in>o")
    system("./bad<in>o2")
    x = open("o","r").read().strip().split()
    y = open("o2","r").read().strip().split()

    for i in range(len(x)):
        if(x[i]!=y[i]):
            print("FAILED!!",i+1)
            exit(0)
    print("ok",t+1)
