#!/usr/bin/env bats


@test "Set example code matches Sample Output" {
	run ./fine-print.exe < ./fine-print.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat fine-print.out)" ]
}

@test "Set example code matches Test Output" {
	run ./fine-print.exe < ./fine-print-test.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat fine-print-test.out)" ]
}
