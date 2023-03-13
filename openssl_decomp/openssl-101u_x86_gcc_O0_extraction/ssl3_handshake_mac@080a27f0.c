
uint __regparm3
ssl3_handshake_mac(int param_1_00,int param_2_00,void *param_3,size_t param_1,uchar *param_2)

{
  EVP_MD_CTX *pEVar1;
  int iVar2;
  EVP_MD *pEVar3;
  uint uVar4;
  int iVar5;
  size_t cnt;
  int in_GS_OFFSET;
  uint local_80;
  uint local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  iVar2 = *(int *)(param_1_00 + 0x58);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(iVar2 + 0x178) != 0) {
    iVar2 = ssl3_digest_cached_records(param_1_00);
    if (iVar2 == 0) goto LAB_080a28a9;
    iVar2 = *(int *)(param_1_00 + 0x58);
  }
  local_7c = 0;
LAB_080a2853:
  pEVar1 = *(EVP_MD_CTX **)(*(int *)(iVar2 + 0x17c) + local_7c * 4);
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    pEVar3 = EVP_MD_CTX_md(pEVar1);
    iVar2 = EVP_MD_type(pEVar3);
    if (iVar2 == param_2_00) {
      pEVar1 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1_00 + 0x58) + 0x17c) + local_7c * 4);
      if (pEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_init(&local_78);
        EVP_MD_CTX_set_flags(&local_78,8);
        EVP_MD_CTX_copy_ex(&local_78,pEVar1);
        pEVar3 = EVP_MD_CTX_md(&local_78);
        iVar2 = EVP_MD_size(pEVar3);
        if (iVar2 < 0) goto LAB_080a28a9;
        if (((param_3 == (void *)0x0) ||
            (iVar5 = EVP_DigestUpdate(&local_78,param_3,param_1), 0 < iVar5)) &&
           (iVar5 = EVP_DigestUpdate(&local_78,(void *)(*(int *)(param_1_00 + 0xc0) + 0x14),
                                     *(size_t *)(*(int *)(param_1_00 + 0xc0) + 0x10)), 0 < iVar5)) {
          cnt = iVar2 * (int)(0x30 / (longlong)iVar2);
          iVar2 = EVP_DigestUpdate(&local_78,ssl3_pad_1,cnt);
          if (iVar2 < 1) goto LAB_080a2a30;
          iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
          if (iVar2 < 1) goto LAB_080a2a30;
          pEVar3 = EVP_MD_CTX_md(&local_78);
          iVar2 = EVP_DigestInit_ex(&local_78,pEVar3,(ENGINE *)0x0);
          if (((iVar2 < 1) ||
              (iVar2 = EVP_DigestUpdate(&local_78,(void *)(*(int *)(param_1_00 + 0xc0) + 0x14),
                                        *(size_t *)(*(int *)(param_1_00 + 0xc0) + 0x10)), iVar2 < 1)
              ) || ((iVar2 = EVP_DigestUpdate(&local_78,
                                              "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"
                                              ,cnt), iVar2 < 1 ||
                    ((iVar2 = EVP_DigestUpdate(&local_78,local_60,local_7c), iVar2 < 1 ||
                     (iVar2 = EVP_DigestFinal_ex(&local_78,param_2,&local_80), iVar2 < 1))))))
          goto LAB_080a2a30;
        }
        else {
LAB_080a2a30:
          ERR_put_error(0x14,0x11d,0x44,"s3_enc.c",0x2b7);
          local_80 = 0;
        }
        EVP_MD_CTX_cleanup(&local_78);
        uVar4 = local_80;
        goto LAB_080a28ab;
      }
LAB_080a2888:
      ERR_put_error(0x14,0x11d,0x144,"s3_enc.c",0x2a0);
LAB_080a28a9:
      uVar4 = 0;
LAB_080a28ab:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uVar4;
    }
  }
  local_7c = local_7c + 1;
  if (5 < local_7c) goto LAB_080a2888;
  iVar2 = *(int *)(param_1_00 + 0x58);
  goto LAB_080a2853;
}

