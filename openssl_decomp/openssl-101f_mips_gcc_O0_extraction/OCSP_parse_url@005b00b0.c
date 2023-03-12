
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar7;
  undefined *puVar5;
  char *pcVar6;
  undefined4 uVar8;
  
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  puVar5 = PTR_BUF_strdup_006a80dc;
  *ppath = (char *)0x0;
  iVar1 = (*(code *)puVar5)();
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x72,0x41,"ocsp_lib.c",0xfa);
    goto LAB_005b01b4;
  }
  puVar2 = (undefined *)(*(code *)PTR_strchr_006aab34)(iVar1,0x3a);
  puVar5 = PTR_strcmp_006aac20;
  if (puVar2 == (undefined *)0x0) {
LAB_005b0180:
    uVar8 = 0x79;
    uVar4 = 0xfe;
  }
  else {
    *puVar2 = 0;
    iVar3 = (*(code *)puVar5)(iVar1,&DAT_00668330);
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_strcmp_006aac20)(iVar1,"https");
      if (iVar3 == 0) {
        *pssl = 1;
        cVar7 = puVar2[1];
        if (cVar7 == '/') goto LAB_005b0238;
      }
      goto LAB_005b0180;
    }
    *pssl = 0;
    cVar7 = puVar2[1];
    if (cVar7 != '/') goto LAB_005b0180;
LAB_005b0238:
    if (puVar2[2] != cVar7) goto LAB_005b0180;
    puVar2 = puVar2 + 3;
    puVar5 = (undefined *)(*(code *)PTR_strchr_006aab34)(puVar2,0x2f);
    if (puVar5 == (undefined *)0x0) {
      pcVar6 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(&DAT_0063ba98);
      *ppath = pcVar6;
    }
    else {
      pcVar6 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(puVar5);
      *ppath = pcVar6;
      *puVar5 = 0;
      pcVar6 = *ppath;
    }
    if (pcVar6 != (char *)0x0) {
      puVar5 = (undefined *)(*(code *)PTR_strchr_006aab34)(puVar2,0x3a);
      if (puVar5 == (undefined *)0x0) {
        if (*pssl == 0) {
          pcVar6 = "80";
        }
        else {
          pcVar6 = "443";
        }
      }
      else {
        pcVar6 = puVar5 + 1;
        *puVar5 = 0;
      }
      pcVar6 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(pcVar6);
      *pport = pcVar6;
      if (pcVar6 != (char *)0x0) {
        pcVar6 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(puVar2);
        *phost = pcVar6;
        if (pcVar6 != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
          return 1;
        }
      }
    }
    uVar8 = 0x41;
    uVar4 = 0xfa;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x72,uVar8,"ocsp_lib.c",uVar4);
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
LAB_005b01b4:
  if (*ppath != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (*pport != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (*phost != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    return 0;
  }
  return 0;
}

