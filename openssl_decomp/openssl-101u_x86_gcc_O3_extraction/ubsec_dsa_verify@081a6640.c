
int ubsec_dsa_verify(uchar *param_1,int param_2,DSA_SIG *param_3,DSA *param_4)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong *puVar5;
  code *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  BIGNUM *pBVar15;
  DSA_METHOD *pDVar16;
  int in_GS_OFFSET;
  int local_38;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_34);
  pBVar15 = param_4->p;
  if (local_34.dmax < pBVar15->top) {
    pBVar15 = bn_expand2(&local_34,pBVar15->top);
    if (pBVar15 == (BIGNUM *)0x0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      iVar9 = 0;
      ERR_put_error(UBSEC_lib_error_code,0x67,0x65,"e_ubsec.c",0x350);
      goto LAB_081a67b5;
    }
    pBVar15 = param_4->p;
  }
  local_38 = BN_num_bits(pBVar15);
  uVar7 = (*p_UBSEC_ubsec_bytes_to_bits)(param_1,param_2);
  iVar8 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
  pcVar6 = p_UBSEC_dsa_verify_ioctl;
  if (iVar8 < 1) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x67,0x6c,"e_ubsec.c",0x35b);
    pDVar16 = DSA_OpenSSL();
    iVar9 = (*pDVar16->dsa_do_verify)(param_1,param_2,param_3,param_4);
  }
  else {
    iVar9 = BN_num_bits(param_3->s);
    puVar1 = param_3->s->d;
    iVar10 = BN_num_bits(param_3->r);
    puVar2 = param_3->r->d;
    iVar11 = BN_num_bits(param_4->pub_key);
    puVar3 = param_4->pub_key->d;
    iVar12 = BN_num_bits(param_4->g);
    puVar4 = param_4->g->d;
    iVar13 = BN_num_bits(param_4->q);
    puVar5 = param_4->q->d;
    iVar14 = BN_num_bits(param_4->p);
    iVar9 = (*pcVar6)(iVar8,0,param_1,uVar7,param_4->p->d,iVar14,puVar5,iVar13,puVar4,iVar12,puVar3,
                      iVar11,puVar2,iVar10,puVar1,iVar9,local_34.d,&local_38);
    if (iVar9 == 0) {
      iVar9 = 1;
      (*p_UBSEC_ubsec_close)(iVar8);
    }
    else {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x67,0x6a,"e_ubsec.c",0x371);
      (*p_UBSEC_ubsec_close)(iVar8);
      pDVar16 = DSA_OpenSSL();
      iVar9 = (*pDVar16->dsa_do_verify)(param_1,param_2,param_3,param_4);
    }
  }
LAB_081a67b5:
  BN_clear_free(&local_34);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

