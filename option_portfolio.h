#pragma once
#include "term_structure.h"
#include "option.h"
#include "binary_option.h"
#include "plainvanilla_option.h"
#include "option_factory.h"

enum Position { Long = 1, Short = -1 };

class OptionPortfolio
{
public:
	OptionPortfolio(YieldTermStructure y_term,
		VolatilityTermStructure v_term,
		DividendTermStructure d_term,
		double spot, Date eval_date)
		:y_term_(y_term), v_term_(v_term), d_term_(d_term), 
			spot_(spot), eval_date_(eval_date) {}

	// void putOption(Option* op, GBMProcess gbm, Date eval_date, Position p = Long, int q = 1);
	// void putOption(Option* op, Position p = Long, int q = 1);
	void pushOption(OptionProduct op, Position p, OptionType t,
		double strike, Date expiration, int q = 1);
	static void printOption(Option* x);
	void printPortfolio();
	~OptionPortfolio();

private:
	YieldTermStructure y_term_;
	VolatilityTermStructure v_term_;
	DividendTermStructure d_term_;
	double spot_;
	Date eval_date_;

	std::vector<Option*> option_arr;
	std::vector<Position> position_arr;
	std::vector<int> quantity_arr;
	OptionFactory factory_;
};


