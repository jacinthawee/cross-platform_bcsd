
X509_EXTENSION * X509V3_EXT_nconf(CONF *conf,X509V3_CTX *ctx,char *name,char *value)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  X509_EXTENSION *pXVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 uVar8;
  
  uVar1 = (*(code *)PTR_strlen_006a9a24)(value);
  if (uVar1 < 9) {
    uVar8 = 0;
LAB_00586354:
    if (uVar1 < 4) goto LAB_00586360;
  }
  else {
    iVar2 = (*(code *)PTR_strncmp_006a9970)(value,"critical,",9);
    if (iVar2 == 0) {
      piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
      pbVar6 = (byte *)(value + 9);
      do {
        value = (char *)pbVar6;
        pbVar6 = (byte *)value + 1;
      } while ((*(ushort *)(*piVar3 + (uint)(byte)*value * 2) & 0x20) != 0);
      uVar8 = 1;
      uVar1 = (*(code *)PTR_strlen_006a9a24)(value);
      goto LAB_00586354;
    }
    uVar8 = 0;
  }
  iVar2 = (*(code *)PTR_strncmp_006a9970)(value,&DAT_0066d64c,4);
  if (iVar2 == 0) {
    pbVar6 = (byte *)value + 4;
    uVar4 = 1;
LAB_005863dc:
    piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
    do {
      pbVar7 = pbVar6;
      pbVar6 = pbVar7 + 1;
    } while ((*(ushort *)(*piVar3 + (uint)*pbVar7 * 2) & 0x20) != 0);
    pXVar5 = (X509_EXTENSION *)v3_generic_extension(name,pbVar7,uVar8,uVar4,ctx);
    return pXVar5;
  }
  if (uVar1 != 4) {
    iVar2 = (*(code *)PTR_strncmp_006a9970)(value,"ASN1:",5);
    if (iVar2 == 0) {
      pbVar6 = (byte *)value + 5;
      uVar4 = 2;
      goto LAB_005863dc;
    }
  }
LAB_00586360:
  uVar4 = (*(code *)PTR_OBJ_sn2nid_006a71a4)(name);
  pXVar5 = (X509_EXTENSION *)do_ext_nconf(conf,ctx,uVar4,uVar8,value);
  if (pXVar5 == (X509_EXTENSION *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x98,0x80,"v3_conf.c",0x5f);
    (*(code *)PTR_ERR_add_error_data_006a813c)(4,"name=",name,", value=",value);
  }
  return pXVar5;
}

