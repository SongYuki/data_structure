#include<stdio.h>
typedef struct {
	char *sport;
	enum{male,female}gender;
	char schoolname;//У��Ϊ'A''B''C''D''E'
	char *result;
	int score;
}resulttype;

typedef struct {
	int malescore;
	int femalescore;
	int totalscore;
}scoretype;

void summary(resulttype result[])//���У����Ů�ֺܷ������ܷ֣��������Ѿ��洢��result[]������
{
	scoretype score;
	i = 0;
	while (result[i].sport!=NULL)
	{
		switch (result[i].schoolname)
		{
		case'A':
			score[0].totalscore += result[i].score;
			if (result[i].gender==0)
			{
				score[0].malescore += result[i].score;
			}
			else
			{
				score[0].femalescore += result[i].score;
			}
			break;
		case'B':
			score[1].totalscore += result[i].score;
			if (result[i].gender == 0)
			{
				score[1].malescore += result[i].score;
			}
			else
			{
				score[1].femalescore += result[i].score;
			}
			break;
		case'C':
			score[2].totalscore += result[i].score;
			if (result[i].gender == 0)
			{
				score[2].malescore += result[i].score;
			}
			else
			{
				score[2].femalescore += result[i].score;
			}
			break;
		case'D':
			score[3].totalscore += result[i].score;
			if (result[i].gender == 0)
			{
				score[3].malescore += result[i].score;
			}
			else
			{
				score[3].femalescore += result[i].score;
			}
			break;
		case'E':
			score[4].totalscore += result[i].score;
			if (result[i].gender == 0)
			{
				score[4].malescore += result[i].score;
			}
			else
			{
				score[4].femalescore += result[i].score;
			}
			break;
		default:
			break;
		}
		i++;
	}
	for ( i = 0; i < 5; i++)
	{
		printf("School %d:\n", i);
		printf("Total score of male:%d\n", score[i].malescore);
		printf("Total score of female:%d\n", score[i].femalescore);
		printf("Total score of all:%d\n\n", score[i].totalscore);
	}
}//summary
