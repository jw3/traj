/*
 * InjectedValidator.h
 *
 *  Created on: Nov 11, 2011
 *      Author: wassj
 */

#ifndef VALIDATIONFIELDS_H_
#define VALIDATIONFIELDS_H_

#include <QWidget>
#include <QLineEdit>
#include <QValidator>
#include <QPalette>

#include <functional>

typedef std::function<bool(QString&, int&)> Validation;

static bool integerValidator(QString& string, int& pos)
{
	bool valid = false;
	string.toInt(&valid);

	return valid || string.isEmpty();
}

static bool doubleValidator(QString& string, int& pos)
{
	bool valid = false;
	string.toDouble(&valid);

	return valid || string.isEmpty();
}

class InjectedValidator :
		public QValidator
{
	Q_OBJECT

	public:
		InjectedValidator(Validation validation, QObject* parent = 0)
				: QValidator(parent), validation(validation), widget(qobject_cast<QWidget*>(parent))
		{
		}

		virtual ~InjectedValidator()
		{
		}

		virtual QValidator::State validate(QString& input, int& pos) const
		{
			bool valid = validation(input, pos);

			if (nullptr != widget) {
				QPalette* palette = new QPalette();
				palette->setColor(QPalette::Text, valid ? Qt::black : Qt::red);
				widget->setPalette(*palette);
				widget->repaint();
			}

			return valid ? QValidator::State::Acceptable : QValidator::State::Invalid;
		}

	private:
		Validation validation;
		QWidget* widget;
};

class IntegerTextField :
		public QLineEdit
{
	Q_OBJECT

	public:
		IntegerTextField(QWidget* parent = 0)
				: QLineEdit(parent)
		{
			this->setValidator(new InjectedValidator(integerValidator, this));
		}
		virtual ~IntegerTextField()
		{
		}
};

class DoubleTextField :
		public QLineEdit
{
	Q_OBJECT

	public:
		DoubleTextField(QWidget* parent = 0)
				: QLineEdit(parent)
		{
			this->setValidator(new InjectedValidator(doubleValidator, this));
		}
		virtual ~DoubleTextField()
		{
		}
};

#endif /* VALIDATIONFIELDS_H_ */
