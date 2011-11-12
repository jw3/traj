/*
 * InjectedValidator.h
 *
 *  Created on: Nov 11, 2011
 *      Author: wassj
 */

#ifndef INJECTEDVALIDATOR_H_
#define INJECTEDVALIDATOR_H_

#include <QValidator>
#include <functional>

typedef std::function<QValidator::State(QString&, int&)> Validation;

class InjectedValidator :
		public QValidator
{
	Q_OBJECT

	public:
		InjectedValidator(Validation validation, QObject* parent = 0)
				: QValidator(parent), validation(validation)
		{
		}

		virtual ~InjectedValidator()
		{
		}

		virtual QValidator::State validate(QString& input, int& pos) const
		{
			return validation(input, pos);
		}

	private:
		Validation validation;
};

#endif /* INJECTEDVALIDATOR_H_ */
