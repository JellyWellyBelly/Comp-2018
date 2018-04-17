// $Id: stop_node.h,v 1.2 2018/04/17 22:31:22 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_STOPNODE_H__
#define __GR8_STOPNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing stop nodes.
   */
  class stop_node: public cdk::expression_node {

  public:
    inline stop_node(int lineno) :
      cdk::expression_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

} // gr8

#endif
