
undefined4 ocsp_resp_cb(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint **ppuVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *local_20;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_SSL_ctrl_006a7788)(param_1,0x46,0,&local_20);
  (*(code *)PTR_BIO_puts_006a6f58)(param_2,"OCSP response: ");
  if (local_20 == (char *)0x0) {
    local_20 = "no response sent\n";
    (*(code *)PTR_BIO_puts_006a6f58)(param_2);
    uVar3 = 1;
  }
  else {
    iVar4 = (*(code *)PTR_d2i_OCSP_RESPONSE_006a793c)(0,&local_20,uVar3);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_puts_006a6f58)(param_2,"response parse error\n");
      (*(code *)PTR_BIO_dump_indent_006a7334)(param_2,local_20,uVar3,4);
      uVar3 = 0;
    }
    else {
      (*(code *)PTR_BIO_puts_006a6f58)(param_2,"\n======================================\n");
      (*(code *)PTR_OCSP_RESPONSE_print_006a7798)(param_2,iVar4,0);
      local_20 = "======================================\n";
      (*(code *)PTR_BIO_puts_006a6f58)(param_2);
      (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(iVar4);
      uVar3 = 1;
    }
  }
  if (local_1c == *(int *)puVar2) {
    return uVar3;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppuVar5 = (uint **)(*(code *)PTR_SSL_get_srp_N_006a7940)();
  if (ppuVar5 == (uint **)0x0) {
    return 0;
  }
  iVar4 = (*(code *)PTR_SSL_get_srp_g_006a7944)(iVar4);
  puVar2 = PTR_bio_err_006a6e3c;
  if (iVar4 == 0) {
    return 0;
  }
  if (((*(int *)(local_20 + 0xc) != 0) || (*(int *)(local_20 + 8) != 0)) ||
     (*(int *)(local_20 + 0x10) == 1)) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"SRP parameters:\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,&DAT_0063cfb4);
    (*(code *)PTR_BN_print_006a6f24)(*(undefined4 *)puVar2,ppuVar5);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,&DAT_0063cfb8);
    (*(code *)PTR_BN_print_006a6f24)(*(undefined4 *)puVar2,iVar4);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"\n");
  }
  iVar6 = (*(code *)PTR_SRP_check_known_gN_param_006a7948)(iVar4,ppuVar5);
  if (iVar6 != 0) {
    return 1;
  }
  if (*(int *)(local_20 + 0x10) != 1) goto LAB_00449330;
  if (*(int *)(local_20 + 0xc) != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "SRP param N and g are not known params, going to check deeper.\n");
  }
  iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar4);
  if (0x40 < iVar6) goto LAB_00449330;
  iVar6 = (*(code *)PTR_BN_CTX_new_006a794c)();
  iVar7 = (*(code *)PTR_BN_new_006a71b4)();
  iVar8 = (*(code *)PTR_BN_new_006a71b4)();
  if (((iVar6 == 0) || ((int)ppuVar5[1] < 1)) ||
     (((**ppuVar5 & 1) == 0 ||
      (iVar9 = (*(code *)PTR_BN_is_prime_ex_006a7950)(ppuVar5,0x40,iVar6,0), iVar9 == 0)))) {
    bVar1 = false;
    if (iVar8 != 0) {
LAB_004493e4:
      bVar1 = false;
LAB_004493e8:
      (*(code *)PTR_BN_free_006a701c)(iVar8);
    }
    if (iVar7 != 0) {
LAB_00449400:
      (*(code *)PTR_BN_free_006a701c)(iVar7);
    }
    if (iVar6 != 0) goto LAB_00449418;
  }
  else {
    if (iVar7 != 0) {
      iVar9 = (*(code *)PTR_BN_rshift1_006a7958)(iVar7,ppuVar5);
      if ((iVar9 == 0) ||
         (iVar9 = (*(code *)PTR_BN_is_prime_ex_006a7950)(iVar7,0x40,iVar6,0), iVar9 == 0)) {
        if (iVar8 != 0) goto LAB_004493e4;
      }
      else if (iVar8 != 0) {
        iVar4 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar8,iVar4,iVar7,ppuVar5,iVar6);
        if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_add_word_006a70bc)(iVar8,1), iVar4 == 0))
        goto LAB_004493e4;
        iVar4 = (*(code *)PTR_BN_cmp_006a7960)(iVar8,ppuVar5);
        bVar1 = iVar4 == 0;
        goto LAB_004493e8;
      }
      bVar1 = false;
      goto LAB_00449400;
    }
    bVar1 = false;
    if (iVar8 != 0) goto LAB_004493e4;
LAB_00449418:
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar6);
  }
  if (bVar1) {
    return 1;
  }
LAB_00449330:
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,"SRP param N and g rejected.\n");
  return 0;
}

