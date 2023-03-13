
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
  
  ppuVar3 = (uint **)(*(code *)PTR_SSL_get_srp_N_006a7940)();
  if (ppuVar3 == (uint **)0x0) {
    return 0;
  }
  iVar4 = (*(code *)PTR_SSL_get_srp_g_006a7944)(param_1);
  puVar2 = PTR_bio_err_006a6e3c;
  if (iVar4 == 0) {
    return 0;
  }
  if (((*(int *)(param_2 + 0xc) != 0) || (*(int *)(param_2 + 8) != 0)) ||
     (*(int *)(param_2 + 0x10) == 1)) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"SRP parameters:\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,&DAT_0063cfb4);
    (*(code *)PTR_BN_print_006a6f24)(*(undefined4 *)puVar2,ppuVar3);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,&DAT_0063cfb8);
    (*(code *)PTR_BN_print_006a6f24)(*(undefined4 *)puVar2,iVar4);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"\n");
  }
  iVar5 = (*(code *)PTR_SRP_check_known_gN_param_006a7948)(iVar4,ppuVar3);
  if (iVar5 != 0) {
    return 1;
  }
  if (*(int *)(param_2 + 0x10) != 1) goto LAB_00449330;
  if (*(int *)(param_2 + 0xc) != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "SRP param N and g are not known params, going to check deeper.\n");
  }
  iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar4);
  if (0x40 < iVar5) goto LAB_00449330;
  iVar5 = (*(code *)PTR_BN_CTX_new_006a794c)();
  iVar6 = (*(code *)PTR_BN_new_006a71b4)();
  iVar7 = (*(code *)PTR_BN_new_006a71b4)();
  if (((iVar5 == 0) || ((int)ppuVar3[1] < 1)) ||
     (((**ppuVar3 & 1) == 0 ||
      (iVar8 = (*(code *)PTR_BN_is_prime_ex_006a7950)(ppuVar3,0x40,iVar5,0), iVar8 == 0)))) {
    bVar1 = false;
    if (iVar7 != 0) {
LAB_004493e4:
      bVar1 = false;
LAB_004493e8:
      (*(code *)PTR_BN_free_006a701c)(iVar7);
    }
    if (iVar6 != 0) {
LAB_00449400:
      (*(code *)PTR_BN_free_006a701c)(iVar6);
    }
    if (iVar5 != 0) goto LAB_00449418;
  }
  else {
    if (iVar6 != 0) {
      iVar8 = (*(code *)PTR_BN_rshift1_006a7958)(iVar6,ppuVar3);
      if ((iVar8 == 0) ||
         (iVar8 = (*(code *)PTR_BN_is_prime_ex_006a7950)(iVar6,0x40,iVar5,0), iVar8 == 0)) {
        if (iVar7 != 0) goto LAB_004493e4;
      }
      else if (iVar7 != 0) {
        iVar4 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar7,iVar4,iVar6,ppuVar3,iVar5);
        if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_add_word_006a70bc)(iVar7,1), iVar4 == 0))
        goto LAB_004493e4;
        iVar4 = (*(code *)PTR_BN_cmp_006a7960)(iVar7,ppuVar3);
        bVar1 = iVar4 == 0;
        goto LAB_004493e8;
      }
      bVar1 = false;
      goto LAB_00449400;
    }
    bVar1 = false;
    if (iVar7 != 0) goto LAB_004493e4;
LAB_00449418:
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar5);
  }
  if (bVar1) {
    return 1;
  }
LAB_00449330:
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,"SRP param N and g rejected.\n");
  return 0;
}

