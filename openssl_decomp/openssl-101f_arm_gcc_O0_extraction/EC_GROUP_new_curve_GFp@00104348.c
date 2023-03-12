
EC_GROUP * EC_GROUP_new_curve_GFp(BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  EC_METHOD *pEVar1;
  EC_GROUP *group;
  int iVar2;
  ulong uVar3;
  
  pEVar1 = EC_GFp_mont_method();
  group = EC_GROUP_new(pEVar1);
  if (group != (EC_GROUP *)0x0) {
    iVar2 = EC_GROUP_set_curve_GFp(group,p,a,b,ctx);
    if (iVar2 != 0) {
      return group;
    }
    uVar3 = ERR_peek_last_error();
    if ((uVar3 >> 0x18 == 0x10) && ((uVar3 & 0xfff) - 0x87 < 2)) {
      ERR_clear_error();
      EC_GROUP_clear_free(group);
      pEVar1 = EC_GFp_mont_method();
      group = EC_GROUP_new(pEVar1);
      if (group == (EC_GROUP *)0x0) {
        return (EC_GROUP *)0x0;
      }
      iVar2 = EC_GROUP_set_curve_GFp(group,p,a,b,ctx);
      if (iVar2 != 0) {
        return group;
      }
    }
    EC_GROUP_clear_free(group);
  }
  return (EC_GROUP *)0x0;
}

