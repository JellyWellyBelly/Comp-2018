#ifndef __GR8_SWEEPINGNODE_H__
#define __GR8_SWEEPINGNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>

namespace gr8 {

  /**
   * Class for describing sweeping nodes.
   */
  class sweeping_node: public cdk::basic_node {
    cdk::expression_node *_lwr_bound, *_hgr_bound, *_step;
    cdk::lvalue_node *_iter;
    gr8::block_node  *_block;
    
  public:
    inline sweeping_node(int lineno, cdk::expression_node *lwr_bound, cdk::expression_node *hgr_bound, 
    cdk::expression_node *step, cdk::lvalue_node *iter, block_node *block) :
        cdk::basic_node(lineno), _lwr_bound(lwr_bound), _hgr_bound(hgr_bound), _step(step), _iter(iter), _block(block) {
    }

  public:
    inline cdk::expression_node *lwr_bound() {
      return _lwr_bound;
    }
    inline cdk::expression_node *hgr_bound() {
      return _hgr_bound;
    }
    inline cdk::expression_node *step() {
      return _step;
    }
    inline block_node *block() {
      return _block;
    }
    inline cdk::lvalue_node *iter() {
      return _iter;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sweeping_node(this, level);
    }

  };

} // gr8

#endif
