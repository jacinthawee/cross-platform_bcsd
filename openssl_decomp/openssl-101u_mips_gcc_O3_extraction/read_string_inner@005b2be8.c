
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint read_string_inner(UI *param_1,UI_STRING *param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  UI_string_types UVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  UI_STRING *uis;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined auStack_20c4 [4];
  code *local_20c0;
  undefined auStack_2034 [8];
  char local_202c [8192];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar15 = 1;
  ps_5950 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  intr_signal = 0;
  (*(code *)PTR_memset_006a99f4)(auStack_20c4,0,0x90);
  iVar17 = 0x6ac8bc;
  local_20c0 = recsig;
  iVar14 = iVar17;
  for (iVar13 = 2;
      (((iVar15 == 0x10 || (iVar15 == 0x11)) || (iVar15 == 9)) ||
      ((*(code *)PTR_sigaction_006a997c)(iVar15,auStack_20c4,iVar14), iVar13 != 0x20));
      iVar13 = iVar13 + 1) {
    iVar15 = iVar15 + 1;
    iVar14 = iVar14 + 0x90;
  }
  (*(code *)PTR_signal_006a9ad8)(0x14,0);
  ps_5950 = 1;
  uVar10 = tty_in;
  if (param_3 == 0) {
    puVar3 = (undefined4 *)tty_orig;
    puVar9 = (undefined4 *)tty_new;
    do {
      puVar2 = puVar3 + 4;
      puVar8 = puVar9 + 4;
      uVar12 = puVar3[1];
      uVar11 = puVar3[2];
      uVar10 = puVar3[3];
      *puVar9 = *puVar3;
      puVar9[1] = uVar12;
      puVar9[2] = uVar11;
      puVar9[3] = uVar10;
      iVar14 = is_a_tty;
      puVar3 = puVar2;
      puVar9 = puVar8;
    } while (puVar2 != (undefined4 *)(tty_orig + 0x30));
    *puVar8 = tty_orig._48_4_;
    uVar10 = tty_in;
    tty_new._12_4_ = tty_new._12_4_ & 0xfffffff7;
    if (iVar14 == 0) goto LAB_005b2ea0;
    uVar11 = (*(code *)PTR_fileno_006a99dc)(tty_in);
    iVar14 = (*(code *)PTR_tcsetattr_006a9a64)(uVar11,0x540e,tty_new);
    if (iVar14 != -1) goto LAB_005b2ea0;
    uVar16 = -(uint)(intr_signal == 2);
LAB_005b2dd4:
    (*(code *)PTR_fputc_006a99a4)(10,tty_out);
    if (ps_5950 < 2) {
LAB_005b2f68:
      if (ps_5950 < 1) goto LAB_005b2f70;
    }
    else {
      puVar3 = (undefined4 *)tty_orig;
      puVar9 = (undefined4 *)tty_new;
      do {
        puVar2 = puVar3 + 4;
        puVar8 = puVar9 + 4;
        uVar12 = puVar3[1];
        uVar11 = puVar3[2];
        uVar10 = puVar3[3];
        *puVar9 = *puVar3;
        puVar9[1] = uVar12;
        puVar9[2] = uVar11;
        puVar9[3] = uVar10;
        iVar14 = is_a_tty;
        puVar3 = puVar2;
        puVar9 = puVar8;
      } while (puVar2 != (undefined4 *)(tty_orig + 0x30));
      *puVar8 = tty_orig._48_4_;
      tty_new._12_4_ = tty_new._12_4_ | 8;
      if (iVar14 != 0) {
        uVar10 = (*(code *)PTR_fileno_006a99dc)(tty_in);
        iVar14 = (*(code *)PTR_tcsetattr_006a9a64)(uVar10,0x540e,tty_new);
        if (iVar14 == -1) {
          uVar16 = 0;
        }
      }
    }
  }
  else {
LAB_005b2ea0:
    local_202c[0] = '\0';
    ps_5950 = 2;
    iVar14 = (*(code *)PTR_fgets_006a9ae0)(local_202c,0x1fff,uVar10);
    uVar10 = tty_in;
    if (((iVar14 == 0) || (iVar14 = (*(code *)PTR_feof_006a9a38)(tty_in), iVar14 != 0)) ||
       (iVar14 = (*(code *)PTR_ferror_006a9ae4)(uVar10), iVar14 != 0)) {
      uVar16 = 0;
    }
    else {
      puVar4 = (undefined *)(*(code *)PTR_strchr_006a9a28)(local_202c,10);
      if (puVar4 == (undefined *)0x0) {
        do {
          iVar14 = (*(code *)PTR_fgets_006a9ae0)(auStack_2034,4,uVar10);
          if (iVar14 == 0) {
            uVar16 = 0;
            goto LAB_005b2eec;
          }
          iVar14 = (*(code *)PTR_strchr_006a9a28)(auStack_2034,10);
        } while (iVar14 == 0);
      }
      else if (param_4 != 0) {
        *puVar4 = 0;
      }
      uVar16 = UI_set_result(param_1,param_2,local_202c);
      uVar16 = ~uVar16 >> 0x1f;
    }
LAB_005b2eec:
    if (intr_signal == 2) {
      uVar16 = 0xffffffff;
    }
    if (param_3 == 0) goto LAB_005b2dd4;
    if (ps_5950 < 2) goto LAB_005b2f68;
  }
  iVar14 = 1;
  for (iVar13 = 2;
      ((iVar14 == 0x10 || (iVar14 == 0x11)) ||
      ((*(code *)PTR_sigaction_006a997c)(iVar14,iVar17,0), iVar13 != 0x20)); iVar13 = iVar13 + 1) {
    iVar14 = iVar14 + 1;
    iVar17 = iVar17 + 0x90;
  }
LAB_005b2f70:
  uis = (UI_STRING *)0x2000;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_202c);
  if (local_2c == *(int *)puVar1) {
    return uVar16;
  }
  iVar14 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  UVar5 = UI_get_string_type(uis);
  uVar10 = tty_out;
  if (UVar5 == UIT_VERIFY) {
    pcVar6 = UI_get0_output_string(uis);
    (*(code *)PTR___fprintf_chk_006a9980)(uVar10,1,"Verifying - %s",pcVar6);
    (*(code *)PTR_fflush_006a9b04)(tty_out);
    uVar16 = UI_get_input_flags(uis);
    uVar16 = read_string_inner(iVar14,uis,uVar16 & 1,1);
    if ((int)uVar16 < 1) {
      return uVar16;
    }
    pcVar6 = UI_get0_result_string(uis);
    pcVar7 = UI_get0_test_string(uis);
    iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar6,pcVar7);
    if (iVar14 != 0) {
      (*(code *)PTR_fwrite_006a9a74)("Verify failure\n",1,0xf,tty_out);
      (*(code *)PTR_fflush_006a9b04)(tty_out);
      return 0;
    }
  }
  else {
    if (UVar5 == UIT_BOOLEAN) {
      pcVar6 = UI_get0_output_string(uis);
      (*(code *)PTR_fputs_006a9954)(pcVar6,tty_out);
      pcVar6 = UI_get0_action_string(uis);
      (*(code *)PTR_fputs_006a9954)(pcVar6,tty_out);
      (*(code *)PTR_fflush_006a9b04)(tty_out);
      uVar16 = UI_get_input_flags(uis);
      uVar16 = read_string_inner(iVar14,uis,uVar16 & 1,0);
      return uVar16;
    }
    if (UVar5 == UIT_PROMPT) {
      pcVar6 = UI_get0_output_string(uis);
      (*(code *)PTR_fputs_006a9954)(pcVar6,tty_out);
      (*(code *)PTR_fflush_006a9b04)(tty_out);
      uVar16 = UI_get_input_flags(uis);
      uVar16 = read_string_inner(iVar14,uis,uVar16 & 1,1);
      return uVar16;
    }
  }
  return 1;
}

