#
# author: vongkh
# created: Mon Jan 04 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    #store all the strings without !
    no_exclamation = set()
    #store all the strings with !
    exclamation = set()

    for _ in range(n):
        s = stdin.readline()
        if s[0] == '!':
            exclamation.add(s)
        else:
            no_exclamation.add(s)

    #if t is unsatisfiable, t must be without ! and t must be in the no_exclamation set
    for t in no_exclamation:
        if ("!" + t) in exclamation:
            stdout.write(t)
            return

    #if we cannot find unsatisfiable t, it is satisfiable
    stdout.write("satisfiable\n")


def main():
    solve()

if __name__ == "__main__":
    main()