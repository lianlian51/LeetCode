// ��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���
// �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ��


bool isMatchCore(char* s, char* p)
{
	// s��p��Ϊ��ʱ������true
	if (*p == '\0' && *s == '\0')
		return true;
	// s��Ϊ�գ�pΪ��ʱ����true
	if (*s != '\0' && *p == '\0')
		return false;
	// p+1����*ʱ������ƥ�䷽ʽ
	if (*(p + 1) == '*')
	{
		// �������
		if (*p != *s && *p != '.')
			return isMatchCore(s, p + 2);
		if (*p == '.' && *s != '\0')
			return isMatchCore(s, p + 2) || isMatchCore(s + 1, p);
		else if (*p == '.' && *s == '\0')
			return isMatchCore(s, p + 2);
		if (*p == *s)
			return isMatchCore(s + 1, p) || isMatchCore(s, p + 2);
	}

	// ����s��Ϊ�գ�������ȵ����
	if ((*p == '.' && *s != '\0') || *p == *s)
		return isMatchCore(s + 1, p + 1);
	return false;
}


bool isMatch(char* s, char* p){
	if (p == NULL && s == NULL)
		return false;
	return isMatchCore(s, p);
}