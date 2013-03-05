/*
 * TreeNodes.h
 *
 *  Created on: Nov 30, 2011
 *      Author: wassj
 */

#ifndef TREENODES_H_
#define TREENODES_H_

#include <vector>
#include <sstream>

#include <QString>
#include <QVariant>

#include "ITreeNode.h"
#include "trajdb/BulletData.h"
#include "trajdb/CaliberData.h"


struct IVariantNode
{
	virtual ~IVariantNode() {}
	virtual QVariant getVariantData() const = 0;
};

template<typename T>
class DefaultTreeNode : public ITreeNode, public IVariantNode
{
	public:
		DefaultTreeNode(T data)
				: data(data)
		{
		}

		virtual ~DefaultTreeNode() {}
		const T& getData() const { return data; }
		void setData(T& data){ this->data = data; }

		virtual QVariant getVariantData() const = 0;

		virtual ITreeNode* child(unsigned int idx) const
		{
			if (idx < children.size()) {
				return children[idx];
			}
			return nullptr;
		}

		virtual int row() const
		 {
		     if (parent)
		         return parent->indexOf(*this);

		     return 0;
		 }

		virtual unsigned int childCount(void) const
		{
			return children.size();
		}

		virtual int indexOf(const ITreeNode& node) const
		{
			for (unsigned int i = 0; i < children.size(); ++i) {
				if (*children.at(i) == node) {
					return i;
				}
			}
			return -1;
		}

		virtual bool allowsChildren(void) const
		{
			return true;
		}

		virtual bool isLeaf(void) const
		{
			return children.empty();
		}

		virtual const std::vector<ITreeNode*>& getChildren(void) const
		{
			return children;
		}

		virtual bool operator==(const ITreeNode& other) const
		{
			return &other == this;
		}

//		virtual std::string toString() const {
//			std::stringstream ss;
//			ss << this->getData();
//			return ss.str();
//		}

		void addChild(ITreeNode* node) {
			node->setParent(this);
			children.push_back(node);
		}


		void removeChild(ITreeNode* child){
			for(auto iter = std::begin(children); iter != std::end(children); ++iter){
				if(*iter == child){
					child->setParent(nullptr);
					children.erase(iter);
					break;
				}
			}
		}

		ITreeNode* getParent(){
			return this->parent;
		}

	protected:
		void setParent(ITreeNode* parent){
			this->parent = parent;
		}

	private:
		T data;

		ITreeNode* parent;
		std::vector<ITreeNode*> children;
};

class RootNode : public DefaultTreeNode<QString>
{
public:
	RootNode(const QString& data) : DefaultTreeNode<QString>(data)
	{
	}
	virtual ~RootNode() {}

	virtual QVariant getVariantData() const { return QVariant(this->getData()); }
};
class CaliberNode : public DefaultTreeNode<traj::CaliberData>
{
public:
	CaliberNode(const traj::CaliberData& data) : DefaultTreeNode<traj::CaliberData>(data)
	{
	}
	virtual ~CaliberNode() {}

	virtual QVariant getVariantData() const { return QVariant(this->getData().getCaliber()); }
};

class BulletNode : public DefaultTreeNode<traj::BulletData>
{
public:
	BulletNode(const traj::BulletData& data) : DefaultTreeNode<traj::BulletData>(data)
	{
	}
	virtual ~BulletNode() {}

	virtual QVariant getVariantData() const { return QVariant(this->getData().getName()); }
};


#endif /* TREENODES_H_ */
