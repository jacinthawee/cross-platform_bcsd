
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ___armv7_tick_from_thumb(undefined4 param_1,uint param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  int unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 *unaff_r7;
  uint in_lr;
  bool bVar7;
  undefined4 in_cr9;
  undefined4 in_cr13;
  undefined8 uVar8;
  undefined8 unaff_d14;
  undefined8 in_d31;
  
  piVar1 = (int *)coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  uVar8 = VectorRoundHalvingAdd(unaff_d14,in_d31,2,1);
  do {
    puVar6 = (undefined4 *)(*piVar1 + param_2);
    bVar7 = (bool)hasExclusiveAccess(piVar1);
  } while (!bVar7);
  *piVar1 = (int)puVar6;
  uVar8 = VectorRoundHalvingAdd(uVar8,in_d31,2,1);
  if (param_2 < 7) {
    puVar2 = puVar6;
    if (param_2 == 0) goto LAB_0006e21c;
  }
  else {
    uVar5 = param_2 - 4;
    for (; ((uint)puVar6 & 3) != 0; puVar6 = (undefined4 *)((int)puVar6 + 1)) {
      *(undefined *)puVar6 = 0;
      uVar5 = uVar5 - 1;
    }
    do {
      param_2 = uVar5;
      puVar2 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar2;
      uVar5 = param_2 - 4;
    } while (3 < param_2);
    if (param_2 == 0) goto LAB_0006e21c;
  }
  do {
    *(undefined *)puVar2 = 0;
    bVar7 = param_2 != 0;
    param_2 = param_2 - 1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  } while (bVar7 && param_2 != 0);
LAB_0006e21c:
  if ((in_lr & 1) == 0) {
    return;
  }
  uVar8 = VectorRoundHalvingAdd(uVar8,in_d31,2,1);
  if ((*(uint *)(PTR_s__crlext_0006e2c0 + 0x6e2c0) & 1) != 0) {
    SignedSaturate(0,0x12);
    SignedDoesSaturate(0,0x12);
    SignedSaturate(0,0x14);
    SignedDoesSaturate(0,0x14);
    SignedSaturate(unaff_r4 << 0x19,0x16);
    SignedDoesSaturate(unaff_r4 << 0x19,0x16);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((in_lr & 1) == 0) {
    return;
  }
  uVar8 = VectorRoundHalvingAdd(uVar8,in_d31,2,1);
  if ((in_lr & 1) == 0) {
    return;
  }
  uVar8 = VectorRoundHalvingAdd(uVar8,in_d31,2,1);
  if ((in_lr & 1) == 0) {
    return;
  }
  VectorRoundHalvingAdd(uVar8,in_d31,2,1);
  *unaff_r7 = unaff_r5;
  unaff_r7[1] = unaff_r6;
  unaff_r7[2] = unaff_r7;
  if (_shift == PTR_s__crlext_0006e2c0) {
    if ((name_funcs_stack != (_STACK *)0x0) &&
       (iVar3 = sk_num(name_funcs_stack), (int)_shift < iVar3)) {
      pvVar4 = sk_value(name_funcs_stack,(int)_shift);
                    /* WARNING: Could not recover jumptable at 0x0006e322. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)pvVar4 + 4))(_DAT_00000008,pcRam0006e2c8);
      return;
    }
    strcmp(_DAT_00000008,pcRam0006e2c8);
    return;
  }
  return;
}

