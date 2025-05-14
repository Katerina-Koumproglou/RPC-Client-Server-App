struct ques1
{
	int n;
	int Y<>;
};

struct ques2
{
	int n;
	int Y<>;
};

struct ques3
{
	int n;
	int Y<>;
    float a;
};

struct return2
{
	int Arr1[2];
};

struct return3
{
	float Arr2<>;
};

program ASK1_PROG
{
    version QUES1_VERSION
    {
        float QUES1(ques1) = 1;
    } = 1;

    version QUES2_VERSION
    {
        return2 QUES2(ques2) = 1;
    } = 2;

    version QUES3_VERSION
    {
        return3 QUES3(ques3) = 1;
    } = 3;
} = 0x12345678;
