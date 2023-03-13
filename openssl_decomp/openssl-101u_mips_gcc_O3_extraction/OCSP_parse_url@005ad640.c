
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
  char *pcVar9;
  undefined *puVar10;
  
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  puVar5 = PTR_BUF_strdup_006a6fdc;
  *ppath = (char *)0x0;
  iVar1 = (*(code *)puVar5)();
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x72,0x41,"ocsp_lib.c",0x109);
    goto LAB_005ad750;
  }
  puVar2 = (undefined *)(*(code *)PTR_strchr_006a9a28)(iVar1,0x3a);
  puVar5 = PTR_strcmp_006a9b18;
  if (puVar2 == (undefined *)0x0) {
LAB_005ad71c:
    uVar8 = 0x79;
    uVar4 = 0x10d;
  }
  else {
    *puVar2 = 0;
    iVar3 = (*(code *)puVar5)(iVar1,&DAT_00667870);
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(iVar1,"https");
      if (iVar3 == 0) {
        *pssl = 1;
        cVar7 = puVar2[1];
        pcVar9 = "443";
        if (cVar7 == '/') goto LAB_005ad7e0;
      }
      goto LAB_005ad71c;
    }
    *pssl = 0;
    cVar7 = puVar2[1];
    pcVar9 = "80";
    if (cVar7 != '/') goto LAB_005ad71c;
LAB_005ad7e0:
    if (puVar2[2] != cVar7) goto LAB_005ad71c;
    puVar10 = puVar2 + 3;
    puVar5 = (undefined *)(*(code *)PTR_strchr_006a9a28)(puVar10,0x2f);
    if (puVar5 == (undefined *)0x0) {
      pcVar6 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(&DAT_0063b2b4);
      *ppath = pcVar6;
    }
    else {
      pcVar6 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(puVar5);
      *ppath = pcVar6;
      *puVar5 = 0;
      pcVar6 = *ppath;
    }
    if (pcVar6 != (char *)0x0) {
      puVar5 = puVar10;
      if (puVar2[3] == '[') {
        puVar10 = puVar2 + 4;
        puVar5 = (undefined *)(*(code *)PTR_strchr_006a9a28)(puVar10,0x5d);
        if (puVar5 == (undefined *)0x0) goto LAB_005ad71c;
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      puVar5 = (undefined *)(*(code *)PTR_strchr_006a9a28)(puVar5,0x3a);
      if (puVar5 != (undefined *)0x0) {
        pcVar9 = puVar5 + 1;
        *puVar5 = 0;
      }
      pcVar9 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(pcVar9);
      *pport = pcVar9;
      if (pcVar9 != (char *)0x0) {
        pcVar9 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(puVar10);
        *phost = pcVar9;
        if (pcVar9 != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
          return 1;
        }
      }
    }
    uVar8 = 0x41;
    uVar4 = 0x109;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x72,uVar8,"ocsp_lib.c",uVar4);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
LAB_005ad750:
  if (*ppath != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (*pport != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (*phost != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    return 0;
  }
  return 0;
}

