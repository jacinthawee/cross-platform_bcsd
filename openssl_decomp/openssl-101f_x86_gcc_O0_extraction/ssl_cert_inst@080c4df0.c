
undefined4 ssl_cert_inst(int **param_1)

{
  int *piVar1;
  EVP_MD *pEVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  int reason;
  int line;
  
  bVar5 = 0;
  if (param_1 == (int **)0x0) {
    line = 0x1a2;
    reason = 0x43;
  }
  else {
    if (*param_1 != (int *)0x0) {
      return 1;
    }
    piVar1 = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xb6);
    if (piVar1 != (int *)0x0) {
      puVar4 = (undefined4 *)((uint)(piVar1 + 1) & 0xfffffffc);
      for (uVar3 = (uint)((int)piVar1 +
                         (0x94 - (int)(undefined4 *)((uint)(piVar1 + 1) & 0xfffffffc))) >> 2;
          uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
      }
      piVar1[0x24] = 1;
      *piVar1 = (int)(piVar1 + 0xc);
      pEVar2 = EVP_sha1();
      piVar1[0x14] = (int)pEVar2;
      pEVar2 = EVP_sha1();
      piVar1[0x11] = (int)pEVar2;
      pEVar2 = EVP_sha1();
      piVar1[0xe] = (int)pEVar2;
      pEVar2 = EVP_sha1();
      piVar1[0x1d] = (int)pEVar2;
      *param_1 = piVar1;
      return 1;
    }
    ERR_put_error(0x14,0xa2,0x41,"ssl_cert.c",0xb9);
    *param_1 = (int *)0x0;
    line = 0x1a9;
    reason = 0x41;
  }
  ERR_put_error(0x14,0xde,reason,"ssl_cert.c",line);
  return 0;
}

