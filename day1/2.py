i=input;a,b,c,d=map(int,i().split())
e=list(map(int,i().split()))
e[c:c]=[b]*d
print("After call multiple_add\nSize =",len(e),'\n',*e,sep=" ")
