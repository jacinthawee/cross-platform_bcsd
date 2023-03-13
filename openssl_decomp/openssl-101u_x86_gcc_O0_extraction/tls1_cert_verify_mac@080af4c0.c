
uint tls1_cert_verify_mac(int param_1,int param_2,uchar *param_3)

{
  EVP_MD_CTX *pEVar1;
  uint uVar2;
  EVP_MD *md;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  uint local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = *(int *)(param_1 + 0x58);
  if (*(int *)(iVar3 + 0x178) != 0) {
    uVar2 = ssl3_digest_cached_records(param_1);
    if (uVar2 == 0) goto LAB_080af55b;
    iVar3 = *(int *)(param_1 + 0x58);
  }
  iVar4 = 0;
LAB_080af50b:
  pEVar1 = *(EVP_MD_CTX **)(*(int *)(iVar3 + 0x17c) + iVar4);
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(pEVar1);
    iVar3 = EVP_MD_type(md);
    if (iVar3 == param_2) {
      pEVar1 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar4);
      if (pEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_init(&local_38);
        iVar3 = EVP_MD_CTX_copy_ex(&local_38,pEVar1);
        if (iVar3 < 1) {
LAB_080af5c8:
          local_3c = 0;
        }
        else {
          iVar3 = EVP_DigestFinal_ex(&local_38,param_3,&local_3c);
          if (iVar3 < 1) goto LAB_080af5c8;
        }
        EVP_MD_CTX_cleanup(&local_38);
        uVar2 = local_3c;
        goto LAB_080af55b;
      }
LAB_080af538:
      ERR_put_error(0x14,0x11e,0x144,"t1_enc.c",0x399);
      uVar2 = 0;
LAB_080af55b:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return uVar2;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  }
  iVar4 = iVar4 + 4;
  if (iVar4 == 0x18) goto LAB_080af538;
  iVar3 = *(int *)(param_1 + 0x58);
  goto LAB_080af50b;
}

