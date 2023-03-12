
/* WARNING: Type propagation algorithm not settling */

undefined4 version_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined *puVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  char **ppcVar12;
  
  puVar8 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar8 == 0) {
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar9 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    *(int *)puVar8 = iVar9;
    if (iVar9 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  bVar2 = param_1 == 1;
  if (param_1 < 2) {
    if (param_1 != 1) {
      return 0;
    }
    uVar5 = false;
    uVar7 = false;
    uVar3 = false;
    uVar4 = false;
    uVar6 = false;
  }
  else {
    ppcVar12 = (char **)(param_2 + 4);
    uVar4 = false;
    uVar7 = false;
    uVar5 = false;
    uVar3 = false;
    uVar6 = false;
    iVar9 = 1;
    do {
      pcVar11 = *ppcVar12;
      if (*pcVar11 != '-') goto LAB_00461644;
      cVar1 = pcVar11[1];
      if (cVar1 == 'v') {
        if (pcVar11[2] == '\0') {
          bVar2 = true;
        }
        else {
LAB_00461740:
          if (cVar1 == 'o') {
            cVar1 = pcVar11[2];
            uVar5 = true;
          }
          else {
            if (cVar1 != 'p') goto LAB_004617bc;
            cVar1 = pcVar11[2];
            uVar4 = true;
          }
joined_r0x00461768:
          if (cVar1 != '\0') {
LAB_00461644:
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"usage:version -[avbofpd]\n");
            return 1;
          }
        }
      }
      else if (cVar1 == 'b') {
        if (pcVar11[2] == '\0') {
          uVar3 = true;
        }
        else {
LAB_004617bc:
          if (cVar1 == 'd') {
            cVar1 = pcVar11[2];
            uVar7 = true;
            goto joined_r0x00461768;
          }
          if ((cVar1 != 'a') || (uVar7 = true, pcVar11[2] != '\0')) goto LAB_00461644;
          uVar4 = true;
          uVar5 = true;
          uVar3 = true;
          bVar2 = true;
          uVar6 = true;
        }
      }
      else {
        if (cVar1 != 'f') goto LAB_00461740;
        if (pcVar11[2] != '\0') goto LAB_004617bc;
        uVar6 = true;
      }
      iVar9 = iVar9 + 1;
      ppcVar12 = ppcVar12 + 1;
    } while (param_1 != iVar9);
    if (!bVar2) goto joined_r0x00461a14;
  }
  iVar9 = (*(code *)PTR_SSLeay_006a7c74)();
  if (iVar9 == 0x1000115f) {
    uVar10 = (*(code *)PTR_SSLeay_version_006a7aa4)(0);
    (*(code *)PTR_puts_006a9a54)(uVar10);
  }
  else {
    uVar10 = (*(code *)PTR_SSLeay_version_006a7aa4)();
    (*(code *)PTR___printf_chk_006a99c4)
              (1,"%s (Library: %s)\n","OpenSSL 1.0.1u  22 Sep 2016",uVar10);
  }
joined_r0x00461a14:
  if ((bool)uVar3) {
    uVar10 = (*(code *)PTR_SSLeay_version_006a7aa4)(3);
    (*(code *)PTR_puts_006a9a54)(uVar10);
  }
  if ((bool)uVar4) {
    uVar10 = (*(code *)PTR_SSLeay_version_006a7aa4)(4);
    (*(code *)PTR_puts_006a9a54)(uVar10);
  }
  if ((bool)uVar5) {
    (*(code *)PTR___printf_chk_006a99c4)(1,"options:  ");
    uVar10 = (*(code *)PTR_BN_options_006a7aa8)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar10);
    uVar10 = (*(code *)PTR_RC4_options_006a7aac)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar10);
    uVar10 = (*(code *)PTR_DES_options_006a7ab0)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar10);
    uVar10 = (*(code *)PTR_idea_options_006a7ab8)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar10);
    uVar10 = (*(code *)PTR_BF_options_006a7abc)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar10);
    (*(code *)PTR_putchar_006a99ec)(10);
  }
  if ((bool)uVar6) {
    uVar10 = (*(code *)PTR_SSLeay_version_006a7aa4)(2);
    (*(code *)PTR_puts_006a9a54)(uVar10);
  }
  if (!(bool)uVar7) {
    return 0;
  }
  uVar10 = (*(code *)PTR_SSLeay_version_006a7aa4)(5);
  (*(code *)PTR_puts_006a9a54)(uVar10);
  return 0;
}

