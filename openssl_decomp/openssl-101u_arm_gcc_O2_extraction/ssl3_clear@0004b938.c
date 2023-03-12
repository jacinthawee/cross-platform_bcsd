
void ssl3_clear(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  ssl3_cleanup_key_block();
  iVar2 = param_1[0x16];
  if (*(_STACK **)(iVar2 + 0x36c) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)(iVar2 + 0x36c),X509_NAME_free + 1);
    iVar2 = param_1[0x16];
  }
  if (*(void **)(iVar2 + 0x120) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar2 + 0x120));
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x120) = 0;
  }
  if (*(DH **)(iVar2 + 0x348) != (DH *)0x0) {
    DH_free(*(DH **)(iVar2 + 0x348));
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x348) = 0;
  }
  if (*(EC_KEY **)(iVar2 + 0x34c) != (EC_KEY *)0x0) {
    EC_KEY_free(*(EC_KEY **)(iVar2 + 0x34c));
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x34c) = 0;
  }
  *(undefined *)(iVar2 + 0x420) = 0;
  pvVar1 = (void *)param_1[0x16];
  uVar7 = *(undefined4 *)((int)pvVar1 + 0xec);
  uVar6 = *(undefined4 *)((int)pvVar1 + 0xfc);
  uVar5 = *(undefined4 *)((int)pvVar1 + 0xf0);
  uVar4 = *(undefined4 *)((int)pvVar1 + 0x100);
  uVar3 = *(undefined4 *)((int)pvVar1 + 0xe8);
  if (*(BIO **)((int)pvVar1 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)((int)pvVar1 + 0x178));
    pvVar1 = (void *)param_1[0x16];
    *(undefined4 *)((int)pvVar1 + 0x178) = 0;
  }
  if (*(int *)((int)pvVar1 + 0x17c) != 0) {
    ssl3_free_digest_list(param_1);
    pvVar1 = (void *)param_1[0x16];
  }
  memset(pvVar1,0,0x424);
  iVar2 = param_1[0x16];
  *(undefined4 *)(iVar2 + 0xec) = uVar7;
  *(undefined4 *)(iVar2 + 0xfc) = uVar6;
  *(undefined4 *)(iVar2 + 0xf0) = uVar5;
  *(undefined4 *)(iVar2 + 0x100) = uVar4;
  *(undefined4 *)(iVar2 + 0xe8) = uVar3;
  ssl_free_wbio_buffer(param_1);
  iVar2 = param_1[0x16];
  pvVar1 = (void *)param_1[0x5d];
  param_1[0x14] = 0;
  *(undefined4 *)(iVar2 + 0x194) = 0;
  *(undefined4 *)(iVar2 + 0x198) = 0;
  *(undefined4 *)(iVar2 + 0x19c) = 0;
  *(undefined4 *)(iVar2 + 0x1a0) = 0;
  *param_1 = 0x300;
  if (pvVar1 != (void *)0x0) {
    CRYPTO_free(pvVar1);
    param_1[0x5d] = 0;
    *(undefined *)(param_1 + 0x5e) = 0;
  }
  return;
}

