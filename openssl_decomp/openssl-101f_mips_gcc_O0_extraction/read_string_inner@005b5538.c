
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint read_string_inner(UI *param_1,UI_STRING *param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  UI_string_types UVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  UI_STRING *uis;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined auStack_20c4 [4];
  code *local_20c0;
  undefined auStack_2034 [8];
  char local_202c [8192];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar16 = 1;
  ps_5950 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  intr_signal = 0;
  (*(code *)PTR_memset_006aab00)(auStack_20c4,0,0x90);
  iVar18 = 0x6ada7c;
  local_20c0 = recsig;
  iVar15 = iVar18;
  for (iVar14 = 2;
      (((iVar16 == 0x10 || (iVar16 == 0x11)) || (iVar16 == 9)) ||
      ((*(code *)PTR_sigaction_006aaa88)(iVar16,auStack_20c4,iVar15), iVar14 != 0x20));
      iVar14 = iVar14 + 1) {
    iVar16 = iVar16 + 1;
    iVar15 = iVar15 + 0x90;
  }
  (*(code *)PTR_signal_006aabe0)(0x14,0);
  ps_5950 = 1;
  uVar11 = tty_in;
  if (param_3 == 0) {
    puVar3 = (undefined4 *)tty_orig;
    puVar4 = (undefined4 *)tty_new;
    do {
      puVar10 = puVar4;
      puVar5 = puVar3;
      uVar13 = puVar5[1];
      uVar12 = puVar5[2];
      uVar11 = puVar5[3];
      *puVar10 = *puVar5;
      puVar10[1] = uVar13;
      puVar10[2] = uVar12;
      puVar10[3] = uVar11;
      iVar15 = is_a_tty;
      puVar3 = puVar5 + 4;
      puVar4 = puVar10 + 4;
    } while (puVar5 + 4 != (undefined4 *)(tty_orig + 0x20));
    uVar11 = puVar5[5];
    uVar1 = *(undefined2 *)(puVar5 + 6);
    puVar10[4] = tty_orig._32_4_;
    puVar10[5] = uVar11;
    *(undefined2 *)(puVar10 + 6) = uVar1;
    uVar11 = tty_in;
    tty_new._6_2_ = tty_new._6_2_ & 0xfff7;
    if (iVar15 == 0) goto LAB_005b580c;
    uVar12 = (*(code *)PTR_fileno_006aaae8)(tty_in);
    iVar15 = (*(code *)PTR_ioctl_006aab90)(uVar12,0x5402,tty_new);
    if (iVar15 != -1) goto LAB_005b580c;
    uVar17 = -(uint)(intr_signal == 2);
LAB_005b5730:
    (*(code *)PTR_fputc_006aaab0)(10,tty_out);
    if (ps_5950 < 2) {
LAB_005b58d4:
      if (ps_5950 < 1) goto LAB_005b58dc;
    }
    else {
      puVar3 = (undefined4 *)tty_orig;
      puVar4 = (undefined4 *)tty_new;
      do {
        puVar10 = puVar4;
        puVar5 = puVar3;
        uVar13 = puVar5[1];
        uVar12 = puVar5[2];
        uVar11 = puVar5[3];
        *puVar10 = *puVar5;
        puVar10[1] = uVar13;
        puVar10[2] = uVar12;
        puVar10[3] = uVar11;
        iVar15 = is_a_tty;
        puVar3 = puVar5 + 4;
        puVar4 = puVar10 + 4;
      } while (puVar5 + 4 != (undefined4 *)(tty_orig + 0x20));
      uVar11 = puVar5[5];
      uVar1 = *(undefined2 *)(puVar5 + 6);
      puVar10[4] = tty_orig._32_4_;
      puVar10[5] = uVar11;
      *(undefined2 *)(puVar10 + 6) = uVar1;
      tty_new._6_2_ = tty_new._6_2_ | 8;
      if (iVar15 != 0) {
        uVar11 = (*(code *)PTR_fileno_006aaae8)(tty_in);
        iVar15 = (*(code *)PTR_ioctl_006aab90)(uVar11,0x5402,tty_new);
        if (iVar15 == -1) {
          uVar17 = 0;
        }
      }
    }
  }
  else {
LAB_005b580c:
    local_202c[0] = '\0';
    ps_5950 = 2;
    iVar15 = (*(code *)PTR_fgets_006aabe8)(local_202c,0x1fff,uVar11);
    uVar11 = tty_in;
    if (((iVar15 == 0) || (iVar15 = (*(code *)PTR_feof_006aab44)(tty_in), iVar15 != 0)) ||
       (iVar15 = (*(code *)PTR_ferror_006aabec)(uVar11), iVar15 != 0)) {
      uVar17 = 0;
    }
    else {
      puVar6 = (undefined *)(*(code *)PTR_strchr_006aab34)(local_202c,10);
      if (puVar6 == (undefined *)0x0) {
        do {
          iVar15 = (*(code *)PTR_fgets_006aabe8)(auStack_2034,4,uVar11);
          if (iVar15 == 0) {
            uVar17 = 0;
            goto LAB_005b5858;
          }
          iVar15 = (*(code *)PTR_strchr_006aab34)(auStack_2034,10);
        } while (iVar15 == 0);
      }
      else if (param_4 != 0) {
        *puVar6 = 0;
      }
      uVar17 = UI_set_result(param_1,param_2,local_202c);
      uVar17 = ~uVar17 >> 0x1f;
    }
LAB_005b5858:
    if (intr_signal == 2) {
      uVar17 = 0xffffffff;
    }
    if (param_3 == 0) goto LAB_005b5730;
    if (ps_5950 < 2) goto LAB_005b58d4;
  }
  iVar15 = 1;
  for (iVar14 = 2;
      ((iVar15 == 0x10 || (iVar15 == 0x11)) ||
      ((*(code *)PTR_sigaction_006aaa88)(iVar15,iVar18,0), iVar14 != 0x20)); iVar14 = iVar14 + 1) {
    iVar15 = iVar15 + 1;
    iVar18 = iVar18 + 0x90;
  }
LAB_005b58dc:
  uis = (UI_STRING *)0x2000;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_202c);
  if (local_2c == *(int *)puVar2) {
    return uVar17;
  }
  iVar15 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  UVar7 = UI_get_string_type(uis);
  uVar11 = tty_out;
  if (UVar7 == UIT_VERIFY) {
    pcVar8 = UI_get0_output_string(uis);
    (*(code *)PTR___fprintf_chk_006aaa8c)(uVar11,1,"Verifying - %s",pcVar8);
    (*(code *)PTR_fflush_006aac0c)(tty_out);
    uVar17 = UI_get_input_flags(uis);
    uVar17 = read_string_inner(iVar15,uis,uVar17 & 1,1);
    if ((int)uVar17 < 1) {
      return uVar17;
    }
    pcVar8 = UI_get0_result_string(uis);
    pcVar9 = UI_get0_test_string(uis);
    iVar15 = (*(code *)PTR_strcmp_006aac20)(pcVar8,pcVar9);
    if (iVar15 != 0) {
      (*(code *)PTR_fwrite_006aab7c)("Verify failure\n",1,0xf,tty_out);
      (*(code *)PTR_fflush_006aac0c)(tty_out);
      return 0;
    }
  }
  else {
    if (UVar7 == UIT_BOOLEAN) {
      pcVar8 = UI_get0_output_string(uis);
      (*(code *)PTR_fputs_006aaa64)(pcVar8,tty_out);
      pcVar8 = UI_get0_action_string(uis);
      (*(code *)PTR_fputs_006aaa64)(pcVar8,tty_out);
      (*(code *)PTR_fflush_006aac0c)(tty_out);
      uVar17 = UI_get_input_flags(uis);
      uVar17 = read_string_inner(iVar15,uis,uVar17 & 1,0);
      return uVar17;
    }
    if (UVar7 == UIT_PROMPT) {
      pcVar8 = UI_get0_output_string(uis);
      (*(code *)PTR_fputs_006aaa64)(pcVar8,tty_out);
      (*(code *)PTR_fflush_006aac0c)(tty_out);
      uVar17 = UI_get_input_flags(uis);
      uVar17 = read_string_inner(iVar15,uis,uVar17 & 1,1);
      return uVar17;
    }
  }
  return 1;
}

