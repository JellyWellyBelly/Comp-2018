#ifndef __GR8_INDEXATIONNODE_H__
#define __GR8_INDEXATIONNODE_H__

#include <cdk/ast/lvalue_node.h>
#include <cdk/ast/expression_node.h>


namespace gr8 {

  /**
   * Class for describing indexation nodes.
   */
  class indexation_node: public cdk::lvalue_node {
    cdk::expression_node *_index;
    cdk::lvalue_node *_cellid;

  public:
    inline indexation_node(int lineno, cdk::expression_node *index, cdk::lvalue_node *cellid) :
        cdk::lvalue_node(lineno), _index(index), _cellid(cellid) {
    }

  public:
    inline cdk::expression_node * index() {
        return _index;
    }
    inline cdk::lvalue_node * cellid() {
        return _cellid;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_indexation_node(this, level);
    }

  };

} // gr8

#endif
