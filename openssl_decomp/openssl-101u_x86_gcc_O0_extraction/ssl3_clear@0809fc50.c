
void ssl3_clear(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  byte bVar9;
  
  bVar9 = 0;
  ssl3_cleanup_key_block(param_1);
  iVar6 = param_1[0x16];
  if (*(_STACK **)(iVar6 + 0x36c) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)(iVar6 + 0x36c),X509_NAME_free);
    iVar6 = param_1[0x16];
  }
  if (*(void **)(iVar6 + 0x120) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar6 + 0x120));
    iVar6 = param_1[0x16];
    *(undefined4 *)(iVar6 + 0x120) = 0;
  }
  if (*(DH **)(iVar6 + 0x348) != (DH *)0x0) {
    DH_free(*(DH **)(iVar6 + 0x348));
    iVar6 = param_1[0x16];
    *(undefined4 *)(iVar6 + 0x348) = 0;
  }
  if (*(EC_KEY **)(iVar6 + 0x34c) != (EC_KEY *)0x0) {
    EC_KEY_free(*(EC_KEY **)(iVar6 + 0x34c));
    iVar6 = param_1[0x16];
    *(undefined4 *)(iVar6 + 0x34c) = 0;
  }
  *(undefined *)(iVar6 + 0x420) = 0;
  puVar7 = (undefined4 *)param_1[0x16];
  uVar1 = puVar7[0x3c];
  uVar2 = puVar7[0x3b];
  uVar3 = puVar7[0x3f];
  uVar4 = puVar7[0x40];
  uVar5 = puVar7[0x3a];
  if ((BIO *)puVar7[0x5e] != (BIO *)0x0) {
    BIO_free((BIO *)puVar7[0x5e]);
    puVar7 = (undefined4 *)param_1[0x16];
    puVar7[0x5e] = 0;
  }
  if (puVar7[0x5f] != 0) {
    ssl3_free_digest_list(param_1);
    puVar7 = (undefined4 *)param_1[0x16];
  }
  *puVar7 = 0;
  puVar7[0x108] = 0;
  uVar8 = (uint)((int)puVar7 + (0x424 - (int)(undefined4 *)((uint)(puVar7 + 1) & 0xfffffffc))) >> 2;
  puVar7 = (undefined4 *)((uint)(puVar7 + 1) & 0xfffffffc);
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
  }
  iVar6 = param_1[0x16];
  *(undefined4 *)(iVar6 + 0xec) = uVar2;
  *(undefined4 *)(iVar6 + 0xfc) = uVar3;
  *(undefined4 *)(iVar6 + 0xe8) = uVar5;
  *(undefined4 *)(iVar6 + 0xf0) = uVar1;
  *(undefined4 *)(iVar6 + 0x100) = uVar4;
  ssl_free_wbio_buffer(param_1);
  iVar6 = param_1[0x16];
  param_1[0x14] = 0;
  *(undefined4 *)(iVar6 + 0x194) = 0;
  *(undefined4 *)(iVar6 + 0x198) = 0;
  *(undefined4 *)(iVar6 + 0x19c) = 0;
  *(undefined4 *)(iVar6 + 0x1a0) = 0;
  *param_1 = 0x300;
  if ((void *)param_1[0x5d] != (void *)0x0) {
    CRYPTO_free((void *)param_1[0x5d]);
    param_1[0x5d] = 0;
    *(undefined *)(param_1 + 0x5e) = 0;
  }
  return;
}

