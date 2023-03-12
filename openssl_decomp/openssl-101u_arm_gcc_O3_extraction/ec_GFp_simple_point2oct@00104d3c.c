
uint ec_GFp_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  BIGNUM *x;
  BIGNUM *y;
  char *__s;
  char cVar4;
  uint uVar5;
  uint __n;
  BN_CTX *c;
  uint uVar6;
  
  if ((param_3 & 0xfffffffb) != 2 && param_3 != 4) {
    ERR_put_error(0x10,0x68,0x68,"ecp_oct.c",0xdf);
    return 0;
  }
  iVar2 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar2 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 != 0) {
      *param_4 = '\0';
      return 1;
    }
    ERR_put_error(0x10,0x68,100,"ecp_oct.c",0xe7);
    return 0;
  }
  iVar3 = BN_num_bits((BIGNUM *)(param_1 + 0x48));
  iVar2 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar2 = iVar3 + 7;
  }
  uVar1 = iVar2 >> 3;
  uVar6 = uVar1;
  if (param_3 != 2) {
    uVar6 = uVar1 * 2;
  }
  uVar6 = uVar6 + 1;
  if (param_4 == (char *)0x0) {
    return uVar6;
  }
  if (param_5 < uVar6) {
    ERR_put_error(0x10,0x68,100,"ecp_oct.c",0xf8);
    return 0;
  }
  if (param_6 == (BN_CTX *)0x0) {
    c = BN_CTX_new();
    param_6 = c;
    if (c == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    c = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_6);
  x = BN_CTX_get(param_6);
  y = BN_CTX_get(param_6);
  if ((y == (BIGNUM *)0x0) ||
     (iVar2 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,param_6), iVar2 == 0))
  goto LAB_00104eb4;
  cVar4 = (char)param_3;
  if (((param_3 & 0xfffffffb) == 2) && ((0 < y->top && ((int)(*y->d << 0x1f) < 0)))) {
    cVar4 = cVar4 + '\x01';
  }
  *param_4 = cVar4;
  iVar3 = BN_num_bits(x);
  iVar2 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar2 = iVar3 + 7;
  }
  uVar5 = uVar1 - (iVar2 >> 3);
  if (uVar1 < uVar5) {
    iVar2 = 0x116;
  }
  else {
    iVar2 = 1;
    if (uVar5 != 0) {
      iVar2 = uVar5 + 1;
      memset(param_4 + 1,0,uVar5);
    }
    iVar3 = BN_bn2bin(x,(uchar *)(param_4 + iVar2));
    uVar5 = uVar1 + 1;
    if (uVar5 == iVar3 + iVar2) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar3 = BN_num_bits(y);
        iVar2 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar2 = iVar3 + 7;
        }
        __n = uVar1 - (iVar2 >> 3);
        if (uVar1 < __n) {
          iVar2 = 0x128;
          goto LAB_00104ea4;
        }
        if (__n != 0) {
          __s = param_4 + uVar5;
          uVar5 = uVar5 + __n;
          memset(__s,0,__n);
        }
        iVar2 = BN_bn2bin(y,(uchar *)(param_4 + uVar5));
        uVar5 = uVar5 + iVar2;
      }
      if (uVar5 == uVar6) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
          return uVar5;
        }
        return uVar5;
      }
      iVar2 = 0x134;
    }
    else {
      iVar2 = 0x120;
    }
  }
LAB_00104ea4:
  ERR_put_error(0x10,0x68,0x44,"ecp_oct.c",iVar2);
LAB_00104eb4:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}

