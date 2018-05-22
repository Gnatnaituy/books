import sys

with open(('%s' % sys.argv[1]), 'a') as f1:
    with open(('%s' % sys.argv[2]), 'r') as f2:
        tmp = f2.readlines()
        f1.write('\n\n\n')
        for tmp_line in tmp:
            line = str(tmp_line)
            f1.write(line)
        f2.close()
    f1.close()
