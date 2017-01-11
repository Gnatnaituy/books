import sys

test_text = open(('%s' % sys.argv[1]), 'w')
try:
    for i in range (int(sys.argv[2])):
        test_text.write('Line %s\n' % i)
finally:
    test_text.close()
