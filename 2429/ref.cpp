#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
 
typedef long long LL;
 
// return (a * b) % m
LL mod_mult(LL a, LL b, LL m) 
{
	LL res = 0;
	LL exp = a % m;
	while (b) 
	{
		if (b & 1) 
		{
			res += exp;
			if (res > m) res -= m;
		}
		exp <<= 1;
		if (exp > m) exp -= m;
		b >>= 1;
	}
	return res;
}
 
// return (a ^ b) % m
LL mod_exp(LL a, LL b, LL m) {
	LL res = 1;
	LL exp = a % m;
	while (b) 
	{
		if (b & 1) res = mod_mult(res, exp, m);
		exp = mod_mult(exp, exp, m);
		b >>= 1;
	}
	return res;
}
 
// 
//************************************
// Method:    miller_rabin
// FullName:  miller_rabin
// Access:    public 
// Returns:   bool �Ƿ�������
// Qualifier: Rabin-Millerǿα��������
// Parameter: LL n ��������
// Parameter: LL times 
//************************************
bool miller_rabin(LL n, LL times) 
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (!(n & 1)) return false;
 
	LL q = n - 1;
	int k = 0;
	while (q % 2 == 0) {
		k++;
		q >>= 1;
	}
	// n - 1 = 2^k * q (q��������)
	// n�������Ļ���һ��������������
	// (i) a^q �� 1 (mod n)
	// (ii) a^q, a^2q,..., a^(k-1)q �е�ĳһ����n��ģΪ-1
	//
	// ���ԡ���������(i)(ii)�е��κ�һ����ʱ�򣬾���3/4�ĸ����Ǻϳ���
	//
	for (int i = 0; i < times; ++i) 
	{
		LL a = rand() % (n - 1) + 1; // ��1,..,n-1�����һ����
		LL x = mod_exp(a, q, n);
		// �������(i)
		if (x == 1) continue;
		// �������(ii)
		bool found = false;
		for (int j = 0; j < k; j++) 
		{
			if (x == n - 1) 
			{
				found = true;
				break;
			}
			x = mod_mult(x, x, n);
		}
		if (found) continue;
 
		return false;
	}
	return true;
}
 
LL get_gcd(LL n, LL m) 
{
	if (n < m) swap(n, m);
	while (m) 
	{
		swap(n, m);
		m %= n;
	}
	return n;
}
 
 
//************************************
// Method:    pollard_rho
// FullName:  pollard_rho
// Access:    public 
// Returns:   LL
// Qualifier: Pollard ?�����ֽ��㷨
// Parameter: LL n
// Parameter: int c
//************************************
LL pollard_rho(LL n, int c) 
{
	LL x = 2;
	LL y = 2;
	LL d = 1;
	while (d == 1) 
	{
		x = mod_mult(x, x, n) + c;
		y = mod_mult(y, y, n) + c;
		y = mod_mult(y, y, n) + c;
		d = get_gcd((x - y >= 0 ? x - y : y - x), n);
	}
	if (d == n) return pollard_rho(n, c + 1);
	return d;
}
 
#define MAX_PRIME 200000
vector<int> primes;
vector<bool> is_prime;
 
// ������MAX_PRIME�ڵ�������
void init_primes() 
{
	is_prime = vector<bool>(MAX_PRIME + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX_PRIME; ++i) 
	{
		if (is_prime[i]) 
		{
			primes.push_back(i);
			for (int j = i * 2; j <= MAX_PRIME; j += i) 
			{
				is_prime[j] = false;
			}
		}
	}
}
 
// �ж��Ƿ������������Ȳ�����n�ܴ���Rabin-Millerǿα��������
bool isPrime(LL n) 
{
	if (n <= MAX_PRIME) return is_prime[n];
	else return miller_rabin(n, 20);
}
 
// �ֽ�������ӣ�С����������������Pollard ?�����ֽ��㷨
void factorize(LL n, map<LL, int>& factors) 
{
	if (isPrime(n)) 
	{
		factors[n]++;
	}
	else 
	{
		for (int i = 0; i < primes.size(); ++i) 
		{
			int p = primes[i];
			while (n % p == 0) 
			{
				factors[p]++;
				n /= p;
			}
		}
		if (n != 1) 
		{
			if (isPrime(n)) 
			{
				factors[n]++;
			}
			else 
			{
				LL d = pollard_rho(n, 1);
				factorize(d, factors);
				factorize(n / d, factors);
			}
		}
	}
}
 
pair<LL, LL> solve(LL a, LL b) 
{
	LL c = b / a;
	map<LL, int> factors;
	factorize(c, factors);
 
	vector<LL> mult_factors;	// ÿ�������ӵ�n�η�������2^2��5^1
	for (map<LL, int>::iterator it = factors.begin(); it != factors.end(); it++) 
	{
		LL mul = 1;
		while (it->second) 
		{
			mul *= it->first;
			it->second--;
		}
		mult_factors.push_back(mul);
	}
 
	LL best_sum = 1e18, best_x = 1, best_y = c;
	// ����һ��ȡ���Ĺ��̣�һ�� 2^size �����
	for (int mask = 0; mask < (1 << mult_factors.size()); ++mask)
	{
		LL x = 1;
		for (int i = 0; i < mult_factors.size(); ++i)
		{
			if (mask & (1 << i)) x *= mult_factors[i];
		}
		LL y = c / x;
		if (x < y && x + y < best_sum) 
		{
			best_sum = x + y;
			best_x = x;
			best_y = y;
		}
	}
	return make_pair(best_x * a, best_y * a);
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	init_primes();
	LL a, b;
	while (cin >> a >> b) 
	{
		pair<LL, LL> ans = solve(a, b);
		cout << ans.first << " " << ans.second << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
///////////////////////////End Sub//////////////////////////////////