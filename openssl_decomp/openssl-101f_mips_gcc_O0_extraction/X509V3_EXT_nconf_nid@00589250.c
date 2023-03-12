
X509_EXTENSION * X509V3_EXT_nconf_nid(CONF *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  X509_EXTENSION *pXVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  uVar1 = (*(code *)PTR_strlen_006aab30)(value);
  if (uVar1 < 9) {
    uVar6 = 0;
LAB_00589318:
    if (uVar1 < 4) goto LAB_00589324;
  }
  else {
    iVar2 = (*(code *)PTR_strncmp_006aaa7c)(value,"critical,",9);
    if (iVar2 == 0) {
      piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
      pbVar8 = (byte *)(value + 9);
      do {
        value = (char *)pbVar8;
        pbVar8 = (byte *)value + 1;
      } while ((*(ushort *)(*piVar3 + (uint)(byte)*value * 2) & 0x20) != 0);
      uVar6 = 1;
      uVar1 = (*(code *)PTR_strlen_006aab30)(value);
      goto LAB_00589318;
    }
    uVar6 = 0;
  }
  iVar2 = (*(code *)PTR_strncmp_006aaa7c)(value,&DAT_0066df5c,4);
  if (iVar2 == 0) {
    pbVar8 = (byte *)value + 4;
    uVar7 = 1;
LAB_0058938c:
    piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
    do {
      pbVar9 = pbVar8;
      pbVar8 = pbVar9 + 1;
    } while ((*(ushort *)(*piVar3 + (uint)*pbVar9 * 2) & 0x20) != 0);
    uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(ext_nid);
    pXVar4 = (X509_EXTENSION *)v3_generic_extension(uVar5,pbVar9,uVar6,uVar7,ctx);
    return pXVar4;
  }
  if (uVar1 != 4) {
    iVar2 = (*(code *)PTR_strncmp_006aaa7c)(value,"ASN1:",5);
    if (iVar2 == 0) {
      pbVar8 = (byte *)value + 5;
      uVar7 = 2;
      goto LAB_0058938c;
    }
  }
LAB_00589324:
  pXVar4 = (X509_EXTENSION *)do_ext_nconf(conf,ctx,ext_nid,uVar6,value);
  return pXVar4;
}

