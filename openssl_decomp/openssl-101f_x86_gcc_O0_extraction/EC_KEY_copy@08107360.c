
EC_KEY * EC_KEY_copy(EC_KEY *dst,EC_KEY *src)

{
  undefined4 *puVar1;
  EC_METHOD *meth;
  EC_GROUP *pEVar2;
  int iVar3;
  EC_POINT *dst_00;
  BIGNUM *pBVar4;
  BIGNUM *a;
  
  if ((dst == (EC_KEY *)0x0) || (src == (EC_KEY *)0x0)) {
    ERR_put_error(0x10,0xb2,0x43,"ec_key.c",0x93);
  }
  else {
    if (*(EC_GROUP **)(src + 4) != (EC_GROUP *)0x0) {
      meth = EC_GROUP_method_of(*(EC_GROUP **)(src + 4));
      if (*(EC_GROUP **)(dst + 4) != (EC_GROUP *)0x0) {
        EC_GROUP_free(*(EC_GROUP **)(dst + 4));
      }
      pEVar2 = EC_GROUP_new(meth);
      *(EC_GROUP **)(dst + 4) = pEVar2;
      if (pEVar2 == (EC_GROUP *)0x0) {
        return (EC_KEY *)0x0;
      }
      iVar3 = EC_GROUP_copy(pEVar2,*(EC_GROUP **)(src + 4));
      if (iVar3 == 0) {
        return (EC_KEY *)0x0;
      }
      if ((*(int *)(src + 8) != 0) && (pEVar2 = *(EC_GROUP **)(src + 4), pEVar2 != (EC_GROUP *)0x0))
      {
        if (*(EC_POINT **)(dst + 8) != (EC_POINT *)0x0) {
          EC_POINT_free(*(EC_POINT **)(dst + 8));
          pEVar2 = *(EC_GROUP **)(src + 4);
        }
        dst_00 = EC_POINT_new(pEVar2);
        *(EC_POINT **)(dst + 8) = dst_00;
        if (dst_00 == (EC_POINT *)0x0) {
          return (EC_KEY *)0x0;
        }
        iVar3 = EC_POINT_copy(dst_00,*(EC_POINT **)(src + 8));
        if (iVar3 == 0) {
          return (EC_KEY *)0x0;
        }
      }
    }
    pBVar4 = *(BIGNUM **)(src + 0xc);
    if (pBVar4 != (BIGNUM *)0x0) {
      a = *(BIGNUM **)(dst + 0xc);
      if (a == (BIGNUM *)0x0) {
        a = BN_new();
        *(BIGNUM **)(dst + 0xc) = a;
        if (a == (BIGNUM *)0x0) {
          return (EC_KEY *)0x0;
        }
        pBVar4 = *(BIGNUM **)(src + 0xc);
      }
      pBVar4 = BN_copy(a,pBVar4);
      if (pBVar4 == (BIGNUM *)0x0) {
        return (EC_KEY *)0x0;
      }
    }
    EC_EX_DATA_free_all_data(dst + 0x20);
    puVar1 = *(undefined4 **)(src + 0x20);
    while( true ) {
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined4 *)(dst + 0x10) = *(undefined4 *)(src + 0x10);
        *(undefined4 *)(dst + 0x14) = *(undefined4 *)(src + 0x14);
        *(undefined4 *)dst = *(undefined4 *)src;
        *(undefined4 *)(dst + 0x1c) = *(undefined4 *)(src + 0x1c);
        return dst;
      }
      iVar3 = (*(code *)puVar1[2])(puVar1[1]);
      if ((iVar3 == 0) ||
         (iVar3 = EC_EX_DATA_set_data(dst + 0x20,iVar3,puVar1[2],puVar1[3],puVar1[4]), iVar3 == 0))
      break;
      puVar1 = (undefined4 *)*puVar1;
    }
  }
  return (EC_KEY *)0x0;
}

