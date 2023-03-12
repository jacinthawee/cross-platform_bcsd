
uint ec_GFp_simple_oct2point
               (EC_GROUP *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  int iVar2;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *a;
  uint uVar5;
  uint y_bit;
  BN_CTX *c;
  
  if (param_4 == 0) {
    ERR_put_error(0x10,0x67,100,"ecp_oct.c",0x152);
    return 0;
  }
  bVar1 = *param_3;
  y_bit = bVar1 & 1;
  uVar5 = bVar1 & 0xfffffffe;
  if ((bVar1 & 0xf8) != 0) {
    iVar4 = 0x15b;
LAB_00104fb6:
    ERR_put_error(0x10,0x67,0x66,"ecp_oct.c",iVar4);
    return 0;
  }
  if ((bVar1 & 0xfa) == 0) {
    iVar4 = 0x15f;
    if ((bVar1 & 1) != 0) goto LAB_00104fb6;
    if ((bVar1 & 0xfe) == 0) {
      if (param_4 == 1) {
        uVar5 = EC_POINT_set_to_infinity(param_1,param_2);
        return uVar5;
      }
      ERR_put_error(0x10,0x67,0x66,"ecp_oct.c",0x165);
      return uVar5;
    }
  }
  a = (BIGNUM *)(param_1 + 0x48);
  iVar2 = BN_num_bits(a);
  iVar4 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar4 = iVar2 + 7;
  }
  iVar4 = iVar4 >> 3;
  iVar2 = iVar4;
  if (uVar5 != 2) {
    iVar2 = iVar4 * 2;
  }
  if (iVar2 + 1 != param_4) {
    iVar4 = 0x172;
    goto LAB_00104fb6;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  ret = BN_CTX_get(param_5);
  ret_00 = BN_CTX_get(param_5);
  if ((ret_00 != (BIGNUM *)0x0) &&
     (pBVar3 = BN_bin2bn(param_3 + 1,iVar4,ret), pBVar3 != (BIGNUM *)0x0)) {
    iVar2 = BN_ucmp(ret,a);
    if (-1 < iVar2) {
      iVar4 = 0x185;
      goto LAB_001050a8;
    }
    if (uVar5 == 2) {
      iVar4 = EC_POINT_set_compressed_coordinates_GFp(param_1,param_2,ret,y_bit,param_5);
    }
    else {
      pBVar3 = BN_bin2bn(param_3 + iVar4 + 1,iVar4,ret_00);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_001050d8;
      iVar4 = BN_ucmp(ret_00,a);
      if (-1 < iVar4) {
        iVar4 = 0x191;
LAB_001050a8:
        uVar5 = 0;
        ERR_put_error(0x10,0x67,0x66,"ecp_oct.c",iVar4);
        goto LAB_001050da;
      }
      if (uVar5 == 6) {
        if (ret_00->top < 1) {
          uVar5 = 0;
        }
        else {
          uVar5 = *ret_00->d & 1;
        }
        if (uVar5 != y_bit) {
          iVar4 = 0x196;
          goto LAB_001050a8;
        }
      }
      iVar4 = EC_POINT_set_affine_coordinates_GFp(param_1,param_2,ret,ret_00,param_5);
    }
    if (iVar4 != 0) {
      iVar4 = EC_POINT_is_on_curve(param_1,param_2,param_5);
      if (iVar4 < 1) {
        uVar5 = 0;
        ERR_put_error(0x10,0x67,0x6b,"ecp_oct.c",0x1a1);
      }
      else {
        uVar5 = 1;
      }
      goto LAB_001050da;
    }
  }
LAB_001050d8:
  uVar5 = 0;
LAB_001050da:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return uVar5;
}

