
undefined4 ssl_srp_verify_param_cb(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  uint **ppuVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  ppuVar3 = (uint **)(*(code *)PTR_SSL_get_srp_N_006a8a2c)();
  if (ppuVar3 == (uint **)0x0) {
    return 0;
  }
  iVar4 = (*(code *)PTR_SSL_get_srp_g_006a8a30)(param_1);
  puVar2 = PTR_bio_err_006a7f3c;
  if (iVar4 == 0) {
    return 0;
  }
  if (((*(int *)(param_2 + 0xc) != 0) || (*(int *)(param_2 + 8) != 0)) ||
     (*(int *)(param_2 + 0x10) == 1)) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"SRP parameters:\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,&DAT_0063d5e4);
    (*(code *)PTR_BN_print_006a8024)(*(undefined4 *)puVar2,ppuVar3);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,&DAT_0063d5e8);
    (*(code *)PTR_BN_print_006a8024)(*(undefined4 *)puVar2,iVar4);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"\n");
  }
  iVar5 = (*(code *)PTR_SRP_check_known_gN_param_006a8a34)(iVar4,ppuVar3);
  if (iVar5 != 0) {
    return 1;
  }
  if (*(int *)(param_2 + 0x10) != 1) goto LAB_00448c70;
  if (*(int *)(param_2 + 0xc) != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,
               "SRP param N and g are not known params, going to check deeper.\n");
  }
  iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar4);
  if (0x40 < iVar5) goto LAB_00448c70;
  iVar5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  iVar6 = (*(code *)PTR_BN_new_006a82b4)();
  iVar7 = (*(code *)PTR_BN_new_006a82b4)();
  if (((iVar5 == 0) || ((int)ppuVar3[1] < 1)) ||
     (((**ppuVar3 & 1) == 0 ||
      (iVar8 = (*(code *)PTR_BN_is_prime_ex_006a8a3c)(ppuVar3,0x40,iVar5,0), iVar8 == 0)))) {
    bVar1 = false;
    if (iVar7 != 0) {
LAB_00448d24:
      bVar1 = false;
LAB_00448d28:
      (*(code *)PTR_BN_free_006a811c)(iVar7);
    }
    if (iVar6 != 0) {
LAB_00448d40:
      (*(code *)PTR_BN_free_006a811c)(iVar6);
    }
    if (iVar5 != 0) goto LAB_00448d58;
  }
  else {
    if (iVar6 != 0) {
      iVar8 = (*(code *)PTR_BN_rshift1_006a8a44)(iVar6,ppuVar3);
      if ((iVar8 == 0) ||
         (iVar8 = (*(code *)PTR_BN_is_prime_ex_006a8a3c)(iVar6,0x40,iVar5,0), iVar8 == 0)) {
        if (iVar7 != 0) goto LAB_00448d24;
      }
      else if (iVar7 != 0) {
        iVar4 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar7,iVar4,iVar6,ppuVar3,iVar5);
        if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_add_word_006a81bc)(iVar7,1), iVar4 == 0))
        goto LAB_00448d24;
        iVar4 = (*(code *)PTR_BN_cmp_006a8a4c)(iVar7,ppuVar3);
        bVar1 = iVar4 == 0;
        goto LAB_00448d28;
      }
      bVar1 = false;
      goto LAB_00448d40;
    }
    bVar1 = false;
    if (iVar7 != 0) goto LAB_00448d24;
LAB_00448d58:
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
  }
  if (bVar1) {
    return 1;
  }
LAB_00448c70:
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,"SRP param N and g rejected.\n");
  return 0;
}

