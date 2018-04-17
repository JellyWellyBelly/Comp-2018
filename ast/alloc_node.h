#ifndef __GR8_PLUSNODE_H__
#define __GR8_PLUSNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing plus nodes.
   */
  class alloc_node: public cdk::unary_expression_node {

  public:
    inline alloc_node(int lineno, cdk::expression_node *result) :
      cdk::unary_expression_node(lineno, result) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_alloc_node(this, level);
    }

  };

} // gr8

#endif
