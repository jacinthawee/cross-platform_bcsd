
EC_POINT * EC_POINT_hex2point(EC_GROUP *param_1,char *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  int iVar1;
  int iVar2;
  uchar *to;
  EC_POINT *p;
  size_t len;
  EC_POINT *pEVar3;
  int in_GS_OFFSET;
  BIGNUM *local_24;
  int local_20;
  
  pEVar3 = (EC_POINT *)0x0;
  local_24 = (BIGNUM *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = BN_hex2bn(&local_24,param_2);
  a = local_24;
  if (iVar1 == 0) goto LAB_081048f2;
  iVar2 = BN_num_bits(local_24);
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  len = iVar1 >> 3;
  if (len == 0) {
LAB_0810495c:
    pEVar3 = (EC_POINT *)0x0;
  }
  else {
    to = (uchar *)CRYPTO_malloc(len,"ec_print.c",99);
    if (to == (uchar *)0x0) goto LAB_0810495c;
    iVar1 = BN_bn2bin(a,to);
    if (iVar1 == 0) {
LAB_08104960:
      CRYPTO_free(to);
    }
    else {
      if (param_3 == (EC_POINT *)0x0) {
        p = EC_POINT_new(param_1);
        if (p == (EC_POINT *)0x0) goto LAB_08104960;
        iVar1 = EC_POINT_oct2point(param_1,p,to,len,param_4);
        pEVar3 = p;
        if (iVar1 == 0) {
          EC_POINT_clear_free(p);
          goto LAB_08104950;
        }
      }
      else {
        iVar1 = EC_POINT_oct2point(param_1,param_3,to,len,param_4);
        pEVar3 = param_3;
        if (iVar1 == 0) {
LAB_08104950:
          CRYPTO_free(to);
          goto LAB_0810495c;
        }
      }
      CRYPTO_free(to);
    }
  }
  BN_clear_free(local_24);
LAB_081048f2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

