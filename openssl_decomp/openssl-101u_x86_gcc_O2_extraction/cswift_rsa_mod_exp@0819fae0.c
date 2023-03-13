
int cswift_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  bool bVar1;
  int iVar2;
  RSA_METHOD *pRVar3;
  BIGNUM *a_03;
  BIGNUM *a_04;
  int iVar4;
  BIGNUM *pBVar5;
  size_t extraout_ECX;
  size_t sVar6;
  size_t extraout_ECX_00;
  size_t extraout_ECX_01;
  size_t sVar7;
  size_t extraout_EDX;
  size_t sVar8;
  size_t extraout_EDX_00;
  size_t extraout_EDX_01;
  int in_GS_OFFSET;
  int line;
  undefined4 local_70;
  int local_6c;
  ulong *local_68;
  size_t local_64;
  ulong *local_60;
  undefined4 local_5c;
  uint local_58;
  uchar *local_54;
  uint local_50;
  uchar *local_4c;
  uint local_48;
  uchar *local_44;
  uint local_40;
  uchar *local_3c;
  uint local_38;
  uchar *local_34;
  undefined local_2d [13];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
      (param_3->dmp1 == (BIGNUM *)0x0)) ||
     ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x6b,0x69,"e_cswift.c",0x2e3);
    iVar2 = 0;
    goto LAB_0819fb73;
  }
  iVar2 = BN_num_bits(param_3->p);
  if ((((0x400 < iVar2) || (iVar2 = BN_num_bits(param_3->q), 0x400 < iVar2)) ||
      ((iVar2 = BN_num_bits(param_3->dmp1), 0x400 < iVar2 ||
       ((iVar2 = BN_num_bits(param_3->dmq1), 0x400 < iVar2 ||
        (iVar2 = BN_num_bits(param_3->iqmp), 0x400 < iVar2)))))) &&
     (pRVar3 = RSA_PKCS1_SSLeay(), pRVar3 != (RSA_METHOD *)0x0)) {
    iVar2 = (*pRVar3->rsa_mod_exp)(param_1,param_2,param_3,param_4);
    goto LAB_0819fb73;
  }
  pBVar5 = param_3->iqmp;
  local_54 = (uchar *)0x0;
  local_4c = (uchar *)0x0;
  local_44 = (uchar *)0x0;
  local_3c = (uchar *)0x0;
  local_34 = (uchar *)0x0;
  a = param_3->dmq1;
  a_00 = param_3->dmp1;
  a_01 = param_3->q;
  a_02 = param_3->p;
  iVar2 = (*p_CSwift_AcquireAccContext)(&local_70);
  if (iVar2 != 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    bVar1 = false;
    iVar2 = 0;
    a_03 = (BIGNUM *)0x0;
    a_04 = (BIGNUM *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x6a,0x6c,"e_cswift.c",0x270);
    goto LAB_081a00c5;
  }
  a_03 = BN_new();
  a_04 = BN_new();
  if ((a_04 == (BIGNUM *)0x0) || (a_03 == (BIGNUM *)0x0)) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x279;
    iVar4 = 0x66;
LAB_081a0188:
    bVar1 = true;
    iVar2 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x6a,iVar4,"e_cswift.c",line);
  }
  else {
    local_5c = 1;
    iVar4 = BN_num_bits(a_02);
    iVar2 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar2 = iVar4 + 0xe;
    }
    local_58 = iVar2 >> 3;
    if ((local_58 & 0x1f) == 0) {
      local_54 = (uchar *)CRYPTO_malloc(local_58,"e_cswift.c",0x24d);
      if (local_54 != (uchar *)0x0) {
        BN_bn2bin(a_02,local_54);
        goto LAB_0819fd0f;
      }
LAB_081a01b0:
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x28a;
LAB_081a01cb:
      iVar4 = 0x67;
      goto LAB_081a0188;
    }
    sVar7 = 0;
    do {
      local_58 = local_58 + 1;
      sVar7 = sVar7 + 1;
    } while ((local_58 & 0x1f) != 0);
    local_54 = (uchar *)CRYPTO_malloc(local_58,"e_cswift.c",0x24d);
    if (local_54 == (uchar *)0x0) goto LAB_081a01b0;
    BN_bn2bin(a_02,local_54 + sVar7);
    memset(local_54,0,sVar7);
