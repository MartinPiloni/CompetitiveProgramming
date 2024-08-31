import sys
from subprocess import run

it = 10000
ins = sys.argv[1] if len(sys.argv) > 1 else 1
for i in range(it):
    casegen = run(["./casegen"], capture_output=True)
    bad = run(["./bad"], input=casegen.stdout, capture_output=True)
    if bad.returncode != 0:
        print(f"{ins}: bad failed")
        exit(0)
    check = run(["./check"], input=casegen.stdout + bad.stdout, capture_output=True)
    if check.returncode != 0:
        print(f"{ins}: failed with '{check.stdout.decode().strip()}'")
        with open(f"{ins}in.txt", "w") as f:
            f.write(casegen.stdout.decode())
        with open(f"{ins}res.txt", "w") as f:
            f.write(bad.stdout.decode() + "\n---\n" + check.stdout.decode())
        exit(0)
    else:
        print(f"Case {i} ok")
