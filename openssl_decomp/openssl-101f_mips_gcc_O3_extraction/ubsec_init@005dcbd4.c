
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ubsec_init(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  code *pcVar13;
  char *pcVar14;
  undefined4 uVar15;
  
  if (ubsec_dso == 0) {
    pcVar14 = UBSEC_LIBNAME;
    if (UBSEC_LIBNAME == (char *)0x0) {
      pcVar14 = "ubsec";
    }
    ubsec_dso = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar14,0,0);
    if (ubsec_dso == 0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar15 = 0x67;
      uVar1 = 0x195;
    }
    else {
      iVar2 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"ubsec_bytes_to_bits");
      if ((((((iVar2 != 0) &&
             (iVar3 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"ubsec_bits_to_bytes"),
             iVar3 != 0)) &&
            (pcVar4 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"ubsec_open"),
            pcVar4 != (code *)0x0)) &&
           (((pcVar5 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"ubsec_close"),
             pcVar5 != (code *)0x0 &&
             (iVar6 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                (ubsec_dso,"diffie_hellman_generate_ioctl"), iVar6 != 0)) &&
            ((iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"diffie_hellman_agree_ioctl"),
             iVar7 != 0 &&
             ((iVar8 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"rsa_mod_exp_ioctl"),
              iVar8 != 0 &&
              (iVar9 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"rsa_mod_exp_crt_ioctl"),
              iVar9 != 0)))))))) &&
          (iVar10 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"dsa_sign_ioctl"), iVar10 != 0))
         && ((((iVar11 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"dsa_verify_ioctl"),
               iVar11 != 0 &&
               (iVar12 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"math_accelerate_ioctl"),
               iVar12 != 0)) &&
              (iVar12 = (*(code *)PTR_DSO_bind_func_006a99ac)(ubsec_dso,"rng_ioctl"), iVar12 != 0))
             && (pcVar13 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)
                                             (ubsec_dso,"ubsec_max_key_len_ioctl"),
                pcVar13 != (code *)0x0)))) {
        p_UBSEC_max_key_len_ioctl = pcVar13;
        p_UBSEC_dsa_verify_ioctl = iVar11;
        p_UBSEC_dsa_sign_ioctl = iVar10;
        p_UBSEC_rsa_mod_exp_crt_ioctl = iVar9;
        p_UBSEC_rsa_mod_exp_ioctl = iVar8;
        p_UBSEC_diffie_hellman_agree_ioctl = iVar7;
        p_UBSEC_diffie_hellman_generate_ioctl = iVar6;
        p_UBSEC_ubsec_close = pcVar5;
        p_UBSEC_ubsec_open = pcVar4;
        p_UBSEC_ubsec_bits_to_bytes = iVar3;
        p_UBSEC_ubsec_bytes_to_bits = iVar2;
        iVar2 = (*pcVar4)("/dev/ubskey");
        if ((0 < iVar2) && (iVar3 = (*p_UBSEC_max_key_len_ioctl)(iVar2,&max_key_len), iVar3 == 0)) {
          (*p_UBSEC_ubsec_close)(iVar2);
          return 1;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x69,0x6c,"e_ubsec.c",0x1d2);
        goto LAB_005dcc78;
      }
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar15 = 0x67;
      uVar1 = 0x1b1;
    }
  }
  else {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar15 = 100;
    uVar1 = 0x18c;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x69,uVar15,"e_ubsec.c",uVar1);
LAB_005dcc78:
  if (ubsec_dso != 0) {
    (*(code *)PTR_DSO_free_006a9994)();
  }
  ubsec_dso = 0;
  p_UBSEC_ubsec_bytes_to_bits = 0;
  p_UBSEC_ubsec_bits_to_bytes = 0;
  p_UBSEC_ubsec_open = (code *)0x0;
  p_UBSEC_ubsec_close = (code *)0x0;
  p_UBSEC_diffie_hellman_generate_ioctl = 0;
  p_UBSEC_diffie_hellman_agree_ioctl = 0;
  p_UBSEC_rsa_mod_exp_ioctl = 0;
  p_UBSEC_rsa_mod_exp_crt_ioctl = 0;
  p_UBSEC_dsa_sign_ioctl = 0;
  p_UBSEC_dsa_verify_ioctl = 0;
  p_UBSEC_max_key_len_ioctl = (code *)0x0;
  return 0;
}

