#include "TrajTableView.h"

#include <iostream>
#include <TrajTableModel.h>

TrajTableView::TrajTableView(QWidget* parent) : QTableView(parent)
{
}

TrajTableView::~TrajTableView()
{
}

void TrajTableView::trajectoryChanged(const traj::TrajectoryData& rangeData)
{
	std::cout << "woo hoo!" << std::endl;
	TrajTableModel* model = new TrajTableModel(rangeData);
	this->setModel(model);
}
