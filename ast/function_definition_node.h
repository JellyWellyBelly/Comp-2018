// $Id: function_definition_node.h,v 1.1 2018/04/17 22:37:27 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_FUNCBODNODE_H__
#define __GR8_FUNCBODNODE_H__

#include <string>

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/identifier_node.h>

namespace gr8 {

  /**
   * Class for describing function-body nodes.
   */
  class function_definition_node: public cdk::basic_node {
    enum Qualifier {EMPTY, USE, PUB};
    cdk::sequence_node   *_args;
    cdk::typed_node      *_return_type;
    gr8::block_node      *_block;
    std::string          *_fidentifier;
    Qualifier             _qualifier;


  public:
    inline function_definition_node(int lineno, cdk::sequence_node *args, cdk::typed_node *return_type, gr8::block_node *block, std::string *fidentifier, Qualifier qualifier) :
        cdk::basic_node(lineno), _args(args), _return_type(return_type), _block(block), _fidentifier(fidentifier), _qualifier(qualifier) {
    }

  public:
    inline cdk::sequence_node *args() {
      return _args;
    }
    inline cdk::typed_node    *return_type() {
      return _return_type;
    }
    inline gr8::block_node    *block() {
      return _block;
    }
    inline std::string        *fidentifier() {
      return _fidentifier;
    }
    inline Qualifier           qualifier() {
      return _qualifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // gr8

#endif
