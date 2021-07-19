package onwtwo

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

type question struct {
	subparts int
	maxmarks int
	maxbysub float32
	qno      int
}

type ques []question

var sessional []int
var q []question
var min, s, n int

func (q ques) Len() int {
	return len(q)
}

func (q ques) Less(i, j int) bool {
	if q[i].subparts != q[j].subparts {
		return q[i].subparts > q[j].subparts
	}
	return q[i].maxbysub < q[j].maxbysub
}
func (q ques) Swap(i, j int) {
	q[i], q[j] = q[j], q[i]
}

func input() {
	defer writer.Flush()
	scanf("%d %d %d \n", &min, &s, &n)
	var i int = 0
	var temp int
	for i < s {
		scanf("%d ", &temp)
		temp = min - temp
		sessional = append(sessional, temp)
		i++
	}
	i = 0
	for i < n {
		var u, v int
		temp := new(question)
		scanf("%d %d\n", &u, &v)
		temp.subparts = v
		temp.maxmarks = u
		temp.maxbysub = float32(u / v)
		temp.qno = i + 1
		q = append(q, *temp)
		i++
	}
}

func printer() {
	var i int = 0
	var j int = 0
	for i < s {
		var pos int = 0
		var ans []int
		for sessional[i] > 0 {
			ans = append(ans, q[pos].qno)
			sessional[i] -= q[pos].maxmarks
			pos++
		}
		sort.Ints(ans)
		printf("%d ", len(ans))
		j = 0
		for j < len(ans) {
			printf("%d ", ans[j])
			j++
		}
		printf("\n")
		i++
	}
}

func main() {
	input()
	sort.Sort(ques(q))
	printer()
}
