
int ubsec_mod_exp_dh(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                    BIGNUM *param_5,BN_CTX *param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong *puVar9;
  int local_2c [2];
  
  local_2c[0] = 0;
  if (ubsec_dso == 0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x6a,0x69,"e_ubsec.c",0x234);
    return 0;
  }
  local_2c[0] = BN_num_bits(param_5);
  if (max_key_len < local_2c[0]) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    iVar3 = 0x23b;
    iVar2 = 0x6b;
  }
  else {
    if ((param_2->dmax < param_5->top) &&
       (pBVar6 = bn_expand2(param_2,param_5->top), pBVar6 == (BIGNUM *)0x0)) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6a,0x65,"e_ubsec.c",0x241);
      return 0;
    }
    iVar2 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar1 = p_UBSEC_rsa_mod_exp_ioctl;
    if (0 < iVar2) {
      puVar7 = param_3->d;
      iVar3 = BN_num_bits(param_3);
      puVar9 = param_5->d;
      iVar4 = BN_num_bits(param_5);
      puVar8 = param_4->d;
      iVar5 = BN_num_bits(param_4);
      iVar3 = (*pcVar1)(iVar2,puVar7,iVar3,puVar9,iVar4,puVar8,iVar5,param_2->d,local_2c);
      if (iVar3 == 0) {
        (*p_UBSEC_ubsec_close)(iVar2);
        iVar3 = BN_num_bits(param_5);
        iVar2 = iVar3 + 0x3e;
        if (-1 < iVar3 + 0x1f) {
          iVar2 = iVar3 + 0x1f;
        }
        param_2->top = iVar2 >> 5;
        return 1;
      }
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6a,0x6a,"e_ubsec.c",0x24f);
      (*p_UBSEC_ubsec_close)(iVar2);
      goto LAB_000f71d8;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    iVar3 = 0x247;
    iVar2 = 0x6c;
  }
  ERR_put_error(UBSEC_lib_error_code,0x6a,iVar2,"e_ubsec.c",iVar3);
LAB_000f71d8:
  iVar2 = BN_mod_exp(param_2,param_3,param_4,param_5,param_6);
  return iVar2;
}

