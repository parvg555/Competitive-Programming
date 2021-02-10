package main

import (
	"fmt"
)

func solve() {
	var n int64
	fmt.Scan(&n)
	var i int64
	for i = 10; i > 0; i-- {
		if n%i == 0 {
			fmt.Println(i)
			return
		}
	}
}
