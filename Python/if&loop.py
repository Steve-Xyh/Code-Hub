import random
ans=random.randint(1,100)

a=1000
while a!=ans:
     a=int(input())
     if a==ans:
          print("Correct! the number is "+str(ans))
     else:
          if a>ans:
               print("it's bigger than the number\n")
          else:
               print("it's smaller than the number\n")
     
