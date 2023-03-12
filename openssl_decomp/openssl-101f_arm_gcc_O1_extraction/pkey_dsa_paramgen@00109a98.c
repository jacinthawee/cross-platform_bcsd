
int pkey_dsa_paramgen(int param_1,EVP_PKEY *param_2)

{
  DSA *r;
  int iVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined auStack_24 [12];
  
  puVar2 = *(undefined **)(param_1 + 0x1c);
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  if (puVar2 != (undefined *)0x0) {
    puVar2 = auStack_24;
    evp_pkey_set_cb_translate(puVar2,param_1);
  }
  r = DSA_new();
  if (r != (DSA *)0x0) {
    iVar1 = dsa_builtin_paramgen(r,*puVar3,puVar3[1],puVar3[2],0,0,0,0,0,puVar2);
    if (iVar1 == 0) {
      DSA_free(r);
      return 0;
    }
    EVP_PKEY_assign(param_2,0x74,r);
    return iVar1;
  }
  return 0;
}

