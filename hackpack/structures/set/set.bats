#!/usr/bin/env bats


@test "Set example code matches Sample Output" {
	run ./set.exe 
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat set.in)" ]
}
