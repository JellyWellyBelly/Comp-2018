// $Id: elsif_node.h,v 1.1 2018/03/23 03:27:42 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_ELSIFNODE_H__
#define __GR8_ELSIFNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing elsif nodes.
   */
  class elsif_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    gr8::block_node      *_block;

  public:
    inline elsif_node(int lineno, cdk::expression_node *condition, gr8::block_node *block) :
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
      sp->do_elsif_node(this, level);
    }

  };

} // gr8

#endif
