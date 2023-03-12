
char * BIO_ptr_ctrl(BIO *bp,int cmd,long larg)

{
  long lVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char **ppcVar6;
  char **ppcVar7;
  char *in_a3;
  _func_603 *p_Var8;
  code *pcVar9;
  _func_599 *p_Var10;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar11;
  undefined *puVar12;
  char *local_28;
  int *local_24;
  
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  local_28 = (char *)0x0;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pcVar2 = (char *)0x0;
  if (bp == (BIO *)0x0) goto LAB_0051f354;
  if ((bp->method == (BIO_METHOD *)0x0) || (p_Var10 = bp->method->ctrl, p_Var10 == (_func_599 *)0x0)
     ) {
    ppcVar7 = (char **)&DAT_00000079;
    in_a3 = "bio_lib.c";
    iVar4 = 0x67;
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
LAB_0051f3ac:
    larg = (long)ppcVar7;
    cmd = iVar4;
    pcVar2 = (char *)0x0;
  }
  else {
    p_Var8 = bp->callback;
    ppcVar6 = &local_28;
    if (p_Var8 == (_func_603 *)0x0) {
      in_a3 = (char *)&local_28;
      iVar4 = (*p_Var10)(bp,cmd,larg,in_a3);
    }
    else {
      iVar4 = 6;
      ppcVar7 = ppcVar6;
      in_a3 = (char *)cmd;
      lVar1 = (*p_Var8)(bp,6,(char *)ppcVar6,cmd,larg,1);
      if (lVar1 < 1) goto LAB_0051f3ac;
      lVar1 = (*bp->method->ctrl)(bp,cmd,larg,ppcVar6);
      iVar5 = 0x86;
      in_a3 = (char *)cmd;
      iVar4 = (*p_Var8)(bp,0x86,(char *)ppcVar6,cmd,larg,lVar1);
      cmd = iVar5;
      larg = (long)ppcVar6;
    }
    pcVar2 = (char *)0x0;
    if (0 < iVar4) {
      pcVar2 = local_28;
    }
  }
LAB_0051f354:
  if (local_24 == *(int **)puVar12) {
    return pcVar2;
  }
  piVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piVar3 != (int *)0x0) {
    puVar12 = &_gp;
    if ((*piVar3 == 0) ||
       (UNRECOVERED_JUMPTABLE = *(code **)(*piVar3 + 0x18), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
      pcVar2 = &SUB_fffffffe;
    }
    else {
      pcVar9 = (code *)piVar3[1];
      if (pcVar9 == (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0051f4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pcVar2 = (char *)(*UNRECOVERED_JUMPTABLE)();
        return pcVar2;
      }
      uVar11 = 1;
      ppcVar7 = (char **)larg;
      pcVar2 = (char *)(*pcVar9)();
      if (0 < (int)pcVar2) {
        uVar11 = (**(code **)(*piVar3 + 0x18))(piVar3,cmd,larg,in_a3,ppcVar7,uVar11,puVar12);
        pcVar2 = (char *)(*pcVar9)(piVar3,0x86,in_a3,cmd,larg,uVar11);
      }
    }
    return pcVar2;
  }
  return (char *)0x0;
}

