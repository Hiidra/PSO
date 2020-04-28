#ifndef _PSO_H_
#define _PSO_H_

#include<cmath>

/*������Ӧ�Ⱥ���ѡ��Ҫ���ĸ���������Ϊ1,��ֻ����һ��Ϊ1*/
#define FUNC_CHOICE "Generalized_Penalized_2"                       //�ģ�������������������
//��ά����
#define six_hump_camel_back_function 0
//���庯��
#define Sphere 0							//range = 100.0,	Best_fitness = 0
#define Sphere_Shifted 0//range = 100.0,	Best_fitness = -450.0,	fbias = -450.0
#define Axis_parallel_hyper_ellipsoid 0
//��庯��
#define Rastrigin	0				//range = 5.12,		Best_fitness = 0
#define Rastrigin_Shifted	0				//range = 5.0,		Best_fitness = -330.0,	fbias = -330.0 
#define Rastrigin_Shifted_Rotated	0		//range = 5.0,		Best_fitness = -330.0,	fbias = -330.0 
#define Ackley 0							//range = 32.0,		Best_fitness = 0
#define Ackley_Shifted_Rotated 0			//range = 32.0,		Best_fitness = -140.0,	fbias = -140.0
#define Griewank 0							//range = 600.0,	Best_fitness = 0
#define Schwefel	0  		//range = 500.0,	Best_fitness = 0
#define Generalized_Penalized_1 0			//range = 50.0,		Best_fitness = 0
#define Generalized_Penalized_2 1			//range = 50.0,		Best_fitness = 0
//����ʽ���Ժ���
#define Martin_and_Gaddy	0
#define Goldstein_and_Price 0
#define Demo 0
#define Rosenbrock 0						//range = 100.0,	Best_fitness = 0

#define PI acos(-1)
#define leftrange  -50.0                               //  �ģ�������������
#define rightrange 50.0                            // �ģ���������
#define Dim 30//����ά��
#define PNum 40	//��Ⱥ��ģ
#define ITE_N  10000//����������
#define REALNUM 0.0    //��������ʵֵ                        �ģ�������������
#define N 1//��������
#define L 50//ÿ�������Ŀ
#define sudu 10.0    //����ٶ�                              ��!!!!!!!!leftrange��1/5
extern int cur_n;			//��ǰ��������

							/*����Ȩ�غ���*/
#define W_START 1.4
#define W_END	0.4
//#define W_FUN	(W_START-(W_START-W_END)*pow((double)cur_n/ITE_N,2))//0.9-cur_n/ITE_N*0.5
#define W_FUN 0.9-cur_n/ITE_N*0.5
/*�������Ⱥ�ṹ��*/
class PARTICLE
{
public:
	double X[Dim];
	double P[Dim];
	double V[Dim];
	double Fitness;
	friend class SWARM;
};
class SWARM
{
public:
	PARTICLE Particle[PNum];
	int GBestIndex;//ȫ���������ӵı��
	double GBest[Dim];
	double Xup[Dim];
	double C1;
	double C2;
	double Xdown[Dim];
	double Vmax[Dim];
public:
	void RandInitofSwarm(void);
	void UpdateofVandX(void);
	void UpdatePandGbest(void);
};
double ComputAFitness(double X[]);


#endif


