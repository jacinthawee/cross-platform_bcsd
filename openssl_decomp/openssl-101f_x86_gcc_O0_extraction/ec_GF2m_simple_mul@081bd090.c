
uint ec_GF2m_simple_mul(int *param_1,EC_POINT *param_2,int param_3,uint param_4,EC_POINT **param_5,
                       int *param_6,BN_CTX *param_7)

{
  EC_POINT *pEVar1;
  int iVar2;
  uint uVar3;
  EC_POINT *point;
  EC_POINT *point_00;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((param_7 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_7 = c, c == (BN_CTX *)0x0)) {
    return 0;
  }
  if (((param_3 != 0 && 1 < param_4) || (2 < param_4)) ||
     ((param_4 == 0 && (iVar2 = EC_GROUP_have_precompute_mult((EC_GROUP *)param_1), iVar2 != 0)))) {
    uVar3 = ec_wNAF_mul(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    goto LAB_081bd103;
  }
  uVar3 = 0;
  point = EC_POINT_new((EC_GROUP *)param_1);
  if (point == (EC_POINT *)0x0) goto LAB_081bd103;
  point_00 = EC_POINT_new((EC_GROUP *)param_1);
  if (point_00 == (EC_POINT *)0x0) {
    EC_POINT_free(point);
    goto LAB_081bd103;
  }
  iVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,point_00);
  if (iVar2 == 0) {
LAB_081bd1ce:
    EC_POINT_free(point);
  }
  else {
    if (param_3 == 0) {
LAB_081bd281:
      if (param_4 == 0) {
LAB_081bd3bd:
        iVar2 = EC_POINT_copy(param_2,point_00);
        uVar3 = (uint)(iVar2 != 0);
        goto LAB_081bd1ce;
      }
      uVar3 = 0;
      iVar2 = *param_6;
      pEVar1 = *param_5;
      while (point != pEVar1) {
        if (((iVar2 == 0) || (*(int *)(iVar2 + 4) == 0)) ||
           ((pEVar1 == (EC_POINT *)0x0 ||
            (iVar2 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,pEVar1), iVar2 != 0)))) {
          iVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,point);
        }
        else {
          if (*(int *)(pEVar1 + 0x40) == 0) goto LAB_081bd1b0;
          iVar2 = ec_GF2m_montgomery_point_multiply_part_0(pEVar1,param_7);
        }
        if ((iVar2 == 0) ||
           (((*(int *)(param_6[uVar3] + 0xc) != 0 &&
             (iVar2 = (**(code **)(*param_1 + 0x60))(param_1,point,param_7), iVar2 == 0)) ||
            (iVar2 = (**(code **)(*param_1 + 0x58))(param_1,point_00,point_00,point,param_7),
            iVar2 == 0)))) goto LAB_081bd1cc;
        uVar3 = uVar3 + 1;
        if (param_4 == uVar3) goto LAB_081bd3bd;
        iVar2 = param_6[uVar3];
        pEVar1 = param_5[uVar3];
      }
LAB_081bd376:
      ERR_put_error(0x10,0xd0,0x70,"ec2_mult.c",0xe2);
    }
    else {
      pEVar1 = (EC_POINT *)param_1[1];
      if (point == pEVar1) goto LAB_081bd376;
      if (((*(int *)(param_3 + 4) == 0) || (pEVar1 == (EC_POINT *)0x0)) ||
         (iVar2 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,pEVar1), iVar2 != 0)) {
        iVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,point);
LAB_081bd238:
        if (((iVar2 == 0) ||
            ((*(int *)(param_3 + 0xc) != 0 &&
             (iVar2 = (**(code **)(*param_1 + 0x60))(param_1,point,param_7), iVar2 == 0)))) ||
           (iVar2 = (**(code **)(*param_1 + 0x58))(param_1,point_00,point_00,point,param_7),
           iVar2 == 0)) {
LAB_081bd1cc:
          uVar3 = 0;
          goto LAB_081bd1ce;
        }
        goto LAB_081bd281;
      }
      if (*(int *)(pEVar1 + 0x40) != 0) {
        iVar2 = ec_GF2m_montgomery_point_multiply_part_0(pEVar1,param_7);
        goto LAB_081bd238;
      }
    }
LAB_081bd1b0:
    uVar3 = 0;
    EC_POINT_free(point);
  }
  EC_POINT_free(point_00);
LAB_081bd103:
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return uVar3;
}

