
EC_KEY * o2i_ECPublicKey(EC_KEY **key,uchar **in,long len)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  EC_POINT *p;
  undefined4 uVar4;
  EC_KEY *pEVar5;
  
  if (((key == (EC_KEY **)0x0) || (pEVar5 = *key, pEVar5 == (EC_KEY *)0x0)) ||
     (group = *(EC_GROUP **)(pEVar5 + 4), group == (EC_GROUP *)0x0)) {
    uVar4 = 0x43;
    uVar3 = 0x56a;
  }
  else {
    p = *(EC_POINT **)(pEVar5 + 8);
    if (p == (EC_POINT *)0x0) {
      p = EC_POINT_new(group);
      *(EC_POINT **)(pEVar5 + 8) = p;
      if (p == (EC_POINT *)0x0) {
        uVar4 = 0x41;
        uVar3 = 0x571;
        goto LAB_0050ae48;
      }
      group = *(EC_GROUP **)(pEVar5 + 4);
    }
    iVar1 = EC_POINT_oct2point(group,p,*in,len,(BN_CTX *)0x0);
    if (iVar1 != 0) {
      pbVar2 = *in;
      *(uint *)(pEVar5 + 0x14) = *pbVar2 & 0xfe;
      *in = pbVar2 + len;
      return pEVar5;
    }
    uVar4 = 0x10;
    uVar3 = 0x576;
  }
LAB_0050ae48:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x98,uVar4,"ec_asn1.c",uVar3);
  return (EC_KEY *)0x0;
}

