
/* WARNING: Removing unreachable block (ram,0x0810a53f) */

int RSA_eay_private_decrypt(int param_1,uchar *param_2,uchar *param_3,int param_4,int param_5)

{
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *n;
  int iVar1;
  size_t len;
  uchar *to;
  BIGNUM *pBVar2;
  int iVar3;
  uint uVar4;
  BN_MONT_CTX *pBVar5;
  undefined4 *puVar6;
  BN_BLINDING *b;
  int in_GS_OFFSET;
  int line;
  BIGNUM *local_48;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    iVar3 = -1;
    goto LAB_0810a46f;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  n = BN_CTX_get(ctx);
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar3 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar3 = iVar1 + 0xe;
  }
  len = iVar3 >> 3;
  to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0x200);
  if ((ret == (BIGNUM *)0x0 || n == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    iVar3 = -1;
    ERR_put_error(4,0x65,0x41,"rsa_eay.c",0x203);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) goto LAB_0810a46f;
  }
  else {
    if ((int)len < param_1) {
      line = 0x20b;
      iVar1 = 0x6c;
LAB_0810a5cf:
      iVar3 = -1;
      ERR_put_error(4,0x65,iVar1,"rsa_eay.c",line);
    }
    else {
      pBVar2 = BN_bin2bn(param_2,param_1,ret);
      if (pBVar2 != (BIGNUM *)0x0) {
        iVar3 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
        if (iVar3 < 0) {
          uVar4 = *(uint *)(param_4 + 0x3c);
          b = (BN_BLINDING *)0x0;
          local_48 = (BIGNUM *)0x0;
          if ((uVar4 & 0x80) != 0) {
LAB_0810a341:
            if (((uVar4 & 0x20) == 0) &&
               ((((*(int *)(param_4 + 0x1c) == 0 || (*(int *)(param_4 + 0x20) == 0)) ||
                 (*(int *)(param_4 + 0x24) == 0)) ||
                ((*(int *)(param_4 + 0x28) == 0 || (*(int *)(param_4 + 0x2c) == 0)))))) {
              puVar6 = *(undefined4 **)(param_4 + 0x18);
              if ((uVar4 & 0x100) == 0) {
                local_34 = *puVar6;
                local_30 = puVar6[1];
                local_2c = puVar6[2];
                local_28 = puVar6[3];
                local_24 = puVar6[4] & 0xfffffffe | local_24 & 1 | 6;
                puVar6 = &local_34;
              }
              if (((uVar4 & 2) != 0) &&
                 (pBVar5 = BN_MONT_CTX_set_locked
                                     ((BN_MONT_CTX **)(param_4 + 0x40),
                                      (int)(BN_MONT_CTX **)(param_4 + 0x40),(BIGNUM *)0x9,
                                      *(BN_CTX **)(param_4 + 0x10)), pBVar5 == (BN_MONT_CTX *)0x0))
              goto LAB_0810a510;
              iVar3 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                                (n,ret,puVar6,*(undefined4 *)(param_4 + 0x10),ctx,
                                 *(undefined4 *)(param_4 + 0x40));
            }
            else {
              iVar3 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(n,ret,param_4,ctx);
            }
            if ((iVar3 == 0) ||
               ((b != (BN_BLINDING *)0x0 &&
                (iVar3 = BN_BLINDING_invert_ex(n,local_48,b,ctx), iVar3 == 0)))) goto LAB_0810a510;
            iVar3 = BN_bn2bin(n,to);
            if (param_5 == 2) {
              iVar3 = RSA_padding_check_SSLv23(param_3,len,to,iVar3,len);
            }
            else if (param_5 < 3) {
              if (param_5 != 1) {
LAB_0810a5c0:
                line = 0x264;
                iVar1 = 0x76;
                goto LAB_0810a5cf;
              }
              iVar3 = RSA_padding_check_PKCS1_type_2(param_3,len,to,iVar3,len);
            }
            else if (param_5 == 3) {
              iVar3 = RSA_padding_check_none(param_3,len,to,iVar3,len);
            }
            else {
              if (param_5 != 4) goto LAB_0810a5c0;
              iVar3 = RSA_padding_check_PKCS1_OAEP(param_3,len,to,iVar3,len,(uchar *)0x0,0);
            }
            if (iVar3 < 0) {
              ERR_put_error(4,0x65,0x72,"rsa_eay.c",0x268);
            }
            goto LAB_0810a43f;
          }
          b = (BN_BLINDING *)rsa_get_blinding();
          if (b == (BN_BLINDING *)0x0) {
            line = 0x21d;
            iVar1 = 0x44;
          }
          else {
            local_48 = BN_CTX_get(ctx);
            if (local_48 != (BIGNUM *)0x0) {
              CRYPTO_lock((int)local_48,9,(char *)0x19,(int)"rsa_eay.c");
              iVar3 = BN_BLINDING_convert_ex(ret,local_48,b,ctx);
              CRYPTO_lock(iVar3,10,(char *)0x19,(int)"rsa_eay.c");
              if (iVar3 == 0) goto LAB_0810a510;
              uVar4 = *(uint *)(param_4 + 0x3c);
              goto LAB_0810a341;
            }
            line = 0x226;
            iVar1 = 0x41;
          }
        }
        else {
          line = 0x214;
          iVar1 = 0x84;
        }
        goto LAB_0810a5cf;
      }
LAB_0810a510:
      iVar3 = -1;
    }
LAB_0810a43f:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
LAB_0810a46f:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

