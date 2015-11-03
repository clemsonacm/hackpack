#!/usr/bin/env bats


@test "Set example code matches Sample Output" {
	run ./one-zero.exe < one-zero.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat one-zero.out)" ]
}
@test "Set example code matches test Output" {
	run ./one-zero.exe < one-zero-test.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat one-zero-test.out)" ]
}
