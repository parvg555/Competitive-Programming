package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func add12(h int64, m int64, s string) (int64, int64) {
	if s == "PM" && h != 12 {
		h += 12
	}
	if s == "AM" && h == 12 {
		h -= 12
	}
	return h, m
}

func main() {
	defer writer.Flush()
	var t int64
	scanf("%d\n", &t)
	var i int64
	for i = 0; i < t; i++ {
		var s string
		var h int64
		var m int64
		scanf("%d:%d %s\n", &h, &m, &s)
		h, m = add12(h, m, s)
		var temp int64
		scanf("%d \n", &temp)
		ans := []int64{}
		var j int64
		for j = 0; j < temp; j++ {
			var h1, h2, m1, m2 int64
			var s1, s2 string
			scanf("%d:%d %s %d:%d %s\n", &h1, &m1, &s1, &h2, &m2, &s2)
			h1, m1 = add12(h1, m1, s1)
			h2, m2 = add12(h2, m2, s2)
			if h2 > h1 {
				if h >= h1 && h <= h2 && m >= m1 && m <= m2 {
					ans = append(ans, 1)
				} else {
					ans = append(ans, 0)
				}
			} else {
				if h1 >= h && h2 <= h && m1 >= m && m2 <= m1 {
					ans = append(ans, 1)
				} else {
					ans = append(ans, 0)
				}
			}
		}
		for k := 0; k < len(ans); k++ {
			printf("%d", ans[k])
		}
		printf("\n")
	}
}
