
DSA_SIG * cswift_dsa_sign(undefined4 param_1,undefined4 param_2,int param_3)

{
  BN_CTX *ctx;
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar3;
  DSA_SIG *pDVar4;
  BIGNUM *pBVar5;
  int in_GS_OFFSET;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  size_t local_64;
  ulong *local_60;
  undefined4 local_5c;
  int local_58;
  ulong *local_54;
  int local_50;
  ulong *local_4c;
  int local_48;
  ulong *local_44;
  int local_40;
  ulong *local_3c;
  undefined local_2d [13];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    pDVar4 = (DSA_SIG *)0x0;
    goto LAB_081a1c24;
  }
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_70);
  if (iVar1 == 0) {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    a_01 = BN_CTX_get(ctx);
    a_02 = BN_CTX_get(ctx);
    if (a_02 == (BIGNUM *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x348;
      iVar1 = 0x66;
LAB_081a1c5c:
      pDVar4 = (DSA_SIG *)0x0;
      ERR_put_error(CSWIFT_lib_error_code,0x65,iVar1,"e_cswift.c",iVar3);
    }
    else {
      iVar1 = *(int *)(*(int *)(param_3 + 0xc) + 4);
      if (pBVar2->dmax < iVar1) {
        pBVar5 = bn_expand2(pBVar2,iVar1);
        if (pBVar5 != (BIGNUM *)0x0) goto LAB_081a19f8;
LAB_081a1c85:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x351;
        iVar1 = 0x67;
        goto LAB_081a1c5c;
      }
LAB_081a19f8:
      iVar1 = *(int *)(*(int *)(param_3 + 0x10) + 4);
      if (a->dmax < iVar1) {
        pBVar5 = bn_expand2(a,iVar1);
        if (pBVar5 != (BIGNUM *)0x0) {
          iVar1 = *(int *)(*(int *)(param_3 + 0x14) + 4);
          if (a_00->dmax < iVar1) goto LAB_081a1ccb;
          goto LAB_081a1a19;
        }
        goto LAB_081a1c85;
      }
      iVar1 = *(int *)(*(int *)(param_3 + 0x14) + 4);
      if (a_00->dmax < iVar1) {
LAB_081a1ccb:
        pBVar5 = bn_expand2(a_00,iVar1);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_081a1c85;
        iVar1 = *(int *)(*(int *)(param_3 + 0x1c) + 4);
        if (a_01->dmax < iVar1) goto LAB_081a1cf2;
LAB_081a1a2c:
        pBVar5 = *(BIGNUM **)(param_3 + 0xc);
        iVar1 = pBVar5->top;
        if (a_02->dmax < iVar1) {
LAB_081a1d1d:
          pBVar5 = bn_expand2(a_02,iVar1);
          if (pBVar5 == (BIGNUM *)0x0) goto LAB_081a1c85;
          pBVar5 = *(BIGNUM **)(param_3 + 0xc);
        }
      }
      else {
LAB_081a1a19:
        iVar1 = *(int *)(*(int *)(param_3 + 0x1c) + 4);
        if (iVar1 <= a_01->dmax) goto LAB_081a1a2c;
LAB_081a1cf2:
        pBVar5 = bn_expand2(a_01,iVar1);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_081a1c85;
        pBVar5 = *(BIGNUM **)(param_3 + 0xc);
        iVar1 = pBVar5->top;
        if (a_02->dmax < iVar1) goto LAB_081a1d1d;
      }
      local_5c = 3;
      local_58 = BN_bn2bin(pBVar5,(uchar *)pBVar2->d);
      local_54 = pBVar2->d;
      local_50 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x10),(uchar *)a->d);
      local_4c = a->d;
      local_48 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x14),(uchar *)a_00->d);
      local_44 = a_00->d;
      local_40 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x1c),(uchar *)a_01->d);
      local_3c = a_01->d;
      iVar1 = (*p_CSwift_AttachKeyParam)(local_70,&local_5c);
      if (iVar1 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x368;
        iVar1 = 0x65;
        goto LAB_081a1c5c;
      }
      if (iVar1 == 0) {
        local_6c = param_2;
        local_68 = param_1;
        iVar3 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
        iVar1 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar1 = iVar3 + 0xe;
        }
        local_64 = iVar1 >> 3;
        memset(a_02->d,0,local_64);
        local_60 = a_02->d;
        iVar1 = (*p_CSwift_SimpleRequest)(local_70,3,&local_6c,1,&local_64,1);
        if (iVar1 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c",0x37f);
          goto LAB_081a1bd8;
        }
        pDVar4 = DSA_SIG_new();
        if (pDVar4 != (DSA_SIG *)0x0) {
          pBVar2 = BN_bin2bn((uchar *)a_02->d,0x14,(BIGNUM *)0x0);
          pDVar4->r = pBVar2;
          pBVar2 = BN_bin2bn((uchar *)(a_02->d + 5),0x14,(BIGNUM *)0x0);
          pDVar4->s = pBVar2;
        }
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c",0x36d);
LAB_081a1bd8:
        __sprintf_chk(local_2d,1,0xd,"%ld",iVar1);
        pDVar4 = (DSA_SIG *)0x0;
        ERR_add_error_data(2,"CryptoSwift error number is ",local_2d);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_70);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    pDVar4 = (DSA_SIG *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x65,0x6c,"e_cswift.c",0x33b);
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_081a1c24:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pDVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

