#!/usr/bin/env bats

@test "Test in a graph without eddies" {
	run ./cowex.exe < cowex.in
	[ "$output" == '9' ]
	[ $status -eq 0 ]
}
