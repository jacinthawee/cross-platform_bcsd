
void tls1_final_finish_mac(int param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  EVP_MD_CTX *in;
  size_t len;
  uint uVar6;
  int iVar7;
  int iVar8;
  uchar *md;
  byte *local_100;
  uint local_e4;
  uint local_e0;
  EVP_MD *local_dc;
  int local_d8;
  int local_d4;
  EVP_MD_CTX EStack_d0;
  byte local_b8;
  byte local_b7;
  byte local_b6;
  byte local_b5;
  byte local_b4;
  byte local_b3;
  byte local_b2;
  byte local_b1;
  byte local_b0;
  byte local_af;
  byte local_ae;
  byte local_ad;
  uchar auStack_ac [128];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if ((*(int *)(*(int *)(param_1 + 0x58) + 0x178) == 0) ||
     (iVar1 = ssl3_digest_cached_records(), iVar1 != 0)) {
    EVP_MD_CTX_init(&EStack_d0);
    iVar7 = 0;
    iVar1 = iVar7;
    md = auStack_ac;
    while (iVar2 = ssl_get_handshake_digest(iVar7,&local_e0,&local_dc), iVar2 != 0) {
      uVar3 = ssl_get_algorithm2(param_1);
      if ((uVar3 & local_e0) != 0) {
        uVar3 = EVP_MD_size(local_dc);
        in = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar7 * 4);
        uVar6 = count_leading_zeroes(in);
        if (((uVar6 >> 5 | uVar3 >> 0x1f) == 0) && ((int)uVar3 <= (int)&local_2c - (int)md)) {
          iVar2 = EVP_MD_CTX_copy_ex(&EStack_d0,in);
          if ((iVar2 == 0) || (iVar2 = EVP_DigestFinal_ex(&EStack_d0,md,&local_e4), iVar2 == 0)) {
            iVar1 = 1;
            md = md + uVar3;
          }
          else {
            md = md + uVar3;
            if (uVar3 != local_e4) {
              iVar1 = 1;
            }
          }
        }
        else {
          iVar1 = 1;
        }
      }
      iVar7 = iVar7 + 1;
    }
    uVar3 = ssl_get_algorithm2(param_1);
    len = (int)md - (int)auStack_ac;
    iVar8 = *(int *)(param_1 + 0xc0) + 0x14;
    uVar6 = *(uint *)(*(int *)(param_1 + 0xc0) + 0x10);
    iVar7 = iVar2;
    while (iVar4 = ssl_get_handshake_digest(iVar7,&local_d8,&local_d4), iVar4 != 0) {
      iVar7 = iVar7 + 1;
      if ((uVar3 & local_d8 << 10) != 0) {
        iVar2 = iVar2 + 1;
      }
    }
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x11c,0x44,"t1_enc.c",0x10a);
LAB_00055b34:
      local_100 = &local_b8;
      EVP_MD_CTX_cleanup(&EStack_d0);
      OPENSSL_cleanse(auStack_ac,len);
      OPENSSL_cleanse(local_100,0xc);
      goto LAB_00055af2;
    }
    iVar7 = __aeabi_idiv(uVar6,iVar2);
    if (iVar2 == 1) {
      uVar6 = 0;
    }
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    param_4[3] = 0;
    param_4[4] = 0;
    param_4[5] = 0;
    param_4[6] = 0;
    param_4[7] = 0;
    param_4[8] = 0;
    param_4[9] = 0;
    param_4[10] = 0;
    param_4[0xb] = 0;
    iVar2 = iVar4;
    while (iVar5 = ssl_get_handshake_digest(iVar2,&local_d8,&local_d4), iVar5 != 0) {
      if ((uVar3 & local_d8 << 10) != 0) {
        if (local_d4 == 0) {
          ERR_put_error(0x14,0x11c,0x146,"t1_enc.c",0x115);
          goto LAB_00055b34;
        }
        iVar5 = tls1_P_hash_constprop_3
                          (local_d4,iVar8,iVar7 + (uVar6 & 1),param_2,param_3,auStack_ac,len,0,0,0,0
                           ,&local_b8,0xc);
        if (iVar5 == 0) goto LAB_00055b34;
        iVar8 = iVar8 + iVar7;
        *param_4 = *param_4 ^ local_b8;
        param_4[1] = param_4[1] ^ local_b7;
        param_4[2] = param_4[2] ^ local_b6;
        param_4[3] = param_4[3] ^ local_b5;
        param_4[4] = param_4[4] ^ local_b4;
        param_4[5] = param_4[5] ^ local_b3;
        param_4[6] = param_4[6] ^ local_b2;
        param_4[7] = param_4[7] ^ local_b1;
        param_4[8] = param_4[8] ^ local_b0;
        param_4[9] = param_4[9] ^ local_af;
        param_4[10] = param_4[10] ^ local_ae;
        param_4[0xb] = local_ad ^ param_4[0xb];
      }
      iVar2 = iVar2 + 1;
    }
    EVP_MD_CTX_cleanup(&EStack_d0);
    OPENSSL_cleanse(auStack_ac,len);
    OPENSSL_cleanse(&local_b8,0xc);
    if (iVar1 == 0) {
      iVar4 = 0xc;
      goto LAB_00055af2;
    }
  }
  iVar4 = 0;
LAB_00055af2:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar4);
  }
  return;
}

