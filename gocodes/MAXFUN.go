package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func maxfun() {
	var n int64
	scanf("%d\n", &n)
	var min int64 = math.MaxInt32
	var max int64 = math.MinInt64
	var i int64
	for i = 0; i < n; i++ {
		var temp int64
		scanf("%d", &temp)
		if temp < min {
			min = temp
		}
		if temp > max {
			max = temp
		}
	}
	var ans int64 = 2 * abs(max-min)
	fmt.Println(ans)
}

func main() {
	defer writer.Flush()
	var t int64
	scanf("%d\n", &t)
	var i int64

	for i = 0; i < t; i++ {
		maxfun()
	}

}
