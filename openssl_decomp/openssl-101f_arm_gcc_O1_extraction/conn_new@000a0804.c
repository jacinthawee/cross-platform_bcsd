
undefined4 conn_new(int param_1)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x2c,"bss_conn.c",0x145);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[10] = 0;
    puVar1[3] = 0;
    *(undefined *)(puVar1 + 4) = 0;
    *(undefined *)((int)puVar1 + 0x11) = 0;
    *(undefined *)((int)puVar1 + 0x12) = 0;
    *(undefined *)((int)puVar1 + 0x13) = 0;
    *(undefined2 *)(puVar1 + 5) = 0;
    *puVar1 = 1;
    memset(puVar1 + 6,0,0x10);
    *(undefined4 **)(param_1 + 0x20) = puVar1;
    return 1;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}

