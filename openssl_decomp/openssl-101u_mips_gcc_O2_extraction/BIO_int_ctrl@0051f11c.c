
long BIO_int_ctrl(BIO *bp,int cmd,long larg,int iarg)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  char *pcVar9;
  BIO *unaff_s0;
  _func_603 *unaff_s1;
  code *pcVar10;
  long unaff_s3;
  int unaff_s4;
  int *unaff_s5;
  _func_599 *p_Var11;
  code *UNRECOVERED_JUMPTABLE;
  undefined *puVar12;
  int *piVar13;
  undefined4 uVar14;
  long lStack_70;
  int *piStack_6c;
  BIO *pBStack_64;
  _func_603 *p_Stack_60;
  undefined *puStack_5c;
  long lStack_58;
  int iStack_54;
  int *piStack_50;
  code *pcStack_4c;
  int local_28;
  int *local_24;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  lVar1 = 0;
  piVar4 = (int *)cmd;
  piVar6 = (int *)larg;
  pcVar9 = (char *)iarg;
  pBStack_64 = unaff_s0;
  local_28 = iarg;
  if (bp != (BIO *)0x0) {
    pBStack_64 = bp;
    if ((bp->method == (BIO_METHOD *)0x0) ||
       (p_Var11 = bp->method->ctrl, p_Var11 == (_func_599 *)0x0)) {
      piVar6 = (int *)&DAT_00000079;
      pcVar9 = "bio_lib.c";
      piVar4 = (int *)0x67;
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
      lVar1 = -2;
    }
    else {
      unaff_s1 = bp->callback;
      unaff_s5 = &local_28;
      if (unaff_s1 == (_func_603 *)0x0) {
        pcVar9 = (char *)&local_28;
        lVar1 = (*p_Var11)(bp,cmd,larg,pcVar9);
        piVar4 = (int *)cmd;
        piVar6 = (int *)larg;
      }
      else {
        piVar4 = (int *)&DAT_00000006;
        piVar6 = unaff_s5;
        pcVar9 = (char *)cmd;
        lVar1 = (*unaff_s1)(bp,6,(char *)unaff_s5,cmd,larg,1);
        unaff_s3 = larg;
        unaff_s4 = cmd;
        if (0 < lVar1) {
          lVar1 = (*bp->method->ctrl)(bp,cmd,larg,unaff_s5);
          piVar4 = (int *)0x86;
          piVar6 = unaff_s5;
          pcVar9 = (char *)cmd;
          lVar1 = (*unaff_s1)(bp,0x86,(char *)unaff_s5,cmd,larg,lVar1);
        }
      }
    }
  }
  if (local_24 == *(int **)puStack_5c) {
    return lVar1;
  }
  pcStack_4c = BIO_ptr_ctrl;
  piVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  lStack_70 = 0;
  piStack_6c = *(int **)PTR___stack_chk_guard_006a9ae8;
  lVar1 = 0;
  p_Stack_60 = unaff_s1;
  lStack_58 = unaff_s3;
  iStack_54 = unaff_s4;
  piStack_50 = unaff_s5;
  if (piVar3 == (int *)0x0) goto LAB_0051f354;
  if ((*piVar3 == 0) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(*piVar3 + 0x18), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    piVar8 = (int *)&DAT_00000079;
    pcVar9 = "bio_lib.c";
    piVar5 = (int *)0x67;
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
LAB_0051f3ac:
    piVar6 = piVar8;
    piVar4 = piVar5;
    lVar1 = 0;
  }
  else {
    pcVar10 = (code *)piVar3[1];
    piVar7 = &lStack_70;
    if (pcVar10 == (code *)0x0) {
      pcVar9 = (char *)&lStack_70;
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
    }
    else {
      piVar5 = (int *)&DAT_00000006;
      uVar14 = 1;
      piVar8 = piVar7;
      pcVar9 = (char *)piVar4;
      piVar13 = piVar6;
      iVar2 = (*pcVar10)();
      if (iVar2 < 1) goto LAB_0051f3ac;
      uVar14 = (**(code **)(*piVar3 + 0x18))(piVar3,piVar4,piVar6,piVar7,piVar13,uVar14);
      piVar5 = (int *)0x86;
      pcVar9 = (char *)piVar4;
      iVar2 = (*pcVar10)(piVar3,0x86,piVar7,piVar4,piVar6,uVar14);
      piVar4 = piVar5;
      piVar6 = piVar7;
    }
    lVar1 = 0;
    if (0 < iVar2) {
      lVar1 = lStack_70;
    }
  }
LAB_0051f354:
  if (piStack_6c == *(int **)puVar12) {
    return lVar1;
  }
  piVar3 = piStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piVar3 != (int *)0x0) {
    puVar12 = &_gp;
    if ((*piVar3 == 0) ||
       (UNRECOVERED_JUMPTABLE = *(code **)(*piVar3 + 0x18), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
      lVar1 = -2;
    }
    else {
      pcVar10 = (code *)piVar3[1];
      if (pcVar10 == (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0051f4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar1 = (*UNRECOVERED_JUMPTABLE)();
        return lVar1;
      }
      uVar14 = 1;
      piVar5 = piVar6;
      lVar1 = (*pcVar10)();
      if (0 < lVar1) {
        uVar14 = (**(code **)(*piVar3 + 0x18))(piVar3,piVar4,piVar6,pcVar9,piVar5,uVar14,puVar12);
        lVar1 = (*pcVar10)(piVar3,0x86,pcVar9,piVar4,piVar6,uVar14);
      }
    }
    return lVar1;
  }
  return 0;
}

