// $Id: return_node.h,v 1.2 2018/04/17 22:31:22 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_RETURNNODE_H__
#define __GR8_RETURNNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing return nodes.
   */
  class return_node: public cdk::basic_node {
      cdk::expression_node * _result;
  public:
    inline return_node(int lineno, cdk::expression_node *result) :
    	cdk::basic_node(lineno), _result(result){
    }

  public:
    inline cdk::expression_node * result() {
        return _result;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // gr8

#endif
