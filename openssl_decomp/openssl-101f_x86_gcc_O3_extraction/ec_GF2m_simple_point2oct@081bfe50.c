
uint ec_GF2m_simple_point2oct
               (int *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  int iVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  BN_CTX *c;
  uint local_28;
  
  if (((param_3 & 0xfffffffb) != 2) && (param_3 != 4)) {
    ERR_put_error(0x10,0xa1,0x68,"ec2_oct.c",0xb2);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar1 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 != 0) {
      *param_4 = '\0';
      return 1;
    }
    ERR_put_error(0x10,0xa1,100,"ec2_oct.c",0xbd);
    return 0;
  }
  iVar2 = EC_GROUP_get_degree((EC_GROUP *)param_1);
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  uVar5 = iVar1 >> 3;
  uVar6 = uVar5 * 2;
  if (param_3 == 2) {
    uVar6 = uVar5;
  }
  uVar6 = uVar6 + 1;
  if (param_4 == (char *)0x0) {
    return uVar6;
  }
  if (param_5 < uVar6) {
    ERR_put_error(0x10,0xa1,100,"ec2_oct.c",0xcf);
    return 0;
  }
  c = (BN_CTX *)0x0;
  if ((param_6 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_6 = c, c == (BN_CTX *)0x0)) {
    return 0;
  }
  BN_CTX_start(param_6);
  a = BN_CTX_get(param_6);
  a_00 = BN_CTX_get(param_6);
  pBVar3 = BN_CTX_get(param_6);
  if ((pBVar3 == (BIGNUM *)0x0) ||
     (iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,a,a_00,param_6), iVar1 == 0))
  goto LAB_081c0055;
  *param_4 = (char)param_3;
  if ((param_3 != 4) && (a->top != 0)) {
    iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,a_00,a,param_6);
    if (iVar1 == 0) goto LAB_081c0055;
    if ((0 < pBVar3->top) && ((*(byte *)pBVar3->d & 1) != 0)) {
      *param_4 = *param_4 + '\x01';
    }
  }
  iVar2 = BN_num_bits(a);
  iVar1 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar1 = iVar2 + 0xe;
  }
  uVar4 = uVar5 - (iVar1 >> 3);
  if (uVar5 < uVar4) {
    iVar1 = 0xef;
  }
  else {
    if (uVar4 == 0) {
      iVar1 = 1;
    }
    else {
      memset(param_4 + 1,0,uVar4);
      iVar1 = uVar4 + 1;
    }
    iVar2 = BN_bn2bin(a,(uchar *)(param_4 + iVar1));
    local_28 = iVar2 + iVar1;
    if (local_28 == uVar5 + 1) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar2 = BN_num_bits(a_00);
        iVar1 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar1 = iVar2 + 0xe;
        }
        uVar4 = uVar5 - (iVar1 >> 3);
        if (uVar5 < uVar4) {
          iVar1 = 0x104;
          goto LAB_081c003f;
        }
        if (uVar4 != 0) {
          memset(param_4 + local_28,0,uVar4);
          local_28 = local_28 + uVar4;
        }
        iVar1 = BN_bn2bin(a_00,(uchar *)(param_4 + local_28));
        local_28 = local_28 + iVar1;
      }
      if (local_28 == uVar6) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
        }
        return local_28;
      }
      iVar1 = 0x112;
    }
    else {
      iVar1 = 0xfb;
    }
  }
LAB_081c003f:
  ERR_put_error(0x10,0xa1,0x44,"ec2_oct.c",iVar1);
LAB_081c0055:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}
