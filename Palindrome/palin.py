flag=1
st=str(input("Enter string to check palindrome or not : "))
for i in range(len(st)//2):
    if(st[i]!=st[len(st)-i-1]):
        flag=0
        break
if(flag==0):
    print('Not Palindrome')
else:
    print('Palindrome')
