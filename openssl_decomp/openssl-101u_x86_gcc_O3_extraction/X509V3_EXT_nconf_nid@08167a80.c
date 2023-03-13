
X509_EXTENSION * X509V3_EXT_nconf_nid(CONF *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  size_t sVar1;
  ushort **ppuVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  char *pcVar7;
  byte *pbVar8;
  bool bVar9;
  byte bVar10;
  
  bVar10 = 0;
  sVar1 = strlen(value);
  bVar9 = sVar1 == 8;
  if (sVar1 < 9) {
LAB_08167af6:
    bVar9 = sVar1 == 3;
    if (sVar1 < 4) goto LAB_08167afb;
  }
  else {
    iVar4 = 9;
    pcVar6 = value;
    pcVar7 = "critical,";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    if (bVar9) {
      ppuVar2 = __ctype_b_loc();
      value = value + 9;
      while ((*(byte *)((int)*ppuVar2 + (uint)(byte)*value * 2 + 1) & 0x20) != 0) {
        value = (char *)((byte *)value + 1);
      }
      sVar1 = strlen(value);
      goto LAB_08167af6;
    }
    bVar9 = true;
  }
  iVar4 = 4;
  pbVar5 = (byte *)value;
  pbVar8 = &DAT_0822bebe;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pbVar5 == *pbVar8;
    pbVar5 = pbVar5 + (uint)bVar10 * -2 + 1;
    pbVar8 = pbVar8 + (uint)bVar10 * -2 + 1;
  } while (bVar9);
  if (!bVar9) {
    bVar9 = sVar1 == 4;
    if (!bVar9) {
      iVar4 = 5;
      pbVar5 = (byte *)value;
      pbVar8 = (byte *)"ASN1:";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pbVar5 == *pbVar8;
        pbVar5 = pbVar5 + (uint)bVar10 * -2 + 1;
        pbVar8 = pbVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        pbVar5 = (byte *)value + 5;
        goto LAB_08167b3a;
      }
    }
LAB_08167afb:
    pXVar3 = (X509_EXTENSION *)do_ext_nconf();
    return pXVar3;
  }
  pbVar5 = (byte *)value + 4;
LAB_08167b3a:
  ppuVar2 = __ctype_b_loc();
  while ((*(byte *)((int)*ppuVar2 + (uint)*pbVar5 * 2 + 1) & 0x20) != 0) {
    pbVar5 = pbVar5 + 1;
  }
  OBJ_nid2sn(ext_nid);
  pXVar3 = (X509_EXTENSION *)v3_generic_extension();
  return pXVar3;
}

