#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/code-factory.h"
#include "src/elements-kind.h"
#include "src/heap/factory-inl.h"
#include "src/objects.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "torque-generated/builtins-base-from-dsl-gen.h"
#include "torque-generated/builtins-arguments-from-dsl-gen.h"
#include "torque-generated/builtins-array-from-dsl-gen.h"
#include "torque-generated/builtins-collections-from-dsl-gen.h"
#include "torque-generated/builtins-data-view-from-dsl-gen.h"
#include "torque-generated/builtins-extras-utils-from-dsl-gen.h"
#include "torque-generated/builtins-object-from-dsl-gen.h"
#include "torque-generated/builtins-iterator-from-dsl-gen.h"
#include "torque-generated/builtins-typed-array-from-dsl-gen.h"
#include "torque-generated/builtins-test-from-dsl-gen.h"

namespace v8 {
namespace internal {

BaseBuiltinsFromDSLAssembler::KeyValuePair CollectionsBuiltinsFromDSLAssembler::LoadKeyValuePairNoSideEffects(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_MayHaveSideEffects) {
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase, FixedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object, Object, Object, Object, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase, FixedDoubleArray> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object, Object, Object, Object, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSReceiver> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    compiler::TNode<Context> tmp0;
    compiler::TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = BaseBuiltinsFromDSLAssembler(state_).Cast13ATFastJSArray(compiler::TNode<Context>{tmp0}, compiler::TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp1);
    }
  }

