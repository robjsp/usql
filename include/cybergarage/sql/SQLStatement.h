/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLSTATEMENT_H
#define CG_USQL_SQLSTATEMENT_H

#include <cybergarage/sql/SQLNode.h>
#include <cybergarage/sql/SQLNodes.h>

namespace uSQL {

class SQLStatement;

class SQLStatementList : public std::vector<SQLStatement *> {

public:

	SQLStatementList()
    {
    }

    void addStatement(SQLStatement *stmt) {
    	push_back(stmt);
    }

    SQLStatement *getStatement(int index) {
    	return at(index);
    }
};

class SQLStatement : public SQLNode {

public:
    
    static const int UNKNOWN;
    static const int SQL92;
    static const int GQL;
    static const int UNQL;
    
private:
    
    int statementType;

public:
	
    SQLStatement();

    void setStatementType(int type) {
        statementType = type;
    }
    
    int getStatementType(int type) {
        return this->statementType;
    }
    
    bool isStatementType(int type) {
        return (this->statementType == type);
    }
    
    bool isSQL92() {
        return isStatementType(SQL92);
    }
    
    bool isGQL() {
        return isStatementType(GQL);
    }
    
    bool isUnQL() {
        return isStatementType(UNQL);
    }
    
    SQLCommand *getCommandNode() {
        return (SQLCommand *)findChildNodeByType(SQLNode::COMMAND);
    }

    SQLCollections *getCollectionsNode() {
        return (SQLCollections *)findChildNodeByType(SQLNode::COLLECTIONS);
    }
    
    SQLCollection *getCollectionNode() {
        SQLCollections *collectionsNode = getCollectionsNode();
        if (!collectionsNode)
            return NULL;
        return (SQLCollection *)collectionsNode->getCollectionNode(0);
    }
    
    SQLSet *getSetNode() {
        return (SQLSet *)findChildNodeByType(SQLNode::SET);
    }
    
    SQLColumn *getColumnNode() {
        return (SQLColumn *)findChildNodeByType(SQLNode::COLUMN);
    }

    SQLValue *getValueNode() {
        return (SQLValue *)findChildNodeByType(SQLNode::VALUE);
    }
    
    SQLWhere *getWhereNode() {
        return (SQLWhere *)findChildNodeByType(SQLNode::WHERE);
    }

    SQLGroupBy *getGroupByNode() {
        return (SQLGroupBy *)findChildNodeByType(SQLNode::GROUPBY);
    }

    SQLHaving *getHavingeNode() {
        return (SQLHaving *)findChildNodeByType(SQLNode::HAVING);
    }
    
    std::string &toString(std::string &buf);

#if defined(DEBUG)
    
    std::string &toTreeString(std::string &buf);    
    
#endif
};

}

#endif
