binary_flag = "B4BY_Sh4rK_DoOoD0od0od0O_DoOd0O0d00O"


def win():
    flag = open("flag.txt", "r").read()
    flag = flag.strip()
    print(flag)


print("Welcome to the Baby Shark Challenge!")
print("The name has nothing to do with the challenge...oops")
print("I just love sharks!!")

user_input = input("==> ")
if user_input != binary_flag:
    print("picoCTF{https://tinyurl.com/32z5dtmd}")
else:
    print("!~~~~Baby shark~~Doodoodoodoodoodoo~~!")
    print("!~~Baby shark~~Doodoodoodoodoodoo~~!")
    print("!~~~~Baby shark~~Doodoodoodoodoodoo~~!")
    print("!~~Baby shark~~!")
    print("Heeeres your flag!")
    win()
