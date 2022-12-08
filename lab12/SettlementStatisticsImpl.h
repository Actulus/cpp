//
// Created by Pati on 12/8/2022.
//

#ifndef LAB12_SETTLEMENTSTATISTICSIMPL_H
#define LAB12_SETTLEMENTSTATISTICSIMPL_H

#include "SettlementStatistics.h"
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>

class SettlementStatisticsImpl : public SettlementStatistics {
private:
	multimap<string, Settlement *> data; //string = county code

public:
	SettlementStatisticsImpl(const char *file);
	int numSettlements() const override;
	int numCounties() const override;
	int numSettlementsByCounty(const string &county) const override;
	vector<Settlement> findSettlementsByCounty(const string &county) const override;
	vector<Settlement> findSettlementsByName(const string &name) override;
	Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;
	Settlement maxPopulationDensity() const override;
	Settlement minPopulationDensity() const override;
	friend ostream &operator<<(ostream &os, const Settlement &settlement);
};


#endif //LAB12_SETTLEMENTSTATISTICSIMPL_H
