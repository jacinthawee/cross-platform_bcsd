
void ssl3_clear(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  ssl3_cleanup_key_block();
  iVar2 = param_1[0x16];
  if (*(int *)(iVar2 + 0x36c) != 0) {
    (*(code *)PTR_sk_pop_free_006a8158)(*(int *)(iVar2 + 0x36c),PTR_X509_NAME_free_006a80f8);
    iVar2 = param_1[0x16];
  }
  if (*(int *)(iVar2 + 0x120) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x120) = 0;
  }
  if (*(int *)(iVar2 + 0x348) != 0) {
    (*(code *)PTR_DH_free_006a8604)();
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x348) = 0;
  }
  if (*(int *)(iVar2 + 0x34c) != 0) {
    (*(code *)PTR_EC_KEY_free_006a82d8)();
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x34c) = 0;
  }
  *(undefined *)(iVar2 + 0x420) = 0;
  iVar2 = param_1[0x16];
  uVar8 = *(undefined4 *)(iVar2 + 0xec);
  uVar7 = *(undefined4 *)(iVar2 + 0xfc);
  uVar6 = *(undefined4 *)(iVar2 + 0xf0);
  uVar5 = *(undefined4 *)(iVar2 + 0x100);
  uVar4 = *(undefined4 *)(iVar2 + 0xe8);
  if (*(int *)(iVar2 + 0x178) != 0) {
    (*(code *)PTR_BIO_free_006a7f70)(*(int *)(iVar2 + 0x178));
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar2 + 0x178) = 0;
  }
  if (*(int *)(iVar2 + 0x17c) != 0) {
    ssl3_free_digest_list(param_1);
    iVar2 = param_1[0x16];
  }
  (*(code *)PTR_memset_006aab00)(iVar2,0,0x424);
  puVar1 = PTR_ssl_free_wbio_buffer_006a9024;
  iVar2 = param_1[0x16];
  *(undefined4 *)(iVar2 + 0xec) = uVar8;
  *(undefined4 *)(iVar2 + 0xfc) = uVar7;
  *(undefined4 *)(iVar2 + 0xf0) = uVar6;
  *(undefined4 *)(iVar2 + 0x100) = uVar5;
  *(undefined4 *)(iVar2 + 0xe8) = uVar4;
  (*(code *)puVar1)(param_1);
  iVar2 = param_1[0x16];
  iVar3 = param_1[0x5d];
  param_1[0x14] = 0;
  *(undefined4 *)(iVar2 + 0x194) = 0;
  *(undefined4 *)(iVar2 + 0x198) = 0;
  *(undefined4 *)(iVar2 + 0x19c) = 0;
  *(undefined4 *)(iVar2 + 0x1a0) = 0;
  *param_1 = 0x300;
  if (iVar3 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    param_1[0x5d] = 0;
    *(undefined *)(param_1 + 0x5e) = 0;
  }
  return;
}

