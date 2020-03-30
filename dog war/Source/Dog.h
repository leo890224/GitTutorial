namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Dog
	{
	public:
		Dog();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow(background *);					// �N���l�ϧζK��e��
		bool MeetCat(CEraser *);        // �ˬd�O�_�����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void SetAttack(bool flag);
		void Jump();                    //�]�w�u��
	protected:
		CAnimation walk;		    // �������ʵe
		CAnimation punch;           // ���h���ʵe
		CAnimation attack;          // �������ʵe
		int x, y;					// ���l���W���y��
		int floor;				    // �a�O��Y�y��
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isAttack;
		bool rising;			    // true��W�ɡBfalse��U��
		int initial_velocity;	    // ��l�t��
		int velocity;			    // �ثe���t��(�I/��)
	};
}