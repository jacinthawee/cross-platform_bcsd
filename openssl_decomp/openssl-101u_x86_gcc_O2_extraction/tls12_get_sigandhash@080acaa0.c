
undefined4 tls12_get_sigandhash(undefined *param_1,int *param_2,EVP_MD *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (param_3 != (EVP_MD *)0x0) {
    iVar2 = EVP_MD_type(param_3);
    if (iVar2 == tls12_md._0_4_) {
      puVar3 = tls12_md;
    }
    else if (iVar2 == tls12_md._8_4_) {
      puVar3 = (undefined1 *)0x82f4e68;
    }
    else if (iVar2 == tls12_md._16_4_) {
      puVar3 = (undefined1 *)0x82f4e70;
    }
    else if (iVar2 == tls12_md._24_4_) {
      puVar3 = (undefined1 *)0x82f4e78;
    }
    else if (iVar2 == tls12_md._32_4_) {
      puVar3 = (undefined1 *)0x82f4e80;
    }
    else {
      if (iVar2 != tls12_md._40_4_) {
        return 0;
      }
      puVar3 = (undefined1 *)0x82f4e88;
    }
    iVar2 = *(int *)(puVar3 + 4);
    if (iVar2 != -1) {
      iVar1 = *param_2;
      if (iVar1 == tls12_sig._0_4_) {
        puVar3 = tls12_sig;
      }
      else if (iVar1 == tls12_sig._8_4_) {
        puVar3 = (undefined1 *)0x82f4e48;
      }
      else {
        if (iVar1 != tls12_sig._16_4_) {
          return 0;
        }
        puVar3 = (undefined1 *)0x82f4e50;
      }
      if (*(int *)(puVar3 + 4) != -1) {
        param_1[1] = (char)*(int *)(puVar3 + 4);
        *param_1 = (char)iVar2;
        return 1;
      }
    }
  }
  return 0;
}

