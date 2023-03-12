
int ubsec_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  BIGNUM *pBVar15;
  RSA_METHOD *pRVar16;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  a = param_3->p;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((a == (BIGNUM *)0x0) || (a_00 = param_3->q, a_00 == (BIGNUM *)0x0)) ||
      (a_01 = param_3->dmp1, a_01 == (BIGNUM *)0x0)) ||
     ((a_02 = param_3->dmq1, a_02 == (BIGNUM *)0x0 || (a_03 = param_3->iqmp, a_03 == (BIGNUM *)0x0))
     )) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x6c,0x68,"e_ubsec.c",0x262);
    iVar8 = 0;
  }
  else {
    local_24 = BN_num_bits(a);
    iVar8 = BN_num_bits(a_00);
    local_24 = local_24 + iVar8;
    if (max_key_len < local_24) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6e,0x6b,"e_ubsec.c",0x27f);
    }
    else {
      iVar8 = a_00->top + a->top;
      if (param_1->dmax <= iVar8) {
        pBVar15 = bn_expand2(param_1,iVar8 + 1);
        if (pBVar15 == (BIGNUM *)0x0) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(UBSEC_lib_error_code,0x6e,0x65,"e_ubsec.c",0x284);
          iVar8 = 0;
          goto LAB_081a8429;
        }
      }
      iVar8 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar7 = p_UBSEC_rsa_mod_exp_crt_ioctl;
      if (iVar8 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6e,0x6c,"e_ubsec.c",0x28a);
      }
      else {
        puVar1 = param_1->d;
        iVar9 = BN_num_bits(a_00);
        puVar2 = a_00->d;
        iVar10 = BN_num_bits(a_02);
        puVar3 = a_02->d;
        iVar11 = BN_num_bits(a);
        puVar4 = a->d;
        iVar12 = BN_num_bits(a_01);
        puVar5 = a_01->d;
        iVar13 = BN_num_bits(a_03);
        puVar6 = a_03->d;
        iVar14 = BN_num_bits(param_2);
        iVar9 = (*pcVar7)(iVar8,param_2->d,iVar14,puVar6,iVar13,puVar5,iVar12,puVar4,iVar11,puVar3,
                          iVar10,puVar2,iVar9,puVar1,&local_24);
        if (iVar9 == 0) {
          (*p_UBSEC_ubsec_close)(iVar8);
          iVar9 = BN_num_bits(a);
          iVar10 = BN_num_bits(a_00);
          iVar8 = iVar10 + iVar9 + 0x1f;
          if (iVar8 < 0) {
            iVar8 = iVar10 + iVar9 + 0x3e;
          }
          param_1->top = iVar8 >> 5;
          iVar8 = 1;
          goto LAB_081a8429;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6e,0x6a,"e_ubsec.c",0x296);
        (*p_UBSEC_ubsec_close)(iVar8);
      }
    }
    pRVar16 = RSA_PKCS1_SSLeay();
    iVar8 = (*pRVar16->rsa_mod_exp)(param_1,param_2,param_3,param_4);
  }
LAB_081a8429:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

