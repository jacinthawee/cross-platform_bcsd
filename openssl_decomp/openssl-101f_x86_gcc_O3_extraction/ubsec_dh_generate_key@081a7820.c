
int ubsec_dh_generate_key(DH *param_1)

{
  ulong *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  DH_METHOD *pDVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *a;
  int in_GS_OFFSET;
  int local_3c;
  int local_28;
  int local_24;
  int local_20;
  
  local_28 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = 0;
  local_3c = 0;
  a = param_1->priv_key;
  if (a == (BIGNUM *)0x0) {
    a = BN_new();
    if (a != (BIGNUM *)0x0) {
      local_24 = BN_num_bits(param_1->p);
      pBVar7 = param_1->p;
      if (pBVar7->top <= a->dmax) goto LAB_081a7a6a;
      pBVar7 = bn_expand2(a,pBVar7->top);
      if (pBVar7 == (BIGNUM *)0x0) {
        iVar3 = 0;
        goto LAB_081a791b;
      }
      do {
        pBVar7 = param_1->p;
LAB_081a7a6a:
        iVar3 = BN_rand_range(a,pBVar7);
        if (iVar3 == 0) {
          iVar3 = 0;
          goto LAB_081a791b;
        }
      } while (a->top == 0);
      local_3c = BN_num_bits(a);
      goto LAB_081a7859;
    }
LAB_081a7a0d:
    iVar3 = 0;
  }
  else {
LAB_081a7859:
    pBVar7 = param_1->pub_key;
    if (pBVar7 == (BIGNUM *)0x0) {
      pBVar7 = BN_new();
      local_28 = BN_num_bits(param_1->p);
      iVar3 = param_1->p->top;
      if (pBVar7->dmax < iVar3) {
        pBVar8 = bn_expand2(pBVar7,iVar3);
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_081a7a0d;
      }
    }
    iVar3 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar2 = p_UBSEC_diffie_hellman_generate_ioctl;
    if (iVar3 < 1) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6f,0x6c,"e_ubsec.c",0x3c2);
      pDVar6 = DH_OpenSSL();
      iVar3 = (*pDVar6->generate_key)(param_1);
    }
    else {
      iVar4 = BN_num_bits(param_1->p);
      puVar1 = param_1->p->d;
      iVar5 = BN_num_bits(param_1->g);
      iVar4 = (*pcVar2)(iVar3,a->d,&local_24,pBVar7->d,&local_28,param_1->g->d,iVar5,puVar1,iVar4,0,
                        0,local_3c);
      if (iVar4 == 0) {
        (*p_UBSEC_ubsec_close)(iVar3);
        param_1->pub_key = pBVar7;
        iVar3 = local_28 + 0x1f;
        if (local_28 + 0x1f < 0) {
          iVar3 = local_28 + 0x3e;
        }
        pBVar7->top = iVar3 >> 5;
        param_1->priv_key = a;
        iVar3 = local_24 + 0x1f;
        if (local_24 + 0x1f < 0) {
          iVar3 = local_24 + 0x3e;
        }
        a->top = iVar3 >> 5;
        iVar3 = 1;
      }
      else {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6f,0x6a,"e_ubsec.c",0x3d2);
        (*p_UBSEC_ubsec_close)(iVar3);
        pDVar6 = DH_OpenSSL();
        iVar3 = (*pDVar6->generate_key)(param_1);
      }
    }
  }
LAB_081a791b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

