
undefined4 ssl3_enc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  code *pcVar8;
  
  if (param_2 == 0) {
    puVar6 = *(undefined4 **)(param_1 + 0x80);
    iVar5 = *(int *)(param_1 + 0x58) + 0x10c;
  }
  else {
    puVar6 = *(undefined4 **)(param_1 + 0x8c);
    iVar5 = *(int *)(param_1 + 0x58) + 0x130;
  }
  if (((puVar6 == (undefined4 *)0x0) ||
      (iVar1 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a9218)(puVar6), *(int *)(param_1 + 0xc0) == 0)
      ) || (iVar1 == 0)) {
    (*(code *)PTR_memmove_006aabfc)
              (*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 4)
              );
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar5 + 0xc);
    return 1;
  }
  uVar7 = *(uint *)(iVar5 + 4);
  uVar2 = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(*puVar6);
  if (uVar2 == 1) {
    if ((param_2 == 0) && (uVar7 == 0)) {
      return 0;
    }
    uVar4 = *(undefined4 *)(iVar5 + 0x10);
    uVar3 = *(undefined4 *)(iVar5 + 0xc);
    pcVar8 = (code *)PTR_EVP_Cipher_006a90b0;
LAB_0048c244:
    (*pcVar8)(puVar6,uVar3,uVar4,uVar7);
    iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x84));
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    if (param_2 != 0) {
      if (uVar2 == 0) {
        trap(7);
      }
      iVar1 = uVar2 - (int)uVar7 % (int)uVar2;
      (*(code *)PTR_memset_006aab00)(*(int *)(iVar5 + 0x10) + *(int *)(iVar5 + 4),0,iVar1);
      pcVar8 = (code *)PTR_EVP_Cipher_006a90b0;
      uVar7 = uVar7 + iVar1;
      *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + iVar1;
      *(char *)(*(int *)(iVar5 + 0x10) + uVar7 + -1) = (char)iVar1 + -1;
      uVar4 = *(undefined4 *)(iVar5 + 0x10);
      uVar3 = *(undefined4 *)(iVar5 + 0xc);
      goto LAB_0048c244;
    }
    if (uVar7 == 0) {
      return 0;
    }
    if (uVar2 == 0) {
      trap(7);
    }
    if (uVar7 % uVar2 != 0) {
      return 0;
    }
    (*(code *)PTR_EVP_Cipher_006a90b0)
              (puVar6,*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10),uVar7);
    iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x84));
    if (iVar1 == 0) goto LAB_0048c2f0;
  }
  uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x84));
  iVar1 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar3);
  if ((uVar2 == 1) || (param_2 != 0)) {
    return 1;
  }
LAB_0048c2f0:
  uVar3 = ssl3_cbc_remove_padding(param_1,iVar5,uVar2,iVar1);
  return uVar3;
}

