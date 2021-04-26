#ifndef CSV_EVALUATOR_H
#define CSV_EVALUATOR_H

#include <iostream>
#include <variant>
#include <unordered_map>
#include <vector>

//Table values operations enum
enum OP{
	ADD,
	SUB,
	MUL,
	DIV
};

template<class TValue>
class TableEvaluator;

//Class to store table with formulas
template<class TValue>
class TableHolder {
private:
	//cells type definition
	class Operation;
	typedef std::variant<TValue, Operation> Cell;
	
	struct Operation {
		Cell* fst;
		Cell* snd;
		OP op;
	};

	std::vector <std::vector<Cell>> data;

	//rows and Columns
	std::unordered_map<std::string, std::size_t> rows_names;
	std::unordered_map<std::string, std::size_t> colomns_names;

	friend class TableEvaluator;

	//operations

	Cell& get_cellstd::string, std::string);
public:
	//initialization
	TableHolder();

	void get_data_from_file(FILE* file); 

	//
	std::string get(std::string, std::string);
};

//Evaluator for given table
template<class TValue>
class TableEvaluator{

	TableEvaluator(TableHolder<TValue>);

	TableHolder<TValue>* evaluate();

	std::vector<std::vector<TValue>>& evaluate();

	bool is_solvable();
};


#endif //CSV_EVALUATOR_H
