
int pkey_dsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  DSA *dsa;
  EVP_MD *md;
  int iVar1;
  int in_GS_OFFSET;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  dsa = *(DSA **)(*(int *)(param_1 + 8) + 0x14);
  md = *(EVP_MD **)(*(int *)(param_1 + 0x14) + 0x14);
  iVar1 = 0x40;
  if (md != (EVP_MD *)0x0) {
    iVar1 = EVP_MD_type(md);
  }
  iVar1 = DSA_sign(iVar1,param_4,param_5,param_2,&local_24,dsa);
  if (0 < iVar1) {
    *param_3 = local_24;
    iVar1 = 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

