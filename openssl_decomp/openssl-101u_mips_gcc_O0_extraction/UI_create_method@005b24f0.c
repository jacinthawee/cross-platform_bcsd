
UI_METHOD * UI_create_method(char *name)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x1c,"ui_lib.c",0x24e);
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)PTR_memset_006a99f4)(puVar1,0,0x1c);
    uVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)(name);
    *puVar1 = uVar2;
  }
  return (UI_METHOD *)puVar1;
}

