
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  byte *unaff_r10;
  byte *pbVar6;
  
  pbVar9 = *pp;
  if (omax == 0) goto LAB_000bf764;
  bVar1 = *pbVar9;
  uVar10 = (uint)bVar1;
  uVar7 = uVar10 & 0x1f;
  if (uVar7 == 0x1f) {
    iVar11 = omax + -1;
    if (iVar11 != 0) {
      uVar7 = 0;
      pbVar8 = pbVar9 + 1;
      while( true ) {
        bVar2 = *pbVar8;
        if ((bVar2 & 0x80) == 0) break;
        iVar11 = iVar11 + -1;
        uVar7 = bVar2 & 0x7f | uVar7 << 7;
        if ((iVar11 == 0) || (pbVar8 = pbVar8 + 1, 0xffffff < (int)uVar7)) goto LAB_000bf764;
      }
      iVar11 = iVar11 + -1;
      if (iVar11 != 0) {
        unaff_r10 = pbVar8 + 1;
      }
      if (iVar11 != 0) {
        uVar7 = (uint)bVar2 | uVar7 << 7;
        goto LAB_000bf7c0;
      }
    }
    goto LAB_000bf764;
  }
  iVar11 = omax + -1;
  if (iVar11 == 0) goto LAB_000bf764;
  unaff_r10 = pbVar9 + 1;
LAB_000bf7c0:
  *ptag = uVar7;
  *pclass = uVar10 & 0xc0;
  if (iVar11 < 1) goto LAB_000bf764;
  uVar7 = (uint)*unaff_r10;
  uVar10 = uVar10 & 0x20;
  if (uVar7 == 0x80) {
    uVar4 = 0;
    *plength = 0;
    if ((bVar1 & 0x20) == 0) goto LAB_000bf764;
    pbVar8 = unaff_r10 + 1;
    uVar7 = 1;
    goto LAB_000bf7f4;
  }
  uVar4 = uVar7 & 0x7f;
  pbVar8 = unaff_r10 + 1;
  uVar3 = uVar4;
  if ((int)(uVar7 << 0x18) < 0) {
    uVar3 = (uint)(4 < uVar4);
    if (iVar11 <= (int)uVar4) {
      uVar3 = 1;
    }
    if (uVar3 != 0) goto LAB_000bf764;
    if ((*unaff_r10 & 0x7f) != 0) {
      pbVar6 = pbVar8;
      do {
        pbVar5 = pbVar6 + 1;
        uVar3 = (uint)*pbVar6 | uVar3 << 8;
        pbVar6 = pbVar5;
      } while (pbVar5 != unaff_r10 + uVar4 + 1);
      pbVar8 = pbVar8 + uVar4;
      goto LAB_000bf7ea;
    }
  }
  else {
LAB_000bf7ea:
    uVar4 = uVar3;
    if ((int)uVar3 < 0) {
LAB_000bf764:
      ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x9d);
      return 0x80;
    }
  }
  uVar7 = 0;
  *plength = uVar4;
LAB_000bf7f4:
  if ((int)(pbVar9 + (omax - (int)pbVar8)) < (int)uVar4) {
    ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x93);
    uVar10 = uVar10 | 0x80;
  }
  *pp = pbVar8;
  return uVar10 | uVar7;
}

