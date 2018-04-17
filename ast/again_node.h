// $Id: again_node.h,v 1.2 2018/04/17 22:31:22 ist426009 Exp $ -*- c++ -*-
#ifndef __GR8_AGAINNODE_H__
#define __GR8_AGAINNODE_H__

namespace gr8 {

  /**
   * Class for describing again nodes.
   */
  class again_node: public cdk::basic_node {
    int _times;
      
  public:
    inline again_node(int lineno, int times) :
      cdk::basic_node(lineno), _times(times) {
    }

  public:
    inline int times() {
        return _times;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_again_node(this, level);
    }

  };

} // gr8 m8 r8 8/8

#endif
