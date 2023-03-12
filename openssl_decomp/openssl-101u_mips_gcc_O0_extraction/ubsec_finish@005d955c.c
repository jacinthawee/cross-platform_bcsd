
undefined4 ubsec_finish(void)

{
  int iVar1;
  
  if (UBSEC_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  UBSEC_LIBNAME = 0;
  if (ubsec_dso != 0) {
    iVar1 = (*(code *)PTR_DSO_free_006a8874)();
    if (iVar1 != 0) {
      ubsec_dso = 0;
      p_UBSEC_ubsec_bytes_to_bits = 0;
      p_UBSEC_ubsec_bits_to_bytes = 0;
      p_UBSEC_ubsec_open = 0;
      p_UBSEC_ubsec_close = 0;
      p_UBSEC_diffie_hellman_generate_ioctl = 0;
      p_UBSEC_diffie_hellman_agree_ioctl = 0;
      p_UBSEC_rsa_mod_exp_ioctl = 0;
      p_UBSEC_rsa_mod_exp_crt_ioctl = 0;
      p_UBSEC_dsa_sign_ioctl = 0;
      p_UBSEC_dsa_verify_ioctl = 0;
      p_UBSEC_max_key_len_ioctl = 0;
      return 1;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x68,0x67,"e_ubsec.c",0x207);
    return 0;
  }
  if (UBSEC_lib_error_code == 0) {
    UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x68,0x69,"e_ubsec.c",0x203);
  return 0;
}

