
undefined4
ec_GFp_simple_group_set_curve
          (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *r;
  BIGNUM *pBVar2;
  uint uVar3;
  undefined4 uVar4;
  BN_CTX *c;
  BIGNUM *a;
  
  iVar1 = BN_num_bits(param_2);
  if (((iVar1 < 3) || (param_2->top < 1)) || (-1 < (int)(*param_2->d << 0x1f))) {
    ERR_put_error(0x10,0xa6,0x67,"ecp_smpl.c",0xb9);
    return 0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  r = BN_CTX_get(param_5);
  if (r != (BIGNUM *)0x0) {
    a = (BIGNUM *)(param_1 + 0x12);
    pBVar2 = BN_copy(a,param_2);
    if (pBVar2 != (BIGNUM *)0x0) {
      BN_set_negative(a,0);
      iVar1 = BN_nnmod(r,param_3,param_2,param_5);
      if (iVar1 != 0) {
        if (*(code **)(*param_1 + 0x90) == (code *)0x0) {
          pBVar2 = BN_copy((BIGNUM *)(param_1 + 0x1d),r);
        }
        else {
          pBVar2 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,param_1 + 0x1d,r,param_5);
        }
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)(param_1 + 0x22);
          iVar1 = BN_nnmod(pBVar2,param_4,param_2,param_5);
          if (((iVar1 != 0) &&
              ((*(code **)(*param_1 + 0x90) == (code *)0x0 ||
               (iVar1 = (**(code **)(*param_1 + 0x90))(param_1,pBVar2,pBVar2,param_5), iVar1 != 0)))
              ) && (iVar1 = BN_add_word(r,3), iVar1 != 0)) {
            iVar1 = BN_cmp(r,a);
            uVar4 = 1;
            uVar3 = count_leading_zeroes(iVar1);
            param_1[0x27] = uVar3 >> 5;
            goto LAB_001233d8;
          }
        }
      }
    }
  }
  uVar4 = 0;
LAB_001233d8:
  BN_CTX_end(param_5);
  if (c == (BN_CTX *)0x0) {
    return uVar4;
  }
  BN_CTX_free(c);
  return uVar4;
}

