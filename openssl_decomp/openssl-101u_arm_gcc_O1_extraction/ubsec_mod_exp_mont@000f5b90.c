
int ubsec_mod_exp_mont(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                      BN_CTX *param_5,BN_MONT_CTX *param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  RSA_METHOD *pRVar6;
  BIGNUM *pBVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong *puVar10;
  int local_2c [2];
  
  iVar2 = BN_num_bits(param_4);
  if (max_key_len < iVar2) {
    pRVar6 = RSA_PKCS1_SSLeay();
    iVar2 = (*pRVar6->bn_mod_exp)(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    local_2c[0] = 0;
    if (ubsec_dso != 0) {
      local_2c[0] = BN_num_bits(param_4);
      if (max_key_len < local_2c[0]) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6a,0x6b,"e_ubsec.c",0x244);
      }
      else {
        if ((param_1->dmax < param_4->top) &&
           (pBVar7 = bn_expand2(param_1,param_4->top), pBVar7 == (BIGNUM *)0x0)) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(UBSEC_lib_error_code,0x6a,0x65,"e_ubsec.c",0x249);
          return 0;
        }
        iVar2 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
        pcVar1 = p_UBSEC_rsa_mod_exp_ioctl;
        if (iVar2 < 1) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(UBSEC_lib_error_code,0x6a,0x6c,"e_ubsec.c",0x24f);
        }
        else {
          puVar8 = param_2->d;
          iVar3 = BN_num_bits(param_2);
          puVar10 = param_4->d;
          iVar4 = BN_num_bits(param_4);
          puVar9 = param_3->d;
          iVar5 = BN_num_bits(param_3);
          iVar3 = (*pcVar1)(iVar2,puVar8,iVar3,puVar10,iVar4,puVar9,iVar5,param_1->d,local_2c);
          if (iVar3 == 0) {
            (*p_UBSEC_ubsec_close)(iVar2);
            iVar3 = BN_num_bits(param_4);
            iVar2 = iVar3 + 0x3e;
            if (-1 < iVar3 + 0x1f) {
              iVar2 = iVar3 + 0x1f;
            }
            param_1->top = iVar2 >> 5;
            return 1;
          }
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(UBSEC_lib_error_code,0x6a,0x6a,"e_ubsec.c",599);
          (*p_UBSEC_ubsec_close)(iVar2);
        }
      }
      iVar2 = BN_mod_exp(param_1,param_2,param_3,param_4,param_5);
      return iVar2;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x6a,0x69,"e_ubsec.c",0x23d);
    iVar2 = 0;
  }
  return iVar2;
}

