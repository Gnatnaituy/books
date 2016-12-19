import getpass

user = input('Enter your uaername: ')
passwd = getpass.getpass()

def svc_login(user, passwd):
    if passwd == '5523':
        return True
    else:
        return False

if svc_login(user, passwd):
    print('Yay!')
else:
    print('Boo!')