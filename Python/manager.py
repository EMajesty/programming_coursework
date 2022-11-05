massit = 0
while True:
    print("Do you want to: \n")
    print("Make a (D)eposit")
    print("Do a (W)ithdrawal or")
    print("Check (B)alance?")

    inp = input()
    if inp == "D":
        print("\nHow much would you like to deposit?")
        dep = int(input())
        massit = massit + dep
        print("\nYou deposited",dep,"credits to your account.")
        print("You have",massit,"credits on your account.\n")
    elif inp == "W":
        if massit != 0:
            print("\nHow much would you like to withdraw?")
            wit = int(input())
            if wit < 0:
                print("Can't withdraw a negative amount")
            elif wit > massit:
                print("\nYou have insufficient credits for the withdrawal of",wit,"credits.")
                print("Withdrew",massit,"credits\n")
                massit = 0
                print("Your have",massit,"credits on your account.\n")
            else:
                print("\nWithdrew",wit,"credits\n")
                massit = massit - wit
                print("Your have",massit,"credits on your account.\n")
        else:
            print("\nTyhjästä on paha nyhjästä\n")

    elif inp == "B":
        print("\nYou have",massit,"credits on your account.\n")
    else:
        print("\nInvalid operation\n")