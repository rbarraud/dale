#ifndef DALE_FORM_PROC_SETF
#define DALE_FORM_PROC_SETF

namespace dale
{
/*! Parse a procedure-body setf statement.
 *  @param units The units context.
 *  @param fn The function currently in scope.
 *  @param block The current block.
 *  @param node The node being parsed.
 *  @param get_address Whether to return the address of the result.
 *  @param prefixed_with_core Whether to ignore overridden setfs.
 *  @param pr The parse result for the response.
 */
bool
FormProcSetfParse(Units *units, Function *fn, llvm::BasicBlock *block,
                  Node *node, bool get_address, bool prefixed_with_core,
                  ParseResult *pr);
}

#endif
