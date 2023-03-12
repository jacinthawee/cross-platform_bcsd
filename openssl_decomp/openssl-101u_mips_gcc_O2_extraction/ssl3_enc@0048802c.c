
undefined4 ssl3_enc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    puVar5 = *(undefined4 **)(param_1 + 0x80);
    iVar4 = *(int *)(param_1 + 0x58) + 0x10c;
  }
  else {
    puVar5 = *(undefined4 **)(param_1 + 0x8c);
    iVar4 = *(int *)(param_1 + 0x58) + 0x130;
  }
  if (((puVar5 == (undefined4 *)0x0) ||
      (iVar1 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a80ec)(puVar5), *(int *)(param_1 + 0xc0) == 0)
      ) || (iVar1 == 0)) {
    (*(code *)PTR_memmove_006a9af4)
              (*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 4)
              );
    uVar3 = 1;
    *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
  }
  else {
    uVar6 = *(uint *)(iVar4 + 4);
    uVar2 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(*puVar5);
    if (uVar2 == 1) {
      if ((param_2 == 0) && (uVar6 == 0)) {
        return 0;
      }
    }
    else if (param_2 == 0) {
      if (uVar6 == 0) {
        return 0;
      }
      if (uVar2 == 0) {
        trap(7);
      }
      if (uVar6 % uVar2 != 0) {
        return 0;
      }
    }
    else {
      if (uVar2 == 0) {
        trap(7);
      }
      iVar1 = uVar2 - (int)uVar6 % (int)uVar2;
      (*(code *)PTR_memset_006a99f4)(*(int *)(iVar4 + 0x10) + *(int *)(iVar4 + 4),0,iVar1);
      uVar6 = uVar6 + iVar1;
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + iVar1;
      *(char *)(*(int *)(iVar4 + 0x10) + uVar6 + -1) = (char)iVar1 + -1;
    }
    iVar1 = (*(code *)PTR_EVP_Cipher_006a80f4)
                      (puVar5,*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 0x10),uVar6);
    if (0 < iVar1) {
      iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x84));
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x84));
        uVar3 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar3);
      }
      if ((uVar2 != 1) && (param_2 == 0)) {
        uVar3 = ssl3_cbc_remove_padding(param_1,iVar4,uVar2,uVar3);
        return uVar3;
      }
      return 1;
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

