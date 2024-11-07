// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

#if defined(_WIN32)
const char* OS_CLEAR = "cls";
#elif defined(__linux__)
const char* OS_CLEAR = "clear";
#elif defined(__unix__)
const char* OS_CLEAR = "clear";
#endif
#define CLS system(OS_CLEAR)

#define MM solverA<TDynamicMatrix<T>, TDynamicMatrix<T>, TDynamicMatrix<T>>(res_m, arg1_m, arg2_m, cur_op)
#define MS solverA<TDynamicMatrix<T>, TDynamicMatrix<T>, T>(res_m, arg1_m, arg2_s, cur_op)
#define MV solverMultiply<TDynamicVector<T>, TDynamicMatrix<T>, TDynamicVector<T>>(res_v, arg1_m, arg2_v, cur_op)
#define VM	//У нас в классе не определены операции vector @ matrix
#define VVM solverMultiply<T, TDynamicVector<T>, TDynamicVector<T>>(res_s, arg1_v, arg2_v,cur_op)
#define VVA solverAA<TDynamicVector<T>, TDynamicVector<T>, TDynamicVector<T>>(res_v, arg1_v, arg2_v,cur_op)
#define VS solverA<TDynamicVector<T>, TDynamicVector<T>, T>(res_v, arg1_v, arg2_s,cur_op)
#define SS solverA<T, T, T>(res_s, arg1_s, arg2_s,cur_op)

inline void g_line() noexcept {		//print line -------
	for (auto i = 0; i < 20; i++) cout << static_cast<char>(0xC4); cout << '\n'; return;
}
inline void arg_type(int arg1,int arg2) noexcept {
	cout << (arg1==1 ? ((arg2==1 ? ("matrix and matrix") : (arg2 == 0 ? "matrix and vector" : "matrix and scalar"))) : (!arg1 ? ((arg2 == 1 ? ("vector and matrix") : (!arg2 ? "vector and vector" : "vector and scalar"))) : ((arg2 == 1 ? ("scalar and matrix") : (!arg2 ? "scalar and vector" : "scalar and scalar"))))) << endl; return;
}

void op_status(int arg1,int arg2,_Notnull_ string op_arr[], int cur_op) {	//print operation and object's types
	g_line();
	cout << "operation type: " << op_arr[cur_op] <<endl;
	cout << "operation args: ";
	arg_type(arg1, arg2);
	g_line();
}
void set_type_args(int& arg1, int& arg2) {		//choose math object for operation
	CLS;
	g_line();
	cout << "Your args: "; arg_type(arg1, arg2);
	cout << "Set a type of args, where m - matrix, v - vector, s - scalar\nExample: m v\n";
	char t1, t2; cin >> t1 >> t2;
	if ((t1 != 'm' && t1 != 'v' && t1!='s') || (t2 != 'm' && t2 != 'v' && t2!='s')) {
		cout << "unknown type!\n";
		return;
	}
	arg1 = (t1 == 'm') + (t1=='s')*2;
	arg2 = (t2 == 'm') + (t2 == 's')*2;
	g_line();
	return;
}
template<class T>
void set_matrix(TDynamicMatrix<T>& matrix_) {	
	g_line();
	size_t size;
	cout << "Type size of matrix: "; cin >> size;
	TDynamicMatrix<T> temp_matrix(size); cin >> temp_matrix;
	matrix_ = temp_matrix;
	g_line();
	return;
}
template<class T>
void set_vector(TDynamicVector<T>& vector_) {
	g_line();
	size_t size;
	cout << "Type size of vector: "; cin >> size;
	TDynamicVector<T> temp_vector(size); cin >> temp_vector;
	vector_ = temp_vector;
	g_line();
	return;
}
template<class T>
void set_scalar(T& s) {
	g_line();
	cout << "Type scalar: ";
	T r; cin >> r;
	s = r;
	g_line();
	return;
}

void choose_operation(int& op, _Notnull_ string op_arr[]) {	
	g_line();
	cout << "Current operation is " << op_arr[op] << endl;
	cout << "Set new operation:\n1 - \'+\'\n2 - \'-\'\n3 - \'*\'\n4 - \'==\'\n";
	char tmp; cin >> tmp;
	if (tmp < 49 || tmp>52) {
		cout << "unknown operation!\n";
	}
	else {
		op = tmp - 49;
	}
	g_line();
	return;
}

