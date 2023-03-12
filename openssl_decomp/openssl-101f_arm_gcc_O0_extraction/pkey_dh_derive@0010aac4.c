
int pkey_dh_derive(int param_1,uchar *param_2,int *param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = DH_compute_key(param_2,*(BIGNUM **)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0x14),
                           *(DH **)(*(int *)(param_1 + 8) + 0x14));
    if (-1 < iVar1) {
      *param_3 = iVar1;
      iVar1 = 1;
    }
    return iVar1;
  }
  ERR_put_error(5,0x70,0x6c,"dh_pmeth.c",0xd1);
  return 0;
}

