package one

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

type custom []question

func (q custom) Len() int { return len(q) }
func (q custom) Less(i, j int) bool {
	if q[i].subparts != q[j].subparts {
		return q[i].subparts > q[j].subparts
	}
	return q[i].maxbysub < q[j].maxbysub
}
func (q custom) Swap(i, j int) { q[i], q[j] = q[j], q[i] }

func main() {
	defer writer.Flush()
	var min, s, n int
	scanf("%d %d %d \n", &min, &s, &n)
	var sessional []int
	var i int
	for i = 0; i < s; i++ {
		var temp int
		scanf("%d ", &temp)
		sessional = append(sessional, min-temp)
	}
	var q []question
	for i = 0; i < n; i++ {
		var u, v int
		temp := new(question)
		scanf("%d %d\n", &u, &v)
		temp.subparts = v
		temp.maxmarks = u
		temp.maxbysub = float32(u / v)
		temp.qno = i + 1
		q = append(q, *temp)
	}
	sort.Sort(custom(q))
	var j int
	for i = 0; i < s; i++ {
		var pos int = 0
		var ans []int
		for sessional[i] > 0 {
			ans = append(ans, q[pos].qno)
			sessional[i] -= q[pos].maxmarks
			pos++
		}
		sort.Ints(ans)
		printf("%d ", len(ans))
		for j = 0; j < len(ans); j++ {
			printf("%d ", ans[j])
		}
		printf("\n")
	}

}
