while True:
    r1=int(input('Enter row dimension for matrix 1(r1) :'))
    c1=int(input('Enter column dimension for matrix 1(c1) :'))
    r2=int(input('Enter row dimension for matrix 2(r2) :'))
    c2=int(input('Enter column dimension for matrix 1(c2) :'))
    if c1!=r2 or type(r1)!=int or type(c1)!=int or type(r2)!=int or type(c2)!=int:
        print('\nEnter valid dimentions')
    else:
        break
m1=[]
m2=[]
t=0
mul=[[0 for i in range(c2)]for i in range(r1)]
for i in range(r1):
    a=[]
    for j in range(c1):        
        print('Enter m1[',i+1,'][',j+1,'] Element')
        a.append(int(input()))
    m1.append(a)
print('\nNow,Enter for second matrix :')
for i in range(r2):
    a=[]
    for j in range(c2):
        print('Enter m2[',i+1,'][',j+1,'] Element')
        a.append(int(input()))
    m2.append(a)
print('\nEntered First Matrix')
for i in range(r1):
    for j in range(c1):
        print(m1[i][j],end=' ')
    print()
print('\nSecond Matrix')
for i in range(r2):
    for j in range(c2):
        print(m2[i][j],end=' ')
    print()
    
for i in range(r1):
    t=0
    for j in range(c2):
        t=0
        for k in range(c1):
            t+=(m1[i][k]*m2[k][j])
        mul[i][j]=t
print('\n\nMultiplication :')
for i in range(r1):
    for j in range(c2):
        print(mul[i][j],end=' ')
    print()

##Output:
##Enter row dimension for matrix 1(r1) :2
##Enter column dimension for matrix 1(c1) :3
##Enter row dimension for matrix 2(r2) :3
##Enter column dimension for matrix 1(c2) :2
##Enter m1[ 1 ][ 1 ] Element
##1
##Enter m1[ 1 ][ 2 ] Element
##2
##Enter m1[ 1 ][ 3 ] Element
##3
##Enter m1[ 2 ][ 1 ] Element
##4
##Enter m1[ 2 ][ 2 ] Element
##5
##Enter m1[ 2 ][ 3 ] Element
##6
##
##Now,Enter for second matrix :
##Enter m2[ 1 ][ 1 ] Element
##1
##Enter m2[ 1 ][ 2 ] Element
##2
##Enter m2[ 2 ][ 1 ] Element
##3
##Enter m2[ 2 ][ 2 ] Element
##4
##Enter m2[ 3 ][ 1 ] Element
##5
##Enter m2[ 3 ][ 2 ] Element
##6
##
##Entered First Matrix
##1 2 3 
##4 5 6 
##
##Second Matrix
##1 2 
##3 4 
##5 6 
##
##
##Multiplication :
##22 28 
##49 64 
