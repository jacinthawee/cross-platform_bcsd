
EC_KEY * o2i_ECPublicKey(EC_KEY **key,uchar **in,long len)

{
  EC_KEY *pEVar1;
  byte *pbVar2;
  int iVar3;
  EC_POINT *p;
  EC_GROUP *group;
  int line;
  
  if (((key == (EC_KEY **)0x0) || (pEVar1 = *key, pEVar1 == (EC_KEY *)0x0)) ||
     (group = *(EC_GROUP **)(pEVar1 + 4), group == (EC_GROUP *)0x0)) {
    line = 0x56a;
    iVar3 = 0x43;
  }
  else {
    p = *(EC_POINT **)(pEVar1 + 8);
    if (p == (EC_POINT *)0x0) {
      p = EC_POINT_new(group);
      *(EC_POINT **)(pEVar1 + 8) = p;
      if (p == (EC_POINT *)0x0) {
        line = 0x571;
        iVar3 = 0x41;
        goto LAB_08106fcf;
      }
      group = *(EC_GROUP **)(pEVar1 + 4);
    }
    iVar3 = EC_POINT_oct2point(group,p,*in,len,(BN_CTX *)0x0);
    if (iVar3 != 0) {
      pbVar2 = *in;
      *(uint *)(pEVar1 + 0x14) = *pbVar2 & 0xfffffffe;
      *in = pbVar2 + len;
      return pEVar1;
    }
    line = 0x576;
    iVar3 = 0x10;
  }
LAB_08106fcf:
  ERR_put_error(0x10,0x98,iVar3,"ec_asn1.c",line);
  return (EC_KEY *)0x0;
}

