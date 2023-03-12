
void ubsec_dh_compute_key(uchar *param_1,BIGNUM *param_2,DH *param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  DH_METHOD *pDVar8;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = BN_num_bits(param_3->p);
  iVar4 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
  pcVar3 = p_UBSEC_diffie_hellman_agree_ioctl;
  if (iVar4 < 1) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x65,0x6c,"e_ubsec.c",0x376);
    pDVar8 = DH_OpenSSL();
  }
  else {
    iVar5 = BN_num_bits(param_3->p);
    puVar1 = param_3->p->d;
    iVar6 = BN_num_bits(param_2);
    puVar2 = param_2->d;
    iVar7 = BN_num_bits(param_3->priv_key);
    iVar5 = (*pcVar3)(iVar4,param_3->priv_key->d,iVar7,puVar2,iVar6,puVar1,iVar5,param_1,&local_24);
    if (iVar5 == 0) {
      (*p_UBSEC_ubsec_close)(iVar4);
      (*p_UBSEC_ubsec_bits_to_bytes)(local_24);
      goto LAB_081a74a6;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x65,0x6a,"e_ubsec.c",900);
    (*p_UBSEC_ubsec_close)(iVar4);
    pDVar8 = DH_OpenSSL();
  }
  (*pDVar8->compute_key)(param_1,param_2,param_3);
LAB_081a74a6:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

