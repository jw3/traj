/*
 * ValidateTextField.cpp
 *
 *  Created on: Nov 11, 2011
 *      Author: wassj
 */

#include "ValidateTextField.h"
#include "InjectedValidator.h"

ValidateTextField::ValidateTextField(QWidget* parent)
		: QLineEdit(parent)
{
	this->setValidator(new InjectedValidator([this](QString& string, int& pos) {
		bool valid = false;
		string.toDouble(&valid);

		QPalette* palette = new QPalette();
		palette->setColor(QPalette::Text, valid || string.isEmpty()? Qt::black : Qt::red);
		this->setPalette(*palette);
		this->repaint();

		return valid || string.isEmpty()? QValidator::State::Acceptable : QValidator::State::Invalid;
	}));
}

ValidateTextField::~ValidateTextField()
{
}