int check(int operation, int op1, int op2) noexcept {	//	\/	\/	\/	\/
	constexpr char MxM = 15;				
	constexpr char MxV = 4;			//every char is table T 2x4, where T[0][0] M+V, T[0][1] M-V, T[0][2] M*V, T[1][0] V+M, T[1][1] V-M, T[1][2] V*M		1 if we can do operation, else 0
	constexpr char MxS = 7;			//T[*][3] for ==
	constexpr char VxS = 7;
	constexpr char VxV = 15;
	constexpr char SxS = 15;

	if (op1 == 1) {
		if (op2 == 1) {
			return ((1 << operation) & MxM) > 0;	//return bit (element T) == true
		}
		else if(op2==2){
			return ((1 << operation) & MxS) > 0;
		}
		else {
			return ((1 << operation) & MxV) > 0;
		}
	}
	else if (op1 == 2) {
		if (op2 == 1) {
			return ((1 << (operation+3)) & MxS) > 0;
		}
		else if (op2 == 2) {
			return ((1 << operation) & SxS) > 0;
		}
		else {
			return ((1 << (3+operation)) & VxS) > 0;
		}
	}
	else {
		if (op2 == 1) {
			return ((1 << (operation + 3)) & MxV) > 0;
		}
		else if (op2 == 2) {
			return ((1 << operation) & VxS) > 0;
		}
		else {
			return ((1 << (operation)) & VxV) > 0;
		}
	}
}
//Хотелось бы обойтись одним solver, но к сожалению, код не скомпилируется, т.к мы передаем сюда так же шаблоны, где для типов неопределены операции (например M + V) и компилятор ругается.
template <class O,class T1,class T2>
void solverA(O& res, T1& arg1,T2& arg2, int operation) {	//A - All

	switch (operation)
	{
	case 0:
		res = arg1 + arg2;
		break;
	case 1:
		res = arg1 - arg2;
		break;
	case 2:
		res = arg1 * arg2;
		break;
	default:
		break;
	}
	return;
}
template <class O, class T1, class T2>
void solverPlus(O& res, T1& arg1, T2& arg2, int operation) {
	res = arg1 + arg2;
	return;
}
template <class O, class T1, class T2>
void solverMultiply(O& res, T1& arg1, T2& arg2, int operation) {
	res = arg1 * arg2;
	return;
}
template <class O, class T1, class T2>
void solverMinus(O& res, T1& arg1, T2& arg2, int operation) {
	res = arg1 - arg2;
	return;
}
template <class O, class T1, class T2>
void solverAA(O& res, T1& arg1, T2& arg2, int operation) {	//AA - All Aддитивность
	if (!operation) res = arg1 + arg2;
	else { res = arg1 - arg2; }
	return;
}
//vector - 
//7x1
//	//--\\
//	| -- |
//	| -- |
//	| -- |
//	| -- |
//	| -- |
//	| -- |
//	\\--//
// 

template <class T>	//Понятно, что не все операции определены (к примеру v+m)
void solver_decor(TDynamicVector<T>& res_v, TDynamicMatrix<T>& res_m, int& res_s, int cur_op, int op1, int op2,TDynamicVector<T>& arg1_v,TDynamicVector<T>& arg2_v,TDynamicMatrix<T>& arg1_m,TDynamicMatrix<T>& arg2_m,int arg1_s, int arg2_s,_Notnull_ string op_arr[]) {
	if (!check(cur_op, op1, op2)) {		//check for allowed operations between types
		cout << "UNDEFINED OPERATION " << op_arr[cur_op] << " FOR ";
		arg_type(op1, op2);
		cout << '\n';
		return;
	}
	if (cur_op == 3 && op1 == op2) {
		if (op1 == 0) {
			res_s = arg1_v == arg2_v;
		}
		else if (op1 == 1) {
			res_s = arg1_m == arg2_m;
		}
		else if (op1 == 2) {
			res_s = arg1_s == arg2_s;
		}
		cout << res_s << endl;
		return;
	}
	else if (cur_op == 3) {
		cout << "UNDEFINED OPERATION " << op_arr[cur_op] << " FOR ";
		arg_type(op1, op2);
		cout << '\n';
		return;
	}
	//if operations not allowed (for example s + m, if s int, double etc.  (because for this data types no operator with our type in argument))
	//then the check function will return false and we'll return to main.

	if (op1==1) {	//matrix
		if (op2==1) {	//matrix
			MM;		//matrix matrix (all)
			cout << res_m << endl;
		}
		else if(!op2){	//vector
			MV;			//matrix vector (only multiply)
			cout << res_v << endl;
		}
		else {//scalar
			MS;	//matrix scalar (all)
			cout << res_m << endl;
		}
	}
	else if(!op1){	//vector
		if (op2==1) {	//matrix
			VM;						//vector matrix (undefined (by us))
			cout << res_m << endl;
		}
		else if(!op2){	//vector
			if (cur_op != 2) {
				VVA;	//vector vector additivity
				cout << res_v << endl;
			}
			else {
				VVM;	//vector vector multiplicativity
				cout << res_s << endl;
			}
		}
		else {	//scalar
			VS;	//vector scalar (all)
			cout << res_v << endl;
		}
	}
	else {	//scalar
		//ok, standart data types haven't operators for our classes, that's why there only one variant
		if (op2 == 2) {
			SS;
			cout << res_s << endl;
		}
	}

	return;
	
}

