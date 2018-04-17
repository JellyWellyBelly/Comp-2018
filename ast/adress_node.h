// $Id: adress_node.h,v 1.1 2018/03/23 03:27:40 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_NANINODE_H__
#define __GR8_NANINODE_H__

#include <cdk/ast/rvalue_node.h>

namespace gr8 {

  /**
   * Class for describing adress nodes.
   */
  class adress_node: public cdk::unary_expression_node {

  public:
    inline adress_node(int lineno, cdk::rvalue_node *rvalue) :
        cdk::unary_expression_node(lineno, rvalue) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_adress_node(this, level);
    }

  };

} // gr8

#endif
