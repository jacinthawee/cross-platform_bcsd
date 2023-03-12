
int def_create(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x10,"conf_def.c",0x84);
  if ((iVar1 != 0) && (iVar2 = (**(code **)(param_1 + 8))(iVar1), iVar2 == 0)) {
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}

