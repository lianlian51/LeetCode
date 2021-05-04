///**
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//* };
//*/
//class Solution {
//	int sum = INT_MIN;
//public:
//	int maxvalue(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		// ������������ļ�ֵ
//		int left = max(maxvalue(root->left), 0);
//		int right = max(maxvalue(root->right), 0);
//
//		// �������ֵ
//		int price = left + right + root->val;
//
//		// ���¼�ֵ
//		sum = max(sum, price);
//
//		return root->val + max(left, right);
//	}
//
//	int maxPathSum(TreeNode* root) {
//		maxvalue(root);
//		return sum;
//	}
//};

//#include <iostream>
//#include <string.h>
//
//bool Increment(char* number);
//void PrintNumber(char* arr);
//
//void Print1ToMax1(int n)
//{
//	if (n <= 0)
//		return;
//	char* arr = new char[n + 1];
//	memset(arr, '0', n);
//	arr[n] = '\0';
//
//	while (!Increment(arr))
//	{
//		PrintNumber(arr);
//	}
//
//	delete[] arr;
//}
//bool Increment(char* number)
//{
//	bool flag = false;
//	int length = strlen(number);
//	int nTakeOver = 0;
//	for (int i = length - 1; i >= 0; --i)
//	{
//		// �ó�ĩβ����
//		int nSum = number[i] - '0' + nTakeOver;
//		// ֻ��ĩβ����++
//		if (length - 1 == i)
//			nSum++;
//
//		// ���iλ�����ִ���10,�������н�λ����
//		if (nSum >= 10)
//		{
//			// ������ʵ�0λ��Ԫ�أ����ʾ���
//			if (i == 0)
//			{
//				flag = true;
//			}
//			else
//			{
//				nSum -= 10;
//				nTakeOver = 1;
//				number[i] = nSum + '0';
//			}
//		}
//		else
//		{
//			number[i] = nSum + '0';
//			break;
//		}
//	}
//	return flag;
//}
//void PrintNumber(char* arr)
//{
//	// ���ַ�����ĵ�һ����0�����ֿ�ʼ��ӡ
//	int length = strlen(arr);
//	bool isbegin = true;
//	for (int i = 0; i < length; ++i)
//	{
//		// �ж��ǲ��Ƿ�0
//		if (isbegin && arr[i] != '0')
//			isbegin = false;
//
//		// ��ӡ��0֮�������
//		if (!isbegin)
//		{
//			printf("%c", arr[i]);
//		}
//	}
//	printf("\t");
//}
//void PrintRecur(char*number, int n, int index);
//void Print1ToMax2(int n)
//{
//	if (n <= 0)
//		return;
//
//	char* number = new char[n + 1];
//	number[n] = '\0';
//
//	for (int i = 0; i < 10; ++i)
//	{
//		number[0] = i + '0';
//		PrintRecur(number, n, 0);
//	}
//	delete[] number;
//}
//void PrintRecur(char*number, int n, int index)
//{
//	if (index == n - 1)
//	{
//		PrintNumber(number);
//		return;
//	}
//
//	for (int i = 0; i < 10; ++i)
//	{
//		number[index + 1] = i + '0';
//		PrintRecur(number, n, index + 1);
//	}
//}
//
//void Test(int n)
//{
//	printf("Test %d begins:\n", n);
//	Print1ToMax1(n);
//	Print1ToMax2(n);
//	printf("Test %d end\n", n);
//}
//
//int main()
//{
//	Test(1);
//	Test(2);
//	Test(-1);
//	return 0;
//}


#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
// ����ģʽ
/*
class Singleton
{
public:
static Singleton* GetInstance()
{
return &m_instance;
}

private:
Singleton(){};

Singleton(Singleton const&) = delete;
Singleton& operator=(Singleton const&) = delete;

static Singleton m_instance;
};

Singleton Singleton::m_instance;
*/

// ����ģʽ
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();
			if (nullptr == m_pInstance)
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}

	// ʵ��һ����Ƕ����������
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������ͷŵ�������
	static CGarbo Garbo;

private:
	// ���캯��˽��
	Singleton(){};
	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx;
};

Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}
