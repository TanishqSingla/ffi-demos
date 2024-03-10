import { describe, it, expect } from 'bun:test';
import { dlopen, suffix } from 'bun:ffi';

describe("print_hello", () => {
	it("prints hello world", () => {
		const output = Bun.spawnSync(["bun", "hello-world.js"]).stdout.toString();

		expect(output).toBe("Hello world");
	});
});


describe("sum", () => {
	const { symbols: { sum, println } } = dlopen(`libdata-passing.${suffix}`, {
		sum: {
			args: ["int", "int"],
			returns: "int"
		},
		println: {
			args: ["cstring"],
			returns: "cstring"
		}
	});

	it("should add 2 numbers", () => {
		expect(sum(1,2)).toBe(3);
		expect(sum(0,2)).toBe(2);
		expect(sum(-2,2)).toBe(0);
		expect(sum(-2,-2)).toBe(-4);
	});

	it("returns input string", () => {
		const output = Bun.spawnSync(["bun", "data-passing.js"]).stdout.toString();

		expect(output).toBe("Hello world");
	});
});

describe("get_metadata", () => {
	const { symbols: { parseMetadata } } = dlopen(`libget_metadata.${suffix}`, {
		parseMetadata: {
			args: ["cstring"],
			returns: "cstring"
		}
	});

	const filename = Buffer.from("TEST.md");
	const output = String(parseMetadata(filename));
	
	expect(JSON.parse(output)).toEqual({ title: "test", date: "12-12-12" })
});
