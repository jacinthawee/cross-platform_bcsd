
UI_METHOD * UI_create_method(char *name)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x1c,"ui_lib.c",0x26d);
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)PTR_memset_006aab00)(puVar1,0,0x1c);
    uVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(name);
    *puVar1 = uVar2;
  }
  return (UI_METHOD *)puVar1;
}

