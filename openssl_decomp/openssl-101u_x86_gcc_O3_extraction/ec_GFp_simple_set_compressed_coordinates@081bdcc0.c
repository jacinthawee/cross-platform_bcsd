
bool ec_GFp_simple_set_compressed_coordinates
               (int *param_1,EC_POINT *param_2,BIGNUM *param_3,int param_4,BN_CTX *param_5)

{
  code *pcVar1;
  bool bVar2;
  BIGNUM *ret;
  int iVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  ulong uVar6;
  BIGNUM *m;
  BN_CTX *pBVar7;
  bool bVar8;
  int line;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24;
  
  ERR_clear_error();
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    if (param_5 == (BN_CTX *)0x0) {
      return false;
    }
    BN_CTX_start(param_5);
    local_24 = BN_CTX_get(param_5);
    local_28 = BN_CTX_get(param_5);
    local_2c = BN_CTX_get(param_5);
    ret = BN_CTX_get(param_5);
    if ((ret == (BIGNUM *)0x0) ||
       (iVar3 = BN_nnmod(local_2c,param_3,(BIGNUM *)(param_1 + 0x12),param_5), pBVar7 = param_5,
       iVar3 == 0)) {
      bVar8 = false;
      BN_CTX_end(param_5);
      goto LAB_081bdd88;
    }
  }
  else {
    BN_CTX_start(param_5);
    local_24 = BN_CTX_get(param_5);
    local_28 = BN_CTX_get(param_5);
    local_2c = BN_CTX_get(param_5);
    ret = BN_CTX_get(param_5);
    if ((ret == (BIGNUM *)0x0) ||
       (iVar3 = BN_nnmod(local_2c,param_3,(BIGNUM *)(param_1 + 0x12),param_5), iVar3 == 0)) {
      BN_CTX_end(param_5);
      return false;
    }
    pBVar7 = (BN_CTX *)0x0;
  }
  bVar8 = param_4 != 0;
  m = (BIGNUM *)(param_1 + 0x12);
  if (*(int *)(*param_1 + 0x94) == 0) {
    iVar3 = (**(code **)(*param_1 + 0x88))(param_1,local_28,param_3,param_5);
    if ((iVar3 != 0) &&
       (iVar3 = (**(code **)(*param_1 + 0x84))(param_1,local_24,local_28,param_3,param_5),
       iVar3 != 0)) goto LAB_081bdddd;
LAB_081bdd72:
    bVar8 = false;
  }
  else {
    iVar3 = BN_mod_sqr(local_28,param_3,m,param_5);
    if ((iVar3 == 0) || (iVar3 = BN_mod_mul(local_24,local_28,param_3,m,param_5), iVar3 == 0))
    goto LAB_081bdd72;
LAB_081bdddd:
    if (param_1[0x27] == 0) {
      pcVar1 = *(code **)(*param_1 + 0x94);
      if (pcVar1 == (code *)0x0) {
        iVar3 = (**(code **)(*param_1 + 0x84))(param_1,local_28,param_1 + 0x1d,local_2c,param_5);
      }
      else {
        iVar3 = (*pcVar1)(param_1,local_28,param_1 + 0x1d,param_5);
        if (iVar3 == 0) goto LAB_081bdd72;
        iVar3 = BN_mod_mul(local_28,local_28,local_2c,m,param_5);
      }
      if ((iVar3 != 0) && (iVar3 = BN_mod_add_quick(local_24,local_24,local_28,m), iVar3 != 0))
      goto LAB_081bde57;
      goto LAB_081bdd72;
    }
    iVar3 = BN_mod_lshift1_quick(local_28,local_2c,m);
    if ((iVar3 == 0) ||
       ((iVar3 = BN_mod_add_quick(local_28,local_28,local_2c,m), iVar3 == 0 ||
        (iVar3 = BN_mod_sub_quick(local_24,local_24,local_28,m), iVar3 == 0)))) goto LAB_081bdd72;
LAB_081bde57:
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      local_28 = (BIGNUM *)(param_1 + 0x22);
    }
    else {
      iVar3 = (**(code **)(*param_1 + 0x94))(param_1,local_28,param_1 + 0x22,param_5);
      if (iVar3 == 0) goto LAB_081bdd72;
    }
    iVar3 = BN_mod_add_quick(local_24,local_24,local_28,m);
    if (iVar3 == 0) goto LAB_081bdd72;
    pBVar4 = BN_mod_sqrt(ret,local_24,m,param_5);
    if (pBVar4 == (BIGNUM *)0x0) {
      uVar6 = ERR_peek_last_error();
      if ((uVar6 >> 0x18 == 3) && ((uVar6 & 0xfff) == 0x6f)) {
        ERR_clear_error();
        line = 0xa3;
        iVar3 = 0x6e;
      }
      else {
        line = 0xa6;
        iVar3 = 3;
      }
LAB_081bdf18:
      ERR_put_error(0x10,0xa9,iVar3,"ecp_oct.c",line);
      goto LAB_081bdd72;
    }
    if (ret->top < 1) {
      if (bVar8) {
        if (ret->top != 0) goto LAB_081bdedf;
        iVar3 = BN_kronecker(local_2c,m,param_5);
        if (iVar3 == -2) goto LAB_081bdd72;
        if (iVar3 == 1) {
          line = 0xb4;
          iVar3 = 0x6d;
        }
        else {
          line = 0xba;
          iVar3 = 0x6e;
        }
        goto LAB_081bdf18;
      }
LAB_081bdefd:
      bVar2 = false;
LAB_081bdeff:
      if (bVar2 != bVar8) {
        line = 0xc2;
        iVar3 = 0x44;
        goto LAB_081bdf18;
      }
    }
    else {
      puVar5 = ret->d;
      if ((*(byte *)puVar5 & 1) == 0) {
        if (bVar8) goto LAB_081bdedf;
LAB_081bdfe6:
        if ((*(byte *)puVar5 & 1) == 0) goto LAB_081bdefd;
        bVar2 = true;
        goto LAB_081bdeff;
      }
      if (!bVar8) {
LAB_081bdedf:
        iVar3 = BN_usub(ret,m,ret);
        if (iVar3 == 0) goto LAB_081bdd72;
        if (ret->top < 1) goto LAB_081bdefd;
        puVar5 = ret->d;
        goto LAB_081bdfe6;
      }
    }
    iVar3 = EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)param_1,param_2,local_2c,ret,param_5);
    bVar8 = iVar3 != 0;
  }
  BN_CTX_end(param_5);
  param_5 = pBVar7;
  if (pBVar7 == (BN_CTX *)0x0) {
    return bVar8;
  }
LAB_081bdd88:
  BN_CTX_free(param_5);
  return bVar8;
}

