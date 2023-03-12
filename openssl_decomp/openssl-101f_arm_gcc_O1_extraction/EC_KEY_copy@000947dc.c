
EC_KEY * EC_KEY_copy(EC_KEY *dst,EC_KEY *src)

{
  EC_METHOD *meth;
  EC_GROUP *pEVar1;
  int iVar2;
  EC_POINT *dst_00;
  BIGNUM *a;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  
  if (src == (EC_KEY *)0x0 || dst == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xb2,0x43,"ec_key.c",0x93);
  }
  else {
    if (*(EC_GROUP **)(src + 4) != (EC_GROUP *)0x0) {
      meth = EC_GROUP_method_of(*(EC_GROUP **)(src + 4));
      if (*(EC_GROUP **)(dst + 4) != (EC_GROUP *)0x0) {
        EC_GROUP_free(*(EC_GROUP **)(dst + 4));
      }
      pEVar1 = EC_GROUP_new(meth);
      *(EC_GROUP **)(dst + 4) = pEVar1;
      if (pEVar1 == (EC_GROUP *)0x0) {
        return (EC_KEY *)0x0;
      }
      iVar2 = EC_GROUP_copy(pEVar1,*(EC_GROUP **)(src + 4));
      if (iVar2 == 0) {
        return (EC_KEY *)0x0;
      }
    }
    if ((*(int *)(src + 8) != 0) && (pEVar1 = *(EC_GROUP **)(src + 4), pEVar1 != (EC_GROUP *)0x0)) {
      if (*(EC_POINT **)(dst + 8) != (EC_POINT *)0x0) {
        EC_POINT_free(*(EC_POINT **)(dst + 8));
        pEVar1 = *(EC_GROUP **)(src + 4);
      }
      dst_00 = EC_POINT_new(pEVar1);
      *(EC_POINT **)(dst + 8) = dst_00;
      if (dst_00 == (EC_POINT *)0x0) {
        return (EC_KEY *)0x0;
      }
      iVar2 = EC_POINT_copy(dst_00,*(EC_POINT **)(src + 8));
      if (iVar2 == 0) {
        return (EC_KEY *)0x0;
      }
    }
    pBVar3 = *(BIGNUM **)(src + 0xc);
    if (pBVar3 != (BIGNUM *)0x0) {
      a = *(BIGNUM **)(dst + 0xc);
      if (a == (BIGNUM *)0x0) {
        a = BN_new();
        *(BIGNUM **)(dst + 0xc) = a;
        if (a == (BIGNUM *)0x0) {
          return (EC_KEY *)0x0;
        }
        pBVar3 = *(BIGNUM **)(src + 0xc);
      }
      pBVar3 = BN_copy(a,pBVar3);
      if (pBVar3 == (BIGNUM *)0x0) {
        return (EC_KEY *)0x0;
      }
    }
    EC_EX_DATA_free_all_data(dst + 0x20);
    piVar7 = *(int **)(src + 0x20);
    while( true ) {
      if (piVar7 == (int *)0x0) {
        uVar4 = *(undefined4 *)(src + 0x14);
        uVar5 = *(undefined4 *)src;
        uVar6 = *(undefined4 *)(src + 0x1c);
        *(undefined4 *)(dst + 0x10) = *(undefined4 *)(src + 0x10);
        *(undefined4 *)(dst + 0x14) = uVar4;
        *(undefined4 *)dst = uVar5;
        *(undefined4 *)(dst + 0x1c) = uVar6;
        return dst;
      }
      iVar2 = (*(code *)piVar7[2])(piVar7[1]);
      if ((iVar2 == 0) ||
         (iVar2 = EC_EX_DATA_set_data(dst + 0x20,iVar2,piVar7[2],piVar7[3],piVar7[4]), iVar2 == 0))
      break;
      piVar7 = (int *)*piVar7;
    }
  }
  return (EC_KEY *)0x0;
}

