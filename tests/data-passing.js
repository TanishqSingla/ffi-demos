import { dlopen, suffix } from 'bun:ffi';

const { symbols } = dlopen(`libdata-passing.${suffix}`, {
	println: { args: ["cstring"] }
});

const input = Buffer.from("Hello world");
symbols.println(input);
