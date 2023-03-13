
undefined4 camellia_init_key(int param_1,uchar *param_2)

{
  int iVar1;
  
  iVar1 = Camellia_set_key(param_2,*(int *)(param_1 + 0x58) << 3,*(CAMELLIA_KEY **)(param_1 + 0x60))
  ;
  if (-1 < iVar1) {
    return 1;
  }
  ERR_put_error(6,0x9f,0x9d,"e_camellia.c",0x6a);
  return 0;
}

