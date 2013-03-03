/*
 * ITreeNode.h
 *
 *  Created on: Nov 12, 2011
 *      Author: wassj
 */

#ifndef ITREENODE_H_
#define ITREENODE_H_

#include <vector>
#include <string>

struct ITreeNode
{
	virtual ~ITreeNode() {}

	virtual ITreeNode* child(unsigned int idx) const = 0;
	virtual unsigned int childCount(void) const = 0;
	virtual int indexOf(const ITreeNode&) const = 0;
	virtual bool allowsChildren(void) const = 0;
	virtual bool isLeaf(void) const = 0;
	virtual int row() const = 0;

	virtual void addChild(ITreeNode* node) = 0;
	virtual void removeChild(ITreeNode* child) = 0;
	virtual const std::vector<ITreeNode*>& getChildren(void) const = 0;

	virtual ITreeNode* getParent(void) = 0;
	virtual void setParent(ITreeNode* parent) = 0;

	virtual bool operator==(const ITreeNode& other) const = 0;
	//virtual std::string toString() const = 0;
};

#endif /* ITREENODE_H_ */
