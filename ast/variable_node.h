// $Id: variable_node.h,v 1.2 2018/04/17 22:31:22 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_VARNODE_H__
#define __GR8_VARNODE_H__

#include <cdk/ast/basic_node.h>

namespace gr8 {

  /**
   * Class for describing variable nodes.
   */
  class variable_node: public cdk::typed_node {
    enum Qualifier {EMPTY, USE, PUB};
    cdk::identifier_node *_identifier;
    cdk::expression_node *_initially;
    Qualifier             _qualifier;

  public:
    inline variable_node(int lineno, cdk::identifier_node *identifier, cdk::expression_node *initially, Qualifier qualifier) :
        cdk::typed_node(lineno), _identifier(identifier), _initially(initially), _qualifier(qualifier) {
    }

  public:
    inline cdk::identifier_node *identifier() {
      return _identifier;
    }
    inline cdk::basic_node      *initially() {
      return _initially;
    }
    inline Qualifier             qualifier() {
      return _qualifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_node(this, level);
    }

  };

} // gr8

#endif
