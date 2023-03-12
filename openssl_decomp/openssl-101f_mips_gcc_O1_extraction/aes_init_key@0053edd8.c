
undefined4 aes_init_key(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_1[0x18];
  uVar4 = *(uint *)(*param_1 + 0x10) & 0xf0007;
  if ((uVar4 - 1 < 2) && (param_4 == 0)) {
    iVar2 = (*(code *)PTR_AES_set_decrypt_key_006a9b38)(param_2,param_1[0x16] << 3,iVar5);
    puVar1 = PTR_AES_decrypt_006a95f8;
    puVar3 = PTR_AES_cbc_encrypt_006a8b2c;
    if (uVar4 != 2) {
      puVar3 = (undefined *)0x0;
    }
    *(undefined **)(iVar5 + 0xf8) = puVar3;
    *(undefined **)(iVar5 + 0xf4) = puVar1;
  }
  else {
    iVar2 = (*(code *)PTR_AES_set_encrypt_key_006a8adc)(param_2,param_1[0x16] << 3,iVar5);
    puVar1 = PTR_AES_encrypt_006a8b90;
    puVar3 = PTR_AES_cbc_encrypt_006a8b2c;
    if (uVar4 != 2) {
      puVar3 = (undefined *)0x0;
    }
    *(undefined **)(iVar5 + 0xf8) = puVar3;
    *(undefined **)(iVar5 + 0xf4) = puVar1;
  }
  if (-1 < iVar2) {
    return 1;
  }
  ERR_put_error(6,0x85,0x8f,"e_aes.c",0x237);
  return 0;
}