LAB_0819fd0f:
    iVar4 = BN_num_bits(a_01);
    iVar2 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar2 = iVar4 + 0xe;
    }
    sVar7 = 0;
    local_50 = iVar2 >> 3;
    if ((local_50 & 0x1f) == 0) {
      local_4c = (uchar *)CRYPTO_malloc(local_50,"e_cswift.c",0x24d);
      if (local_4c == (uchar *)0x0) {
LAB_081a01d4:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x28e;
        goto LAB_081a01cb;
      }
      BN_bn2bin(a_01,local_4c);
    }
    else {
      do {
        local_50 = local_50 + 1;
        sVar7 = sVar7 + 1;
      } while ((local_50 & 0x1f) != 0);
      local_4c = (uchar *)CRYPTO_malloc(local_50,"e_cswift.c",0x24d);
      if (local_4c == (uchar *)0x0) goto LAB_081a01d4;
      BN_bn2bin(a_01,local_4c + sVar7);
      memset(local_4c,0,sVar7);
    }
    iVar4 = BN_num_bits(a_00);
    iVar2 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar2 = iVar4 + 0xe;
    }
    sVar7 = 0;
    local_48 = iVar2 >> 3;
    if ((local_48 & 0x1f) == 0) {
      local_44 = (uchar *)CRYPTO_malloc(local_48,"e_cswift.c",0x24d);
      if (local_44 == (uchar *)0x0) {
LAB_081a01f1:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x292;
        goto LAB_081a01cb;
      }
      BN_bn2bin(a_00,local_44);
    }
    else {
      do {
        local_48 = local_48 + 1;
        sVar7 = sVar7 + 1;
      } while ((local_48 & 0x1f) != 0);
      local_44 = (uchar *)CRYPTO_malloc(local_48,"e_cswift.c",0x24d);
      if (local_44 == (uchar *)0x0) goto LAB_081a01f1;
      BN_bn2bin(a_00,local_44 + sVar7);
      memset(local_44,0,sVar7);
    }
    iVar4 = BN_num_bits(a);
    iVar2 = iVar4 + 0xe;
    if (-1 < iVar4 + 7) {
      iVar2 = iVar4 + 7;
    }
    sVar7 = 0;
    local_40 = iVar2 >> 3;
    if ((local_40 & 0x1f) == 0) {
      local_3c = (uchar *)CRYPTO_malloc(local_40,"e_cswift.c",0x24d);
      if (local_3c == (uchar *)0x0) {
LAB_081a0278:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x296;
        goto LAB_081a01cb;
      }
      BN_bn2bin(a,local_3c);
    }
    else {
      do {
        local_40 = local_40 + 1;
        sVar7 = sVar7 + 1;
      } while ((local_40 & 0x1f) != 0);
      local_3c = (uchar *)CRYPTO_malloc(local_40,"e_cswift.c",0x24d);
      if (local_3c == (uchar *)0x0) goto LAB_081a0278;
      BN_bn2bin(a,local_3c + sVar7);
      memset(local_3c,0,sVar7);
    }
    iVar4 = BN_num_bits(pBVar5);
    iVar2 = iVar4 + 0xe;
    if (-1 < iVar4 + 7) {
      iVar2 = iVar4 + 7;
    }
    sVar7 = 0;
    local_38 = iVar2 >> 3;
    if ((local_38 & 0x1f) == 0) {
      local_34 = (uchar *)CRYPTO_malloc(local_38,"e_cswift.c",0x24d);
      if (local_34 == (uchar *)0x0) goto LAB_081a0306;
      sVar7 = extraout_EDX_00;
      BN_bn2bin(pBVar5,local_34);
      sVar6 = extraout_ECX_01;
      sVar8 = extraout_EDX_01;
LAB_0819ff4f:
      if (((a_03->dmax < param_2->top) &&
          (pBVar5 = bn_expand2(a_03,param_2->top), sVar6 = extraout_ECX_00, sVar7 = sVar8,
          pBVar5 == (BIGNUM *)0x0)) ||
         ((iVar2 = a_02->top + a_01->top, a_04->dmax < iVar2 &&
          (pBVar5 = bn_expand2(a_04,iVar2), sVar7 = sVar6, pBVar5 == (BIGNUM *)0x0))))
      goto LAB_081a0306;
      iVar2 = (*p_CSwift_AttachKeyParam)(local_70,&local_5c,sVar7);
      if (iVar2 == -0x2716) {
        ERR_CSWIFT_error_constprop_3();
        bVar1 = true;
        iVar2 = 0;
      }
      else {
        if (iVar2 == 0) {
          local_6c = BN_bn2bin(param_2,(uchar *)a_03->d);
          local_68 = a_03->d;
          iVar4 = BN_num_bits(a_02);
          sVar7 = ((iVar4 + 7) / 8) * 2;
          local_64 = sVar7;
          memset(a_04->d,0,sVar7);
          local_60 = a_04->d;
          iVar2 = (*p_CSwift_SimpleRequest)(local_70,1,&local_6c,1,&local_64,1,sVar7,iVar2);
          if (iVar2 == 0) {
            iVar2 = 1;
            bVar1 = true;
            BN_bin2bn((uchar *)a_04->d,local_64,param_1);
            goto LAB_081a00c5;
          }
          ERR_CSWIFT_error_constprop_3();
        }
        else {
          ERR_CSWIFT_error_constprop_3();
        }
        bVar1 = true;
        __sprintf_chk(local_2d,1,0xd,"%ld",iVar2);
        iVar2 = 0;
        ERR_add_error_data(2,"CryptoSwift error number is ",local_2d);
      }
    }
    else {
      do {
        local_38 = local_38 + 1;
        sVar7 = sVar7 + 1;
      } while ((local_38 & 0x1f) != 0);
      local_34 = (uchar *)CRYPTO_malloc(local_38,"e_cswift.c",0x24d);
      if (local_34 != (uchar *)0x0) {
        BN_bn2bin(pBVar5,local_34 + sVar7);
        memset(local_34,0,sVar7);
        sVar6 = extraout_ECX;
        sVar8 = extraout_EDX;
        goto LAB_0819ff4f;
      }
LAB_081a0306:
      bVar1 = true;
      ERR_CSWIFT_error_constprop_3();
      iVar2 = 0;
    }
  }
LAB_081a00c5:
  if (local_54 != (uchar *)0x0) {
    CRYPTO_free(local_54);
  }
  if (local_4c != (uchar *)0x0) {
    CRYPTO_free(local_4c);
  }
  if (local_44 != (uchar *)0x0) {
    CRYPTO_free(local_44);
  }
  if (local_3c != (uchar *)0x0) {
    CRYPTO_free(local_3c);
  }
  if (local_34 != (uchar *)0x0) {
    CRYPTO_free(local_34);
  }
  if (a_04 != (BIGNUM *)0x0) {
    BN_free(a_04);
  }
  if (a_03 != (BIGNUM *)0x0) {
    BN_free(a_03);
  }
  if (bVar1) {
    (*p_CSwift_ReleaseAccContext)(local_70);
  }
LAB_0819fb73:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

