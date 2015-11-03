#!/usr/bin/env bats


@test "Set example code matches Sample Output" {
	run ./cowy.exe < cowy.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat cowy.out)" ]
}
@test "Set example code matches Test Output" {
	run ./cowy.exe < cowy-test.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat cowy-test.out)" ]
}
