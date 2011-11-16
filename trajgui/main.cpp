#include <QtGui>
#include <QApplication>

#include <iostream>
#include <string>
#include <map>

#include <trajdb/TrajDatabase.h>
#include <trajdb/CaliberData.h>
#include <trajdb/BulletData.h>

#include "ITreeNode.h"
#include "DefaultTreeNode.h"
#include "TrajFrame.h"

using namespace std;
using namespace traj;



void printTree(ITreeNode& node, int depth = 0)
{
	for (int i = 0; i < depth; ++i) {
		cout << " ";
	}

	cout << (node.isLeaf() ? "-" : "+") << node.toString();
	if(!node.isLeaf()){
		cout << "(" << node.childCount() << ")";
	}
	cout << endl;

	if (node.childCount() > 0) {
		for (auto child : node.getChildren()) {
			printTree(*child, depth + 1);
		}
	}
}


int main(int c, char** v)
{
	//QApplication app(c, v);

	//app.setApplicationName("Traj");

	TrajDatabase db;
	if (!db.connect()) {
		cout << "Error connecting to db, " << db.getError() << endl;
		return 1;
	}

	DefaultTreeNode<std::string> root("root");
	for (auto calPair : db.getCalibers()) {
		auto cal = calPair.second;
		DefaultTreeNode<float>* caliberNode = new DefaultTreeNode<float>(cal.getCaliber());
		root.addChild(caliberNode);

		std::stringstream where;
		where << "caliber=";
		where << cal.getId();
		auto bullets = db.getBullets(where.str().c_str());
		for (auto bulletPair : bullets) {
			auto bullet = bulletPair.second;
			DefaultTreeNode<std::string>* bulletNode = new DefaultTreeNode<std::string>(bullet.getName());
			caliberNode->addChild(bulletNode);
		}
	}

	printTree(root);

//TrajFrame f;
//f.show();

//return app.exec();
	return 0;
}
