#ifndef __GR8_FUNCINVNODE_H__
#define __GR8_FUNCINVNODE_H__

#include <string>

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/identifier_node.h>

namespace gr8 {

  /**
   * Class for describing function-invocation nodes.
   */
  class function_invocation_node: public cdk::expression_node {
    cdk::sequence_node   *_args;
    std::string          *_fidentifier;

  public:
    inline function_invocation_node(int lineno, cdk::sequence_node *args, std::string *fidentifier) :
        cdk::expression_node(lineno), _args(args), _fidentifier(fidentifier) {
    }

  public:
    inline std::string        *fidentifier() {
      return _fidentifier;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_invocation_node(this, level);
    }

  };

} // gr8

#endif
