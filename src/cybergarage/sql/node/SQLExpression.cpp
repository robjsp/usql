/******************************************************************
*
* uSQL for C++
*
* SQLExpression.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLExpression.h>

std::string &uSQL::SQLExpression::toString(std::string &buf) 
{
	std::size_t expressionsCount = expressions.size();
    
    if (expressionsCount <= 0) {
    	buf = "";
    	return buf;
    }

	bool hasDictionary = false;
    for (SQLExpressions::iterator expr=expressions.begin(); expr != expressions.end(); expr++) {
    	if ((*expr)->isDictionary() == true) {
        	hasDictionary = true;
            break;
        }
    }

	std::ostringstream oss;
        
	if (hasDictionary) {
    	oss << "{";
	    for (SQLExpressions::iterator expr=expressions.begin(); expr != expressions.end(); expr++) {
    		if (expr != expressions.begin())
		    	oss << ",";
            if ((*expr)->isOperator()) {
            	std::string buf;
                oss << (*expr)->toString(buf);
            	continue;
            }
            if ((*expr)->isFunction()) {
            	std::string buf;
                oss << (*expr)->toString(buf);
            	continue;
            }
            oss << (*expr)->getName() << ":" << (*expr)->getValue();
    	}
    	oss << "}";
    }
    else {
        if (1 < expressionsCount)
            oss << "[";
	    for (SQLExpressions::iterator expr=expressions.begin(); expr != expressions.end(); expr++) {
    		if (expr != expressions.begin())
		    	oss << ",";
            if ((*expr)->isOperator()) {
            	std::string buf;
                oss << (*expr)->toString(buf);
            	continue;
            }
            if ((*expr)->isFunction()) {
            	std::string buf;
                oss << (*expr)->toString(buf);
            	continue;
            }
            oss << (*expr)->getValue();
    	}
        if (1 < expressionsCount)
            oss << "]";
    }
    
    buf = oss.str();
    return buf;
}