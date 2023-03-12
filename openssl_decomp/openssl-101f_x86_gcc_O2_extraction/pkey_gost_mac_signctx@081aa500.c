
int pkey_gost_mac_signctx(undefined4 param_1,uchar *param_2,uint *param_3,EVP_MD_CTX *param_4)

{
  int iVar1;
  int in_GS_OFFSET;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = *param_3;
  if (param_2 == (uchar *)0x0) {
    *param_3 = 4;
    iVar1 = 1;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(param_4,param_2,&local_14);
    *param_3 = local_14;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

