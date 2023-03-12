
X509_EXTENSION * X509V3_EXT_nconf(CONF *conf,X509V3_CTX *ctx,char *name,char *value)

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
  undefined4 local_24;
  
  bVar10 = 0;
  sVar1 = strlen(value);
  bVar9 = sVar1 == 8;
  if (sVar1 < 9) {
    local_24 = 0;
LAB_08169841:
    bVar9 = sVar1 == 3;
    if (sVar1 < 4) goto LAB_08169846;
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
      local_24 = 1;
      goto LAB_08169841;
    }
    local_24 = 0;
  }
  iVar4 = 4;
  pbVar5 = (byte *)value;
  pbVar8 = &DAT_0822ba1e;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pbVar5 == *pbVar8;
    pbVar5 = pbVar5 + (uint)bVar10 * -2 + 1;
    pbVar8 = pbVar8 + (uint)bVar10 * -2 + 1;
  } while (bVar9);
  if (bVar9) {
    pbVar5 = (byte *)value + 4;
LAB_081698a0:
    ppuVar2 = __ctype_b_loc();
    while ((*(byte *)((int)*ppuVar2 + (uint)*pbVar5 * 2 + 1) & 0x20) != 0) {
      pbVar5 = pbVar5 + 1;
    }
    pXVar3 = (X509_EXTENSION *)v3_generic_extension();
    return pXVar3;
  }
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
      goto LAB_081698a0;
    }
  }
LAB_08169846:
  OBJ_sn2nid(name);
  pXVar3 = (X509_EXTENSION *)do_ext_nconf(local_24,value);
  if (pXVar3 == (X509_EXTENSION *)0x0) {
    ERR_put_error(0x22,0x98,0x80,"v3_conf.c",0x5d);
    ERR_add_error_data(4,"name=",name,", value=",value);
  }
  return pXVar3;
}

