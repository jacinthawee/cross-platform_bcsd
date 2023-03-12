
undefined4 tls12_get_sigandhash(undefined *param_1,int *param_2,EVP_MD *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (param_3 != (EVP_MD *)0x0) {
    iVar1 = EVP_MD_type(param_3);
    if (iVar1 == tls12_md._0_4_) {
      puVar2 = tls12_md;
    }
    else if (iVar1 == tls12_md._8_4_) {
      puVar2 = (undefined1 *)0x18ccf8;
    }
    else if (iVar1 == tls12_md._16_4_) {
      puVar2 = (undefined1 *)0x18cd00;
    }
    else if (iVar1 == tls12_md._24_4_) {
      puVar2 = (undefined1 *)0x18cd08;
    }
    else if (iVar1 == tls12_md._32_4_) {
      puVar2 = (undefined1 *)0x18cd10;
    }
    else {
      if (iVar1 != tls12_md._40_4_) {
        return 0;
      }
      puVar2 = (undefined1 *)0x18cd18;
    }
    if (*(int *)(puVar2 + 4) != -1) {
      iVar1 = *param_2;
      if (iVar1 == tls12_sig._0_4_) {
        puVar3 = tls12_sig;
      }
      else if (iVar1 == tls12_sig._8_4_) {
        puVar3 = (undefined1 *)0x18cd28;
      }
      else {
        if (iVar1 != tls12_sig._16_4_) {
          return 0;
        }
        puVar3 = (undefined1 *)0x18cd30;
      }
      iVar1 = *(int *)(puVar3 + 4);
      if (iVar1 != -1) {
        *param_1 = (char)*(int *)(puVar2 + 4);
        param_1[1] = (char)iVar1;
        return 1;
      }
    }
  }
  return 0;
}

