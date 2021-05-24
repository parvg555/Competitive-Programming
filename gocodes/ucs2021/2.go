package two

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

const mxn = 1000 + 3

var arr [mxn][mxn]int
var m int
var n int

func merger(rfs int, rfe int, cfs int, cfe int) {
	var i int
	var j int

	for i = rfs; i <= rfe; i++ {
		var temp []int
		for j = cfs; j <= cfe; j++ {
			temp = append(temp, arr[i][j])
			fmt.Println(i, j, arr[i][j])
		}
		sort.Ints(temp)
		var start int
		start = 0
		for j = cfs; j <= cfe; j++ {
			arr[i][j] = temp[start]
			start++
		}
	}

	for i = cfs; i <= cfe; i++ {
		var temp []int
		for j = rfs; j <= rfe; j++ {
			temp = append(temp, arr[j][i])
		}
		sort.Ints(temp)
		var start int
		start = 0
		for j = rfs; j <= rfe; j++ {
			arr[j][i] = temp[start]
			start++
		}
	}
}

func mergesort(rs int, re int, cs int, ce int) {
	var flag bool = true
	if rs < 0 || re < 0 || rs > m || re > m || cs < 0 || cs > n || ce < 0 || ce > n {
		flag = false
	}
	if rs >= re && cs >= ce {
		flag = false
	}
	if flag == true {
		var rmid int
		rmid = rs + (re-rs)/2
		var cmid int
		cmid = cs + (ce-cs)/2
		mergesort(rs, rmid, cs, cmid)
		mergesort(rmid+1, re, cs, cmid)
		mergesort(rs, rmid, cmid+1, ce)
		mergesort(rmid+1, re, cmid+1, ce)
		merger(rs, re, cs, ce)
	}
}

func solver() {
	defer writer.Flush()
	var i int
	var j int

	for i = 0; i < mxn; i++ {
		for j = 0; j < mxn; j++ {
			arr[i][j] = 0
		}
	}

	var M int
	var N int
	scanf("%d %d\n", &M, &N)
	m = M
	n = N
	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			var temp int
			scanf("%d ", &temp)
			arr[i][j] = temp
		}
	}

	mergesort(0, m-1, 0, n-1)

	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			printf("%d ", arr[i][j])
		}
	}
}
