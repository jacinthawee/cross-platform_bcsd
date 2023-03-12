
int CONF_module_add(char *name,undefined1 *ifunc,undefined1 *ffunc)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (((supported_modules != 0) ||
      (supported_modules = (*(code *)PTR_sk_new_null_006a6fa4)(), supported_modules != 0)) &&
     (puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"conf_mod.c",0x11d),
     puVar1 = PTR_BUF_strdup_006a6fdc, puVar2 != (undefined4 *)0x0)) {
    *puVar2 = 0;
    uVar3 = (*(code *)puVar1)(name);
    iVar4 = supported_modules;
    puVar2[1] = uVar3;
    puVar2[2] = ifunc;
    puVar2[3] = ffunc;
    puVar1 = PTR_sk_push_006a6fa8;
    puVar2[4] = 0;
    iVar4 = (*(code *)puVar1)(iVar4,puVar2);
    if (iVar4 != 0) {
      return 1;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar2);
  }
  return 0;
}

