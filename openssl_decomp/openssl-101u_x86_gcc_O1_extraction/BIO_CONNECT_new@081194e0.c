
void BIO_CONNECT_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x2c,"bss_conn.c",0x128);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[10] = 0;
    puVar1[3] = 0;
    *(undefined *)(puVar1 + 4) = 0;
    *(undefined *)((int)puVar1 + 0x11) = 0;
    *(undefined *)((int)puVar1 + 0x12) = 0;
    *(undefined *)((int)puVar1 + 0x13) = 0;
    *(undefined2 *)(puVar1 + 5) = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
  }
  return;
}

