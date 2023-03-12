
undefined4
ec_GFp_simple_set_Jprojective_coordinates_GFp
          (int *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,BN_CTX *param_6)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  BN_CTX *c;
  BIGNUM *pBVar4;
  code *pcVar5;
  code *pcVar6;
  
  c = (BN_CTX *)0x0;
  if ((param_6 == (BN_CTX *)0x0) && (param_6 = BN_CTX_new(), c = param_6, param_6 == (BN_CTX *)0x0))
  {
    return 0;
  }
  if (param_3 == (BIGNUM *)0x0) {
LAB_00122a86:
    if (param_4 != (BIGNUM *)0x0) {
      pBVar4 = (BIGNUM *)(param_2 + 0x18);
      iVar1 = BN_nnmod(pBVar4,param_4,(BIGNUM *)(param_1 + 0x12),param_6);
      if ((iVar1 == 0) ||
         ((*(code **)(*param_1 + 0x90) != (code *)0x0 &&
          (iVar1 = (**(code **)(*param_1 + 0x90))(param_1,pBVar4,pBVar4,param_6), iVar1 == 0))))
      goto LAB_00122a72;
    }
    if (param_5 == (BIGNUM *)0x0) {
      uVar3 = 1;
      goto LAB_00122a74;
    }
    pBVar4 = (BIGNUM *)(param_2 + 0x2c);
    iVar1 = BN_nnmod(pBVar4,param_5,(BIGNUM *)(param_1 + 0x12),param_6);
    if (iVar1 != 0) {
      if (((*(int *)(param_2 + 0x30) == 1) &&
          (pcVar5 = **(code ***)(param_2 + 0x2c), pcVar5 == (code *)0x1)) &&
         (*(int *)(param_2 + 0x38) == 0)) {
        pcVar6 = *(code **)(*param_1 + 0x90);
        if (pcVar6 != (code *)0x0) {
          pcVar2 = *(code **)(*param_1 + 0x98);
          if (pcVar2 == (code *)0x0) goto LAB_00122b46;
          iVar1 = (*pcVar2)(param_1,pBVar4,param_6);
          if (iVar1 == 0) goto LAB_00122a72;
        }
        pcVar5 = (code *)0x1;
      }
      else {
        pcVar6 = *(code **)(*param_1 + 0x90);
        pcVar5 = pcVar6;
        if (pcVar6 != (code *)0x0) {
          pcVar5 = (code *)0x0;
LAB_00122b46:
          iVar1 = (*pcVar6)(param_1,pBVar4,pBVar4,param_6);
          if (iVar1 == 0) goto LAB_00122a72;
        }
      }
      uVar3 = 1;
      *(code **)(param_2 + 0x40) = pcVar5;
      goto LAB_00122a74;
    }
  }
  else {
    pBVar4 = (BIGNUM *)(param_2 + 4);
    iVar1 = BN_nnmod(pBVar4,param_3,(BIGNUM *)(param_1 + 0x12),param_6);
    if ((iVar1 != 0) &&
       ((*(code **)(*param_1 + 0x90) == (code *)0x0 ||
        (iVar1 = (**(code **)(*param_1 + 0x90))(param_1,pBVar4,pBVar4,param_6), iVar1 != 0))))
    goto LAB_00122a86;
  }
LAB_00122a72:
  uVar3 = 0;
LAB_00122a74:
  if (c == (BN_CTX *)0x0) {
    return uVar3;
  }
  BN_CTX_free(c);
  return uVar3;
}

