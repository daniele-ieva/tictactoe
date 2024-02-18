DEBUG:
	${CC} ${DFLAGS} ./src/*.c -o ./target/debug


RELEASE:
	${CC} ${CFLAGS} ./src/*.c -o ./target/release

CLEAN:
	rm -f ./target/*
