bool _exist(char** board, int boardSize, int* boardColSize, char* word, int row, int col, int len)
{
	// �Ա߽����������ж�
	if (row < 0 || col < 0 || row >= boardSize || col >= *boardColSize || board[row][col] != word[len])
		return false;

	// �ж��Ƿ����·�������·��˵�������л���������������·��
	if (strlen(word) - 1 == len)
		return true;
	// ����ǰ��λ������Ϊ����ĸ��ʹ�õݹ�ʱ��������ٴβ��ҵ����
	char tmp = board[row][col];
	board[row][col] = '*';
	// �ӵ�ǰλ�õ��������ҵݹ��ж��ĸ������Ƿ��������·������һ���ڵ�
	// �����ڵĻ�����false���еĻ�����true
	bool res = (_exist(board, boardSize, boardColSize, word, row, col + 1, len + 1) ||
		_exist(board, boardSize, boardColSize, word, row, col - 1, len + 1) ||
		_exist(board, boardSize, boardColSize, word, row + 1, col, len + 1) ||
		_exist(board, boardSize, boardColSize, word, row - 1, col, len + 1));
	// ����λ�û�ԭ
	board[row][col] = tmp;
	return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < *boardColSize; j++)
		{
			// �Ծ����е�������ĸ��ʼ������Ȼ����һ����ĸ������ڵĻ�����ôһ������true�����򷵻�false��֪������trueλ�ã�ѭ������û�з���true�Ļ���ֱ�ӷ���false
			if (_exist(board, boardSize, boardColSize, word, i, j, 0))
				return true;
		}
	}
	return false;
}