
bool conn_new(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR_CRYPTO_malloc_006a7008;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar2 = (undefined4 *)(*(code *)puVar1)(0x2c,"bss_conn.c",0x128);
  puVar1 = PTR_memset_006a99f4;
  if (puVar2 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[10] = 0;
    puVar2[3] = 0;
    *puVar2 = 1;
    *(undefined *)(puVar2 + 4) = 0;
    *(undefined *)((int)puVar2 + 0x11) = 0;
    *(undefined *)((int)puVar2 + 0x12) = 0;
    *(undefined *)((int)puVar2 + 0x13) = 0;
    *(undefined2 *)(puVar2 + 5) = 0;
    (*(code *)puVar1)(puVar2 + 6,0,0x10);
    *(undefined4 **)(param_1 + 0x20) = puVar2;
  }
  return puVar2 != (undefined4 *)0x0;
}

