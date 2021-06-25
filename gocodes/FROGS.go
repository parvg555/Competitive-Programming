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

type data struct {
	weight int64
	jump   int64
	pos    int64
}

func swap(s1 *data, s2 *data) {
	var temp1, temp2, temp3 int64
	temp1 = s1.weight
	temp2 = s1.jump
	temp3 = s1.pos
	s1.weight = s2.weight
	s1.jump = s2.jump
	s1.pos = s2.pos
	s2.weight = temp1
	s2.jump = temp2
	s2.pos = temp3
}

func frogs() {
	var n int64
	scanf("%d\n", &n)
	var i int64
	var j int64
	st := make([]data, 0)
	w := make([]int64, 0)
	ju := make([]int64, 0)
	for i = 0; i < n; i++ {
		var weight int64
		scanf("%d", &weight)
		w = append(w, weight)
	}
	scanf("\n")
	for i = 0; i < n; i++ {
		var jumpsize int64
		scanf("%d", &jumpsize)
		ju = append(ju, jumpsize)
	}
	for i = 0; i < n; i++ {
		st = append(st, data{w[i], ju[i], i})
	}

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			if st[i].weight < st[j].weight {
				swap(&st[i], &st[j])
			}
		}
	}

	var ans int64 = 0
	var current int64 = st[0].pos
	for i = 1; i < n; i++ {
		for st[i].pos < current {
			ans++
			st[i].pos += st[i].jump
		}
		current = st[i].pos

	}
	printf("%d\n", ans)
}

func main() {
	var t int64
	scanf("%d\n", &t)
	for ; t > 0; t-- {
		frogs()
	}
}
