// $Id: if_node.h,v 1.3 2018/04/17 22:31:22 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_IFNODE_H__
#define __GR8_IFNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing if-then nodes.
   */
  class if_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    gr8::block_node *_block;

  public:
    inline if_node(int lineno, cdk::expression_node *condition, gr8::block_node *block) :
        cdk::basic_node(lineno), _condition(condition), _block(block) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline gr8::block_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_if_node(this, level);
    }

  };

} // gr8

#endif
