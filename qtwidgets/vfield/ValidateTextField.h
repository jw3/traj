/*
 * ValidateTextField.h
 *
 *  Created on: Nov 11, 2011
 *      Author: wassj
 */

#ifndef VALIDATETEXTFIELD_H_
#define VALIDATETEXTFIELD_H_

#include <QLineEdit>

class ValidateTextField :
		public QLineEdit
{
	Q_OBJECT

	public:
		ValidateTextField(QWidget* parent = 0);
		virtual ~ValidateTextField();

	private:

};

#endif /* VALIDATETEXTFIELD_H_ */
