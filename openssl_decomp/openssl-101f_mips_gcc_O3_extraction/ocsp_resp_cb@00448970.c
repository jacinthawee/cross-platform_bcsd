
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar3 = (*(code *)PTR_SSL_ctrl_006a8878)(param_1,0x46,0,&local_20);
  (*(code *)PTR_BIO_puts_006a8058)(param_2,"OCSP response: ");
  if (local_20 == (char *)0x0) {
    local_20 = "no response sent\n";
    (*(code *)PTR_BIO_puts_006a8058)(param_2);
    uVar3 = 1;
  }
  else {
    iVar4 = (*(code *)PTR_d2i_OCSP_RESPONSE_006a8a28)(0,&local_20,uVar3);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_puts_006a8058)(param_2,"response parse error\n");
      (*(code *)PTR_BIO_dump_indent_006a8434)(param_2,local_20,uVar3,4);
      uVar3 = 0;
    }
    else {
      (*(code *)PTR_BIO_puts_006a8058)(param_2,"\n======================================\n");
      (*(code *)PTR_OCSP_RESPONSE_print_006a8888)(param_2,iVar4,0);
      local_20 = "======================================\n";
      (*(code *)PTR_BIO_puts_006a8058)(param_2);
      (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(iVar4);
      uVar3 = 1;
    }
  }
  if (local_1c == *(int *)puVar2) {
    return uVar3;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  ppuVar5 = (uint **)(*(code *)PTR_SSL_get_srp_N_006a8a2c)();
  if (ppuVar5 == (uint **)0x0) {
    return 0;
  }
  iVar4 = (*(code *)PTR_SSL_get_srp_g_006a8a30)(iVar4);
  puVar2 = PTR_bio_err_006a7f3c;
  if (iVar4 == 0) {
    return 0;
  }
  if (((*(int *)(local_20 + 0xc) != 0) || (*(int *)(local_20 + 8) != 0)) ||
     (*(int *)(local_20 + 0x10) == 1)) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"SRP parameters:\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,&DAT_0063d5e4);
    (*(code *)PTR_BN_print_006a8024)(*(undefined4 *)puVar2,ppuVar5);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,&DAT_0063d5e8);
    (*(code *)PTR_BN_print_006a8024)(*(undefined4 *)puVar2,iVar4);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"\n");
  }
  iVar6 = (*(code *)PTR_SRP_check_known_gN_param_006a8a34)(iVar4,ppuVar5);
  if (iVar6 != 0) {
    return 1;
  }
  if (*(int *)(local_20 + 0x10) != 1) goto LAB_00448c70;
  if (*(int *)(local_20 + 0xc) != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,
               "SRP param N and g are not known params, going to check deeper.\n");
  }
  iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar4);
  if (0x40 < iVar6) goto LAB_00448c70;
  iVar6 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  iVar7 = (*(code *)PTR_BN_new_006a82b4)();
  iVar8 = (*(code *)PTR_BN_new_006a82b4)();
  if (((iVar6 == 0) || ((int)ppuVar5[1] < 1)) ||
     (((**ppuVar5 & 1) == 0 ||
      (iVar9 = (*(code *)PTR_BN_is_prime_ex_006a8a3c)(ppuVar5,0x40,iVar6,0), iVar9 == 0)))) {
    bVar1 = false;
    if (iVar8 != 0) {
LAB_00448d24:
      bVar1 = false;
LAB_00448d28:
      (*(code *)PTR_BN_free_006a811c)(iVar8);
    }
    if (iVar7 != 0) {
LAB_00448d40:
      (*(code *)PTR_BN_free_006a811c)(iVar7);
    }
    if (iVar6 != 0) goto LAB_00448d58;
  }
  else {
    if (iVar7 != 0) {
      iVar9 = (*(code *)PTR_BN_rshift1_006a8a44)(iVar7,ppuVar5);
      if ((iVar9 == 0) ||
         (iVar9 = (*(code *)PTR_BN_is_prime_ex_006a8a3c)(iVar7,0x40,iVar6,0), iVar9 == 0)) {
        if (iVar8 != 0) goto LAB_00448d24;
      }
      else if (iVar8 != 0) {
        iVar4 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar8,iVar4,iVar7,ppuVar5,iVar6);
        if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_add_word_006a81bc)(iVar8,1), iVar4 == 0))
        goto LAB_00448d24;
        iVar4 = (*(code *)PTR_BN_cmp_006a8a4c)(iVar8,ppuVar5);
        bVar1 = iVar4 == 0;
        goto LAB_00448d28;
      }
      bVar1 = false;
      goto LAB_00448d40;
    }
    bVar1 = false;
    if (iVar8 != 0) goto LAB_00448d24;
LAB_00448d58:
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar6);
  }
  if (bVar1) {
    return 1;
  }
LAB_00448c70:
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,"SRP param N and g rejected.\n");
  return 0;
}

