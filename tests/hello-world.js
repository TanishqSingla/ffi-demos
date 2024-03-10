import { dlopen, suffix } from 'bun:ffi';

const { symbols } = dlopen(`libhello-world.${suffix}`, {
	print_hello: {}
});

symbols.print_hello();
