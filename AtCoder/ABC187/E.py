#
# author: vongkh
# created: Mon Jan 04 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    #list of nodes that shares and edge with the target list
    adjacent_list = [ [] for _ in range(n)] 

    edge = [(-1,-1) for _ in range(n-1)]
    for i in range(n-1):
        a, b = list(map(int, input().split()))
        a -= 1
        b -= 1
        adjacent_list[a].append(b)
        adjacent_list[b].append(a)
        edge[i] = (a, b)

    root = 0
    #stores the direct parent of a node
    parent = [-1 for _ in range(n)]
    #get parent of each node, when we set the root = 0 using dfs
    #using recursive will give RE because of the number of recursive calls, hence we use stack
    stack = [(root, -1)]
    while stack:
        node, par = stack.pop()
        parent[node] = par
        for next_node in adjacent_list[node]:
            if next_node != par:
                stack.append((next_node, node))
    #the problem statement is equivalent to: do a propagation update from a/b until reach b/a
    #Since the propagation does not affect one another but superposition each other, 
    # we can process the propagation only once after we listen all the query

    #down_propagate value at each node
    add_to_node = [0] * n 
    q = int(input())
    for _ in range(q):
        t, e, x = list(map(int, input().split()))
        e -= 1
        a = edge[e][0]
        b = edge[e][1]
        if t == 2:
            a, b = b, a
        #we've to add to each node the tree that can reach from a without passing b

        #case 1: a is b's parent
        #the propagation <==> down-propagate update x from root & down-propagate update -x from b
        if parent[b] == a:
            add_to_node[root] += x
            add_to_node[b] += -x

        #case 2: a is b's child
        #the propagation <==> down-propagate update x from a
        else:
            add_to_node[a] += x

    #final_result after processing all the queries
    final_result = [0] * n 
    #down propagate using dfs
    stack = [(root, -1 , 0)]

    while stack:
        #acc : accumulate sum
        node, par, acc = stack.pop()
        acc += add_to_node[node]
        final_result[node] = acc
        for next_node in adjacent_list[node]:
            if next_node != par:
                stack.append((next_node, node, acc))

    for i in range(n):
        print(final_result[i])

def main():
    solve()

if __name__ == "__main__":
    main()