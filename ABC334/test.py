A = -177018739841739480
M = 2436426 
L = -80154573737296504
R = 585335723211047198

print(A-L)
print(R-A)
negative_tree = (A-L) / M
positive_tree = (R-A) / M

print(negative_tree)
print(positive_tree)

print(negative_tree + positive_tree + 1)