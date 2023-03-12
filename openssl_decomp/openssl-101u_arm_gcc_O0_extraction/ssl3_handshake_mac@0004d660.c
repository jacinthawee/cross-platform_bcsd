
void ssl3_handshake_mac(int param_1,int param_2,void *param_3,size_t param_4,uchar *param_5)

{
  EVP_MD_CTX *pEVar1;
  EVP_MD *pEVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_84;
  uint local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  iVar6 = *(int *)(param_1 + 0x58);
  local_24 = __stack_chk_guard;
  uVar5 = *(uint *)(iVar6 + 0x178);
  if (*(uint *)(iVar6 + 0x178) != 0) {
    iVar6 = ssl3_digest_cached_records();
    if (iVar6 == 0) goto LAB_0004d6da;
    iVar6 = *(int *)(param_1 + 0x58);
    local_80 = 0;
    uVar5 = local_80;
  }
  local_80 = uVar5;
  uVar5 = 0;
LAB_0004d69e:
  pEVar1 = *(EVP_MD_CTX **)(*(int *)(iVar6 + 0x17c) + uVar5 * 4);
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    pEVar2 = EVP_MD_CTX_md(pEVar1);
    iVar6 = EVP_MD_type(pEVar2);
    if (iVar6 == param_2) {
      pEVar1 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + local_80 * 4);
      if (pEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_init(&EStack_7c);
        EVP_MD_CTX_set_flags(&EStack_7c,8);
        EVP_MD_CTX_copy_ex(&EStack_7c,pEVar1);
        pEVar2 = EVP_MD_CTX_md(&EStack_7c);
        iVar6 = EVP_MD_size(pEVar2);
        if (iVar6 < 0) goto LAB_0004d6da;
        if (((param_3 == (void *)0x0) ||
            (iVar3 = EVP_DigestUpdate(&EStack_7c,param_3,param_4), 0 < iVar3)) &&
           (iVar3 = EVP_DigestUpdate(&EStack_7c,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                                     *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10)), 0 < iVar3)) {
          iVar3 = __aeabi_idiv(0x30,iVar6);
          iVar4 = EVP_DigestUpdate(&EStack_7c,&ssl3_pad_1,iVar6 * iVar3);
          if ((iVar4 < 1) ||
             (iVar4 = EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80), iVar4 < 1))
          goto LAB_0004d7cc;
          pEVar2 = EVP_MD_CTX_md(&EStack_7c);
          iVar4 = EVP_DigestInit_ex(&EStack_7c,pEVar2,(ENGINE *)0x0);
          if ((((iVar4 < 1) ||
               ((iVar4 = EVP_DigestUpdate(&EStack_7c,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                                          *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10)), iVar4 < 1
                || (iVar6 = EVP_DigestUpdate(&EStack_7c,PTR_ssl3_pad_2_0004d7f8,iVar6 * iVar3),
                   iVar6 < 1)))) ||
              (iVar6 = EVP_DigestUpdate(&EStack_7c,auStack_64,local_80), iVar6 < 1)) ||
             (iVar6 = EVP_DigestFinal_ex(&EStack_7c,param_5,&local_84), iVar6 < 1))
          goto LAB_0004d7cc;
        }
        else {
LAB_0004d7cc:
          ERR_put_error(0x14,0x11d,0x44,"s3_enc.c",0x2b7);
          local_84 = 0;
        }
        EVP_MD_CTX_cleanup(&EStack_7c);
        uVar5 = local_84;
        goto LAB_0004d6dc;
      }
LAB_0004d6be:
      ERR_put_error(0x14,0x11d,0x144,"s3_enc.c",0x2a0);
LAB_0004d6da:
      uVar5 = 0;
LAB_0004d6dc:
      if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar5);
      }
      return;
    }
  }
  uVar5 = local_80 + 1;
  local_80 = uVar5;
  if (5 < uVar5) goto LAB_0004d6be;
  iVar6 = *(int *)(param_1 + 0x58);
  goto LAB_0004d69e;
}

