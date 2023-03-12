
void cswift_dsa_sign(undefined4 param_1,undefined4 param_2,int param_3)

{
  DSA_SIG *ctx;
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *pBVar3;
  int iVar4;
  ulong *puVar5;
  DSA_SIG *pDVar6;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  size_t local_70;
  ulong *local_6c;
  undefined4 local_68;
  int local_64;
  ulong *local_60;
  int local_5c;
  ulong *local_58;
  int local_54;
  ulong *local_50;
  int local_4c;
  ulong *local_48;
  undefined auStack_3c [16];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  ctx = (DSA_SIG *)BN_CTX_new();
  if (ctx == (DSA_SIG *)0x0) goto LAB_000f0a60;
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
  if (iVar1 == 0) {
    BN_CTX_start((BN_CTX *)ctx);
    pBVar2 = BN_CTX_get((BN_CTX *)ctx);
    a = BN_CTX_get((BN_CTX *)ctx);
    a_00 = BN_CTX_get((BN_CTX *)ctx);
    a_01 = BN_CTX_get((BN_CTX *)ctx);
    a_02 = BN_CTX_get((BN_CTX *)ctx);
    if (a_02 == (BIGNUM *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      pDVar6 = (DSA_SIG *)0x0;
      ERR_put_error(CSWIFT_lib_error_code,0x65,0x66,"e_cswift.c",0x339);
      goto LAB_000f0bea;
    }
    iVar1 = *(int *)(*(int *)(param_3 + 0xc) + 4);
    if (pBVar2->dmax < iVar1) {
      pBVar3 = bn_expand2(pBVar2,iVar1);
      if (pBVar3 != (BIGNUM *)0x0) {
        iVar1 = *(int *)(*(int *)(param_3 + 0x10) + 4);
        if (a->dmax < iVar1) goto LAB_000f0c68;
        goto LAB_000f0ac2;
      }
LAB_000f0bfc:
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      pDVar6 = (DSA_SIG *)0x0;
      ERR_put_error(CSWIFT_lib_error_code,0x65,0x67,"e_cswift.c",0x341);
    }
    else {
      iVar1 = *(int *)(*(int *)(param_3 + 0x10) + 4);
      if (a->dmax < iVar1) {
LAB_000f0c68:
        pBVar3 = bn_expand2(a,iVar1);
        if (pBVar3 == (BIGNUM *)0x0) goto LAB_000f0bfc;
      }
LAB_000f0ac2:
      iVar1 = *(int *)(*(int *)(param_3 + 0x14) + 4);
      if ((a_00->dmax < iVar1) && (pBVar3 = bn_expand2(a_00,iVar1), pBVar3 == (BIGNUM *)0x0))
      goto LAB_000f0bfc;
      iVar1 = *(int *)(*(int *)(param_3 + 0x1c) + 4);
      if (a_01->dmax < iVar1) {
        pBVar3 = bn_expand2(a_01,iVar1);
        if (pBVar3 == (BIGNUM *)0x0) goto LAB_000f0bfc;
        pBVar3 = *(BIGNUM **)(param_3 + 0xc);
        iVar1 = pBVar3->top;
        if (a_02->dmax < iVar1) goto LAB_000f0c42;
      }
      else {
        pBVar3 = *(BIGNUM **)(param_3 + 0xc);
        iVar1 = pBVar3->top;
        if (a_02->dmax < iVar1) {
LAB_000f0c42:
          pBVar3 = bn_expand2(a_02,iVar1);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_000f0bfc;
          pBVar3 = *(BIGNUM **)(param_3 + 0xc);
        }
      }
      local_68 = 3;
      local_64 = BN_bn2bin(pBVar3,(uchar *)pBVar2->d);
      local_60 = pBVar2->d;
      local_5c = BN_bn2bin(*(BIGNUM **)(param_3 + 0x10),(uchar *)a->d);
      local_58 = a->d;
      local_54 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x14),(uchar *)a_00->d);
      local_50 = a_00->d;
      local_4c = BN_bn2bin(*(BIGNUM **)(param_3 + 0x1c),(uchar *)a_01->d);
      local_48 = a_01->d;
      iVar1 = (*p_CSwift_AttachKeyParam)(local_7c,&local_68);
      if (iVar1 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        pDVar6 = (DSA_SIG *)0x0;
        ERR_put_error(CSWIFT_lib_error_code,0x65,0x65,"e_cswift.c",0x354);
      }
      else {
        if (iVar1 == 0) {
          local_78 = param_2;
          local_74 = param_1;
          iVar4 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
          iVar1 = iVar4 + 0xe;
          if (-1 < iVar4 + 7) {
            iVar1 = iVar4 + 7;
          }
          local_70 = iVar1 >> 3;
          memset(a_02->d,0,local_70);
          local_6c = a_02->d;
          iVar1 = (*p_CSwift_SimpleRequest)(local_7c,3,&local_78,1,&local_70,1);
          if (iVar1 == 0) {
            pDVar6 = DSA_SIG_new();
            if (pDVar6 != (DSA_SIG *)0x0) {
              pBVar2 = BN_bin2bn((uchar *)a_02->d,0x14,(BIGNUM *)0x0);
              puVar5 = a_02->d;
              pDVar6->r = pBVar2;
              pBVar2 = BN_bin2bn((uchar *)(puVar5 + 5),0x14,(BIGNUM *)0x0);
              pDVar6->s = pBVar2;
            }
            goto LAB_000f0bea;
          }
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar4 = 0x36a;
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar4 = 0x359;
        }
        pDVar6 = (DSA_SIG *)0x0;
        ERR_put_error(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c",iVar4);
        __sprintf_chk(auStack_3c,1,0xd,&DAT_00168298,iVar1);
        ERR_add_error_data(2,"CryptoSwift error number is ",auStack_3c);
      }
    }
LAB_000f0bea:
    (*p_CSwift_ReleaseAccContext)(local_7c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    pDVar6 = (DSA_SIG *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x65,0x6c,"e_cswift.c",0x32d);
  }
  BN_CTX_end((BN_CTX *)ctx);
  BN_CTX_free((BN_CTX *)ctx);
  ctx = pDVar6;
LAB_000f0a60:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ctx);
  }
  return;
}

