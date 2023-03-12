
undefined4 mime_hdr_addparam_isra_1(undefined4 *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  char *pcVar2;
  int *piVar3;
  int *piVar4;
  char **ppcVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_2 == 0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(param_2);
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
    uVar6 = (uint)*pcVar2;
    if (uVar6 != 0) {
      piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
      pcVar7 = pcVar2;
      do {
        if ((*(ushort *)(*piVar3 + (uVar6 & 0xff) * 2) & 1) != 0) {
          piVar4 = (int *)(*(code *)PTR___ctype_tolower_loc_006aaa50)();
          *pcVar7 = (char)*(undefined4 *)(*piVar4 + (uVar6 & 0xff) * 4);
        }
        pcVar7 = pcVar7 + 1;
        uVar6 = (uint)*pcVar7;
      } while (uVar6 != 0);
    }
  }
  if (param_3 == 0) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(param_3);
    if (pcVar7 == (char *)0x0) {
      return 0;
    }
  }
  ppcVar5 = (char **)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"asn_mime.c",0x356);
  puVar1 = PTR_sk_push_006a80a8;
  if (ppcVar5 == (char **)0x0) {
    return 0;
  }
  *ppcVar5 = pcVar2;
  ppcVar5[1] = pcVar7;
  (*(code *)puVar1)(*param_1,ppcVar5);
  return 1;
}

