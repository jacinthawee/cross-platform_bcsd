
undefined4 hmac_signctx(int param_1,uchar *param_2,uint *param_3,EVP_MD_CTX *param_4)

{
  EVP_MD *md;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)(param_1 + 0x14);
  md = EVP_MD_CTX_md(param_4);
  uVar1 = EVP_MD_size(md);
  if (-1 < (int)uVar1) {
    *param_3 = uVar1;
    uVar3 = 1;
    if (param_2 == (uchar *)0x0) goto LAB_081ad0c4;
    iVar2 = HMAC_Final((HMAC_CTX *)(iVar2 + 0x14),param_2,&local_24);
    if (iVar2 != 0) {
      *param_3 = local_24;
      goto LAB_081ad0c4;
    }
  }
  uVar3 = 0;
LAB_081ad0c4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

