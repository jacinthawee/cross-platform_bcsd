
undefined4 * BIO_CONNECT_new(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2c,"bss_conn.c",0x128);
  puVar1 = PTR_memset_006a99f4;
  if (puVar2 != (undefined4 *)0x0) {
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
  }
  return puVar2;
}

