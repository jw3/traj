#include "TrajFrame.h"

#include <QtUiTools>

#include <memory>
#include <functional>

#include <traj/Trajectory.h>
#include <traj/TrajBC.h>
#include <trajdb/BulletData.h>

#include "ValidationFields.h"

TrajFrame::TrajFrame(TrajBulletTreeModel* bulletModel, QWidget* parent)
		: QMainWindow(parent), bulletModel(bulletModel)
{
	ui.setupUi(this);

	ui.bulletTreeView->setModel(bulletModel);

	connect(ui.bcField, SIGNAL(returnPressed()), this, SLOT(calculateTrajectory()));
	connect(this, SIGNAL(trajectoryUpdated(const traj::TrajectoryData&)), ui.tableView, SLOT(trajectoryChanged(const traj::TrajectoryData&)));
}

TrajFrame::~TrajFrame()
{
}

void TrajFrame::calculateTrajectory()
{
	traj::Trajectory t;

	bool valid = false;

	auto bc = ui.bcField->text().toDouble(&valid);
	if (valid) {
		traj::TrajBC tbc = t.getBC();
		tbc.setBC(bc);
		t.setBC(tbc);
	}

	auto vel = ui.velocityField->text().toDouble(&valid);
	if (valid) {
		t.setVelocity(vel);
	}

	auto sightHeight = ui.sightHeightField->text().toDouble(&valid);
	if (valid) {
		t.setSightHeight(sightHeight);
	}

	auto zeroRange = ui.zeroRangeField->text().toDouble(&valid);
	if (valid) {
		t.getZeroVector().setX(zeroRange);
	}

	auto maxRange = ui.maxRangeField->currentText().toDouble(&valid);
	if (valid) {
		t.setMaximumRange(maxRange);
	}

	auto rangeStep = ui.rangeStepCombo->currentText().toDouble(&valid);
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
		ui.bcField->setValue(bulletData.getBc());
		ui.dragCombo->setCurrentIndex(bulletData.getDragFx());
		ui.weightSpinBox->setValue(bulletData.getWeight());

		ui.velocityField->setText(QString(bulletData.getVelocity()));
		//ui.chronoField->setText(QString(bulletData.getChronoDistance()));
	}
}
