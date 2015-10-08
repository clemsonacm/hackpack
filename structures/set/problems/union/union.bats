#!/usr/bin/env bats


@test "General test of union" {
	run ./union.exe < union-test.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat union-test.out)" ]
}

