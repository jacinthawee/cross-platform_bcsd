
char ** multi_split(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char **ppcVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  char cVar15;
  uint uVar14;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  char acStack_42d [1025];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  pcVar16 = acStack_42d + 1;
  pcVar18 = (char *)0x0;
  bVar1 = true;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar5 = (*(code *)PTR_strlen_006aab30)(param_2);
  uVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
  *param_3 = uVar6;
  cVar15 = '\0';
  bVar3 = false;
LAB_0060d2b0:
  pcVar17 = pcVar16;
  iVar7 = (*(code *)PTR_BIO_gets_006a85d0)(param_1,pcVar16,0x400);
  bVar2 = bVar3;
  do {
    if (iVar7 < 1) {
      ppcVar9 = (char **)0x0;
LAB_0060d358:
      if (local_2c == *(int *)puVar4) {
        return ppcVar9;
      }
      iVar5 = local_2c;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      if (iVar5 == 0) {
        pcVar18 = (char *)0x0;
      }
      else {
        pcVar18 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)();
        if (pcVar18 == (char *)0x0) {
          return (char **)0x0;
        }
        uVar14 = (uint)*pcVar18;
        if (uVar14 != 0) {
          piVar12 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
          pcVar16 = pcVar18;
          do {
            if ((*(ushort *)(*piVar12 + (uVar14 & 0xff) * 2) & 1) != 0) {
              piVar13 = (int *)(*(code *)PTR___ctype_tolower_loc_006aaa50)();
              *pcVar16 = (char)*(undefined4 *)(*piVar13 + (uVar14 & 0xff) * 4);
            }
            pcVar16 = pcVar16 + 1;
            uVar14 = (uint)*pcVar16;
          } while (uVar14 != 0);
        }
      }
      if (pcVar17 == (char *)0x0) {
        pcVar16 = (char *)0x0;
      }
      else {
        pcVar16 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(pcVar17);
        if (pcVar16 == (char *)0x0) {
          return (char **)0x0;
        }
        uVar14 = (uint)*pcVar16;
        if (uVar14 != 0) {
          piVar12 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
          pcVar17 = pcVar16;
          do {
            if ((*(ushort *)(*piVar12 + (uVar14 & 0xff) * 2) & 1) != 0) {
              piVar13 = (int *)(*(code *)PTR___ctype_tolower_loc_006aaa50)();
              *pcVar17 = (char)*(undefined4 *)(*piVar13 + (uVar14 & 0xff) * 4);
            }
            pcVar17 = pcVar17 + 1;
            uVar14 = (uint)*pcVar17;
          } while (uVar14 != 0);
        }
      }
      ppcVar9 = (char **)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xc,"asn_mime.c",0x339);
      puVar4 = PTR_sk_new_006a91b4;
      if (ppcVar9 != (char **)0x0) {
        *ppcVar9 = pcVar18;
        ppcVar9[1] = pcVar16;
        pcVar18 = (char *)(*(code *)puVar4)(mime_param_cmp);
        ppcVar9[2] = pcVar18;
        if (pcVar18 != (char *)0x0) {
          return ppcVar9;
        }
      }
      return (char **)0x0;
    }
    iVar11 = iVar5;
    if (iVar5 == -1) {
      iVar11 = (*(code *)PTR_strlen_006aab30)(param_2);
    }
    bVar3 = bVar2;
    if (((iVar11 + 1 < iVar7) &&
        (iVar8 = (*(code *)PTR_strncmp_006aaa7c)(pcVar16,&DAT_0067a2e4,2), iVar8 == 0)) &&
       (iVar8 = (*(code *)PTR_strncmp_006aaa7c)(acStack_42d + 3,param_2,iVar11), iVar8 == 0)) {
      iVar7 = (*(code *)PTR_strncmp_006aaa7c)(pcVar16 + iVar11 + 2,&DAT_0067a2e4,2);
      if (iVar7 == 0) {
        (*(code *)PTR_sk_push_006a80a8)(uVar6);
        ppcVar9 = (char **)0x1;
        pcVar17 = pcVar18;
        goto LAB_0060d358;
      }
      cVar15 = cVar15 + '\x01';
      bVar1 = true;
      goto LAB_0060d2b0;
    }
    if (cVar15 == '\0') goto LAB_0060d2b0;
    bVar3 = false;
    pcVar17 = pcVar16 + iVar7 + -1;
    do {
      while (*pcVar17 != '\n') {
        if (*pcVar17 != '\r') goto LAB_0060d3e8;
        iVar7 = iVar7 + -1;
        pcVar17 = pcVar17 + -1;
        if (iVar7 == 0) goto LAB_0060d3e8;
      }
      iVar7 = iVar7 + -1;
      bVar3 = true;
      pcVar17 = pcVar17 + -1;
    } while (iVar7 != 0);
LAB_0060d3e8:
    if (bVar1) {
      if (pcVar18 != (char *)0x0) {
        (*(code *)PTR_sk_push_006a80a8)(uVar6,pcVar18);
      }
      uVar10 = (*(code *)PTR_BIO_s_mem_006a8d04)();
      pcVar18 = (char *)(*(code *)PTR_BIO_new_006a7fa4)(uVar10);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pcVar18,0x82,0,0);
    }
    else if (bVar2) {
      (*(code *)PTR_BIO_write_006a7f14)(pcVar18,"\r\n",2);
    }
    if (iVar7 != 0) break;
    pcVar17 = pcVar16;
    iVar7 = (*(code *)PTR_BIO_gets_006a85d0)(param_1,pcVar16,0x400);
    bVar1 = false;
    bVar2 = bVar3;
  } while( true );
  (*(code *)PTR_BIO_write_006a7f14)(pcVar18,pcVar16,iVar7);
  bVar1 = false;
  goto LAB_0060d2b0;
}

