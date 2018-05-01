#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
double A =9179;//   в формуле вариант коэффициент
double Sum=0;
double disp = 0;
double col1=0,col2=0,col3=0,col4=0,col5=0,col6=0,col7=0,col8=0,col9=0,col10=0;
int i = 0;
double C = 5904;//в формуле вариант коэффициент
double matoj=0;
double r = 0;
double r1 = 0;
double r2 = 0;
double r3 = 0;
double r4 = 0;
double prob = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int s = 0;
double R =7;// х0 или начальное значение в формуле
double R1 = 5;
double R2 = 7;
double R3 = 9;
double R4 = 13;
 double m =6009;// модуль в формуле 
  double deviation(double disp);
  double disperse();
  double mat();
double randomix()
{
	// все, что в этом коде зеленое, пусть так и будет, это все ко 2 лабе относится, это потом будет нужно
	R =(A * R + C);//R - начальное значение и дальнейшее значение , полученное по формуле, в скобках -ваша формула, до связия по модулю
	  R = fmod(R, m);// это сама часть взятия по модулю, можно было расписать на предыдущей строчке , но я что-то не додумалась:))

	  r = R / m;// вот это само число окончательное, рандомное, в рамках от 0 до 1 
	 Sum += r;// эта строчка означает, что прибавляется к sum это полученное число, чтобы потом посчитать мат ожидание
	
	if(r>0 && r<=0.1)// здесь прога смотрит в какой диапазон цифр попадает полученное число, чтобы посчитать , сколько цифр входит в диапазон, это частота 
	{
		col1++;

	}
	if(r>0.1 && r<=0.2){
	
	col2++;
	}
	if(r>0.2 && r<=0.3){
	
	col3++;
	}
	if(r>0.3 && r<=0.4){
	
	col4++;
	}
	if(r>0.4 && r<=0.5){
	
	col5++;
	}
	if(r>0.5 && r<=0.6){
	
	col6++;
	}
	if(r>0.6 && r<=0.7){
	
	col7++;
	}
	if(r>0.7 && r<=0.8){
	
	col8++;
	}
	if(r>0.8 && r<=0.9){
	
	col9++;
	}
	if(r>0.9 && r<=1){
	
	col10++;
	}
	
    return r;
	
}/*double B()
{ 
	//double R =5;
	R = (A * R + C);
	R = fmod(R, m);
	r1 = R / m;
	//B
	if (r1 < 0.9)
	{
		b = 1;
	}
	else {
		b = 0;
	}
	
	return b;
}
double C1()
{
//	double R = 7;
	R = (A * R + C);
	R = fmod(R, m);
	r2 = R / m;
	//B
	if (r2 < 0.85)
	{
		c = 1;
	}
	else {
		c = 0;
	}
	Sum += (r2);
	return c;
}
double D()
{
	//double R = 33;
	R= (A * R + C);
	R = fmod(R, m);
	r3 = R / m;
	//B
	if (r3 < 0.7)
	{
		d = 1;
	}
	else {
		d = 0;
	}
	
	return d;
}
double E() 
{
	//double R =2;
	R= (A * R + C);
	R= fmod(R, m);
	r4 = R / m;
	//B
	if (r4 < 0.6)
	{
		e = 1;
	}
	else {
		e = 0;
	}

	return e;
}*/
double mat()
{
	matoj = Sum / 600;// расчет мат ожидания, вместо 600 вставить количество чисел для вашего варианта( от 500 до 1000, кажется)
//disperse();
	
	return matoj;
}
double disperse()
{
	for (i = 0; i<600; i++)// поменять 600 на ваше количесто чисел
	{

		std::cout << randomix() << "\n";
		disp+=((R/m)-matoj)*((R/m)-matoj);// расчет дисперсии с помощью мат ожидания
	
	}
	
	return disp;
}
double deviation(double disp){

	double dev=0;
	dev=sqrt(disp);// расчет среднеквадратичного отклонения
	return dev;
}
void count()// эта функция просто считает значения для графика плоности распределения, где тупеньки, там в цикле просто делятся числа от 1-до количеста ваших чисел на все количество ваших чисел, типо 1:600, 2:600...600:600
{ double leftax=0;
 std::  ofstream out("D:\\projects VS c++\\genrandomnumbers\\numbers.txt"); // // создаем в папке проекта, где эта прога у ас лежит текстовый файл с названием numbers, там будут эти числа для графика после выполнения программы.
	 // открываем файл
std::cout<<"/n This is vertical  axis";
	for (double i=1;i<600;i++)// вставить свое количество чисел
	{
		leftax = ((i/600));//вставить свое количество чисел
		std::cout<<leftax  <<std::endl;
		  out << leftax << '\n'; 
	}
	 out.close();
}
// ниже часть для 3 лабы,не удалять
/*double result()
{
	int one = 0; int two = 0; int three = 0;
	one = a | b;
	two = one | c;
	three = d | e;
	one = two & three;
	prob+= (a |b |c)&(d | e);
	return prob;
}*/
int main(int argc, char **argv)// начало проги, чтобы запустить проект в папку, где лежит эта прога, создать текстовый файл с назанием numbers1, после выполнения проги в этом файле будут все вши сгенеренные числа
{std::  ofstream out("D:\\projects VS c++\\genrandomnumbers\\numbers1.txt"); // // создаем объект класса ifstream
    for(i=0; i<600; i++)// вставить свое количество чисел
	{	
  
    std::cout <<"A:"<<randomix() << "\n";
	/*std::cout << "B:" << B() << "\n";
	std::cout << "C:" << C1() << "\n";
	std::cout << "D:" << D() << "\n";
	std::cout << "E:" << E() << "\n";*/
	out<<randomix()<<"\n";
	
	}
	// отсюда все выводит на экран, все частоты написаны от col1 до col10 , то есть 10 интералов одинаковых
	a = col1 + col2 + col3 + col4 + col5 + col6 + col7 + col8 + col9 + col10;

	std::cout<<"Sum" << a << "\n" << col1 << "\n";
	std::cout << col2 << "\n";;
	std::cout << col3 << "\n";;
	std::cout << col4 << "\n";;
	std::cout << col5 << "\n";;
	std::cout << col6 << "\n";;
	std::cout << col7 << "\n";;
	std::cout << col8 << "\n";;
	std::cout << col9 << "\n";;
	std::cout << col10;
	std::cout<<"Matoj";
	std::cout<< mat()<<"\n:";
	std::cout << "Disperse";
	disperse();
	disp = disp / 600;
	std::cout << disp << "\n";
	deviation(disp);
	out.close();
	//count();
	
    
  system ("pause"); //Чтобы сразу не пропадало окно
 return 0;
}

