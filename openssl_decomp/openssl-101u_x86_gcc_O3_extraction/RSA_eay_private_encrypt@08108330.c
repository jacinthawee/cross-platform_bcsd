
/* WARNING: Removing unreachable block (ram,0x081086b9) */

size_t RSA_eay_private_encrypt(int param_1,uchar *param_2,void *param_3,int param_4,int param_5)

{
  ulong **ppuVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *n;
  int iVar2;
  uchar *to;
  BIGNUM *pBVar3;
  uint uVar4;
  BN_MONT_CTX *pBVar5;
  size_t len;
  size_t sVar6;
  int in_GS_OFFSET;
  int iVar7;
  BIGNUM *local_50;
  BN_BLINDING *local_4c;
  BIGNUM *local_48;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    sVar6 = 0xffffffff;
    goto LAB_08108448;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  n = BN_CTX_get(ctx);
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar7 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar7 = iVar2 + 7;
  }
  len = iVar7 >> 3;
  to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0x172);
  if ((ret == (BIGNUM *)0x0 || n == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar6 = 0xffffffff;
    ERR_put_error(4,0x66,0x41,"rsa_eay.c",0x174);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) goto LAB_08108448;
  }
  else {
    if (param_5 != 3) {
      if (param_5 == 5) {
        iVar7 = RSA_padding_add_X931(to,len,param_2,param_1);
        goto LAB_0810847d;
      }
      if (param_5 == 1) {
        iVar7 = RSA_padding_add_PKCS1_type_1(to,len,param_2,param_1);
        goto LAB_0810847d;
      }
      iVar2 = 0x184;
      iVar7 = 0x76;
      goto LAB_0810840a;
    }
    iVar7 = RSA_padding_add_none(to,len,param_2,param_1);
LAB_0810847d:
    if ((iVar7 < 1) || (pBVar3 = BN_bin2bn(to,len,ret), pBVar3 == (BIGNUM *)0x0)) goto LAB_08108416;
    iVar7 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
    if (iVar7 < 0) {
      uVar4 = *(uint *)(param_4 + 0x3c);
      local_4c = (BN_BLINDING *)0x0;
      local_48 = (BIGNUM *)0x0;
      if ((uVar4 & 0x80) == 0) {
        local_4c = (BN_BLINDING *)rsa_get_blinding();
        if (local_4c == (BN_BLINDING *)0x0) {
          iVar2 = 0x197;
          iVar7 = 0x44;
        }
        else {
          local_48 = BN_CTX_get(ctx);
          if (local_48 != (BIGNUM *)0x0) {
            CRYPTO_lock((int)local_48,9,(char *)0x19,(int)"rsa_eay.c");
            iVar7 = BN_BLINDING_convert_ex(ret,local_48,local_4c,ctx);
            CRYPTO_lock(iVar7,10,(char *)0x19,(int)"rsa_eay.c");
            if (iVar7 == 0) goto LAB_08108416;
            uVar4 = *(uint *)(param_4 + 0x3c);
            goto LAB_081084c8;
          }
          iVar2 = 0x19e;
          iVar7 = 0x41;
        }
        goto LAB_0810840a;
      }
LAB_081084c8:
      if (((uVar4 & 0x20) == 0) &&
         ((((*(int *)(param_4 + 0x1c) == 0 || (*(int *)(param_4 + 0x20) == 0)) ||
           (*(int *)(param_4 + 0x24) == 0)) ||
          ((*(int *)(param_4 + 0x28) == 0 || (*(int *)(param_4 + 0x2c) == 0)))))) {
        if ((uVar4 & 0x100) == 0) {
          pBVar3 = &local_34;
          BN_init(pBVar3);
          ppuVar1 = *(ulong ***)(param_4 + 0x18);
          local_34.d = *ppuVar1;
          local_34.top = (int)ppuVar1[1];
          local_34.dmax = (int)ppuVar1[2];
          local_34.neg = (int)ppuVar1[3];
          local_34.flags = (uint)ppuVar1[4] & 0xfffffffe | local_34.flags & 1U | 6;
          uVar4 = *(uint *)(param_4 + 0x3c);
        }
        else {
          pBVar3 = *(BIGNUM **)(param_4 + 0x18);
        }
        if ((((uVar4 & 2) == 0) ||
            (pBVar5 = BN_MONT_CTX_set_locked
                                ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),ctx
                                ), pBVar5 != (BN_MONT_CTX *)0x0)) &&
           (iVar7 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                              (n,ret,pBVar3,*(undefined4 *)(param_4 + 0x10),ctx,
                               *(undefined4 *)(param_4 + 0x40)), iVar7 != 0)) goto LAB_0810851b;
        goto LAB_08108416;
      }
      iVar7 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(n,ret,param_4,ctx);
      if (iVar7 == 0) goto LAB_08108416;
LAB_0810851b:
      if ((local_4c != (BN_BLINDING *)0x0) &&
         (iVar7 = BN_BLINDING_invert_ex(n,local_48,local_4c,ctx), iVar7 == 0)) goto LAB_08108416;
      local_50 = n;
      if (param_5 == 5) {
        BN_sub(ret,*(BIGNUM **)(param_4 + 0x10),n);
        iVar7 = BN_cmp(n,ret);
        local_50 = ret;
        if (iVar7 < 1) {
          local_50 = n;
        }
      }
      iVar2 = BN_num_bits(local_50);
      iVar7 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar7 = iVar2 + 0xe;
      }
      iVar7 = BN_bn2bin(local_50,(uchar *)((len - (iVar7 >> 3)) + (int)param_3));
      sVar6 = len;
      if (0 < (int)(len - iVar7)) {
        memset(param_3,0,len - iVar7);
      }
    }
    else {
      iVar2 = 400;
      iVar7 = 0x84;
LAB_0810840a:
      ERR_put_error(4,0x66,iVar7,"rsa_eay.c",iVar2);
LAB_08108416:
      sVar6 = 0xffffffff;
    }
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
LAB_08108448:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

