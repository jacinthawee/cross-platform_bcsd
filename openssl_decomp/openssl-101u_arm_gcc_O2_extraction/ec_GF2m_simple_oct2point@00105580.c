
uint ec_GF2m_simple_oct2point
               (int *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  int iVar2;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  BN_CTX *c;
  
  if (param_4 == 0) {
    ERR_put_error(0x10,0xa0,100,"ec2_oct.c",0x135);
    return 0;
  }
  bVar1 = *param_3;
  uVar7 = bVar1 & 1;
  uVar6 = bVar1 & 0xfffffffe;
  if ((bVar1 & 0xf8) != 0) {
    iVar5 = 0x13e;
LAB_001055a6:
    ERR_put_error(0x10,0xa0,0x66,"ec2_oct.c",iVar5);
    return 0;
  }
  if ((bVar1 & 0xfa) == 0) {
    iVar5 = 0x142;
    if ((bVar1 & 1) != 0) goto LAB_001055a6;
    if ((bVar1 & 0xfe) == 0) {
      if (param_4 != 1) {
        ERR_put_error(0x10,0xa0,0x66,"ec2_oct.c",0x148);
        return uVar6;
      }
      uVar6 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
      return uVar6;
    }
  }
  iVar2 = EC_GROUP_get_degree((EC_GROUP *)param_1);
  iVar5 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar5 = iVar2 + 7;
  }
  iVar5 = iVar5 >> 3;
  iVar2 = iVar5;
  if (uVar6 != 2) {
    iVar2 = iVar5 * 2;
  }
  if (iVar2 + 1 != param_4) {
    iVar5 = 0x155;
    goto LAB_001055a6;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  ret = BN_CTX_get(param_5);
  ret_00 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  if ((pBVar3 != (BIGNUM *)0x0) &&
     (pBVar4 = BN_bin2bn(param_3 + 1,iVar5,ret), pBVar4 != (BIGNUM *)0x0)) {
    iVar2 = BN_ucmp(ret,(BIGNUM *)(param_1 + 0x12));
    if (-1 < iVar2) {
      iVar5 = 0x169;
LAB_0010569e:
      uVar6 = 0;
      ERR_put_error(0x10,0xa0,0x66,"ec2_oct.c",iVar5);
      goto LAB_001056ce;
    }
    if (uVar6 == 2) {
      iVar5 = EC_POINT_set_compressed_coordinates_GF2m(param_1,param_2,ret,uVar7,param_5);
    }
    else {
      pBVar4 = BN_bin2bn(param_3 + iVar5 + 1,iVar5,ret_00);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_001056cc;
      iVar5 = BN_ucmp(ret_00,(BIGNUM *)(param_1 + 0x12));
      if (-1 < iVar5) {
        iVar5 = 0x175;
        goto LAB_0010569e;
      }
      if (uVar6 == 6) {
        iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,ret_00,ret,param_5);
        if (iVar5 == 0) goto LAB_001056cc;
        if (pBVar3->top < 1) {
          uVar6 = 0;
        }
        else {
          uVar6 = *pBVar3->d & 1;
        }
        if (uVar6 != uVar7) {
          iVar5 = 0x17c;
          goto LAB_0010569e;
        }
      }
      iVar5 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,ret,ret_00,param_5);
    }
    if (iVar5 != 0) {
      iVar5 = EC_POINT_is_on_curve((EC_GROUP *)param_1,param_2,param_5);
      if (iVar5 < 1) {
        uVar6 = 0;
        ERR_put_error(0x10,0xa0,0x6b,"ec2_oct.c",0x187);
      }
      else {
        uVar6 = 1;
      }
      goto LAB_001056ce;
    }
  }
LAB_001056cc:
  uVar6 = 0;
LAB_001056ce:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return uVar6;
}

