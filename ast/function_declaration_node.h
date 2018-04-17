// $Id: function_declaration_node.h,v 1.4 2018/04/17 22:31:22 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_FUNCDECNODE_H__
#define __GR8_FUNCDECNODE_H__

#include <string>

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/identifier_node.h>

namespace gr8 {

  /**
   * Class for describing function-declaration nodes.
   */
  class function_declaration_node: public cdk::typed_node {
    enum Qualifier {EMPTY, USE, PUB};
    cdk::sequence_node   *_args;
    std::string          *_fidentifier;
    Qualifier             _qualifier;

  public:
    inline function_declaration_node(int lineno, cdk::sequence_node *args, std::string *fidentifier, Qualifier qualifier) :
        cdk::typed_node(lineno), _args(args), _fidentifier(fidentifier), _qualifier(qualifier) {
    }

  public:
    inline cdk::sequence_node *args() {
      return _args;
    }
    inline std::string        *fidentifier() {
      return _fidentifier;
    }
    inline Qualifier           qualifier() {
      return _qualifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // gr8

#endif
