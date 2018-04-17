// $Id: address_node.h,v 1.1 2018/04/17 22:37:27 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_NANINODE_H__
#define __GR8_NANINODE_H__

#include <cdk/ast/lvalue_node.h>

namespace gr8 {

  /**
   * Class for describing adress nodes.
   */
  class address_node: public cdk::expression_node {
    cdk::lvalue_node * _address;
  public:
    inline address_node(int lineno, cdk::lvalue_node * address) :
        cdk::expression_node(lineno), _address(address){
    }

  public:
    inline cdk::lvalue_node * address() {
        return _address;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_address_node(this, level);
    }

  };

} // gr8

#endif
