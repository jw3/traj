/*
 * DefaultTreeNode.h
 *
 *  Created on: Nov 14, 2011
 *      Author: wassj
 */

#ifndef DEFAULTTREENODE_H_
#define DEFAULTTREENODE_H_

#include <vector>
#include <sstream>

#include "ITreeNode.h"


template<class T>
class DefaultTreeNode : public ITreeNode
{
	public:
		DefaultTreeNode(T data)
				: data(data)
		{
		}
		virtual ~DefaultTreeNode() {}
		const T& getData() const { return data; }
		void setData(T& data){ this->data = data; }


		virtual ITreeNode* child(unsigned int idx) const
		{
			if (!(idx < 0) && idx < children.size()) {
				return children[idx];
			}
			return nullptr;
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

		virtual std::string toString() const {
			std::stringstream ss;
			ss << this->getData();
			return ss.str();
		}

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


#endif /* DEFAULTTREENODE_H_ */
