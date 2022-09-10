#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
	Cell();

	QTableWidgetItem* clone() const override;
	void setData(int role, const QVariant& value) override;
	QVariant data(int role) const override;
	void setFormula(const QVariant& formula);
	QString formula() const;
	void setDirty();

private:
	QVariant value() const;
	QVariant evalExpression(const QString& str, int& pos) const;
	QVariant evalTerm(const QString& str, int& pos) const;
	QVariant evalFactor(const QString& str, int& pos) const;

	mutable QVariant cachedValue;
	mutable bool cacheIsDirty;
};

#endif