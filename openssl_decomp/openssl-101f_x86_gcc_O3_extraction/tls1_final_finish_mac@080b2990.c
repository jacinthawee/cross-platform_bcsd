
int tls1_final_finish_mac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  EVP_MD_CTX *in;
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_GS_OFFSET;
  uchar *local_fc;
  int local_e0;
  uint local_d8;
  uint local_d4;
  EVP_MD *local_d0;
  int local_cc;
  int local_c8;
  EVP_MD_CTX local_c4;
  byte local_ac;
  byte local_ab;
  byte local_aa;
  byte local_a9;
  byte local_a8;
  byte local_a7;
  byte local_a6;
  byte local_a5;
  byte local_a4;
  byte local_a3;
  byte local_a2;
  byte local_a1;
  uchar local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(int *)(*(int *)(param_1 + 0x58) + 0x178) == 0) ||
     (iVar3 = ssl3_digest_cached_records(param_1), iVar3 != 0)) {
    iVar3 = 0;
    EVP_MD_CTX_init(&local_c4);
    bVar1 = false;
    local_fc = local_a0;
    while (iVar4 = ssl_get_handshake_digest(iVar3,&local_d4,&local_d0), iVar4 != 0) {
      uVar5 = ssl_get_algorithm2(param_1);
      if ((local_d4 & uVar5) != 0) {
        uVar5 = EVP_MD_size(local_d0);
        in = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar3 * 4);
        if (((in == (EVP_MD_CTX *)0x0) || ((int)uVar5 < 0)) ||
           (0x80 - ((int)local_fc - (int)local_a0) < (int)uVar5)) {
          bVar1 = true;
        }
        else {
          iVar4 = EVP_MD_CTX_copy_ex(&local_c4,in);
          if ((iVar4 == 0) || (iVar4 = EVP_DigestFinal_ex(&local_c4,local_fc,&local_d8), iVar4 == 0)
             ) {
            bVar2 = true;
          }
          else {
            bVar2 = true;
            if (local_d8 == uVar5) {
              bVar2 = bVar1;
            }
          }
          local_fc = local_fc + uVar5;
          bVar1 = bVar2;
        }
      }
      iVar3 = iVar3 + 1;
    }
    uVar5 = ssl_get_algorithm2(param_1);
    iVar3 = 0;
    while (local_e0 = ssl_get_handshake_digest(iVar3,&local_cc,&local_c8), local_e0 != 0) {
      iVar3 = iVar3 + 1;
    }
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    iVar3 = 0;
    while (iVar4 = ssl_get_handshake_digest(iVar3,&local_cc,&local_c8), iVar4 != 0) {
      if ((uVar5 & local_cc << 10) != 0) {
        if (local_c8 == 0) {
          ERR_put_error(0x14,0x11c,0x146,"t1_enc.c",0x114);
        }
        else {
          iVar4 = tls1_P_hash_constprop_2
                            (param_2,param_3,local_a0,(int)local_fc - (int)local_a0,0,0,0,0,
                             &local_ac,0xc);
          if (iVar4 != 0) {
            *(byte *)param_4 = *(byte *)param_4 ^ local_ac;
            *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) ^ local_ab;
            *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) ^ local_aa;
            *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) ^ local_a9;
            *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) ^ local_a8;
            *(byte *)((int)param_4 + 5) = *(byte *)((int)param_4 + 5) ^ local_a7;
            *(byte *)((int)param_4 + 6) = *(byte *)((int)param_4 + 6) ^ local_a6;
            *(byte *)((int)param_4 + 7) = *(byte *)((int)param_4 + 7) ^ local_a5;
            *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) ^ local_a4;
            *(byte *)((int)param_4 + 9) = *(byte *)((int)param_4 + 9) ^ local_a3;
            *(byte *)((int)param_4 + 10) = *(byte *)((int)param_4 + 10) ^ local_a2;
            *(byte *)((int)param_4 + 0xb) = *(byte *)((int)param_4 + 0xb) ^ local_a1;
            goto LAB_080b2c14;
          }
        }
        EVP_MD_CTX_cleanup(&local_c4);
        goto LAB_080b2c4d;
      }
LAB_080b2c14:
      iVar3 = iVar3 + 1;
    }
    EVP_MD_CTX_cleanup(&local_c4);
    if (!bVar1) {
      local_e0 = 0xc;
      goto LAB_080b2c4d;
    }
  }
  local_e0 = 0;
LAB_080b2c4d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_e0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