  if (block6.is_used()) {
    compiler::TNode<Context> tmp3;
    compiler::TNode<Object> tmp4;
    compiler::TNode<Object> tmp5;
    compiler::TNode<Object> tmp6;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block4, tmp3, tmp4, tmp5);
  }

  if (block5.is_used()) {
    compiler::TNode<Context> tmp7;
    compiler::TNode<Object> tmp8;
    compiler::TNode<Object> tmp9;
    compiler::TNode<Object> tmp10;
    compiler::TNode<JSArray> tmp11;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    compiler::TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = ca_.UncheckedCast<Smi>(CodeStubAssembler(state_).LoadFastJSArrayLength(compiler::TNode<JSArray>{tmp11}));
    compiler::TNode<FixedArrayBase> tmp13;
    USE(tmp13);
    tmp13 = ca_.UncheckedCast<FixedArrayBase>(BaseBuiltinsFromDSLAssembler(state_).LoadJSObjectElements(compiler::TNode<JSObject>{tmp11}));
    compiler::TNode<FixedArray> tmp14;
    USE(tmp14);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp14 = BaseBuiltinsFromDSLAssembler(state_).Cast12ATFixedArray(compiler::TNode<Context>{tmp7}, compiler::TNode<HeapObject>{tmp13}, &label0);
    ca_.Goto(&block9, tmp7, tmp8, tmp9, tmp11, tmp12, tmp13, tmp13, tmp14);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp7, tmp8, tmp9, tmp11, tmp12, tmp13, tmp13);
    }
  }

  if (block10.is_used()) {
    compiler::TNode<Context> tmp15;
    compiler::TNode<Object> tmp16;
    compiler::TNode<Object> tmp17;
    compiler::TNode<JSArray> tmp18;
    compiler::TNode<Smi> tmp19;
    compiler::TNode<FixedArrayBase> tmp20;
    compiler::TNode<FixedArrayBase> tmp21;
    ca_.Bind(&block10, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block8, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20);
  }

  if (block9.is_used()) {
    compiler::TNode<Context> tmp22;
    compiler::TNode<Object> tmp23;
    compiler::TNode<Object> tmp24;
    compiler::TNode<JSArray> tmp25;
    compiler::TNode<Smi> tmp26;
    compiler::TNode<FixedArrayBase> tmp27;
    compiler::TNode<FixedArrayBase> tmp28;
    compiler::TNode<FixedArray> tmp29;
    ca_.Bind(&block9, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    compiler::TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = ca_.UncheckedCast<Smi>(BaseBuiltinsFromDSLAssembler(state_).FromConstexpr5ATSmi17ATconstexpr_int31(0));
    compiler::TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).SmiGreaterThan(compiler::TNode<Smi>{tmp26}, compiler::TNode<Smi>{tmp30}));
    ca_.Branch(tmp31, &block11, &block12, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp29, ca_.Uninitialized<Object>(), ca_.Uninitialized<Object>());
  }

  if (block11.is_used()) {
    compiler::TNode<Context> tmp32;
    compiler::TNode<Object> tmp33;
    compiler::TNode<Object> tmp34;
    compiler::TNode<JSArray> tmp35;
    compiler::TNode<Smi> tmp36;
    compiler::TNode<FixedArrayBase> tmp37;
    compiler::TNode<FixedArray> tmp38;
    compiler::TNode<Object> tmp39;
    compiler::TNode<Object> tmp40;
    ca_.Bind(&block11, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    compiler::TNode<Object> tmp41;
    USE(tmp41);
    tmp41 = ca_.UncheckedCast<Object>(ArrayBuiltinsFromDSLAssembler(state_).LoadElementOrUndefined(compiler::TNode<FixedArray>{tmp38}, 0));
    ca_.Goto(&block14, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block12.is_used()) {
    compiler::TNode<Context> tmp42;
    compiler::TNode<Object> tmp43;
    compiler::TNode<Object> tmp44;
    compiler::TNode<JSArray> tmp45;
    compiler::TNode<Smi> tmp46;
    compiler::TNode<FixedArrayBase> tmp47;
    compiler::TNode<FixedArray> tmp48;
    compiler::TNode<Object> tmp49;
    compiler::TNode<Object> tmp50;
    ca_.Bind(&block12, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    compiler::TNode<Oddball> tmp51;
    USE(tmp51);
    tmp51 = BaseBuiltinsFromDSLAssembler(state_).Undefined();
    ca_.Goto(&block13, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51);
  }

  if (block14.is_used()) {
    compiler::TNode<Context> tmp52;
    compiler::TNode<Object> tmp53;
    compiler::TNode<Object> tmp54;
    compiler::TNode<JSArray> tmp55;
    compiler::TNode<Smi> tmp56;
    compiler::TNode<FixedArrayBase> tmp57;
    compiler::TNode<FixedArray> tmp58;
    compiler::TNode<Object> tmp59;
    compiler::TNode<Object> tmp60;
    compiler::TNode<Object> tmp61;
    ca_.Bind(&block14, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block13, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61);
  }

  if (block13.is_used()) {
    compiler::TNode<Context> tmp62;
    compiler::TNode<Object> tmp63;
    compiler::TNode<Object> tmp64;
    compiler::TNode<JSArray> tmp65;
    compiler::TNode<Smi> tmp66;
    compiler::TNode<FixedArrayBase> tmp67;
    compiler::TNode<FixedArray> tmp68;
    compiler::TNode<Object> tmp69;
    compiler::TNode<Object> tmp70;
    compiler::TNode<Object> tmp71;
    ca_.Bind(&block13, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    compiler::TNode<Smi> tmp72;
    USE(tmp72);
    tmp72 = ca_.UncheckedCast<Smi>(BaseBuiltinsFromDSLAssembler(state_).FromConstexpr5ATSmi17ATconstexpr_int31(1));
    compiler::TNode<BoolT> tmp73;
    USE(tmp73);
    tmp73 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).SmiGreaterThan(compiler::TNode<Smi>{tmp66}, compiler::TNode<Smi>{tmp72}));
    ca_.Branch(tmp73, &block15, &block16, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71);
  }

  if (block15.is_used()) {
    compiler::TNode<Context> tmp74;
    compiler::TNode<Object> tmp75;
    compiler::TNode<Object> tmp76;
    compiler::TNode<JSArray> tmp77;
    compiler::TNode<Smi> tmp78;
    compiler::TNode<FixedArrayBase> tmp79;
    compiler::TNode<FixedArray> tmp80;
    compiler::TNode<Object> tmp81;
    compiler::TNode<Object> tmp82;
    compiler::TNode<Object> tmp83;
    ca_.Bind(&block15, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83);
    compiler::TNode<Object> tmp84;
    USE(tmp84);
    tmp84 = ca_.UncheckedCast<Object>(ArrayBuiltinsFromDSLAssembler(state_).LoadElementOrUndefined(compiler::TNode<FixedArray>{tmp80}, 1));
    ca_.Goto(&block18, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84);
  }

  if (block16.is_used()) {
    compiler::TNode<Context> tmp85;
    compiler::TNode<Object> tmp86;
    compiler::TNode<Object> tmp87;
    compiler::TNode<JSArray> tmp88;
    compiler::TNode<Smi> tmp89;
    compiler::TNode<FixedArrayBase> tmp90;
    compiler::TNode<FixedArray> tmp91;
    compiler::TNode<Object> tmp92;
    compiler::TNode<Object> tmp93;
    compiler::TNode<Object> tmp94;
    ca_.Bind(&block16, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    compiler::TNode<Oddball> tmp95;
    USE(tmp95);
    tmp95 = BaseBuiltinsFromDSLAssembler(state_).Undefined();
    ca_.Goto(&block17, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95);
  }

  if (block18.is_used()) {
    compiler::TNode<Context> tmp96;
    compiler::TNode<Object> tmp97;
    compiler::TNode<Object> tmp98;
    compiler::TNode<JSArray> tmp99;
    compiler::TNode<Smi> tmp100;
    compiler::TNode<FixedArrayBase> tmp101;
    compiler::TNode<FixedArray> tmp102;
    compiler::TNode<Object> tmp103;
    compiler::TNode<Object> tmp104;
    compiler::TNode<Object> tmp105;
    compiler::TNode<Object> tmp106;
    ca_.Bind(&block18, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106);
    ca_.Goto(&block17, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106);
  }

  if (block17.is_used()) {
    compiler::TNode<Context> tmp107;
    compiler::TNode<Object> tmp108;
    compiler::TNode<Object> tmp109;
    compiler::TNode<JSArray> tmp110;
    compiler::TNode<Smi> tmp111;
    compiler::TNode<FixedArrayBase> tmp112;
    compiler::TNode<FixedArray> tmp113;
    compiler::TNode<Object> tmp114;
    compiler::TNode<Object> tmp115;
    compiler::TNode<Object> tmp116;
    compiler::TNode<Object> tmp117;
    ca_.Bind(&block17, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117);
    ca_.Goto(&block19, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp116, tmp117, tmp116, tmp117, tmp116, tmp117);
  }

  if (block19.is_used()) {
    compiler::TNode<Context> tmp118;
    compiler::TNode<Object> tmp119;
    compiler::TNode<Object> tmp120;
    compiler::TNode<JSArray> tmp121;
    compiler::TNode<Smi> tmp122;
    compiler::TNode<FixedArrayBase> tmp123;
    compiler::TNode<FixedArray> tmp124;
    compiler::TNode<Object> tmp125;
    compiler::TNode<Object> tmp126;
    compiler::TNode<Object> tmp127;
    compiler::TNode<Object> tmp128;
    compiler::TNode<Object> tmp129;
    compiler::TNode<Object> tmp130;
    ca_.Bind(&block19, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    ca_.Goto(&block2, tmp118, tmp119, tmp125, tmp126);
  }

  if (block8.is_used()) {
    compiler::TNode<Context> tmp131;
    compiler::TNode<Object> tmp132;
    compiler::TNode<Object> tmp133;
    compiler::TNode<JSArray> tmp134;
    compiler::TNode<Smi> tmp135;
    compiler::TNode<FixedArrayBase> tmp136;
    ca_.Bind(&block8, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136);
    compiler::TNode<FixedDoubleArray> tmp137;
    USE(tmp137);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp137 = BaseBuiltinsFromDSLAssembler(state_).Cast18ATFixedDoubleArray(compiler::TNode<Context>{tmp131}, compiler::TNode<HeapObject>{ca_.UncheckedCast<FixedArrayBase>(tmp136)}, &label0);
    ca_.Goto(&block22, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, ca_.UncheckedCast<FixedArrayBase>(tmp136), tmp137);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block23, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, ca_.UncheckedCast<FixedArrayBase>(tmp136));
    }
  }

  if (block23.is_used()) {
    compiler::TNode<Context> tmp138;
    compiler::TNode<Object> tmp139;
    compiler::TNode<Object> tmp140;
    compiler::TNode<JSArray> tmp141;
    compiler::TNode<Smi> tmp142;
    compiler::TNode<FixedArrayBase> tmp143;
    compiler::TNode<FixedArrayBase> tmp144;
    ca_.Bind(&block23, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144);
    ca_.Goto(&block21, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143);
  }

  if (block22.is_used()) {
    compiler::TNode<Context> tmp145;
    compiler::TNode<Object> tmp146;
    compiler::TNode<Object> tmp147;
    compiler::TNode<JSArray> tmp148;
    compiler::TNode<Smi> tmp149;
    compiler::TNode<FixedArrayBase> tmp150;
    compiler::TNode<FixedArrayBase> tmp151;
    compiler::TNode<FixedDoubleArray> tmp152;
    ca_.Bind(&block22, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152);
    compiler::TNode<Smi> tmp153;
    USE(tmp153);
    tmp153 = ca_.UncheckedCast<Smi>(BaseBuiltinsFromDSLAssembler(state_).FromConstexpr5ATSmi17ATconstexpr_int31(0));
    compiler::TNode<BoolT> tmp154;
    USE(tmp154);
    tmp154 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).SmiGreaterThan(compiler::TNode<Smi>{tmp149}, compiler::TNode<Smi>{tmp153}));
    ca_.Branch(tmp154, &block24, &block25, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp152, ca_.Uninitialized<Object>(), ca_.Uninitialized<Object>());
  }

  if (block24.is_used()) {
    compiler::TNode<Context> tmp155;
    compiler::TNode<Object> tmp156;
    compiler::TNode<Object> tmp157;
    compiler::TNode<JSArray> tmp158;
    compiler::TNode<Smi> tmp159;
    compiler::TNode<FixedArrayBase> tmp160;
    compiler::TNode<FixedDoubleArray> tmp161;
    compiler::TNode<Object> tmp162;
    compiler::TNode<Object> tmp163;
    ca_.Bind(&block24, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    compiler::TNode<Object> tmp164;
    USE(tmp164);
    tmp164 = ca_.UncheckedCast<Object>(ArrayBuiltinsFromDSLAssembler(state_).LoadElementOrUndefined(compiler::TNode<FixedDoubleArray>{tmp161}, 0));
    ca_.Goto(&block27, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164);
  }

  if (block25.is_used()) {
    compiler::TNode<Context> tmp165;
    compiler::TNode<Object> tmp166;
    compiler::TNode<Object> tmp167;
    compiler::TNode<JSArray> tmp168;
    compiler::TNode<Smi> tmp169;
    compiler::TNode<FixedArrayBase> tmp170;
    compiler::TNode<FixedDoubleArray> tmp171;
    compiler::TNode<Object> tmp172;
    compiler::TNode<Object> tmp173;
    ca_.Bind(&block25, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173);
    compiler::TNode<Oddball> tmp174;
    USE(tmp174);
    tmp174 = BaseBuiltinsFromDSLAssembler(state_).Undefined();
    ca_.Goto(&block26, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174);
  }

  if (block27.is_used()) {
    compiler::TNode<Context> tmp175;
    compiler::TNode<Object> tmp176;
    compiler::TNode<Object> tmp177;
    compiler::TNode<JSArray> tmp178;
    compiler::TNode<Smi> tmp179;
    compiler::TNode<FixedArrayBase> tmp180;
    compiler::TNode<FixedDoubleArray> tmp181;
    compiler::TNode<Object> tmp182;
    compiler::TNode<Object> tmp183;
    compiler::TNode<Object> tmp184;
    ca_.Bind(&block27, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184);
    ca_.Goto(&block26, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184);
  }

  if (block26.is_used()) {
    compiler::TNode<Context> tmp185;
    compiler::TNode<Object> tmp186;
    compiler::TNode<Object> tmp187;
    compiler::TNode<JSArray> tmp188;
    compiler::TNode<Smi> tmp189;
    compiler::TNode<FixedArrayBase> tmp190;
    compiler::TNode<FixedDoubleArray> tmp191;
    compiler::TNode<Object> tmp192;
    compiler::TNode<Object> tmp193;
    compiler::TNode<Object> tmp194;
    ca_.Bind(&block26, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194);
    compiler::TNode<Smi> tmp195;
    USE(tmp195);
    tmp195 = ca_.UncheckedCast<Smi>(BaseBuiltinsFromDSLAssembler(state_).FromConstexpr5ATSmi17ATconstexpr_int31(1));
    compiler::TNode<BoolT> tmp196;
    USE(tmp196);
    tmp196 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).SmiGreaterThan(compiler::TNode<Smi>{tmp189}, compiler::TNode<Smi>{tmp195}));
    ca_.Branch(tmp196, &block28, &block29, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194);
  }

  if (block28.is_used()) {
    compiler::TNode<Context> tmp197;
    compiler::TNode<Object> tmp198;
    compiler::TNode<Object> tmp199;
    compiler::TNode<JSArray> tmp200;
    compiler::TNode<Smi> tmp201;
    compiler::TNode<FixedArrayBase> tmp202;
    compiler::TNode<FixedDoubleArray> tmp203;
    compiler::TNode<Object> tmp204;
    compiler::TNode<Object> tmp205;
    compiler::TNode<Object> tmp206;
    ca_.Bind(&block28, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206);
    compiler::TNode<Object> tmp207;
    USE(tmp207);
    tmp207 = ca_.UncheckedCast<Object>(ArrayBuiltinsFromDSLAssembler(state_).LoadElementOrUndefined(compiler::TNode<FixedDoubleArray>{tmp203}, 1));
    ca_.Goto(&block31, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207);
  }

  if (block29.is_used()) {
    compiler::TNode<Context> tmp208;
    compiler::TNode<Object> tmp209;
    compiler::TNode<Object> tmp210;
    compiler::TNode<JSArray> tmp211;
    compiler::TNode<Smi> tmp212;
    compiler::TNode<FixedArrayBase> tmp213;
    compiler::TNode<FixedDoubleArray> tmp214;
    compiler::TNode<Object> tmp215;
    compiler::TNode<Object> tmp216;
    compiler::TNode<Object> tmp217;
    ca_.Bind(&block29, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217);
    compiler::TNode<Oddball> tmp218;
    USE(tmp218);
    tmp218 = BaseBuiltinsFromDSLAssembler(state_).Undefined();
    ca_.Goto(&block30, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217, tmp218);
  }

  if (block31.is_used()) {
    compiler::TNode<Context> tmp219;
    compiler::TNode<Object> tmp220;
    compiler::TNode<Object> tmp221;
    compiler::TNode<JSArray> tmp222;
    compiler::TNode<Smi> tmp223;
    compiler::TNode<FixedArrayBase> tmp224;
    compiler::TNode<FixedDoubleArray> tmp225;
    compiler::TNode<Object> tmp226;
    compiler::TNode<Object> tmp227;
    compiler::TNode<Object> tmp228;
    compiler::TNode<Object> tmp229;
    ca_.Bind(&block31, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229);
    ca_.Goto(&block30, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229);
  }

  if (block30.is_used()) {
    compiler::TNode<Context> tmp230;
    compiler::TNode<Object> tmp231;
    compiler::TNode<Object> tmp232;
    compiler::TNode<JSArray> tmp233;
    compiler::TNode<Smi> tmp234;
    compiler::TNode<FixedArrayBase> tmp235;
    compiler::TNode<FixedDoubleArray> tmp236;
    compiler::TNode<Object> tmp237;
    compiler::TNode<Object> tmp238;
    compiler::TNode<Object> tmp239;
    compiler::TNode<Object> tmp240;
    ca_.Bind(&block30, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240);
    ca_.Goto(&block32, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp236, tmp239, tmp240, tmp239, tmp240, tmp239, tmp240);
  }

  if (block32.is_used()) {
    compiler::TNode<Context> tmp241;
    compiler::TNode<Object> tmp242;
    compiler::TNode<Object> tmp243;
    compiler::TNode<JSArray> tmp244;
    compiler::TNode<Smi> tmp245;
    compiler::TNode<FixedArrayBase> tmp246;
    compiler::TNode<FixedDoubleArray> tmp247;
    compiler::TNode<Object> tmp248;
    compiler::TNode<Object> tmp249;
    compiler::TNode<Object> tmp250;
    compiler::TNode<Object> tmp251;
    compiler::TNode<Object> tmp252;
    compiler::TNode<Object> tmp253;
    ca_.Bind(&block32, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253);
    ca_.Goto(&block2, tmp241, tmp242, tmp248, tmp249);
  }

  if (block21.is_used()) {
    compiler::TNode<Context> tmp254;
    compiler::TNode<Object> tmp255;
    compiler::TNode<Object> tmp256;
    compiler::TNode<JSArray> tmp257;
    compiler::TNode<Smi> tmp258;
    compiler::TNode<FixedArrayBase> tmp259;
    ca_.Bind(&block21, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259);
    CodeStubAssembler(state_).Print("halting because of \'unreachable\' at ../../src/builtins/collections.tq:32:13");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    compiler::TNode<Context> tmp260;
    compiler::TNode<Object> tmp261;
    compiler::TNode<Object> tmp262;
    ca_.Bind(&block4, &tmp260, &tmp261, &tmp262);
    compiler::TNode<JSReceiver> tmp263;
    USE(tmp263);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp263 = BaseBuiltinsFromDSLAssembler(state_).Cast10JSReceiver(compiler::TNode<Context>{tmp260}, compiler::TNode<Object>{ca_.UncheckedCast<Object>(tmp262)}, &label0);
    ca_.Goto(&block35, tmp260, tmp261, tmp262, ca_.UncheckedCast<Object>(tmp262), tmp263);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block36, tmp260, tmp261, tmp262, ca_.UncheckedCast<Object>(tmp262));
    }
  }

  if (block36.is_used()) {
    compiler::TNode<Context> tmp264;
    compiler::TNode<Object> tmp265;
    compiler::TNode<Object> tmp266;
    compiler::TNode<Object> tmp267;
    ca_.Bind(&block36, &tmp264, &tmp265, &tmp266, &tmp267);
    ca_.Goto(&block34, tmp264, tmp265, tmp266);
  }

  if (block35.is_used()) {
    compiler::TNode<Context> tmp268;
    compiler::TNode<Object> tmp269;
    compiler::TNode<Object> tmp270;
    compiler::TNode<Object> tmp271;
    compiler::TNode<JSReceiver> tmp272;
    ca_.Bind(&block35, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272);
    ca_.Goto(&block1);
  }

  if (block34.is_used()) {
    compiler::TNode<Context> tmp273;
    compiler::TNode<Object> tmp274;
    compiler::TNode<Object> tmp275;
    ca_.Bind(&block34, &tmp273, &tmp274, &tmp275);
    CodeStubAssembler(state_).ThrowTypeError(compiler::TNode<Context>{tmp273}, MessageTemplate::kIteratorValueNotAnObject, compiler::TNode<Object>{ca_.UncheckedCast<Object>(tmp275)});
  }

  if (block2.is_used()) {
    compiler::TNode<Context> tmp276;
    compiler::TNode<Object> tmp277;
    compiler::TNode<Object> tmp278;
    compiler::TNode<Object> tmp279;
    ca_.Bind(&block2, &tmp276, &tmp277, &tmp278, &tmp279);
    ca_.Goto(&block37, tmp276, tmp277, tmp278, tmp279);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_MayHaveSideEffects);
  }

    compiler::TNode<Context> tmp280;
    compiler::TNode<Object> tmp281;
    compiler::TNode<Object> tmp282;
    compiler::TNode<Object> tmp283;
    ca_.Bind(&block37, &tmp280, &tmp281, &tmp282, &tmp283);
  return BaseBuiltinsFromDSLAssembler::KeyValuePair{compiler::TNode<Object>{tmp282}, compiler::TNode<Object>{tmp283}};
}

