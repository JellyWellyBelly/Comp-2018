// $Id: plus_node.h,v 1.1 2018/03/23 03:27:44 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_PLUSNODE_H__
#define __GR8_PLUSNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing plus nodes.
   */
  class plus_node: public cdk::unary_expression_node {

  public:
    inline plus_node(int lineno, cdk::expression_node *result) :
      cdk::unary_expression_node(lineno, result) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_plus_node(this, level);
    }

  };

} // gr8

#endif
