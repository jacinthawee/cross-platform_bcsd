
int ubsec_mod_exp_mont(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                      BN_CTX *param_5,BN_MONT_CTX *param_6)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  RSA_METHOD *pRVar9;
  BIGNUM *pBVar10;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = BN_num_bits(param_4);
  if (max_key_len < iVar5) {
    pRVar9 = RSA_PKCS1_SSLeay();
    iVar5 = (*pRVar9->bn_mod_exp)(param_1,param_2,param_3,param_4,param_5,param_6);
    goto LAB_081a612a;
  }
  local_24 = 0;
  if (ubsec_dso == 0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    iVar6 = 0x23d;
    iVar5 = 0x69;
LAB_081a6207:
    ERR_put_error(UBSEC_lib_error_code,0x6a,iVar5,"e_ubsec.c",iVar6);
    iVar5 = 0;
  }
  else {
    local_24 = BN_num_bits(param_4);
    if (max_key_len < local_24) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6a,0x6b,"e_ubsec.c",0x244);
    }
    else {
      if (param_1->dmax < param_4->top) {
        pBVar10 = bn_expand2(param_1,param_4->top);
        if (pBVar10 == (BIGNUM *)0x0) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = ERR_get_next_error_library();
          }
          iVar6 = 0x249;
          iVar5 = 0x65;
          goto LAB_081a6207;
        }
      }
      iVar5 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar4 = p_UBSEC_rsa_mod_exp_ioctl;
      if (iVar5 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6a,0x6c,"e_ubsec.c",0x24f);
      }
      else {
        puVar1 = param_1->d;
        iVar6 = BN_num_bits(param_3);
        puVar2 = param_3->d;
        iVar7 = BN_num_bits(param_4);
        puVar3 = param_4->d;
        iVar8 = BN_num_bits(param_2);
        iVar6 = (*pcVar4)(iVar5,param_2->d,iVar8,puVar3,iVar7,puVar2,iVar6,puVar1,&local_24);
        if (iVar6 == 0) {
          (*p_UBSEC_ubsec_close)(iVar5);
          iVar6 = BN_num_bits(param_4);
          iVar5 = iVar6 + 0x1f;
          if (iVar6 + 0x1f < 0) {
            iVar5 = iVar6 + 0x3e;
          }
          param_1->top = iVar5 >> 5;
          iVar5 = 1;
          goto LAB_081a612a;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6a,0x6a,"e_ubsec.c",599);
        (*p_UBSEC_ubsec_close)(iVar5);
      }
    }
    iVar5 = BN_mod_exp(param_1,param_2,param_3,param_4,param_5);
  }
LAB_081a612a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

