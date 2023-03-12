
undefined1 *
RSA_eay_private_decrypt(int param_1,uchar *param_2,uchar *param_3,int param_4,int param_5)

{
  undefined *puVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar2;
  uchar *to;
  BIGNUM *pBVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  BN_MONT_CTX *pBVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int iVar12;
  code *pcVar13;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_44 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    puVar6 = (undefined1 *)0xffffffff;
    goto LAB_0050f26c;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar12 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar12 = iVar2 + 0xe;
  }
  iVar12 = iVar12 >> 3;
  to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12,&DAT_006675b8,0x200);
  if (((ret == (BIGNUM *)0x0) || (a == (BIGNUM *)0x0)) || (to == (uchar *)0x0)) {
    puVar6 = (undefined1 *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x65,0x41,&DAT_006675b8,0x203);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) goto LAB_0050f26c;
  }
  else {
    if (iVar12 < param_1) {
      uVar10 = 0x6c;
      uVar8 = 0x20b;
LAB_0050f47c:
      puVar6 = (undefined1 *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x65,uVar10,&DAT_006675b8,uVar8);
    }
    else {
      pBVar3 = BN_bin2bn(param_2,param_1,ret);
      if (pBVar3 == (BIGNUM *)0x0) {
LAB_0050f34c:
        puVar6 = (undefined1 *)0xffffffff;
      }
      else {
        iVar2 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
        if (-1 < iVar2) {
          uVar10 = 0x84;
          uVar8 = 0x214;
          goto LAB_0050f47c;
        }
        uVar4 = *(uint *)(param_4 + 0x3c);
        pBVar3 = (BIGNUM *)0x0;
        if ((uVar4 & 0x80) == 0) {
          iVar2 = rsa_get_blinding(param_4,&local_44,ctx);
          if (iVar2 == 0) {
            uVar10 = 0x44;
            uVar8 = 0x21d;
            goto LAB_0050f47c;
          }
          if (local_44 == 0) {
            pBVar3 = BN_CTX_get(ctx);
            if (pBVar3 == (BIGNUM *)0x0) {
              uVar10 = 0x41;
              uVar8 = 0x226;
              goto LAB_0050f47c;
            }
            (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x19,&DAT_006675b8,0x149);
            iVar5 = (*(code *)PTR_BN_BLINDING_convert_ex_006a9830)(ret,pBVar3,iVar2,ctx);
            (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x19,&DAT_006675b8,0x14b);
          }
          else {
            iVar5 = (*(code *)PTR_BN_BLINDING_convert_ex_006a9830)(ret,0,iVar2,ctx);
            pBVar3 = (BIGNUM *)0x0;
          }
          if (iVar5 == 0) goto LAB_0050f34c;
          uVar4 = *(uint *)(param_4 + 0x3c);
        }
        else {
          iVar2 = 0;
        }
        if (((uVar4 & 0x20) == 0) &&
           (((*(int *)(param_4 + 0x1c) == 0 || (*(int *)(param_4 + 0x20) == 0)) ||
            ((*(int *)(param_4 + 0x24) == 0 ||
             ((*(int *)(param_4 + 0x28) == 0 || (*(int *)(param_4 + 0x2c) == 0)))))))) {
          puVar11 = &local_40;
          if ((uVar4 & 0x100) == 0) {
            puVar9 = *(undefined4 **)(param_4 + 0x18);
            local_40 = *puVar9;
            local_3c = puVar9[1];
            local_38 = puVar9[2];
            local_34 = puVar9[3];
            local_30 = local_30 & 1 | puVar9[4] & 0xfffffffe | 6;
          }
          else {
            puVar11 = *(undefined4 **)(param_4 + 0x18);
          }
          if (((uVar4 & 2) != 0) &&
             (pBVar7 = BN_MONT_CTX_set_locked
                                 ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),
                                  ctx), pBVar7 == (BN_MONT_CTX *)0x0)) goto LAB_0050f34c;
          iVar5 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                            (a,ret,puVar11,*(undefined4 *)(param_4 + 0x10),ctx,
                             *(undefined4 *)(param_4 + 0x40));
        }
        else {
          iVar5 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(a,ret,param_4,ctx);
        }
        if ((iVar5 == 0) ||
           ((iVar2 != 0 &&
            (iVar2 = (*(code *)PTR_BN_BLINDING_invert_ex_006a9828)(a,pBVar3,iVar2,ctx), iVar2 == 0))
           )) goto LAB_0050f34c;
        iVar2 = BN_bn2bin(a,to);
        pcVar13 = (code *)PTR_RSA_padding_check_SSLv23_006a983c;
        if (param_5 == 2) {
LAB_0050f2bc:
          puVar6 = (undefined1 *)(*pcVar13)(param_3,iVar12,to,iVar2,iVar12);
        }
        else {
          if (param_5 < 3) {
            pcVar13 = (code *)PTR_RSA_padding_check_PKCS1_type_2_006a9838;
            if (param_5 != 1) {
LAB_0050f468:
              uVar10 = 0x76;
              uVar8 = 0x264;
              goto LAB_0050f47c;
            }
            goto LAB_0050f2bc;
          }
          pcVar13 = (code *)PTR_RSA_padding_check_none_006a980c;
          if (param_5 == 3) goto LAB_0050f2bc;
          if (param_5 != 4) goto LAB_0050f468;
          puVar6 = (undefined1 *)
                   RSA_padding_check_PKCS1_OAEP(param_3,iVar12,to,iVar2,iVar12,(uchar *)0x0,0);
        }
        if ((int)puVar6 < 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x65,0x72,&DAT_006675b8,0x268);
        }
      }
    }
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(to,iVar12);
  (*(code *)PTR_CRYPTO_free_006a7f88)(to);
LAB_0050f26c:
  if (local_2c == *(int *)puVar1) {
    return puVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return rsa_pkcs1_eay_meth;
}

