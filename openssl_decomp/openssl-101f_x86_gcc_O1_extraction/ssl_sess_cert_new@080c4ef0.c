
undefined4 * ssl_sess_cert_new(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x7c,"ssl_cert.c",0x1b5);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x14,0xe1,0x41,"ssl_cert.c",0x1b8);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar3 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    for (uVar2 = (uint)((int)puVar1 + (0x7c - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc)))
                 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    puVar1[0x1e] = 1;
    puVar1[2] = puVar1 + 3;
  }
  return puVar1;
}

