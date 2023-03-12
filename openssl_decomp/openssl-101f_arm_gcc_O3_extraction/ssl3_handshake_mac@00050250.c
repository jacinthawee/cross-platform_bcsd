
void ssl3_handshake_mac(int param_1,int param_2,void *param_3,size_t param_4,uchar *param_5)

{
  EVP_MD_CTX *pEVar1;
  EVP_MD *pEVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_84;
  uint local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  iVar5 = *(int *)(param_1 + 0x58);
  local_24 = __TMC_END__;
  uVar4 = *(uint *)(iVar5 + 0x178);
  if (*(uint *)(iVar5 + 0x178) != 0) {
    iVar5 = ssl3_digest_cached_records();
    if (iVar5 == 0) goto LAB_000502ca;
    iVar5 = *(int *)(param_1 + 0x58);
    local_80 = 0;
    uVar4 = local_80;
  }
  local_80 = uVar4;
  uVar4 = 0;
LAB_0005028e:
  pEVar1 = *(EVP_MD_CTX **)(*(int *)(iVar5 + 0x17c) + uVar4 * 4);
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    pEVar2 = EVP_MD_CTX_md(pEVar1);
    iVar5 = EVP_MD_type(pEVar2);
    if (iVar5 == param_2) {
      pEVar1 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + local_80 * 4);
      if (pEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_init(&EStack_7c);
        EVP_MD_CTX_set_flags(&EStack_7c,8);
        EVP_MD_CTX_copy_ex(&EStack_7c,pEVar1);
        pEVar2 = EVP_MD_CTX_md(&EStack_7c);
        iVar5 = EVP_MD_size(pEVar2);
        if (iVar5 < 0) goto LAB_000502ca;
        iVar3 = __aeabi_idiv(0x30,iVar5);
        if (param_3 != (void *)0x0) {
          EVP_DigestUpdate(&EStack_7c,param_3,param_4);
        }
        EVP_DigestUpdate(&EStack_7c,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                         *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
        EVP_DigestUpdate(&EStack_7c,&ssl3_pad_1,iVar5 * iVar3);
        EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80);
        pEVar2 = EVP_MD_CTX_md(&EStack_7c);
        EVP_DigestInit_ex(&EStack_7c,pEVar2,(ENGINE *)0x0);
        EVP_DigestUpdate(&EStack_7c,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                         *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
        EVP_DigestUpdate(&EStack_7c,PTR_ssl3_pad_2_000503a4,iVar5 * iVar3);
        EVP_DigestUpdate(&EStack_7c,auStack_64,local_80);
        EVP_DigestFinal_ex(&EStack_7c,param_5,&local_84);
        EVP_MD_CTX_cleanup(&EStack_7c);
        goto LAB_000502cc;
      }
LAB_000502ae:
      ERR_put_error(0x14,0x11d,0x144,"s3_enc.c",0x2a3);
LAB_000502ca:
      local_84 = 0;
LAB_000502cc:
      if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(local_84);
      }
      return;
    }
  }
  uVar4 = local_80 + 1;
  local_80 = uVar4;
  if (5 < uVar4) goto LAB_000502ae;
  iVar5 = *(int *)(param_1 + 0x58);
  goto LAB_0005028e;
}

