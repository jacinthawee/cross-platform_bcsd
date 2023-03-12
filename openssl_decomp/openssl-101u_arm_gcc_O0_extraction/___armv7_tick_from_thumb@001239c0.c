
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ___armv7_tick_from_thumb(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int unaff_r4;
  uint in_lr;
  bool bVar7;
  bool bVar8;
  undefined4 in_cr9;
  undefined4 in_cr13;
  undefined8 uVar9;
  undefined8 unaff_d14;
  undefined8 in_d31;
  
  piVar1 = (int *)coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  uVar9 = VectorRoundHalvingAdd(unaff_d14,in_d31,2,1);
  do {
    puVar6 = (undefined4 *)(*piVar1 + (int)param_2);
    bVar7 = (bool)hasExclusiveAccess(piVar1);
  } while (!bVar7);
  *piVar1 = (int)puVar6;
  uVar9 = VectorRoundHalvingAdd(uVar9,in_d31,2,1);
  if ((undefined4 *)0x6 < param_2) {
    puVar5 = param_2 + -1;
    goto LAB_0006bd54;
  }
  bVar7 = false;
  if (param_2 == (undefined4 *)0x0) goto LAB_0006bd7c;
  do {
    do {
      *(undefined *)puVar6 = 0;
      bVar8 = param_2 != (undefined4 *)0x0;
      bVar7 = SBORROW4((int)param_2,1);
      param_2 = (undefined4 *)((int)param_2 + -1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    } while (bVar8 && param_2 != (undefined4 *)0x0);
LAB_0006bd7c:
    do {
      if ((in_lr & 1) == 0) {
        return;
      }
      uVar9 = VectorRoundHalvingAdd(uVar9,in_d31,2,1);
      puVar5 = &DAT_0006be20;
      if ((*(uint *)((int)&DAT_0006be20 + DAT_0006be20) & 1) != 0) {
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
      uVar9 = VectorRoundHalvingAdd(uVar9,in_d31,2,1);
      if ((in_lr & 1) == 0) {
        return;
      }
      uVar9 = VectorRoundHalvingAdd(uVar9,in_d31,2,1);
      puVar6 = (undefined4 *)0x0;
      if ((in_lr & 1) == 0) {
        return;
      }
      uVar9 = VectorRoundHalvingAdd(uVar9,in_d31,2,1);
      if (bVar7 != false) {
        if (_shift != DAT_0006be20) {
          return;
        }
        if ((name_funcs_stack != (_STACK *)0x0) &&
           (iVar3 = sk_num(name_funcs_stack), _shift < iVar3)) {
          pvVar4 = sk_value(name_funcs_stack,_shift);
                    /* WARNING: Could not recover jumptable at 0x0006be82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)((int)pvVar4 + 4))(_DAT_00000008,pcRam0006be28);
          return;
        }
        strcmp(_DAT_00000008,pcRam0006be28);
        return;
      }
LAB_0006bd54:
      for (; puVar2 = puVar6, ((uint)puVar6 & 3) != 0; puVar6 = (undefined4 *)((int)puVar6 + 1)) {
        *(undefined *)puVar6 = 0;
        puVar5 = (undefined4 *)((int)puVar5 + -1);
      }
      do {
        param_2 = puVar5;
        puVar6 = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = puVar6;
        puVar5 = param_2 + -1;
      } while ((undefined4 *)0x3 < param_2);
      bVar7 = SCARRY4((int)(param_2 + -1),4);
    } while (param_2 == (undefined4 *)0x0);
  } while( true );
}

