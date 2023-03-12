
/* WARNING: Restarted to delay deadcode elimination for space: ram */

BIGNUM * ubsec_dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  code *pcVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  undefined4 uVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  DSA_METHOD *pDVar9;
  ulong *puVar10;
  ulong *puVar11;
  ulong *puVar12;
  ulong *puVar13;
  undefined4 local_44;
  undefined4 local_40;
  BIGNUM BStack_3c;
  
  local_44 = 0xa0;
  local_40 = 0xa0;
  BN_init(&BStack_3c);
  a = BN_new();
  a_00 = BN_new();
  if (a == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) {
joined_r0x000f5b22:
    if (a_00 != (BIGNUM *)0x0) {
      BN_free(a_00);
    }
  }
  else {
    uVar2 = (*p_UBSEC_ubsec_bytes_to_bits)(param_1,param_2);
    if (((a_00->dmax < 5) && (pBVar3 = bn_expand2(a_00,5), pBVar3 == (BIGNUM *)0x0)) ||
       ((a->dmax < 5 && (pBVar3 = bn_expand2(a,5), pBVar3 == (BIGNUM *)0x0)))) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x66,0x65,"e_ubsec.c",0x301);
      goto joined_r0x000f5b22;
    }
    pBVar3 = BN_bin2bn(param_1,param_2,&BStack_3c);
    if (pBVar3 == (BIGNUM *)0x0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x66,0x65,"e_ubsec.c",0x306);
      goto joined_r0x000f5b22;
    }
    iVar4 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar1 = p_UBSEC_dsa_sign_ioctl;
    if (iVar4 < 1) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x66,0x6c,"e_ubsec.c",0x30d);
    }
    else {
      puVar10 = param_3->p->d;
      iVar5 = BN_num_bits(param_3->p);
      puVar12 = param_3->q->d;
      iVar6 = BN_num_bits(param_3->q);
      puVar11 = param_3->g->d;
      iVar7 = BN_num_bits(param_3->g);
      puVar13 = param_3->priv_key->d;
      iVar8 = BN_num_bits(param_3->priv_key);
      iVar5 = (*pcVar1)(iVar4,0,param_1,uVar2,0,0,puVar10,iVar5,puVar12,iVar6,puVar11,iVar7,puVar13,
                        iVar8,a_00->d,&local_40,a->d,&local_44);
      if (iVar5 == 0) {
        (*p_UBSEC_ubsec_close)(iVar4);
        a_00->top = 5;
        a->top = 5;
        pBVar3 = (BIGNUM *)DSA_SIG_new();
        if (pBVar3 != (BIGNUM *)0x0) {
          pBVar3->d = (ulong *)a_00;
          pBVar3->top = (int)a;
          goto LAB_000f5a56;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x66,0x65,"e_ubsec.c",0x333);
        goto joined_r0x000f5b22;
      }
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x66,0x6a,"e_ubsec.c",0x324);
      (*p_UBSEC_ubsec_close)(iVar4);
    }
    pDVar9 = DSA_OpenSSL();
    pBVar3 = (BIGNUM *)(*pDVar9->dsa_do_sign)(param_1,param_2,param_3);
    if (pBVar3 != (BIGNUM *)0x0) goto LAB_000f5a56;
    BN_free(a_00);
  }
  pBVar3 = a;
  if (a != (BIGNUM *)0x0) {
    pBVar3 = (BIGNUM *)0x0;
    BN_free(a);
  }
LAB_000f5a56:
  BN_clear_free(&BStack_3c);
  return pBVar3;
}

