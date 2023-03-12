
uint ec_GFp_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  BIGNUM *x;
  BIGNUM *y;
  char *__s;
  uint uVar4;
  uint __n;
  BN_CTX *c;
  uint uVar5;
  uint uVar6;
  
  if ((param_3 != 4) && ((param_3 & 0xfffffffb) != 2)) {
    ERR_put_error(0x10,0x68,0x68,"ecp_oct.c",0xd4);
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
    ERR_put_error(0x10,0x68,100,"ecp_oct.c",0xdf);
    return 0;
  }
  iVar3 = BN_num_bits((BIGNUM *)(param_1 + 0x48));
  iVar2 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar2 = iVar3 + 7;
  }
  uVar4 = iVar2 >> 3;
  uVar5 = uVar4 * 2;
  if (param_3 == 2) {
    uVar5 = uVar4;
  }
  uVar5 = uVar5 + 1;
  if (param_4 == (char *)0x0) {
    return uVar5;
  }
  if (param_5 < uVar5) {
    ERR_put_error(0x10,0x68,100,"ecp_oct.c",0xf1);
    return 0;
  }
  c = (BN_CTX *)0x0;
  if ((param_6 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_6 = c, c == (BN_CTX *)0x0)) {
    return 0;
  }
  BN_CTX_start(param_6);
  x = BN_CTX_get(param_6);
  y = BN_CTX_get(param_6);
  if ((y == (BIGNUM *)0x0) ||
     (iVar2 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,param_6), iVar2 == 0))
  goto LAB_081bf56c;
  cVar1 = (char)param_3;
  if (((param_3 & 0xfffffffb) == 2) && ((0 < y->top && ((*(byte *)y->d & 1) != 0)))) {
    cVar1 = cVar1 + '\x01';
  }
  *param_4 = cVar1;
  iVar3 = BN_num_bits(x);
  iVar2 = iVar3 + 7;
  if (iVar3 + 7 < 0) {
    iVar2 = iVar3 + 0xe;
  }
  uVar6 = uVar4 - (iVar2 >> 3);
  if (uVar4 < uVar6) {
    iVar2 = 0x10e;
  }
  else {
    if (uVar6 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = uVar6 + 1;
      memset(param_4 + 1,0,uVar6);
    }
    iVar3 = BN_bn2bin(x,(uchar *)(param_4 + iVar2));
    uVar6 = iVar2 + iVar3;
    if (uVar6 == uVar4 + 1) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar3 = BN_num_bits(y);
        iVar2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar2 = iVar3 + 0xe;
        }
        __n = uVar4 - (iVar2 >> 3);
        if (uVar4 < __n) {
          iVar2 = 0x123;
          goto LAB_081bf559;
        }
        if (__n != 0) {
          __s = param_4 + uVar6;
          uVar6 = uVar6 + __n;
          memset(__s,0,__n);
        }
        iVar2 = BN_bn2bin(y,(uchar *)(param_4 + uVar6));
        uVar6 = uVar6 + iVar2;
      }
      if (uVar6 == uVar5) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
        }
        return uVar6;
      }
      iVar2 = 0x131;
    }
    else {
      iVar2 = 0x11a;
    }
  }
LAB_081bf559:
  ERR_put_error(0x10,0x68,0x44,"ecp_oct.c",iVar2);
LAB_081bf56c:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}

