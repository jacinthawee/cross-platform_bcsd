
undefined4 dtls1_enc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined uVar6;
  int iVar5;
  undefined *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  
  if (param_2 == 0) {
    iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x84));
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x84));
      iVar1 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar2);
      if (iVar1 < 0) {
        OpenSSLDie("d1_enc.c",0xac,"mac_size >= 0");
      }
    }
    puVar9 = *(undefined4 **)(param_1 + 0x80);
    iVar8 = *(int *)(param_1 + 0x58) + 0x10c;
    if (puVar9 == (undefined4 *)0x0) goto LAB_004a555c;
    iVar3 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a80ec)(puVar9);
  }
  else {
    iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x90));
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x90));
      iVar1 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar2);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
    }
    iVar10 = *(int *)(param_1 + 0x58);
    puVar9 = *(undefined4 **)(param_1 + 0x8c);
    iVar8 = iVar10 + 0x130;
    if (puVar9 == (undefined4 *)0x0) goto LAB_004a555c;
    iVar3 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a80ec)(puVar9);
    if (*(int *)(iVar10 + 0x13c) == *(int *)(iVar10 + 0x140)) {
      iVar5 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(*puVar9);
      if (1 < iVar5) {
        uVar11 = *(undefined4 *)(iVar10 + 0x140);
        uVar2 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(*puVar9);
        iVar10 = (*(code *)PTR_RAND_bytes_006a7574)(uVar11,uVar2);
        if (iVar10 < 1) {
          return 0xffffffff;
        }
      }
    }
    else {
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stderr_006a9af8,1,"%s:%d: rec->data != rec->input\n","d1_enc.c",
                 0xa2);
    }
  }
  if ((*(int *)(param_1 + 0xc0) != 0) && (iVar3 != 0)) {
    uVar12 = *(uint *)(iVar8 + 4);
    uVar4 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(*puVar9);
    if (uVar4 == 1) {
      if ((param_2 == 0) && (uVar12 == 0)) {
        return 0;
      }
      iVar1 = (*(code *)PTR_EVP_Cipher_006a80f4)
                        (puVar9,*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10),uVar12);
      if (0 < iVar1) {
        return 1;
      }
    }
    else {
      if (param_2 != 0) {
        if (uVar4 == 0) {
          trap(7);
        }
        iVar1 = uVar4 - (int)uVar12 % (int)uVar4;
        uVar6 = (undefined)(iVar1 + -1);
        if ((*(uint *)(param_1 + 0x100) & 0x200) != 0) {
          iVar10 = iVar1 + -1;
          if ((**(uint **)(param_1 + 0x58) & 8) != 0) {
            iVar10 = iVar1;
          }
          uVar6 = (undefined)iVar10;
        }
        uVar4 = uVar12 + iVar1;
        if ((int)uVar12 < (int)uVar4) {
          do {
            puVar7 = (undefined *)(*(int *)(iVar8 + 0x10) + uVar12);
            uVar12 = uVar12 + 1;
            *puVar7 = uVar6;
          } while (uVar12 != uVar4);
        }
        puVar7 = PTR_EVP_Cipher_006a80f4;
        *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + iVar1;
        iVar1 = (*(code *)puVar7)(puVar9,*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10))
        ;
        if (0 < iVar1) {
          return 1;
        }
        return 0xffffffff;
      }
      if (uVar12 == 0) {
        return 0;
      }
      if (uVar4 == 0) {
        trap(7);
      }
      if (uVar12 % uVar4 != 0) {
        return 0;
      }
      iVar10 = (*(code *)PTR_EVP_Cipher_006a80f4)
                         (puVar9,*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10),uVar12);
      if (0 < iVar10) {
        uVar2 = tls1_cbc_remove_padding(param_1,iVar8,uVar4,iVar1);
        return uVar2;
      }
    }
    return 0xffffffff;
  }
LAB_004a555c:
  (*(code *)PTR_memmove_006a9af4)
            (*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 4));
  *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(iVar8 + 0xc);
  return 1;
}

