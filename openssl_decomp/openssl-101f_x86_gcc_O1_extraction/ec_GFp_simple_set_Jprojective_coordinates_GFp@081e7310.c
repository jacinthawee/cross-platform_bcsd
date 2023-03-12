
undefined4
ec_GFp_simple_set_Jprojective_coordinates_GFp
          (int *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,BN_CTX *param_6)

{
  BIGNUM *pBVar1;
  code *pcVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((param_6 == (BN_CTX *)0x0) && (param_6 = BN_CTX_new(), c = param_6, param_6 == (BN_CTX *)0x0))
  {
    return 0;
  }
  if (param_3 == (BIGNUM *)0x0) {
LAB_081e7389:
    if (param_4 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)(param_2 + 0x18);
      iVar3 = BN_nnmod(pBVar1,param_4,(BIGNUM *)(param_1 + 0x12),param_6);
      if ((iVar3 == 0) ||
         ((*(code **)(*param_1 + 0x90) != (code *)0x0 &&
          (iVar3 = (**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_6), iVar3 == 0))))
      goto LAB_081e734b;
    }
    if (param_5 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)(param_2 + 0x2c);
      iVar3 = BN_nnmod(pBVar1,param_5,(BIGNUM *)(param_1 + 0x12),param_6);
      if (iVar3 == 0) goto LAB_081e734b;
      if (((*(int *)(param_2 + 0x30) == 1) && (**(int **)(param_2 + 0x2c) == 1)) &&
         (*(int *)(param_2 + 0x38) == 0)) {
        pcVar4 = *(code **)(*param_1 + 0x90);
        if (pcVar4 != (code *)0x0) {
          pcVar2 = *(code **)(*param_1 + 0x98);
          if (pcVar2 == (code *)0x0) {
            uVar5 = 1;
            goto LAB_081e7455;
          }
          iVar3 = (*pcVar2)(param_1,pBVar1,param_6);
          if (iVar3 == 0) goto LAB_081e734b;
        }
        uVar5 = 1;
      }
      else {
        uVar5 = 0;
        pcVar4 = *(code **)(*param_1 + 0x90);
        if (pcVar4 != (code *)0x0) {
LAB_081e7455:
          iVar3 = (*pcVar4)(param_1,pBVar1,pBVar1,param_6);
          if (iVar3 == 0) goto LAB_081e734b;
        }
      }
      *(undefined4 *)(param_2 + 0x40) = uVar5;
    }
    uVar5 = 1;
  }
  else {
    pBVar1 = (BIGNUM *)(param_2 + 4);
    iVar3 = BN_nnmod(pBVar1,param_3,(BIGNUM *)(param_1 + 0x12),param_6);
    if ((iVar3 != 0) &&
       ((*(code **)(*param_1 + 0x90) == (code *)0x0 ||
        (iVar3 = (**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_6), iVar3 != 0))))
    goto LAB_081e7389;
LAB_081e734b:
    uVar5 = 0;
  }
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return uVar5;
}