BaseBuiltinsFromDSLAssembler::KeyValuePair CollectionsBuiltinsFromDSLAssembler::LoadKeyValuePair(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o) {
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    compiler::TNode<Context> tmp0;
    compiler::TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TNode<Object> tmp2;
    USE(tmp2);
    compiler::TNode<Object> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    std::tie(tmp2, tmp3) = CollectionsBuiltinsFromDSLAssembler(state_).LoadKeyValuePairNoSideEffects(compiler::TNode<Context>{tmp0}, compiler::TNode<Object>{tmp1}, &label0).Flatten();
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    compiler::TNode<Context> tmp4;
    compiler::TNode<Object> tmp5;
    compiler::TNode<Object> tmp6;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    compiler::TNode<Context> tmp7;
    compiler::TNode<Object> tmp8;
    compiler::TNode<Object> tmp9;
    compiler::TNode<Object> tmp10;
    compiler::TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block1, tmp7, tmp8, tmp10, tmp11);
  }

  if (block3.is_used()) {
    compiler::TNode<Context> tmp12;
    compiler::TNode<Object> tmp13;
    ca_.Bind(&block3, &tmp12, &tmp13);
    compiler::TNode<Smi> tmp14;
    USE(tmp14);
    tmp14 = ca_.UncheckedCast<Smi>(BaseBuiltinsFromDSLAssembler(state_).Convert5ATSmi17ATconstexpr_int31(0));
    compiler::TNode<Object> tmp15;
    USE(tmp15);
    tmp15 = ca_.UncheckedCast<Object>(CodeStubAssembler(state_).GetProperty(compiler::TNode<Context>{tmp12}, compiler::TNode<Object>{tmp13}, compiler::TNode<Object>{tmp14}));
    compiler::TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = ca_.UncheckedCast<Smi>(BaseBuiltinsFromDSLAssembler(state_).Convert5ATSmi17ATconstexpr_int31(1));
    compiler::TNode<Object> tmp17;
    USE(tmp17);
    tmp17 = ca_.UncheckedCast<Object>(CodeStubAssembler(state_).GetProperty(compiler::TNode<Context>{tmp12}, compiler::TNode<Object>{tmp13}, compiler::TNode<Object>{tmp16}));
    ca_.Goto(&block6, tmp12, tmp13, tmp15, tmp17, tmp15, tmp17, tmp15, tmp17);
  }

  if (block6.is_used()) {
    compiler::TNode<Context> tmp18;
    compiler::TNode<Object> tmp19;
    compiler::TNode<Object> tmp20;
    compiler::TNode<Object> tmp21;
    compiler::TNode<Object> tmp22;
    compiler::TNode<Object> tmp23;
    compiler::TNode<Object> tmp24;
    compiler::TNode<Object> tmp25;
    ca_.Bind(&block6, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block1, tmp18, tmp19, tmp20, tmp21);
  }

  if (block1.is_used()) {
    compiler::TNode<Context> tmp26;
    compiler::TNode<Object> tmp27;
    compiler::TNode<Object> tmp28;
    compiler::TNode<Object> tmp29;
    ca_.Bind(&block1, &tmp26, &tmp27, &tmp28, &tmp29);
    ca_.Goto(&block7, tmp26, tmp27, tmp28, tmp29);
  }

    compiler::TNode<Context> tmp30;
    compiler::TNode<Object> tmp31;
    compiler::TNode<Object> tmp32;
    compiler::TNode<Object> tmp33;
    ca_.Bind(&block7, &tmp30, &tmp31, &tmp32, &tmp33);
  return BaseBuiltinsFromDSLAssembler::KeyValuePair{compiler::TNode<Object>{tmp32}, compiler::TNode<Object>{tmp33}};
}

}  // namespace internal
}  // namespace v8

