#include "TrajFrame.h"

#include <QtUiTools>
#include <ui_TrajFrame.h>

#include <memory>
#include <functional>

#include <traj/Trajectory.h>
#include <traj/TrajBC.h>
#include <trajdb/BulletData.h>

#include "ValidationFields.h"

TrajFrame::TrajFrame(TrajBulletTreeModel* bulletModel, QWidget* parent)
		: QMainWindow(parent), bulletModel(bulletModel)
{
	ui->setupUi(this);

	ui->bulletTreeView->setModel(bulletModel);

	connect(this, SIGNAL(trajectoryUpdated(const traj::TrajectoryData&)), ui->tableView, SLOT(trajectoryChanged(const traj::TrajectoryData&)));
}

TrajFrame::~TrajFrame()
{
}

void TrajFrame::calculateTrajectory()
{
	traj::Trajectory t;

	bool valid = false;

	auto bc = ui->bcField->value();
	DRAGFUNC dragfn = (DRAGFUNC) ui->dragCombo->currentIndex();

	traj::TrajBC tbc = t.getBC();
	tbc.setDragFx(dragfn);
	tbc.setBC(bc);
	t.setBC(tbc);

	auto weight = ui->weightSpinBox->value();
	t.setBulletWeight(weight);

	auto vel = ui->velocityField->text().toDouble(&valid);
	if (valid) {
		t.setVelocity(vel);
	}

	auto zeroRange = ui->zeroRangeField->text().toDouble(&valid);
	if (valid) {
		t.getZeroVector().setX(zeroRange);
	}

	auto fromChrono = ui->chronoField->text().toDouble(&valid);
	if (valid) {
		t.setChronoDistance(fromChrono);
	}

	auto sightHeight = ui->sightHeightField->text().toDouble(&valid);
	if (valid) {
		t.setSightHeight(sightHeight);
	}

	auto maxRange = ui->maxRangeField->currentText().toDouble(&valid);
	if (valid) {
		t.setMaximumRange(maxRange);
	}

	auto rangeStep = ui->rangeStepCombo->currentText().toDouble(&valid);
	if (valid) {
		t.setStepSize(rangeStep);
	}

	emit
	trajectoryUpdated(t.calculate());
}

void TrajFrame::setBulletModelIndex(QModelIndex index)
{
	BulletNode* node = dynamic_cast<BulletNode*>(static_cast<ITreeNode*>(index.internalPointer()));
	if (node) {
		const traj::BulletData& bulletData = node->getData();
		ui->bcField->setValue(bulletData.getBc());
		ui->dragCombo->setCurrentIndex(bulletData.getDragFx());
		ui->weightSpinBox->setValue(bulletData.getWeight());

		std::stringstream ss;
		ss << bulletData.getVelocity();
		ui->velocityField->setText(QString(ss.str().c_str()));
		//ui.chronoField->setText(QString(bulletData.getChronoDistance()));

		calculateTrajectory();
	}
}
