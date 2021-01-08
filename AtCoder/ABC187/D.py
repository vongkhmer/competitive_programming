#
# author: vongkh
# created: Mon Jan 04 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    aoki = [0] * n
    takahashi = [0] * n
    for i in range(n):
        aoki[i], takahashi[i] = list(map(int, input().split())) 

    #voter_diff : how many voter aoki has more than takahashi
    #initially, if takahashi doesn't visit any town, it is equal to aoki's supporter
    voter_diff = 0 
    for voter in aoki: 
        voter_diff += voter

    #Each time takahashi visits a town with a- aoki's supporter and t- supporter, 
    # he gains (a + t) votes, and aoki lost a votes ==> change = 2 * a + t
    # It is optimal to choose the town that gives the biggest change
    change_after_visit = [2 * a + t for (a, t) in zip(aoki, takahashi)]
    change_after_visit.sort(reverse=True)
    
    visit_num = 0
    #Takahashi will "greedily" visit towns until he wins Aoki
    for change in change_after_visit:
        visit_num += 1 
        voter_diff -= change
        if voter_diff < 0 :
            break
    print(visit_num)

def main():
    solve()

if __name__ == "__main__":
    main()