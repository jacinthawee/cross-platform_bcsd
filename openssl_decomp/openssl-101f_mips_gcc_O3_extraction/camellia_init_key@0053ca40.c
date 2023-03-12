
undefined4 camellia_init_key(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_Camellia_set_key_006a8ae0)
                    (param_2,*(int *)(param_1 + 0x58) << 3,*(undefined4 *)(param_1 + 0x60));
  if (-1 < iVar1) {
    return 1;
  }
  ERR_put_error(6,0x9f,0x9d,"e_camellia.c",0x76);
  return 0;
}

