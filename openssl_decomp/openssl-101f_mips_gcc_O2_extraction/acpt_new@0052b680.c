
bool acpt_new(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  puVar1 = PTR_CRYPTO_malloc_006a8108;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar2 = (undefined4 *)(*(code *)puVar1)(0x20,"bss_acpt.c",0x94);
  if (puVar2 != (undefined4 *)0x0) {
    (*(code *)PTR_memset_006aab00)(puVar2,0,0x20);
    puVar2[2] = 0xffffffff;
    puVar2[6] = 0;
    *(undefined4 **)(param_1 + 0x20) = puVar2;
    *puVar2 = 1;
    *(undefined4 *)(param_1 + 0x10) = 1;
  }
  return puVar2 != (undefined4 *)0x0;
}

