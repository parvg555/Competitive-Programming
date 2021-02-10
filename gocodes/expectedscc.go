package main

import (
	"fmt"
)

var mod int64 = 998244353
var ll2 int64 = 2
var ll0 int64 = 0

func power(a int64, b int64) int64 {
	if b == 0 {
		return 1
	}
	if b == 1 {
		return a
	}
	if b%2 == 1 {
		return (power(a, b-1) * a) % mod
	}

	var q int64 = power(a, b/2)
	return (q * q) % mod
}

func max(a int64, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func solve() {
	var m int64
	var n int64
	var k int64
	fmt.Scan(&m)
	fmt.Scan(&n)
	fmt.Scan(&k)
	if m == 2 {
		var x int64 = power(k, 2*n)
		x = power(x, mod-2)
		if k == 1 {
			fmt.Println(x)
			return
		}
		dp := make([][]int64, n)
		var i int64
		for i = 0; i < n; i++ {
			dp[i] = make([]int64, 2)
		}

		dp[0][0] = k
		dp[0][1] = (2 * k * (k - 1)) % mod
		for i = 0; i < n; i++ {
			dp[i][0] += ((k - 1) * (dp[i-1][0] + (k*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][0] %= mod
			dp[i][0] = dp[i-1][0]
			dp[i][0] %= mod
			dp[i][0] += (ll2 * dp[i-1][1]) % mod
			dp[i][0] %= mod
			dp[i][0] += ((k - 2) * (dp[i-1][1] + (((k*(k-1))%mod)*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][0] %= mod
			//for j=1
			dp[i][1] += ((k - 1) * (dp[i-1][0] + (k*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += ((k - 1) * (dp[i-1][0] + (k*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += ((((k - 2) * (k - 1)) % mod) * (dp[i-1][0] + (2*k*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += dp[i-1][1]
			dp[i][1] %= mod
			dp[i][1] += (((k - 2) % mod) * (dp[i-1][1] + (((k*(k-1))%mod)*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += (((k - 2) % mod) * (dp[i-1][1] + (((k*(k-1))%mod)*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += (((k - 2) % mod) * (dp[i-1][1] + ((2*(k*(k-1))%mod)*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += (((k - 1) % mod) * (dp[i-1][1] + ((2*(k*(k-1))%mod)*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
			dp[i][1] += ((((k - 2) * (max(k-3, ll0))) % mod) * (dp[i-1][1] + ((2*(k*(k-1))%mod)*power(k, 2*(i-1)))%mod) % mod) % mod
			dp[i][1] %= mod
		}
		var ans int64 = dp[n-1][0] + dp[n-1][1]
		ans %= mod
		ans *= x
		ans %= mod
		fmt.Println(ans)
	} else {
		dp := make([]int64, n+1)

		dp[1] = k
		var i int64
		for i = 2; i < n+1; i++ {
			dp[i] += dp[i-1]
			dp[i] %= mod
			dp[i] += ((k - 1) * (dp[i-1] + (power(k, i-1)))) % mod
			dp[i] %= mod
		}
		var xx int64 = power(k, n)
		xx = power(xx, mod-2)
		println((dp[n] * xx) % mod)
	}
}

func main() {
	solve()
}
