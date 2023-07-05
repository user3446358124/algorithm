#include<iostream> // 引入输入输出流库
#include <string> // 引入字符串库
#include<vector> // 引入向量库

using namespace std; // 使用命名空间 std

vector<int> multiplication(vector<int> a, vector<int> b) // 定义一个函数，用于将两个整数向量相乘
{
	vector<int> c(a.size() + b.size() - 1, 0); // 定义一个新的整数向量 c
	reverse(a.begin(), a.end()); // 将 a 反转
	reverse(b.begin(), b.end()); // 将 b 反转

	for (int i = 0; i < a.size(); i++) // 从后往前遍历 a 和 b
	{
		for (int j = 0; j < b.size(); j++)
		{
			c[i + j] = a[i] * b[j]; // 将 a 和 b 的每一位相乘，结果存储在 c 中
		}
	}
	for (int i = 0; i < c.size(); i++) // 遍历 c
	{
		if (c[i] > 9) // 如果 c 的第 i 位大于 9
		{
			c[i + 1] += c[i] / 10; // 进位
			c[i] = c[i] % 10; // 取余数
		}
	}
	reverse(c.begin(), c.end()); // 将 c 反转
	return c; // 返回 c
}
int main() // 主函数
{
	string a, b; // 定义两个字符串变量 a 和 b
	cin >> a >> b; // 从控制台读入两个字符串

	vector<int> a1, b1; // 定义两个整数向量 a1 和 b1
	for (int i = 0; i < a.size(); i++)
	{
		a1.push_back(a[i] - '0'); // 将字符串 a 转换为整数向量 a1
	}
	for (int i = 0; i < b.size(); i++)
	{
		b1.push_back(b[i] - '0'); // 将字符串 b 转换为整数向量 b1
	}

	vector<int> c1 = multiplication(a1, b1); // 调用 multiplication 函数，将 a1 和 b1 相乘，结果存储在 c1 中
	string c;

	for (int i = 0; i < c1.size(); i++)
	{
		c += to_string(c1[i]); // 将整数向量 c1 转换为字符串 c
	}
	cout << c; // 输出字符串 c 到控制台
	return 0;
}
