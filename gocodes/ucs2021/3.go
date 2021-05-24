package three

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

const mxn = 1000 + 3

var arr [mxn][mxn]int
var mp = make(map[int][]int)
var direction [mxn * mxn][9]int
var vis [mxn*mxn + 3]bool

func recur(i int, j int, m int, n int, paths []int) {
	var path []int
	for k := range paths {
		path = append(path, paths[k])
	}
	if i == 0 && j == 0 {
		path = append(path, arr[i][j])
		if _, found := mp[1]; !found {
			mp[1] = path
		} else if len(mp[1]) > len(path) {
			mp[1] = path
		}
		return
	}

	if i == 0 && j == n-1 {
		path = append(path, arr[i][j])

		if _, found := mp[2]; !found {
			mp[2] = path
		} else if len(mp[2]) > len(path) {
			mp[2] = path
		}
		return
	}

	if i == m-1 && j == 0 {
		path = append(path, arr[i][j])
		if _, found := mp[3]; !found {
			mp[3] = path
		} else if len(mp[3]) > len(path) {
			mp[3] = path
		}
		return
	}

	if i == m-1 && j == n-1 {
		path = append(path, arr[i][j])
		if _, found := mp[4]; !found {
			mp[4] = path
		} else if len(mp[4]) > len(path) {
			mp[4] = path
		}
		return
	}

	if i < 0 || j < 0 || i >= m || j >= n {
		return
	}

	if vis[arr[i][j]] {
		return
	}

	path = append(path, arr[i][j])
	vis[arr[i][j]] = true
	var curr int = arr[i][j]

	if direction[curr][1] == 1 {
		recur(i-1, j, m, n, path)
	}

	if direction[curr][3] == 1 {
		recur(i, j+1, m, n, path)
	}

	if direction[curr][5] == 1 {
		recur(i+1, j, m, n, path)
	}

	if direction[curr][7] == 1 {
		recur(i, j-1, m, n, path)
	}

	if direction[curr][2] == 1 {
		recur(i-1, j+1, m, n, path)
	}

	if direction[curr][4] == 1 {
		recur(i+1, j+1, m, n, path)
	}

	if direction[curr][6] == 1 {
		recur(i+1, j-1, m, n, path)
	}

	if direction[curr][8] == 1 {
		recur(i-1, j-1, m, n, path)
	}

	if len(path) > 0 {
		path = path[:len(path)-1]
	}
	vis[arr[i][j]] = false
}

func solver() {
	defer writer.Flush()
	var m int
	var n int
	var s int
	var i int
	var j int
	var starti int = 0
	var startj int = 0
	scanf("%d %d %d\n", &m, &n, &s)

	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			arr[i][j] = (j + 1) + (n * i)
			if arr[i][j] == s {
				starti = i
				startj = j
			}
			//printf("%d ", arr[i][j])
		}
		//printf("\n")
	}

	for i = 0; i < m*n; i++ {
		var t1, t2, t3, t4, t5, t6, t7, t8, t9 int
		scanf("%d %d %d %d %d %d %d %d %d \n", &t1, &t2, &t3, &t4, &t5, &t6, &t7, &t8, &t9)

		direction[t1][1] = t2
		direction[t1][2] = t3
		direction[t1][3] = t4
		direction[t1][4] = t5
		direction[t1][5] = t6
		direction[t1][6] = t7
		direction[t1][7] = t8
		direction[t1][8] = t9
	}

	var paths []int

	recur(starti, startj, m, n, paths)

	for i = 1; i <= 4; i++ {
		for k := range mp[i] {
			printf("%d ", mp[i][k])
		}
		printf("\n")
	}
}
