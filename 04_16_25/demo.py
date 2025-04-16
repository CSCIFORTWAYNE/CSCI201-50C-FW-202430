

'''
int num;
std::cout << "Enter a number between 1 and 100: ";
std::cin >> num;
'''
try:
    num = int(input("Enter a number between 1 and 100: "))
except:
    num = int(input("Enter a number not the word facebook!"))