
undefined4 * ECDH_DATA_new_method_constprop_1(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"ech_lib.c",0x8e);
  if (puVar2 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2b,0x65,0x41,"ech_lib.c",0x91);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    if (default_ECDH_method == (ECDH_METHOD *)0x0) {
      default_ECDH_method = ECDH_OpenSSL();
    }
    puVar1 = PTR_ENGINE_get_default_ECDH_006aa884;
    puVar2[3] = default_ECDH_method;
    puVar2[1] = 0;
    iVar3 = (*(code *)puVar1)();
    puVar2[1] = iVar3;
    if (iVar3 == 0) {
      iVar3 = puVar2[3];
    }
    else {
      iVar3 = (*(code *)PTR_ENGINE_get_ECDH_006aa888)(iVar3);
      puVar2[3] = iVar3;
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2b,0x65,0x26,"ech_lib.c",0xa1);
        (*(code *)PTR_ENGINE_finish_006a80c4)(puVar2[1]);
        (*(code *)PTR_CRYPTO_free_006a7f88)(puVar2);
        return (undefined4 *)0x0;
      }
    }
    puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
    puVar2[2] = *(undefined4 *)(iVar3 + 8);
    (*(code *)puVar1)(0xd,puVar2,puVar2 + 4);
  }
  return puVar2;
}
