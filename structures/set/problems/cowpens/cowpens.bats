#!/usr/bin/env bats


@test "General test of cowpens" {
	run ./cowpens.exe < cowpens-test2.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat cowpens.out)" ]
}

@test "General test of cowpens" {
	run ./cowpens.exe < cowpens-test1.in
	[ "$status" -eq 0 ]
	[ "$output" = "1000000000000" ]
}
