q=len
def r(o, m, s):
    if q(s)>n: return 
    elif m>=k and q(s)==n:print(s)
    else:r(0,m,s+'0');r(o+1,max(m,o+1),s+'1')
n,k=map(int,input().split())
r(0,0,"")
