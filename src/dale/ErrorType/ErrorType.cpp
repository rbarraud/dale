#include "ErrorType.h"

#include <cstdio>
#include <cstdlib>

namespace dale
{
const char *
errorInstanceToString(int error_instance)
{
    const char *ret;
    switch (error_instance) {
    case ErrorInst::Lexer::Null:
        ret = "Null";
        break;
    case ErrorInst::Parser::ExpectedLeftParen:
        ret = "expected left parenthesis";
        break;
    case ErrorInst::Parser::MissingLeftParen:
        ret = "missing left parenthesis";
        break;
    case ErrorInst::Parser::MissingRightParen:
        ret = "missing right parenthesis";
        break;
    case ErrorInst::Lexer::UnterminatedStringLiteral:
        ret = "unterminated string literal";
        break;
    case ErrorInst::Lexer::InvalidInteger:
        ret = "invalid integer";
        break;
    case ErrorInst::Lexer::InvalidFloatingPointNumber:
        ret = "invalid floating point number";
        break;
    case ErrorInst::Generator::CannotOnceTheLastOpenFile:
        ret = "'once' cannot be used in the last open file";
        break;
    case ErrorInst::Generator::OnlyListsAtTopLevel:
        ret = "top level elements must be lists";
        break;
    case ErrorInst::Generator::NoEmptyLists:
        ret = "lists cannot be empty";
        break;
    case ErrorInst::Generator::FirstListElementMustBeAtom:
        ret = "first list element must be atom";
        break;
    case ErrorInst::Generator::FirstListElementMustBeSymbol:
        ret = "first list element must be symbol";
        break;
    case ErrorInst::Generator::NoEmptyDo:
        ret = "'do' form must not be empty";
        break;
    case ErrorInst::Generator::IncorrectNumberOfArgs:
        ret = "'%s' requires %s arguments (got %s instead)";
        break;
    case ErrorInst::Generator::IncorrectMinimumNumberOfArgs:
        ret = "'%s' requires at least %s arguments "
              "(got %s instead)";
        break;
    case ErrorInst::Generator::IncorrectMaximumNumberOfArgs:
        ret = "'%s' takes at most %s arguments "
              "(got %s instead)";
        break;
    case ErrorInst::Generator::IncorrectArgType:
        ret = "'%s' requires %s for argument %s (got %s instead)";
        break;
    case ErrorInst::Generator::IncorrectSingleParameterType:
        ret = "single parameter type must be %s (got %s instead)";
        break;
    case ErrorInst::Generator::IncorrectParameterTypeNumberOfArgs:
        ret = "parameter type requires %s arguments "
              "(got %s instead)";
        break;
    case ErrorInst::Generator::LabelNotInScope:
        ret = "label not in scope: '%s'";
        break;
    case ErrorInst::Generator::TypeNotInScope:
        ret = "type not in scope: '%s'";
        break;
    case ErrorInst::Generator::MacroNotInScope:
        ret = "macro not in scope: '%s'";
        break;
    case ErrorInst::Generator::NamespaceNotInScope:
        ret = "namespace not in scope: '%s'";
        break;
    case ErrorInst::Generator::OverloadedFunctionOrMacroNotInScope:
        ret = "overloaded function/macro not in scope: '%s' "
              "(parameters are %s)";
        break;
    case ErrorInst::Generator::OverloadedFunctionOrMacroNotInScopeWithClosest:
        ret = "overloaded function/macro not in scope: '%s' "
              "(parameters are %s, closest candidate expects %s)";
        break;
    case ErrorInst::Generator::NotInScope:
        ret = "not in scope: '%s'";
        break;
    case ErrorInst::Generator::VariableNotInScope:
        ret = "variable not in scope: '%s'";
        break;
    case ErrorInst::Generator::UnexpectedElement:
        ret = "expected %s for %s (got %s instead)";
        break;
    case ErrorInst::Generator::VoidMustBeTheOnlyParameter:
        ret = "'void' must be the only parameter";
        break;
    case ErrorInst::Generator::VarArgsMustBeLastParameter:
        ret = "the varargs specifier must be the last parameter";
        break;
    case ErrorInst::Generator::TypeNotAllowedInStruct:
        ret = "'%s' fields are not allowed in structs";
        break;
    case ErrorInst::Generator::CannotInitialiseExternVar:
        ret = "'extern' variables cannot be initialised";
        break;
    case ErrorInst::Generator::InvalidType:
        ret = "invalid type";
        break;
    case ErrorInst::Generator::CannotParseLiteral:
        ret = "parsing literals of type %s is not supported";
        break;
    case ErrorInst::Generator::RedefinitionOfVariable:
        ret = "variable '%s' has already been defined in "
              "this scope";
        break;
    case ErrorInst::Generator::RedeclarationOfEnum:
        ret = "enum '%s' has already been defined";
        break;
    case ErrorInst::Generator::RedeclarationOfEnumElement:
        ret = "enum element '%s' has already been defined";
        break;
    case ErrorInst::Generator::RedeclarationOfStruct:
        ret = "struct '%s' has already been defined in "
              "this scope";
        break;
    case ErrorInst::Generator::RedeclarationOfLabel:
        ret = "label '%s' has already been defined in "
              "this scope";
        break;
    case ErrorInst::Generator::RedeclarationOfFunctionOrMacro:
        ret = "function/macro '%s' has already been defined in "
              "this scope";
        break;
    case ErrorInst::Generator::NonPointerFunctionParameter:
        ret = "all function parameters must be pointers to "
              "functions";
        break;
    case ErrorInst::Generator::ExternCInNamespace:
        ret = "functions with extern-c linkage cannot be "
              "defined within a namespace";
        break;
    case ErrorInst::Generator::IncorrectType:
        ret = "expected expression with type %s (got type "
              "%s instead)";
        break;
    case ErrorInst::Generator::IncorrectReturnType:
        ret = "expected return expression with type %s (got type "
              "%s instead)";
        break;
    case ErrorInst::Generator::CannotDereferenceNonPointer:
        ret = "cannot dereference non-pointer (type is %s)";
        break;
    case ErrorInst::Generator::CannotDereferenceVoidPointer:
        ret = "cannot dereference void pointer (type is %s)";
        break;
    case ErrorInst::Generator::OverloadedFunctionAddressWithoutTypes:
        ret = "cannot take address of overloaded function "
              "without also providing the function's types";
        break;
    case ErrorInst::Generator::NoSuchFileOrDirectory:
        ret = "%s: no such file or directory";
        break;
    case ErrorInst::Generator::FileError:
        ret = "%s: %s";
        break;
    case ErrorInst::Generator::InvalidCast:
        ret = "unable to cast from type %s to type %s";
        break;
    case ErrorInst::Generator::FieldDoesNotExistInStruct:
        ret = "field '%s' does not exist in struct %s";
        break;
    case ErrorInst::Generator::EnumValueDoesNotExist:
        ret = "value '%s' does not exist for enum";
        break;
    case ErrorInst::Generator::IfBranchesHaveDifferentTypes:
        ret = "'if' branches must have the same type "
              "(got %s and %s)";
        break;
    case ErrorInst::Generator::OnlyVarPermitted:
        ret = "'def' within a function may only be used "
              "for var and struct forms";
        break;
        // this is very much a 'last resort' error.
    case ErrorInst::Generator::UnableToParseForm:
        ret = "unable to parse form";
        break;
    case ErrorInst::Generator::InvalidChar:
        ret = "'%s' is not a valid char literal";
        break;
    case ErrorInst::Generator::TypeNotSupportedForMacro:
        ret = "type %s cannot be used for macro parameters";
        break;
    case ErrorInst::Generator::GotNullPointerFromMacroCall:
        ret = "macro '%s' returned a null pointer";
        break;
    case ErrorInst::Generator::UnableToParseInteger:
        ret = "unable to parse integer %s";
        break;
    case ErrorInst::Generator::UnableToConvertTypeToLLVMType:
        ret = "unable to convert type %s to LLVM type";
        break;
    case ErrorInst::Generator::DNodeHasNoString:
        ret = "DNode returned by macro is an atom but "
              "has no string";
        break;
    case ErrorInst::Generator::DNodeIsNeitherTokenNorList:
        ret = "DNode returned by macro is neither token "
              "nor list";
        break;
    case ErrorInst::Generator::NodeIsNeitherTokenNorList:
        ret = "internal node is neither token nor list";
        break;
    case ErrorInst::Generator::TypeIsNotFirstClass:
        ret = "type %s cannot be used, because it is not "
              "a first-class type";
        break;
    case ErrorInst::Generator::ExternalError:
        ret = "%s";
        break;
    case ErrorInst::Generator::NamespaceNotInContext:
        ret = "namespace '%s' does not exist in context";
        break;
    case ErrorInst::Generator::CannotDeactivateInactiveNamespace:
        ret = "cannot deactivate inactive namespace '%s'";
        break;
    case ErrorInst::Generator::CannotDeactivateNonLastNamespace:
        ret = "cannot deactivate namespace '%s'; it is not "
              "the most recently used namespace";
        break;
    case ErrorInst::Generator::ArraysCannotBeFunctionParameters:
        ret = "arrays cannot be function parameters; use a "
              "pointer instead";
        break;
    case ErrorInst::Generator::IncorrectNumberOfArrayElements:
        ret = "incorrect number of array elements (got "
              "%s, expected %s)";
        break;
    case ErrorInst::Generator::CanOnlyIndexIntoPointersAndArrays:
        ret = "can only index into pointers and arrays (type "
              "of value is %s)";
        break;
    case ErrorInst::Generator::EnumTypeMustBeInteger:
        ret = "enum types must be integers";
        break;
    case ErrorInst::Generator::ExternCXorOtherLinkageForName:
        ret = "cannot have extern-c function for name "
              "as well as extern/intern functions for "
              "name: %s";
        break;
    case ErrorInst::Generator::ReturnTypesCannotBeArrays:
        ret = "return types cannot be arrays (use a pointer "
              "instead)";
        break;
    case ErrorInst::Generator::CannotTakeAddressOfNonLvalue:
        ret = "cannot take address of non-lvalue";
        break;
    case ErrorInst::Generator::FunctionNotInScope:
        ret = "function not in scope: '%s' (parameters are %s, "
              "function expects %s)";
        break;
    case ErrorInst::Generator::MustHaveInitialiserForImpliedType:
        ret = "must have initialiser for variable with implied "
              "type";
        break;
    case ErrorInst::Generator::MustHaveInitialiserForConstType:
        ret = "must have initialiser for variable with const "
              "type";
        break;
    case ErrorInst::Generator::MustHaveInitialiserForType:
        ret = "must have initialiser for variable of this type";
        break;
    case ErrorInst::Generator::CannotLinkModules:
        ret = "cannot link modules: %s";
        break;
    case ErrorInst::Generator::StructContainsPadding:
        ret = "struct contains padding, may cause problems";
        break;
    case ErrorInst::Generator::NonNullPointerInGlobalStructDeclaration:
        ret = "cannot have non-null non-char pointer value "
              "in global struct declaration";
        break;
    case ErrorInst::Generator::TypeNotSupported:
        ret = "type %s is not supported on this platform";
        break;
    case ErrorInst::Generator::ValueWillNeverBeNull:
        ret = "this value will never be null";
        break;
    case ErrorInst::Generator::NoCoreFormNameInMacro:
        ret = "core form names cannot be used as macro names";
        break;
    case ErrorInst::Generator::ThisCoreFormCannotBeOverridden:
        ret = "this core form cannot be overridden";
        break;
    case ErrorInst::Generator::InvalidAttribute:
        ret = "invalid attribute";
        break;
    case ErrorInst::Generator::AttributesOfDeclAndDefAreDifferent:
        ret = "attributes for the declaration of function '%s' "
              "do not match the attributes for the definition";
        break;
    case ErrorInst::Generator::ApplyMustTakePointerToStructAsFirstArgument:
        ret = "the 'apply' function must take a pointer to "
              "the relevant struct as its first argument";
        break;
    case ErrorInst::Generator::HasBothExternAndInitialiser:
        ret = "a function-scoped variable cannot have extern "
              "linkage as well as an initialiser";
        break;
    case ErrorInst::Generator::CannotInstantiateOpaqueStruct:
        ret = "cannot instantiate opaque struct";
        break;
    case ErrorInst::Generator::ModuleDoesNotProvideForms:
        ret = "module '%s' does not provide the following forms: %s";
        break;
    case ErrorInst::Generator::UnableToLoadModule:
        ret = "unable to load module '%s'";
        break;
    case ErrorInst::Generator::InvalidModuleName:
        ret = "module name '%s' is invalid: module names may "
              "only comprise alphanumeric characters, periods, "
              "hyphens and underscores";
        break;
    case ErrorInst::Generator::BitfieldMustHaveIntegerType:
        ret = "bitfields must have an integer type";
        break;
    case ErrorInst::Generator::ZeroLengthGlobalArraysAreUnsupported:
        ret = "zero-length global arrays are currently unsupported";
        break;
    case ErrorInst::Generator::GotoWillCrossDeclaration:
        ret = "this goto will cross a declaration";
        break;
    case ErrorInst::Generator::FunctionHasSameParamsAsMacro:
        ret = "function '%s' has same parameters as an "
              "existing macro of that name";
        break;
    case ErrorInst::Generator::MacroHasSameParamsAsFunction:
        ret = "macro '%s' has same parameters as an "
              "existing function of that name";
        break;
    case ErrorInst::Generator::CannotModifyConstVariable:
        ret = "cannot modify const variable";
        break;
    case ErrorInst::Generator::SetfOverridesMustReturnBool:
        ret = "setf overrides must return bool";
        break;
    case ErrorInst::Generator::RefsNotPermittedHere:
        ret = "reference types not permitted in this context";
        break;
    case ErrorInst::Generator::RetvalsNotPermittedHere:
        ret = "retval types not permitted in this context";
        break;
    default:
        ret = "(Unknown)";
    }
    return ret;
}
}