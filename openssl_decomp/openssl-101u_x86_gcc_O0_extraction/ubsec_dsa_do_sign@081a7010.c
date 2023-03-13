
DSA_SIG * ubsec_dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong *puVar5;
  code *pcVar6;
  BIGNUM *a;
  BIGNUM *a_00;
  undefined4 uVar7;
  BIGNUM *pBVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  DSA_SIG *pDVar14;
  DSA_METHOD *pDVar15;
  int in_GS_OFFSET;
  undefined4 local_3c;
  undefined4 local_38;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = 0xa0;
  local_38 = 0xa0;
  BN_init(&local_34);
  a = BN_new();
  a_00 = BN_new();
  if ((a == (BIGNUM *)0x0) || (a_00 == (BIGNUM *)0x0)) {
    if (a_00 != (BIGNUM *)0x0) {
      BN_free(a_00);
    }
  }
  else {
    uVar7 = (*p_UBSEC_ubsec_bytes_to_bits)(param_1,param_2);
    if (((a_00->dmax < 5) && (pBVar8 = bn_expand2(a_00,5), pBVar8 == (BIGNUM *)0x0)) ||
       ((a->dmax < 5 && (pBVar8 = bn_expand2(a,5), pBVar8 == (BIGNUM *)0x0)))) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      iVar9 = 0x301;
LAB_081a7291:
      ERR_put_error(UBSEC_lib_error_code,0x66,0x65,"e_ubsec.c",iVar9);
    }
    else {
      pBVar8 = BN_bin2bn(param_1,param_2,&local_34);
      if (pBVar8 == (BIGNUM *)0x0) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        iVar9 = 0x306;
        goto LAB_081a7291;
      }
      iVar9 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar6 = p_UBSEC_dsa_sign_ioctl;
      if (iVar9 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x66,0x6c,"e_ubsec.c",0x30d);
        pDVar15 = DSA_OpenSSL();
      }
      else {
        puVar1 = a_00->d;
        puVar2 = a->d;
        iVar10 = BN_num_bits(param_3->priv_key);
        puVar3 = param_3->priv_key->d;
        iVar11 = BN_num_bits(param_3->g);
        puVar4 = param_3->g->d;
        iVar12 = BN_num_bits(param_3->q);
        puVar5 = param_3->q->d;
        iVar13 = BN_num_bits(param_3->p);
        iVar10 = (*pcVar6)(iVar9,0,param_1,uVar7,0,0,param_3->p->d,iVar13,puVar5,iVar12,puVar4,
                           iVar11,puVar3,iVar10,puVar1,&local_38,puVar2,&local_3c);
        if (iVar10 == 0) {
          (*p_UBSEC_ubsec_close)(iVar9);
          a_00->top = 5;
          a->top = 5;
          pDVar14 = DSA_SIG_new();
          if (pDVar14 != (DSA_SIG *)0x0) {
            pDVar14->r = a_00;
            pDVar14->s = a;
            goto LAB_081a71b9;
          }
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = ERR_get_next_error_library();
          }
          iVar9 = 0x333;
          goto LAB_081a7291;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x66,0x6a,"e_ubsec.c",0x324);
        (*p_UBSEC_ubsec_close)(iVar9);
        pDVar15 = DSA_OpenSSL();
      }
      pDVar14 = (*pDVar15->dsa_do_sign)(param_1,param_2,param_3);
      if (pDVar14 != (DSA_SIG *)0x0) goto LAB_081a71b9;
    }
    BN_free(a_00);
  }
  pDVar14 = (DSA_SIG *)0x0;
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
LAB_081a71b9:
  BN_clear_free(&local_34);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pDVar14;
}

