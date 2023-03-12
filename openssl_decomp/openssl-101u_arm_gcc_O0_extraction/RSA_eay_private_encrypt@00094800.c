
size_t RSA_eay_private_encrypt(int param_1,uchar *param_2,void *param_3,int param_4,int param_5)

{
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *n;
  int iVar1;
  uchar *to;
  BIGNUM *pBVar2;
  BN_MONT_CTX *pBVar3;
  int iVar4;
  ulong **ppuVar5;
  uint uVar6;
  size_t sVar7;
  size_t len;
  BN_BLINDING *b;
  BIGNUM *local_44;
  int local_40;
  BIGNUM local_3c;
  
  local_40 = 0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  n = BN_CTX_get(ctx);
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar4 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar4 = iVar1 + 7;
  }
  len = iVar4 >> 3;
  to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0x172);
  if ((n == (BIGNUM *)0x0 || ret == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar7 = 0xffffffff;
    ERR_put_error(4,0x66,0x41,"rsa_eay.c",0x174);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return 0xffffffff;
    }
    goto LAB_000948a6;
  }
  if (param_5 == 3) {
    iVar4 = RSA_padding_add_none(to,len,param_2,param_1);
LAB_000948c6:
    if ((iVar4 < 1) || (pBVar2 = BN_bin2bn(to,len,ret), pBVar2 == (BIGNUM *)0x0)) {
LAB_000949b2:
      sVar7 = 0xffffffff;
    }
    else {
      iVar4 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
      if (iVar4 < 0) {
        uVar6 = *(uint *)(param_4 + 0x3c);
        local_44 = (BIGNUM *)(uVar6 & 0x80);
        if (local_44 == (BIGNUM *)0x0) {
          b = (BN_BLINDING *)rsa_get_blinding(param_4,&local_40,ctx);
          if (b == (BN_BLINDING *)0x0) {
            ERR_put_error(4,0x66,0x44,"rsa_eay.c",0x197);
            sVar7 = 0xffffffff;
            goto LAB_0009489a;
          }
          if (local_40 == 0) {
            local_44 = BN_CTX_get(ctx);
            if (local_44 == (BIGNUM *)0x0) {
              ERR_put_error(4,0x66,0x41,"rsa_eay.c",0x19e);
              sVar7 = 0xffffffff;
              goto LAB_0009489a;
            }
            CRYPTO_lock(9,0x19,"rsa_eay.c",0x146);
            iVar4 = BN_BLINDING_convert_ex(ret,local_44,b,ctx);
            CRYPTO_lock(10,0x19,"rsa_eay.c",0x148);
          }
          else {
            iVar4 = BN_BLINDING_convert_ex(ret,(BIGNUM *)0x0,b,ctx);
          }
          if (iVar4 == 0) goto LAB_000949b2;
          uVar6 = *(uint *)(param_4 + 0x3c);
        }
        else {
          b = (BN_BLINDING *)0x0;
          local_44 = (BIGNUM *)0x0;
        }
        if (((int)(uVar6 << 0x1a) < 0) ||
           ((((*(int *)(param_4 + 0x1c) != 0 && (*(int *)(param_4 + 0x20) != 0)) &&
             (*(int *)(param_4 + 0x24) != 0)) &&
            ((*(int *)(param_4 + 0x28) != 0 && (*(int *)(param_4 + 0x2c) != 0)))))) {
          iVar4 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(n,ret,param_4,ctx);
        }
        else {
          if ((int)(uVar6 << 0x17) < 0) {
            pBVar2 = *(BIGNUM **)(param_4 + 0x18);
          }
          else {
            pBVar2 = &local_3c;
            BN_init(pBVar2);
            ppuVar5 = *(ulong ***)(param_4 + 0x18);
            uVar6 = *(uint *)(param_4 + 0x3c);
            local_3c.d = *ppuVar5;
            local_3c.top = (int)ppuVar5[1];
            local_3c.flags = local_3c.flags & 1U | (uint)ppuVar5[4] & 0xfffffffe | 6;
            local_3c.dmax = (int)ppuVar5[2];
            local_3c.neg = (int)ppuVar5[3];
          }
          if (((int)(uVar6 << 0x1e) < 0) &&
             (pBVar3 = BN_MONT_CTX_set_locked
                                 ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),
                                  ctx), pBVar3 == (BN_MONT_CTX *)0x0)) goto LAB_000949b2;
          iVar4 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                            (n,ret,pBVar2,*(undefined4 *)(param_4 + 0x10),ctx,
                             *(undefined4 *)(param_4 + 0x40));
        }
        if ((iVar4 == 0) ||
           ((b != (BN_BLINDING *)0x0 &&
            (iVar4 = BN_BLINDING_invert_ex(n,local_44,b,ctx), iVar4 == 0)))) goto LAB_000949b2;
        if (param_5 == 5) {
          BN_sub(ret,*(BIGNUM **)(param_4 + 0x10),n);
          iVar4 = BN_cmp(n,ret);
          if (0 < iVar4) {
            n = ret;
          }
        }
        iVar1 = BN_num_bits(n);
        iVar4 = iVar1 + 0xe;
        if (-1 < iVar1 + 7) {
          iVar4 = iVar1 + 7;
        }
        iVar4 = BN_bn2bin(n,(uchar *)((len - (iVar4 >> 3)) + (int)param_3));
        sVar7 = len;
        if (0 < (int)(len - iVar4)) {
          memset(param_3,0,len - iVar4);
        }
      }
      else {
        ERR_put_error(4,0x66,0x84,"rsa_eay.c",400);
        sVar7 = 0xffffffff;
      }
    }
  }
  else {
    if (param_5 == 5) {
      iVar4 = RSA_padding_add_X931(to,len,param_2,param_1);
      goto LAB_000948c6;
    }
    if (param_5 == 1) {
      iVar4 = RSA_padding_add_PKCS1_type_1(to,len,param_2,param_1);
      goto LAB_000948c6;
    }
    ERR_put_error(4,0x66,0x76,"rsa_eay.c",0x184);
    sVar7 = 0xffffffff;
  }
LAB_0009489a:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_000948a6:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return sVar7;
}