signed main()
{

	TDynamicVector<int> vector1(4),vector2(4), res_v(4);
	TDynamicMatrix<int> matrix1(4), matrix2(4), res_m(4);
	int s1 = 0, s2 = 0, res_s = 0;

	int op1 = 0, op2 = 0;
	int do_;
	int current_op = 0;
	
	char bug_;

	string operations[] = { "+", "-", "*","=="};

	while (true) {
		
		cout << "What to do?\n0 - print data\n1 - print operation status\n2 - set args type\n3 - set first matrix\n4 - set second matrix\n5 - set first vector\n6 - set second vector\n7 - choose operation\n8 - do operation\na - set first scalar\nb - set second scalar\ne - exit\n\nYou ans: ";
		cin >> bug_;
		do_ = bug_ - 48;	//without this if we type string directly into int a bug with infinity loop will appear.
		CLS;
		switch (do_)
		{
		case 1:
			op_status(op1, op2, operations, current_op);
			break;
		case 2:
			set_type_args(op1,op2);
			break;
		case 3:
			set_matrix(matrix1);
			break;
		case 4:
			set_matrix(matrix2);
			break;
		case 5:
			set_vector(vector1);
			break;
		case 6:
			set_vector(vector2);
			break;
		case 7:
			choose_operation(current_op, operations);
			break;
		case 8:
			solver_decor(res_v, res_m, res_s, current_op, op1, op2, vector1, vector2, matrix1, matrix2, s1, s2,operations);
			break;
		case 'a'-48:
			set_scalar(s1);
			break;
		case 'b'-48:
			set_scalar(s2);
			break;
		case 'e'-48:
			exit(0);
		case 0:
		{
			CLS;
			string r0;
			cout << "This is print mode\nThis is a loop and you can use this commands:\n	v1 - print vector 1\n	v2 - print vector 2\n	vr - print result vector\n	m1 - print matrix 1\n	m2 - print matrix 2\n	mr - print result matrix\n	s1 - print scalar 1\n	s2 - print scalar 2\n	sr - print res scalar\n	ex - exit\n	cls - clear window\n";
			while (true)
			{
				cout << "Your ans: ";
				cin >> r0;
				if (r0 == "v1") {
					cout << vector1 << endl;
				}
				else if (r0 == "v2") {
					cout << vector2 << endl;
				}
				else if (r0 == "vr") {
					cout << res_v << endl;
				}
				else if (r0 == "m1") {
					cout << matrix1 << endl;
				}
				else if (r0 == "m2") {
					cout << matrix2 << endl;
				}
				else if (r0 == "mr") {
					cout << res_m << endl;
				}
				else if (r0 == "s1") {
					cout << s1 << endl;
				}
				else if (r0 == "s2") {
					cout << s2 << endl;
				}
				else if (r0 == "sr") {
					cout << res_s << endl;
				}
				else if (r0 == "ex") {
					CLS;
					break;
				}
				else if (r0 == "cls") {
					CLS;
				}
				else {
					cout << "UNKNOWN COMMAND" << endl;
				}
			}
		}
			break;
		default:
			break;
		}
	}

	return 0;
}
//---------------------------------------------------------------------------
