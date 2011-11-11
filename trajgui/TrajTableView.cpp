#include "TrajTableView.h"

#include <TrajTableModel.h>

TrajTableView::TrajTableView(QWidget* parent)
		: QTableView(parent)
{
}

TrajTableView::~TrajTableView()
{
}

void TrajTableView::trajectoryChanged(const traj::TrajectoryData& rangeData)
{
	TrajTableModel* model = new TrajTableModel(rangeData);
	this->setModel(model);
}
