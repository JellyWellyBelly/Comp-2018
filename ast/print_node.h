// $Id: print_node.h,v 1.3 2018/03/23 03:27:44 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_PRINTNODE_H__
#define __GR8_PRINTNODE_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::expression_node *_argument;
    bool _is_tweet;

  public:
    inline print_node(int lineno, cdk::expression_node *argument, bool is_tweet = false) :
      cdk::basic_node(lineno), _argument(argument), _is_tweet(is_tweet) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }
    inline bool newLine() {
        return _is_tweet;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // gr8

#endif
