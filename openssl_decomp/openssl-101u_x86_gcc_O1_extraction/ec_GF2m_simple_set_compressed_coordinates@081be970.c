
bool ec_GF2m_simple_set_compressed_coordinates
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  undefined4 extraout_EDX;
  BN_CTX *pBVar9;
  bool bVar10;
  int line;
  int *piVar11;
  
  ERR_clear_error();
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    if (param_5 == (BN_CTX *)0x0) {
      return false;
    }
    BN_CTX_start(param_5);
    pBVar1 = BN_CTX_get(param_5);
    pBVar2 = BN_CTX_get(param_5);
    pBVar3 = BN_CTX_get(param_5);
    pBVar4 = BN_CTX_get(param_5);
    if (pBVar4 != (BIGNUM *)0x0) {
      piVar11 = param_1 + 0x17;
      iVar5 = BN_GF2m_mod_arr(pBVar2,param_3,piVar11,extraout_EDX,pBVar3,pBVar1,piVar11);
      pBVar9 = param_5;
      if (iVar5 != 0) goto LAB_081be9f9;
    }
    bVar10 = false;
    BN_CTX_end(param_5);
    goto LAB_081bea5e;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  pBVar2 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  pBVar4 = BN_CTX_get(param_5);
  if (pBVar4 == (BIGNUM *)0x0) {
LAB_081bea78:
    BN_CTX_end(param_5);
    return false;
  }
  piVar11 = param_1 + 0x17;
  iVar5 = BN_GF2m_mod_arr(pBVar2,param_3,piVar11);
  if (iVar5 == 0) goto LAB_081bea78;
  pBVar9 = (BN_CTX *)0x0;
LAB_081be9f9:
  uVar8 = (uint)(param_4 != 0);
  if (pBVar2->top == 0) {
    iVar5 = BN_GF2m_mod_sqrt_arr(pBVar3,param_1 + 0x22,piVar11,param_5);
    pBVar1 = pBVar3;
    if (iVar5 != 0) {
LAB_081bea27:
      iVar5 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,pBVar2,pBVar1,param_5);
      bVar10 = iVar5 != 0;
      goto LAB_081bea4a;
    }
LAB_081beab1:
    bVar10 = false;
  }
  else {
    iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar2,param_5);
    if ((((iVar5 == 0) ||
         (iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar1,param_1 + 0x22,pBVar1,param_5),
         iVar5 == 0)) || (iVar5 = BN_GF2m_add(pBVar1,param_1 + 0x1d,pBVar1), iVar5 == 0)) ||
       (iVar5 = BN_GF2m_add(pBVar1,pBVar2,pBVar1), iVar5 == 0)) goto LAB_081beab1;
    iVar5 = BN_GF2m_mod_solve_quad_arr(pBVar4,pBVar1,piVar11,param_5);
    if (iVar5 == 0) {
      uVar7 = ERR_peek_last_error();
      if ((uVar7 >> 0x18 == 3) && ((uVar7 & 0xfff) == 0x74)) {
        ERR_clear_error();
        line = 0x8d;
        iVar5 = 0x6e;
      }
      else {
        line = 0x90;
        iVar5 = 3;
      }
      bVar10 = false;
      ERR_put_error(0x10,0xa4,iVar5,"ec2_oct.c",line);
    }
    else {
      if (pBVar4->top < 1) {
        uVar6 = 0;
      }
      else {
        uVar6 = *pBVar4->d & 1;
      }
      pBVar1 = pBVar3;
      iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar2,pBVar4,param_5);
      if (iVar5 == 0) goto LAB_081beab1;
      if ((uVar6 == uVar8) || (iVar5 = BN_GF2m_add(pBVar3,pBVar3,pBVar2,uVar8), iVar5 != 0))
      goto LAB_081bea27;
      bVar10 = false;
    }
  }
LAB_081bea4a:
  BN_CTX_end(param_5);
  param_5 = pBVar9;
  if (pBVar9 == (BN_CTX *)0x0) {
    return bVar10;
  }
LAB_081bea5e:
  BN_CTX_free(param_5);
  return bVar10;
}

