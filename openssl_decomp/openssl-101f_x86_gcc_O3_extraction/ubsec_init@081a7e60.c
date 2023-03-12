
undefined4 ubsec_init(void)

{
  char *filename;
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  DSO_FUNC_TYPE pDVar11;
  int iVar12;
  int iVar13;
  
  if (ubsec_dso == (DSO *)0x0) {
    filename = UBSEC_LIBNAME;
    if (UBSEC_LIBNAME == (char *)0x0) {
      filename = "ubsec";
    }
    ubsec_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (ubsec_dso == (DSO *)0x0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      iVar12 = 0x195;
    }
    else {
      pDVar1 = DSO_bind_func(ubsec_dso,"ubsec_bytes_to_bits");
      if ((((((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
             (pDVar2 = DSO_bind_func(ubsec_dso,"ubsec_bits_to_bytes"), pDVar2 != (DSO_FUNC_TYPE)0x0)
             ) && (pDVar3 = DSO_bind_func(ubsec_dso,"ubsec_open"), pDVar3 != (DSO_FUNC_TYPE)0x0)) &&
           (((pDVar4 = DSO_bind_func(ubsec_dso,"ubsec_close"), pDVar4 != (DSO_FUNC_TYPE)0x0 &&
             (pDVar5 = DSO_bind_func(ubsec_dso,"diffie_hellman_generate_ioctl"),
             pDVar5 != (DSO_FUNC_TYPE)0x0)) &&
            ((pDVar6 = DSO_bind_func(ubsec_dso,"diffie_hellman_agree_ioctl"),
             pDVar6 != (DSO_FUNC_TYPE)0x0 &&
             ((pDVar7 = DSO_bind_func(ubsec_dso,"rsa_mod_exp_ioctl"), pDVar7 != (DSO_FUNC_TYPE)0x0
              && (pDVar8 = DSO_bind_func(ubsec_dso,"rsa_mod_exp_crt_ioctl"),
                 pDVar8 != (DSO_FUNC_TYPE)0x0)))))))) &&
          (pDVar9 = DSO_bind_func(ubsec_dso,"dsa_sign_ioctl"), pDVar9 != (DSO_FUNC_TYPE)0x0)) &&
         ((((pDVar10 = DSO_bind_func(ubsec_dso,"dsa_verify_ioctl"), pDVar10 != (DSO_FUNC_TYPE)0x0 &&
            (pDVar11 = DSO_bind_func(ubsec_dso,"math_accelerate_ioctl"),
            pDVar11 != (DSO_FUNC_TYPE)0x0)) &&
           (pDVar11 = DSO_bind_func(ubsec_dso,"rng_ioctl"), pDVar11 != (DSO_FUNC_TYPE)0x0)) &&
          (pDVar11 = DSO_bind_func(ubsec_dso,"ubsec_max_key_len_ioctl"),
          pDVar11 != (DSO_FUNC_TYPE)0x0)))) {
        p_UBSEC_max_key_len_ioctl = pDVar11;
        p_UBSEC_dsa_verify_ioctl = pDVar10;
        p_UBSEC_dsa_sign_ioctl = pDVar9;
        p_UBSEC_rsa_mod_exp_crt_ioctl = pDVar8;
        p_UBSEC_rsa_mod_exp_ioctl = pDVar7;
        p_UBSEC_diffie_hellman_agree_ioctl = pDVar6;
        p_UBSEC_diffie_hellman_generate_ioctl = pDVar5;
        p_UBSEC_ubsec_close = pDVar4;
        p_UBSEC_ubsec_open = pDVar3;
        p_UBSEC_ubsec_bits_to_bytes = pDVar2;
        p_UBSEC_ubsec_bytes_to_bits = pDVar1;
        iVar12 = (*pDVar3)("/dev/ubskey");
        if ((0 < iVar12) &&
           (iVar13 = (*p_UBSEC_max_key_len_ioctl)(iVar12,&max_key_len), iVar13 == 0)) {
          (*p_UBSEC_ubsec_close)(iVar12);
          return 1;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x69,0x6c,"e_ubsec.c",0x1d2);
        goto LAB_081a7e9b;
      }
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      iVar12 = 0x1b1;
    }
    ERR_put_error(UBSEC_lib_error_code,0x69,0x67,"e_ubsec.c",iVar12);
  }
  else {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x69,100,"e_ubsec.c",0x18c);
  }
LAB_081a7e9b:
  if (ubsec_dso != (DSO *)0x0) {
    DSO_free(ubsec_dso);
  }
  ubsec_dso = (DSO *)0x0;
  p_UBSEC_ubsec_bytes_to_bits = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_ubsec_bits_to_bytes = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_ubsec_open = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_ubsec_close = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_diffie_hellman_generate_ioctl = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_diffie_hellman_agree_ioctl = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_rsa_mod_exp_ioctl = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_rsa_mod_exp_crt_ioctl = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_dsa_sign_ioctl = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_dsa_verify_ioctl = (DSO_FUNC_TYPE)0x0;
  p_UBSEC_max_key_len_ioctl = (DSO_FUNC_TYPE)0x0;
  return 0;
}

