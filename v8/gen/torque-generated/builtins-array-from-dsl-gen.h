#ifndef V8_TORQUE_ARRAY_FROM_DSL_BASE_H__
#define V8_TORQUE_ARRAY_FROM_DSL_BASE_H__

#include "src/builtins/builtins-array-gen.h"


 namespace v8 {
namespace internal {

class ArrayBuiltinsFromDSLAssembler: public ArrayBuiltinsAssembler {
 public:
  explicit ArrayBuiltinsFromDSLAssembler(compiler::CodeAssemblerState* state) : ArrayBuiltinsAssembler(state) {}

  using Node = compiler::Node;
  template <class T>
  using TNode = compiler::TNode<T>;
  template <class T>
  using SloppyTNode = compiler::SloppyTNode<T>;

  void EnsureWriteableFastElements(TNode<JSArray> p_array);
  TNode<BoolT> IsJSArray(TNode<Object> p_o);
  void StoreArrayHole(TNode<FixedDoubleArray> p_elements, TNode<Smi> p_k);
  void StoreArrayHole(TNode<FixedArray> p_elements, TNode<Smi> p_k);
  void CopyArrayElement(TNode<FixedArray> p_elements, TNode<FixedArray> p_newElements, TNode<Smi> p_from, TNode<Smi> p_to);
  void CopyArrayElement(TNode<FixedDoubleArray> p_elements, TNode<FixedDoubleArray> p_newElements, TNode<Smi> p_from, TNode<Smi> p_to);
  TNode<Number> ConvertToRelativeIndex(TNode<Number> p_index, TNode<Number> p_length);
  TNode<Object> ArrayForEachTorqueContinuation(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, TNode<Number> p_initialK);
  TNode<Object> FastArrayForEach(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout, TVariable<Smi>* label_Bailout_parameter_0);
  TNode<Object> LoadWithHoleCheck12ATFixedArray(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, Label* label_IfHole);
  TNode<Object> LoadWithHoleCheck18ATFixedDoubleArray(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, Label* label_IfHole);
  TNode<Number> GetFromIndex(TNode<Context> p_context, TNode<Number> p_length, CodeStubArguments* p_arguments);
  TNode<Object> TryFastArrayLastIndexOf(TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<Object> p_searchElement, TNode<Number> p_from, Label* label_Slow);
  TNode<Object> GenericArrayLastIndexOf(TNode<Context> p_context, TNode<JSReceiver> p_object, TNode<Object> p_searchElement, TNode<Number> p_from);
  TNode<Smi> LoadElement23ATFastPackedSmiElements5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index);
  TNode<Object> LoadElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index);
  TNode<Float64T> LoadElement26ATFastPackedDoubleElements9ATfloat64(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index);
  void StoreElement23ATFastPackedSmiElements5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Smi> p_value);
  void StoreElement26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Object> p_value);
  void StoreElement26ATFastPackedDoubleElements9ATfloat64(TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Float64T> p_value);
  TNode<Object> GenericArrayReverse(TNode<Context> p_context, TNode<Object> p_receiver);
  void TryFastPackedArrayReverse(TNode<Object> p_receiver, Label* label_Slow);
  TNode<FixedArray> Extract12ATFixedArray(TNode<FixedArrayBase> p_elements, TNode<Smi> p_first, TNode<Smi> p_count, TNode<Smi> p_capacity);
  TNode<FixedDoubleArray> Extract18ATFixedDoubleArray(TNode<FixedArrayBase> p_elements, TNode<Smi> p_first, TNode<Smi> p_count, TNode<Smi> p_capacity);
  TNode<Object> FastArraySplice(TNode<Context> p_context, CodeStubArguments* p_args, TNode<JSReceiver> p_o, TNode<Number> p_originalLengthNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber, Label* label_Bailout);
  TNode<Object> FillDeletedElementsArray(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount, TNode<JSReceiver> p_a);
  void HandleForwardCase(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_itemCount, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount);
  void HandleBackwardCase(TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_itemCount, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount);
  TNode<Object> SlowSplice(TNode<Context> p_context, CodeStubArguments* p_arguments, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_actualStart, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCount);
  void TryFastArrayUnshift(TNode<Context> p_context, TNode<Object> p_receiver, CodeStubArguments* p_arguments, Label* label_Slow);
  TNode<Number> GenericArrayUnshift(TNode<Context> p_context, TNode<Object> p_receiver, CodeStubArguments* p_arguments);
  TNode<Smi> kGenericElementsAccessorId();
  TNode<Smi> kFastElementsAccessorId();
  int31_t kReceiverIdx();
  int31_t kInitialReceiverMapIdx();
  int31_t kInitialReceiverLengthIdx();
  int31_t kUserCmpFnIdx();
  int31_t kSortComparePtrIdx();
  int31_t kLoadFnIdx();
  int31_t kStoreFnIdx();
  int31_t kCanUseSameAccessorFnIdx();
  int31_t kBailoutStatusIdx();
  int31_t kMinGallopIdx();
  int31_t kPendingRunsSizeIdx();
  int31_t kPendingRunsIdx();
  int31_t kTempArraySizeIdx();
  int31_t kTempArrayIdx();
  int31_t kAccessorIdx();
  TNode<IntPtrT> kSortStateSize();
  TNode<Smi> kFailure();
  TNode<Smi> kSuccess();
  int31_t kMaxMergePending();
  int31_t kMinGallopWins();
  TNode<Smi> kSortStateTempSize();
  TNode<Number> CallCompareFn(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Object> p_x, TNode<Object> p_y, Label* label_Bailout);
  TNode<HeapObject> ReloadElements(TNode<FixedArray> p_sortState);
  TNode<Code> GetLoadFn(TNode<FixedArray> p_sortState);
  TNode<Code> GetStoreFn(TNode<FixedArray> p_sortState);
  TNode<Code> GetCanUseSameAccessorFn(TNode<FixedArray> p_sortState);
  TNode<JSReceiver> GetReceiver(TNode<FixedArray> p_sortState);
  TNode<FixedArray> GetTempArray(TNode<FixedArray> p_sortState);
  TNode<Smi> GetPendingRunsSize(TNode<FixedArray> p_sortState);
  void SetPendingRunsSize(TNode<FixedArray> p_sortState, TNode<Smi> p_value);
  TNode<Smi> GetPendingRunBase(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run);
  void SetPendingRunBase(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run, TNode<Smi> p_value);
  TNode<Smi> GetPendingRunLength(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run);
  void SetPendingRunLength(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_run, TNode<Smi> p_value);
  void PushRun(TNode<FixedArray> p_sortState, TNode<Smi> p_base, TNode<Smi> p_length);
  TNode<FixedArray> GetTempArray(TNode<FixedArray> p_sortState, TNode<Smi> p_requestedSize);
  void EnsureSuccess(TNode<FixedArray> p_sortState, Label* label_Bailout);
  TNode<Smi> Failure(TNode<FixedArray> p_sortState);
  TNode<Object> CallLoad(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_load, TNode<HeapObject> p_elements, TNode<Smi> p_index, Label* label_Bailout);
  void CallStore(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_store, TNode<HeapObject> p_elements, TNode<Smi> p_index, TNode<Object> p_value, Label* label_Bailout);
  void CallCopyFromTempArray(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<HeapObject> p_dstElements, TNode<Smi> p_dstPos, TNode<FixedArray> p_tempArray, TNode<Smi> p_srcPos, TNode<Smi> p_length, Label* label_Bailout);
  void CallCopyWithinSortArray(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<HeapObject> p_elements, TNode<Smi> p_srcPos, TNode<Smi> p_dstPos, TNode<Smi> p_length, Label* label_Bailout);
  TNode<Smi> CallGallopRight(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_load, TNode<Object> p_key, TNode<Smi> p_base, TNode<Smi> p_length, TNode<Smi> p_hint, TNode<Oddball> p_useTempArray, Label* label_Bailout);
  TNode<Smi> CallGallopLeft(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_load, TNode<Object> p_key, TNode<Smi> p_base, TNode<Smi> p_length, TNode<Smi> p_hint, TNode<Oddball> p_useTempArray, Label* label_Bailout);
  void CallMergeAt(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_i, Label* label_Bailout);
  TNode<Smi> GetReceiverLengthProperty(TNode<Context> p_context, TNode<FixedArray> p_sortState);
  void CopyToTempArray(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_load, TNode<HeapObject> p_srcElements, TNode<Smi> p_srcPos, TNode<FixedArray> p_tempArray, TNode<Smi> p_dstPos, TNode<Smi> p_length, Label* label_Bailout);
  TNode<Smi> CountAndMakeRun(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_lowArg, TNode<Smi> p_high, Label* label_Bailout);
  void ReverseRange(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_load, TNode<Code> p_store, TNode<HeapObject> p_elements, TNode<Smi> p_from, TNode<Smi> p_to, Label* label_Bailout);
  TNode<HeapObject> LoadElementsOrTempArray(TNode<Oddball> p_useTempArray, TNode<FixedArray> p_sortState);
  void CopyElement(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Code> p_load, TNode<Code> p_store, TNode<HeapObject> p_elements, TNode<Smi> p_from, TNode<Smi> p_to, Label* label_Bailout);
  void MergeLow(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_baseA, TNode<Smi> p_lengthAArg, TNode<Smi> p_baseB, TNode<Smi> p_lengthBArg, Label* label_Bailout);
  void MergeHigh(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_baseA, TNode<Smi> p_lengthAArg, TNode<Smi> p_baseB, TNode<Smi> p_lengthBArg, Label* label_Bailout);
  TNode<Smi> ComputeMinRunLength(TNode<Smi> p_nArg);
  TNode<BoolT> RunInvariantEstablished(TNode<FixedArray> p_pendingRuns, TNode<Smi> p_n);
  void MergeCollapse(TNode<Context> p_context, TNode<FixedArray> p_sortState, Label* label_Bailout);
  void MergeForceCollapse(TNode<Context> p_context, TNode<FixedArray> p_sortState, Label* label_Bailout);
  void InitializeSortState(TNode<FixedArray> p_sortState);
  void InitializeSortStateAccessor25ATGenericElementsAccessor(TNode<FixedArray> p_sortState);
  void ArrayTimSortImpl(TNode<Context> p_context, TNode<FixedArray> p_sortState, TNode<Smi> p_length, Label* label_Bailout);
  void VisitAllElements18ATFixedDoubleArray(TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout, TVariable<Smi>* label_Bailout_parameter_0);
  void VisitAllElements12ATFixedArray(TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout, TVariable<Smi>* label_Bailout_parameter_0);
  TNode<Smi> FastArrayLastIndexOf12ATFixedArray(TNode<Context> p_context, TNode<JSArray> p_array, TNode<Smi> p_from, TNode<Object> p_searchElement);
  TNode<Smi> FastArrayLastIndexOf18ATFixedDoubleArray(TNode<Context> p_context, TNode<JSArray> p_array, TNode<Smi> p_from, TNode<Object> p_searchElement);
  void FastPackedArrayReverse23ATFastPackedSmiElements5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_length);
  void FastPackedArrayReverse26ATFastPackedObjectElements22UT12ATHeapObject5ATSmi(TNode<FixedArrayBase> p_elements, TNode<Smi> p_length);
  void FastPackedArrayReverse26ATFastPackedDoubleElements9ATfloat64(TNode<FixedArrayBase> p_elements, TNode<Smi> p_length);
  void FastSplice12ATFixedArray22UT12ATHeapObject5ATSmi(CodeStubArguments* p_args, TNode<JSArray> p_a, TNode<Smi> p_length, TNode<Smi> p_newLength, TNode<Smi> p_lengthDelta, TNode<Smi> p_actualStart, TNode<Smi> p_insertCount, TNode<Smi> p_actualDeleteCount, Label* label_Bailout);
  void FastSplice18ATFixedDoubleArray22UT12ATHeapNumber5ATSmi(CodeStubArguments* p_args, TNode<JSArray> p_a, TNode<Smi> p_length, TNode<Smi> p_newLength, TNode<Smi> p_lengthDelta, TNode<Smi> p_actualStart, TNode<Smi> p_insertCount, TNode<Smi> p_actualDeleteCount, Label* label_Bailout);
  void InitializeSortStateAccessor20ATFastDoubleElements(TNode<FixedArray> p_sortState);
  void InitializeSortStateAccessor23ATFastPackedSmiElements(TNode<FixedArray> p_sortState);
  void InitializeSortStateAccessor25ATFastSmiOrObjectElements(TNode<FixedArray> p_sortState);
  void InitializeSortStateAccessor20ATDictionaryElements(TNode<FixedArray> p_sortState);
  void DoMoveElements12ATFixedArray(TNode<FixedArray> p_elements, TNode<Smi> p_dstIndex, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
  void StoreHoles12ATFixedArray(TNode<FixedArray> p_elements, TNode<Smi> p_holeStartIndex, TNode<Smi> p_holeEndIndex);
  void DoCopyElements12ATFixedArray(TNode<FixedArray> p_dstElements, TNode<Smi> p_dstIndex, TNode<FixedArray> p_srcElements, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
  void DoMoveElements18ATFixedDoubleArray(TNode<FixedDoubleArray> p_elements, TNode<Smi> p_dstIndex, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
  void StoreHoles18ATFixedDoubleArray(TNode<FixedDoubleArray> p_elements, TNode<Smi> p_holeStartIndex, TNode<Smi> p_holeEndIndex);
  void DoCopyElements18ATFixedDoubleArray(TNode<FixedDoubleArray> p_dstElements, TNode<Smi> p_dstIndex, TNode<FixedDoubleArray> p_srcElements, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
};

}  // namespace internal
}  // namespace v8

#endif  // V8_TORQUE_ARRAY_FROM_DSL_BASE_H__
