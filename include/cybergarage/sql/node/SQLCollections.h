/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCOLLECTIONS_H
#define CG_USQL_SQLCOLLECTIONS_H

#include <cybergarage/sql/node/SQLDataSet.h>

namespace uSQL {

class SQLCollection;

class SQLCollections : public SQLDataSet {

public:

	SQLCollections() {
    	setType(COLLECTIONS);
	}

    SQLCollection *getCollectionNode(int index) {
        return (SQLCollection *)getChildNode(index);
    }
    
    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << childNodesToString(childNodeStr, ",");
    	buf = oss.str();
		return buf;
	}
    
};

class SQLFrom : public SQLCollections {

public:

	SQLFrom() {
	}

    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << "FROM " << SQLCollections::toString(childNodeStr);
    	buf = oss.str();
		return buf;
	}

};

}

#endif
