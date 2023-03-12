
X509_EXTENSION * X509V3_EXT_nconf(CONF *conf,X509V3_CTX *ctx,char *name,char *value)

{
  size_t sVar1;
  int iVar2;
  ushort **ppuVar3;
  X509_EXTENSION *pXVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  sVar1 = strlen(value);
  if (sVar1 < 9) {
    uVar7 = 0;
LAB_000d0238:
    if (sVar1 < 4) goto LAB_000d023c;
  }
  else {
    iVar2 = strncmp(value,"critical,",9);
    if (iVar2 == 0) {
      ppuVar3 = __ctype_b_loc();
      pbVar5 = (byte *)(value + 9);
      do {
        value = (char *)pbVar5;
        pbVar5 = (byte *)value + 1;
      } while ((int)((uint)(*ppuVar3)[(byte)*value] << 0x12) < 0);
      uVar7 = 1;
      sVar1 = strlen(value);
      goto LAB_000d0238;
    }
    uVar7 = 0;
  }
  iVar2 = strncmp(value,"DER:",4);
  if (iVar2 == 0) {
    pbVar5 = (byte *)value + 4;
    uVar8 = 1;
  }
  else {
    if ((sVar1 == 4) || (iVar2 = strncmp(value,"ASN1:",5), iVar2 != 0)) {
LAB_000d023c:
      iVar2 = OBJ_sn2nid(name);
      pXVar4 = (X509_EXTENSION *)do_ext_nconf(conf,ctx,iVar2,uVar7,value);
      if (pXVar4 == (X509_EXTENSION *)0x0) {
        ERR_put_error(0x22,0x98,0x80,"v3_conf.c",0x5d);
        ERR_add_error_data(4,"name=",name,", value=",value);
      }
      return pXVar4;
    }
    pbVar5 = (byte *)value + 5;
    uVar8 = 2;
  }
  ppuVar3 = __ctype_b_loc();
  do {
    pbVar6 = pbVar5;
    pbVar5 = pbVar6 + 1;
  } while ((int)((uint)(*ppuVar3)[*pbVar6] << 0x12) < 0);
  pXVar4 = (X509_EXTENSION *)v3_generic_extension(name,pbVar6,uVar7,uVar8,ctx);
  return pXVar4;
}

