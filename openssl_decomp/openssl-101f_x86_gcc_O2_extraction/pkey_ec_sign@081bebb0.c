
int pkey_ec_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  EC_KEY *eckey;
  EVP_MD *md;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)(param_1 + 0x14);
  eckey = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
  if (param_2 == (uchar *)0x0) {
    uVar3 = ECDSA_size(eckey);
    *param_3 = uVar3;
    iVar2 = 1;
  }
  else {
    uVar3 = *param_3;
    uVar1 = ECDSA_size(eckey);
    if (uVar3 < uVar1) {
      ERR_put_error(0x10,0xda,100,"ec_pmeth.c",0x86);
      iVar2 = 0;
    }
    else {
      md = *(EVP_MD **)(iVar2 + 4);
      iVar2 = 0x40;
      if (md != (EVP_MD *)0x0) {
        iVar2 = EVP_MD_type(md);
      }
      iVar2 = ECDSA_sign(iVar2,param_4,param_5,param_2,&local_24,eckey);
      if (0 < iVar2) {
        *param_3 = local_24;
        iVar2 = 1;
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

